#pragma once

#include "utility.h"

class Level {
public:
  Level(Arduboy2 &arduboy) : arduboy(arduboy) {}

  void init(uint8_t level);

  void update();
  void render();

private:
  Arduboy2 &arduboy;

  // 8 rows of 16 elements each
  uint16_t rock[8];
  uint16_t soil[8];
  uint16_t food[8];
};
