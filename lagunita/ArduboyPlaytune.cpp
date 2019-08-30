/**
 * @file ArduboyPlaytune.cpp
 * \brief An Arduino library that plays a one or two part musical score and
 * generates tones. Intended for the Arduboy game system.
 */

/*****************************************************************************
 * ArduboyPlaytune
 *
 * Plays a one or two part musical score and generates tones.
 *
 * Derived from:
 * Playtune: An Arduino tune player library
 * https://github.com/LenShustek/arduino-playtune
 *
 * Modified to work well with the Arduboy game system
 * https://www.arduboy.com/
 *
 * The MIT License (MIT)
 *
 * (C) Copyright 2016, Chris J. Martinez, Kevin Bates, Josh Goebel, Scott Allen
 * Based on work (C) Copyright 2011, 2015, Len Shustek
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 *all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This was inspired by and adapted from "A Tone Generator Library",
 * written by Brett Hagman, http://www.roguerobotics.com/
 *
 *****************************************************************************/
/* 27 March 2018, L. Shustek
This was adapted from my Playtune library, but it was missing this fix that
prevents a "stuttering" playback because of timing errors:
  15 August 2016, L. Shustek,
      - Fixed a timing error: T Wasiluk's change to using a 16-bit timer instead
        of an 8-bit timer for score waits exposed a old bug that was in the
original Brett Hagman code: when writing the timer OCR value, we need to clear
the timer counter, or else (the manual says) "the counter [might] miss the
compare match...and will have to count to its maximum value (0xFFFF) and wrap
around starting at 0 before the compare match can occur". This caused an error
that was small and not noticeable for the 8-bit timer, but could be hundreds of
        milliseconds for the 16-bit counter. Thanks go to Joey Babcock for
pushing me to figure out why his music sounded weird, and for discovering that
it worked ok with the 2013 version that used the 8-bit timer for score waits.
*/

#include "ArduboyPlaytune.hpp"
#include <avr/power.h>

static const byte tune_pin_to_timer[] = {3, 1};
static volatile byte* _tunes_timer1_pin_port;
static volatile byte _tunes_timer1_pin_mask;
static volatile int32_t timer1_toggle_count;
static volatile byte* _tunes_timer3_pin_port;
static volatile byte _tunes_timer3_pin_mask;
static byte _tune_pins[AVAILABLE_TIMERS];
static byte _tune_num_chans = 0;
static volatile boolean tune_playing = false;   // is the score still playing?
static volatile unsigned wait_timer_frequency2; /* its current frequency */
static volatile boolean wait_timer_playing =
    false; /* is it currently playing a note? */
static volatile unsigned long wait_toggle_count; /* countdown score waits */
static volatile boolean all_muted = false;       // indicates all sound is muted
static volatile boolean tone_playing = false;
static volatile boolean tone_mutes_score = false;
static volatile boolean tone_only =
    false;  // indicates don't play score on tone channel
static volatile boolean mute_score =
    false;  // indicates tone playing so mute other channels

// pointer to a function that indicates if sound is enabled
static boolean (*outputEnabled)();

// pointers to your musical score and your position in said score
static volatile const byte* score_start = 0;
static volatile const byte* score_cursor = 0;

// array of frequencies used by the music
const unsigned int _frequencies[] PROGMEM = {
    16,  73,  82,  87,  98,  110, 131, 147, 165, 175, 196, 220,
    247, 262, 294, 330, 349, 392, 440, 494, 523, 587, 659};

// array of note durations used by the music
const unsigned int _durations[] PROGMEM = {0, 136, 272, 409, 545, 818, 1090};

ArduboyPlaytune::ArduboyPlaytune(boolean (*outEn)()) {
  outputEnabled = outEn;
}

