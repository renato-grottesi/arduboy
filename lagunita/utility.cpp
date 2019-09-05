#include "utility.hpp"

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
  int rows = h / 8;
  rows += (h % 8 != 0) ? 1 : 0;

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
  int rows = h / 8;
  rows += (h % 8 != 0) ? 1 : 0;

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
                pgm_read_byte(bitmap + (a * w) + w - 1 - iCol) << yOffset;
          }
          if (yOffset && bRow < (HEIGHT / 8) - 1 && bRow > -2) {
            sBuffer[((bRow + 1) * WIDTH) + x + iCol] |=
                pgm_read_byte(bitmap + (a * w) + w - 1 - iCol) >> (8 - yOffset);
          }
        }
      }
    }
  }
}
