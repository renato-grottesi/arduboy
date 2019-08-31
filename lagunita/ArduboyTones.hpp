/**
 * @file ArduboyTones.h
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

#ifndef ARDUBOY_TONES_H
#define ARDUBOY_TONES_H

#include <Arduino.h>

// ************************************************************
// ***** Values to use as function parameters in sketches *****
// ************************************************************

/** \brief
 * Frequency value for sequence termination. (No duration follows)
 */
#define TONES_END 0x8000

/** \brief
 * Frequency value for sequence repeat. (No duration follows)
 */
#define TONES_REPEAT 0x8001

/** \brief
 * Add this to the frequency to play a tone at high volume
 */
#define TONE_HIGH_VOLUME 0x8000

/** \brief
 * `volumeMode()` parameter. Use the volume encoded in each tone's frequency
 */
#define VOLUME_IN_TONE 0

/** \brief
 * `volumeMode()` parameter. Play all tones at normal volume, ignoring
 * what's encoded in the frequencies
 */
#define VOLUME_ALWAYS_NORMAL 1

/** \brief
 * `volumeMode()` parameter. Play all tones at high volume, ignoring
 * what's encoded in the frequencies
 */
#define VOLUME_ALWAYS_HIGH 2

// ************************************************************

#ifndef AB_DEVKIT
// ***** SPEAKER ON TWO PINS *****
// Indicates that each of the speaker leads is attached to a pin, the way
// the Arduboy is wired. Allows tones of a higher volume to be produced.
// If commented out only one speaker pin will be used. The other speaker
// lead should be attached to ground.
#define TONES_2_SPEAKER_PINS
// *******************************

// ***** VOLUME HIGH/NORMAL SUPPORT *****
// With the speaker placed across two pins, higher volume is produced by
// toggling the second pin to the opposite state of the first pin.
// Normal volume is produced by leaving the second pin low.
// Comment this out for only normal volume support, which will slightly
// reduce the code size.
#define TONES_VOLUME_CONTROL
// **************************************

#ifdef TONES_VOLUME_CONTROL
// Must be defined for volume control, so force it if necessary.
#define TONES_2_SPEAKER_PINS
#endif
#endif

#ifndef AB_DEVKIT
// Arduboy speaker pin 1 = Arduino pin 5 = ATmega32u4 PC6
#define TONE_PIN_PORT PORTC
#define TONE_PIN_DDR DDRC
#define TONE_PIN PORTC6
#define TONE_PIN_MASK _BV(TONE_PIN)
// Arduboy speaker pin 2 = Arduino pin 13 = ATmega32u4 PC7
#define TONE_PIN2_PORT PORTC
#define TONE_PIN2_DDR DDRC
#define TONE_PIN2 PORTC7
#define TONE_PIN2_MASK _BV(TONE_PIN2)
#else
// DevKit speaker pin 1 = Arduino pin A2 = ATmega32u4 PF5
#define TONE_PIN_PORT PORTF
#define TONE_PIN_DDR DDRF
#define TONE_PIN PORTF5
#define TONE_PIN_MASK _BV(TONE_PIN)
#endif

// Dummy frequency used to for silent tones (rests).
#define SILENT_FREQ 250

/** \brief
 * The ArduboyTones class for generating tones by specifying
 * frequency/duration pairs.
 */
class ArduboyTones {
 public:
  /** \brief
   * The ArduboyTones class constructor.
   */
  ArduboyTones(bool (*outEn)());

  /** \brief
   * Play a tone sequence from frequency/duration pairs in a PROGMEM array.
   *
   * \param tones A pointer to an array of frequency/duration pairs.
   * The array must be placed in code space using `PROGMEM`.
   *
   * \details
   * \parblock
   * See the `tone()` function for details on the frequency and duration values.
   * A frequency of 0 for any tone means silence (a musical rest).
   *
   * The last element of the array must be `TONES_END` or `TONES_REPEAT`.
   *
   * Example:
   *
   * \code
   * const uint16_t sound1[] PROGMEM = {
   *   220,1000, 0,250, 440,500, 880,2000,
   *   TONES_END
   * };
   * \endcode
   *
   * \endparblock
   */
  static void tones(const uint8_t* tones);

  /** \brief
   * Stop playing the tone or sequence.
   *
   * \details
   * If a tone or sequence is playing, it will stop. If nothing
   * is playing, this function will do nothing.
   */
  static void noTone();

  /** \brief
   * Check if a tone or tone sequence is playing.
   *
   * \return boolean `true` if playing (even if sound is muted).
   */
  static bool playing();

 private:
  // Get the next value in the sequence
  static uint8_t getNext();

 public:
  // Called from ISR so must be public. Should not be called by a program.
  static void nextTone();
};

#endif
