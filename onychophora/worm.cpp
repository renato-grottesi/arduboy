#include "worm.h"
#include "bitmaps.h"

bool Worm::moveTo(Direction dir, bool enlarge, bool shorten) {
  Cell newHead = cells[0];

  switch (dir) {
  case Direction::up:
    newHead.x--;
    break;
  case Direction::down:
    newHead.x++;
    break;
  case Direction::left:
    newHead.y--;
    break;
  case Direction::right:
    newHead.y++;
    break;
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

void Worm::addPiece(uint8_t x, uint8_t y) {
  cells[count].x = x;
  cells[count].y = y;
  count++;
}
