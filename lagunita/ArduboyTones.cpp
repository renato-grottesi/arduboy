/**
 * @file ArduboyTones.cpp
 * \brief An Arduino library for playing tones and tone sequences,
 * intended for the Arduboy game system.
 */

/*****************************************************************************
  ArduboyTones

An Arduino library to play tones and tone sequences.

Specifically written for use by the Arduboy miniature game system
https://www.arduboy.com/
but could work with other Arduino AVR boards that have 16 bit timer 3
available, by changing the port and bit definintions for the pin(s)
if necessary.

Copyright (c) 2017 Scott Allen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#include "ArduboyTones.hpp"

// pointer to a function that indicates if sound is enabled
static bool (*outputEnabled)();

static volatile long durationToggleCount = 0;
static volatile bool tonesPlaying = false;
static volatile bool toneSilent;

static volatile uint8_t* tonesStart;
static volatile uint8_t* tonesIndex;

// array of frequencies used by the music
static const unsigned int frequencies[] PROGMEM = {0,   73,  82,  87,  98,  110, 131, 147,
                                                   165, 175, 196, 220, 247, 262, 294, 330,
                                                   349, 392, 440, 494, 523, 587, 659};

// array of note durations used by the music
static const unsigned int durations[] PROGMEM = {0, 136, 272, 409, 545, 818, 1090};

ArduboyTones::ArduboyTones(bool (*outEn)()) {
  outputEnabled = outEn;

  bitClear(TONE_PIN_PORT, TONE_PIN);  // set the pin low
  bitSet(TONE_PIN_DDR, TONE_PIN);     // set the pin to output mode
}

void ArduboyTones::tones(const uint8_t* tones) {
  bitWrite(TIMSK3, OCIE3A, 0);                // disable the output compare match interrupt
  tonesStart = tonesIndex = (uint8_t*)tones;  // set to start of sequence array
  nextTone();                                 // start playing
}

void ArduboyTones::noTone() {
  bitWrite(TIMSK3, OCIE3A, 0);        // disable the output compare match interrupt
  TCCR3B = 0;                         // stop the counter
  bitClear(TONE_PIN_PORT, TONE_PIN);  // set the pin low
  tonesPlaying = false;
}

bool ArduboyTones::playing() {
  return tonesPlaying;
}

void ArduboyTones::nextTone() {
  uint16_t freq;
  uint16_t dur;
  long toggleCount;
  uint32_t ocrValue;

  uint8_t cmd = getNext();

  if (cmd == 0) {  // "end of sequence" marker
    noTone();      // stop playing
    return;
  }

  tonesPlaying = true;

  freq = pgm_read_word(frequencies + (cmd & 0x1f));
  dur = pgm_read_word(durations + (cmd >> 5));

  if (freq == 0) {                               // if tone is silent
    ocrValue = F_CPU / 8 / SILENT_FREQ / 2 - 1;  // dummy tone for silence
    freq = SILENT_FREQ;
    toneSilent = true;
    bitClear(TONE_PIN_PORT, TONE_PIN);  // set the pin low
  } else {
    ocrValue = F_CPU / 8 / freq / 2 - 1;
    toneSilent = false;
  }

  if (!outputEnabled()) {  // if sound has been muted
    toneSilent = true;
  }

  if (dur != 0) {
    // A right shift is used to divide by 512 for efficency.
    // For durations in milliseconds it should actually be a divide by 500,
    // so durations will by shorter by 2.34% of what is specified.
    toggleCount = (static_cast<long>(dur) * freq) >> 9;
  } else {
    toggleCount = 1;  // indicate no duration
  }

  TCCR3A = 0;
  TCCR3B = _BV(WGM32) | _BV(CS31);  // CTC mode, prescaler /8
  OCR3A = ocrValue;
  durationToggleCount = toggleCount;
  bitWrite(TIMSK3, OCIE3A, 1);  // enable the output compare match interrupt
}

uint8_t ArduboyTones::getNext() {
  return pgm_read_byte(tonesIndex++);
}

ISR(TIMER3_COMPA_vect) {
  if (durationToggleCount != 0) {
    if (!toneSilent) {
      *(&TONE_PIN_PORT) ^= TONE_PIN_MASK;  // toggle the pin
    }
    if (durationToggleCount > 0) {
      durationToggleCount--;
    }
  } else {
    ArduboyTones::nextTone();
  }
}
