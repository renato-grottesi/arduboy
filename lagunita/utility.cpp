#include "utility.hpp"

/* This code comes from the arduboy2 library. */
void Drawing::drawBitmapPlain(int16_t x,
                              int16_t y,
                              const uint8_t* bitmap,
                              uint8_t w,
                              uint8_t h) {
  if (x + w < 0 || x > WIDTH - 1 || y + h < 0 || y > HEIGHT - 1) {
    return;
  }

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  const int rows = (h % 8 != 0) ? (h / 8) + 1 : (h / 8);

  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT / 8) - 1) {
      break;
    }
    if (bRow > -2) {
      for (int iCol = 0; iCol < w; iCol++) {
        if (iCol + x > (WIDTH - 1)) {
          break;
        }
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            sBuffer[(bRow * WIDTH) + x + iCol] |=
                pgm_read_byte(bitmap + (a * w) + iCol) << yOffset;
          }
          if (yOffset && bRow < (HEIGHT / 8) - 1 && bRow > -2) {
            sBuffer[((bRow + 1) * WIDTH) + x + iCol] |=
                pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset);
          }
        }
      }
    }
  }
}

void Drawing::drawBitmapMirrored(int16_t x,
                                 int16_t y,
                                 const uint8_t* bitmap,
                                 uint8_t w,
                                 uint8_t h) {
  if (x + w < 0 || x > WIDTH - 1 || y + h < 0 || y > HEIGHT - 1) {
    return;
  }

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  const int rows = (h % 8 != 0) ? (h / 8) + 1 : (h / 8);

  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT / 8) - 1) {
      break;
    }
    if (bRow > -2) {
      for (int iCol = 0; iCol < w; iCol++) {
        if (iCol + x > (WIDTH - 1)) {
          break;
        }
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            /* Reverse the column read in the source image. */
            sBuffer[(bRow * WIDTH) + x + iCol] |=
                pgm_read_byte(bitmap + (a * w) + w - 1 - iCol) << yOffset;
          }
          if (yOffset && bRow < (HEIGHT / 8) - 1 && bRow > -2) {
            /* Reverse the column read in the source image. */
            sBuffer[((bRow + 1) * WIDTH) + x + iCol] |=
                pgm_read_byte(bitmap + (a * w) + w - 1 - iCol) >> (8 - yOffset);
          }
        }
      }
    }
  }
}

void Drawing::drawBitmapAlpha(int16_t x,
                              int16_t y,
                              const uint8_t* bitmap,
                              uint8_t w,
                              uint8_t h) {
  if (x + w < 0 || x > WIDTH - 1 || y + h < 0 || y > HEIGHT - 1) {
    return;
  }

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  const int rows = (h % 8 != 0) ? (h / 8) + 1 : (h / 8);

  /* This booleans array track if we found the first white
     pixel on top of the bitmap.
   */
  bool bits[w] = {
      false,
  };

  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT / 8) - 1) {
      break;
    }
    if (bRow > -2) {
      for (int iCol = 0; iCol < w; iCol++) {
        if (iCol + x > (WIDTH - 1)) {
          break;
        }
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            uint8_t src_byte = pgm_read_byte(bitmap + (a * w) + iCol)
                               << yOffset;
            if (bits[iCol]) {
              /* full overwrite of the background */
              sBuffer[(bRow * WIDTH) + x + iCol] &= ~(0xff << yOffset);
              sBuffer[(bRow * WIDTH) + x + iCol] |= src_byte;
            } else {
              /* proceed bit by bit vertically */
              for (uint8_t b = 0; b < yOffset; b++) {
                uint8_t bitmask = (0x1 << (b + yOffset));
                uint8_t bitmap_bit = src_byte & bitmask;
                /* keep or delete the destination's pixel */
                sBuffer[(bRow * WIDTH) + x + iCol] &=
                    bits[iCol] ? ~bitmask : 0xff;
                /* update the bits array */
                bits[iCol] = bits[iCol] || (bitmap_bit != 0);
                /* copy source bit to destination */
                sBuffer[(bRow * WIDTH) + x + iCol] |= bitmap_bit;
              }
            }
          }
          if (yOffset && bRow < (HEIGHT / 8) - 1 && bRow > -2) {
            uint8_t src_byte =
                pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset);
            if (bits[iCol]) {
              /* full overwrite of the background */
              sBuffer[((bRow + 1) * WIDTH) + x + iCol] &=
                  ~(0xff >> (8 - yOffset));
              sBuffer[((bRow + 1) * WIDTH) + x + iCol] |= src_byte;
            } else {
              /* proceed bit by bit vertically */
              for (uint8_t b = 0; b < yOffset; b++) {
                uint8_t bitmask = (0x1 << (b));
                /* keep or delete the destination's pixel */
                uint8_t bitmap_bit = src_byte & bitmask;
                sBuffer[((bRow + 1) * WIDTH) + x + iCol] &=
                    bits[iCol] ? ~bitmask : 0xff;
                /* update the bits array */
                bits[iCol] = bits[iCol] || (bitmap_bit != 0);
                /* copy source bit to destination */
                sBuffer[((bRow + 1) * WIDTH) + x + iCol] |= bitmap_bit;
              }
            }
          }
        }
      }
    }
  }
}
