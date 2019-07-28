#include "level.h"
#include "bitmaps.h"

void Level::init(uint8_t level) {
  static uint16_t level_001_rock[8] = {
      0b1111111111111111, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000001000000001, /**/
      0b1000011100000001, /**/
      0b1111111111111111, /**/
  };
  static uint16_t level_001_soil[8] = {
      0b0000000000000000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000011000, /**/
      0b0000000000000000, /**/
  };
  static uint16_t level_001_food[8] = {
      0b1111111111111111, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000001000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1111111111111111, /**/
  };

  for (uint8_t row = 0; row < 8; row++) {
    rock[row] = level_001_rock[row];
    soil[row] = level_001_soil[row];
    food[row] = level_001_food[row];
  }
}

void Level::update() {}

void Level::render() {
  for (uint8_t row = 0; row < 8; row++) {
    for (uint16_t col = 0; col < 16; col++) {
      if (rock[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_rock, 8, 8);
      }
      if (soil[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_soil, 8, 8);
      }
      if (food[row] & (1 << (15 - col))) {
        arduboy.drawBitmap(col * 8, row * 8, bmp_food, 8, 8);
      }
    }
  }
  worm.render();
}
