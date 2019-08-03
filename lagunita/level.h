#pragma once

#include "utility.h"

class Level {
public:
  Level(Arduboy2 &arduboy, Tinyfont &tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont) {}

  void init();

  void update();
  void onInput(Input dir);
  void render();

private:
  Arduboy2 &arduboy;
  Tinyfont &tinyfont;

  // 8 rows of 16 elements each
  uint16_t rock[8];

  const char *tutorial;
  Cell goal;

  struct {
    bool moving : 1;
    bool falling : 1;
  } is = {
      false, /* not moving */
      false  /* nothing is falling */
  };
};
