#pragma once

#include "utility.h"

/* Class that implements the worm. */
class Worm {
public:
  Worm(Arduboy2 &arduboy) : arduboy(arduboy) {}
  bool moveTo(Cell newHead, bool enlarge, bool shorten);
  void render();
  void addPiece(Cell c);
  void reset(Cell c);
  Cell getHead() { return cells[0]; }
  bool fall(uint16_t rock[8], uint16_t soil[8]);

private:
  Arduboy2 &arduboy;

  /* The body can be at most 16 cells long. First cell is the head. */
  Cell cells[16] = {};
  uint8_t count = 0;
};