void ArduboyPlaytune::initChannel(byte pin) {
  byte timer_num;
  byte pin_port;
  byte pin_mask;
  volatile byte* out_reg;

  // we are all out of timers
  if (_tune_num_chans == AVAILABLE_TIMERS)
    return;

  timer_num = tune_pin_to_timer[_tune_num_chans];
  _tune_pins[_tune_num_chans] = pin;
  if ((_tune_num_chans == 1) &&
      (_tune_pins[0] == pin)) {  // if channels 0 and 1 use the same pin
    tone_only = true;            // don't play the score on channel 1
  }
  _tune_num_chans++;

  pin_port = digitalPinToPort(pin);
  pin_mask = digitalPinToBitMask(pin);
  out_reg = portOutputRegister(pin_port);

  *portModeRegister(pin_port) |= pin_mask;  // set pin to output mode

  switch (timer_num) {
    case 1:  // 16 bit timer
      power_timer1_enable();
      TCCR1A = 0;
      TCCR1B = 0;
      bitWrite(TCCR1B, WGM12, 1);
      bitWrite(TCCR1B, CS10, 1);
      _tunes_timer1_pin_port = out_reg;
      _tunes_timer1_pin_mask = pin_mask;
      break;
    case 3:  // 16 bit timer
      power_timer3_enable();
      TCCR3A = 0;
      TCCR3B = 0;
      bitWrite(TCCR3B, WGM32, 1);
      bitWrite(TCCR3B, CS30, 1);
      _tunes_timer3_pin_port = out_reg;
      _tunes_timer3_pin_mask = pin_mask;
      playNote(0, 60); /* start and stop channel 0 (timer 3) on middle C so
                          wait/delay works */
      stopNote(0);
      break;
  }
}

void ArduboyPlaytune::playNote(byte chan, byte note) {
  byte timer_num;
  byte prescalar_bits;
  unsigned int frequency2; /* frequency times 2 */
  unsigned long ocr;

  // we can't play on a channel that does not exist
  if (chan >= _tune_num_chans) {
    return;
  }

  // if channel 1 is for tones only
  if ((chan == 1) && tone_only) {
    return;
  }

  // we only have frequencies for 128 notes
  if (note > 127) {
    return;
  }

  timer_num = tune_pin_to_timer[chan];
  frequency2 = pgm_read_word(_frequencies + note);

  //******  16-bit timer  *********
  // two choices for the 16 bit timers: ck/1 or ck/64
  ocr = F_CPU / frequency2 - 1;
  prescalar_bits = 0b001;
  if (ocr > 0xffff) {
    ocr = F_CPU / frequency2 / 64 - 1;
    prescalar_bits = 0b011;
  }
  // Set the OCR for the given timer, then turn on the interrupts
  switch (timer_num) {
    case 1:
      if (!tone_playing) {
        TCCR1B = (TCCR1B & 0b11111000) | prescalar_bits;
        OCR1A = ocr;
        TCNT1 = 0;  // LJS
        bitWrite(TIMSK1, OCIE1A, 1);
      }
      break;
    case 3:
      TCCR3B = (TCCR3B & 0b11111000) | prescalar_bits;
      OCR3A = ocr;
      TCNT3 = 0;                           // LJS
      wait_timer_frequency2 = frequency2;  // for "tune_delay" function
      wait_timer_playing = true;
      bitWrite(TIMSK3, OCIE3A, 1);
      break;
  }
}

void ArduboyPlaytune::stopNote(byte chan) {
  byte timer_num;
  timer_num = tune_pin_to_timer[chan];
  switch (timer_num) {
    case 1:
      if (!tone_playing) {
        TIMSK1 &= ~(1 << OCIE1A);  // disable the interrupt
        *_tunes_timer1_pin_port &=
            ~(_tunes_timer1_pin_mask);  // keep pin low after stop
      }
      break;
    case 3:
      wait_timer_playing = false;
      if (!mute_score) {
        *_tunes_timer3_pin_port &=
            ~(_tunes_timer3_pin_mask);  // keep pin low after stop
      }
      break;
  }
}

void ArduboyPlaytune::playScore(const byte* score) {
  score_start = score;
  score_cursor = score_start;
  step();              /* execute initial commands */
  tune_playing = true; /* release the interrupt routine */
}

void ArduboyPlaytune::stopScore() {
  for (uint8_t i = 0; i < _tune_num_chans; i++)
    stopNote(i);
  tune_playing = false;
}

boolean ArduboyPlaytune::playing() {
  return tune_playing;
}

