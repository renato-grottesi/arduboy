#pragma once

/* List of headers included by all the other headers. */
#include <Arduboy2.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Tinyfont.hpp"

extern "C" {
#include <stdint.h>
}

/* Enum class for the 6 input buttons. */
enum class Input : uint8_t { left, right, up, down, a, b };

/* A class with utilities for special drawing. */
class Drawing {
 public:
  Drawing(uint8_t* buff) : sBuffer(buff){};

  /* Draw a bitmap. */
  void drawBitmap(int16_t x,
                  int16_t y,
                  const uint8_t* bitmap,
                  uint8_t w,
                  uint8_t h,
                  bool mirrored = false) {
    if (mirrored) {
      drawBitmapMirrored(x, y, bitmap, w, h);
    } else {
      drawBitmapPlain(x, y, bitmap, w, h);
    }
  }

  /* Draw a plain bitmap. */
  void drawBitmapPlain(int16_t x,
                       int16_t y,
                       const uint8_t* bitmap,
                       uint8_t w,
                       uint8_t h);

  /* Draw a mirrored bitmap. */
  void drawBitmapMirrored(int16_t x,
                          int16_t y,
                          const uint8_t* bitmap,
                          uint8_t w,
                          uint8_t h);

  /* Draw a bitmap that is transparent from the top
     down to the first white pixel.
   */
  void drawBitmapAlpha(int16_t x,
                       int16_t y,
                       const uint8_t* bitmap,
                       uint8_t w,
                       uint8_t h);

  /* Lake reflection effect. */
  void waterReflection(uint8_t frame);

 private:
  uint8_t* sBuffer;
};
