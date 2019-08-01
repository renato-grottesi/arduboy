#include "worm.h"
#include "bitmaps.h"

bool Worm::moveTo(Cell newHead, bool enlarge, bool shorten) {
  if (enlarge) {
    count++;
  }
  if (shorten) {
    count--;
  }
  if (count < 2) {
    count = 2;
  }
  if (count > 16) {
    count = 16;
  }
  if (newHead.x > 7) {
    return;
  }

  for (uint8_t i = 0; i < count; i++) {
    if (cells[i].intersects(newHead)) {
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

void Worm::reset(Cell c) {
  count = 0;
  addPiece(c);
}

void Worm::addPiece(Cell c) {
  cells[count] = c;
  count++;
}

bool Worm::fall(uint16_t rock[8], uint16_t soil[8]) {
  for (uint8_t i = 0; i < count; i++) {
    /* Can't go outside the bottom of the screen. */
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