/* Do score commands until a "wait" is found, or the score is stopped.
This is called initially from playScore(), but then is called
from the interrupt routine when waits expire.

If CMD < 0x80, then the other 7 bits and the next byte are a
15-bit big-endian number of msec to wait
*/
void ArduboyPlaytune::step() {
  byte command, note, dur;
  const byte chan = 0;

  while (1) {
    command = pgm_read_byte(score_cursor++);
    if (command == 0) {
      tune_playing = false;
      return;
    }

    note = command & 0x19;
    dur = (command >> 5) & 0x7;

    if (!note) { /* stop note */
      stopNote(chan);
    } else { /* play note */
      all_muted = !outputEnabled();
      playNote(chan, note);
    };

    if (dur) { /* wait count in msec. */
      wait_toggle_count = ((unsigned long)wait_timer_frequency2 *
                               pgm_read_word(_durations + dur) +
                           500) /
                          1000;
      if (wait_toggle_count == 0)
        wait_toggle_count = 1;
    }
  }
}

void ArduboyPlaytune::closeChannels() {
  byte timer_num;
  for (uint8_t chan = 0; chan < _tune_num_chans; chan++) {
    timer_num = tune_pin_to_timer[chan];
    switch (timer_num) {
      case 1:
        TIMSK1 &= ~(1 << OCIE1A);
        *_tunes_timer1_pin_port &= ~(_tunes_timer1_pin_mask);  // set pin low
        break;
      case 3:
        TIMSK3 &= ~(1 << OCIE3A);
        *_tunes_timer3_pin_port &= ~(_tunes_timer3_pin_mask);  // set pin low
        break;
    }
  }
  _tune_num_chans = 0;
  tune_playing = tone_playing = tone_only = mute_score = false;
}

void ArduboyPlaytune::tone(unsigned int frequency, unsigned long duration) {
  // don't output the tone if sound is muted or
  // the tone channel isn't initialised
  if (!outputEnabled() || _tune_num_chans < 2) {
    return;
  }

  tone_playing = true;
  mute_score = tone_mutes_score;

  uint8_t prescalarbits = 0b001;
  int32_t toggle_count = 0;
  uint32_t ocr = 0;

  // two choices for the 16 bit timers: ck/1 or ck/64
  ocr = F_CPU / frequency / 2 - 1;
  prescalarbits = 0b001;
  if (ocr > 0xffff) {
    ocr = F_CPU / frequency / 2 / 64 - 1;
    prescalarbits = 0b011;
  }
  TCCR1B = (TCCR1B & 0b11111000) | prescalarbits;

  // Calculate the toggle count
  if (duration > 0) {
    toggle_count = 2 * frequency * duration / 1000;
  } else {
    toggle_count = -1;
  }
  // Set the OCR for the given timer,
  // set the toggle count,
  // then turn on the interrupts
  OCR1A = ocr;
  timer1_toggle_count = toggle_count;
  bitWrite(TIMSK1, OCIE1A, 1);
}

void ArduboyPlaytune::toneMutesScore(boolean mute) {
  tone_mutes_score = mute;
}

// ===== Interrupt service routines =====

// TIMER 1
ISR(TIMER1_COMPA_vect) {
  if (tone_playing) {
    if (timer1_toggle_count != 0) {
      // toggle the pin
      *_tunes_timer1_pin_port ^= _tunes_timer1_pin_mask;
      if (timer1_toggle_count > 0)
        timer1_toggle_count--;
    } else {
      tone_playing = mute_score = false;
      TIMSK1 &= ~(1 << OCIE1A);  // disable the interrupt
      *_tunes_timer1_pin_port &=
          ~(_tunes_timer1_pin_mask);  // keep pin low after stop
    }
  } else {
    if (!all_muted) {
      *_tunes_timer1_pin_port ^= _tunes_timer1_pin_mask;  // toggle the pin
    }
  }
}

// TIMER 3
ISR(TIMER3_COMPA_vect) {
  // Timer 3 is the one assigned first, so we keep it running always
  // and use it to time score waits, whether or not it is playing a note.

  // toggle the pin if we're sounding a note
  if (wait_timer_playing && !mute_score && !all_muted) {
    *_tunes_timer3_pin_port ^= _tunes_timer3_pin_mask;
  }

  if (tune_playing && wait_toggle_count && --wait_toggle_count == 0) {
    // end of a score wait, so execute more score commands
    ArduboyPlaytune::step();  // execute commands
  }
}
