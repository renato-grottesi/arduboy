#include "worm.h"
#include "bitmaps.h"

bool Worm::moveTo(Cell newHead, bool enlarge, bool shorten) {
  if (enlarge) {
    count++;
  }
  if (shorten) {
    count--;
  }

  for (uint8_t i = 0; i < count; i++) {
    if ((cells[i].x == newHead.x) && (cells[i].y == newHead.y)) {
      return false;
    }
  }

  for (uint8_t i = count - 1; i > 0; i--) {
    cells[i] = cells[i - 1];
  }

  cells[0] = newHead;

  return true;
}

void Worm::render() {
  for (uint8_t i = 0; i < count; i++) {
    uint8_t col = cells[i].y;
    uint8_t row = cells[i].x;
    arduboy.drawBitmap(col * 8, row * 8, bmp_worm, 8, 8);
  }
}

void Worm::reset(uint8_t x, uint8_t y) {
  count = 0;
  addPiece(x, y);
}

void Worm::addPiece(uint8_t x, uint8_t y) {
  cells[count].x = x;
  cells[count].y = y;
  count++;
}

bool Worm::fall(uint16_t rock[8], uint16_t soil[8]) {
  for (uint8_t i = 0; i < count; i++) {
    if (cells[i].x == 7) {
      return false;
    }
    if (rock[cells[i].x + 1] & (1 << (15 - cells[i].y))) {
      return false;
    }
    if (soil[cells[i].x + 1] & (1 << (15 - cells[i].y))) {
      return false;
    }
  }

  for (uint8_t i = 0; i < count; i++) {
    cells[i].x++;
  }
  fall(rock, soil);
  return true;
}
