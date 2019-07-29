#pragma once

#include "utility.h"

/* Class that implements the worm. */
class Worm {
public:
  Worm(Arduboy2 &arduboy) : arduboy(arduboy) {}
  bool moveTo(Direction dir, bool enlarge, bool shorten);
  void render();
  void addPiece(uint8_t x, uint8_t y);

private:
  Arduboy2 &arduboy;

  /* The body can be at most 16 cells long. First cell is the head. */
  Cell cells[16] = {};
  uint8_t count = 0;
};
