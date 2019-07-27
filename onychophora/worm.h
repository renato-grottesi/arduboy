#pragma once

#include "utility.h"

/* Class that implements the worm. */
class Worm {
public:
  Worm() = default;
  bool isStuck();
  bool moveTo(direction dir, bool enlarge, bool shorten);
  void render();

private:
  class Cell {
  public:
    uint8_t x : 4;
    uint8_t y : 4;
  };
  /* The body can be at most 16 cells long.  */
  Cell cells[16] = {};
  uint8_t count = 0;
};
