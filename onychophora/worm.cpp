#include "worm.h"
#include "bitmaps.h"

bool Worm::moveTo(direction dir, bool enlarge, bool shorten) {
  return true;
}

void Worm::render() {
  for (uint8_t i = 0; i < count; i++) {
    uint8_t col = cells[i].y;
    uint8_t row = cells[i].x;
    arduboy.drawBitmap(col * 8, row * 8, bmp_worm, 8, 8);
  }
}

void Worm::addPiece(uint8_t x, uint8_t y) {
  cells[count].x = x;
  cells[count].y = y;
  count++;
}
