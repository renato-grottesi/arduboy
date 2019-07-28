#include "worm.h"
#include "bitmaps.h"

bool Worm::isStuck() { return false; }

bool Worm::moveTo(direction dir, bool enlarge, bool shorten) { return true; }

void Worm::render() {
  for(uint8_t i=0; i<16; i++)
  {
    uint8_t col = cells[i].y;
    uint8_t row = cells[i].x;
    arduboy.drawBitmap(col * 8, row * 8, bmp_food, 8, 8);
  }
}
