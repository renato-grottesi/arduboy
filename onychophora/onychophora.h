#pragma once

#include "level.h"
#include "utility.h"

class Onychophora {
public:
  Onychophora() : level(arduboy) {}
  void init();
  void loop();

private:
  void update();
  void render();

private:
  Arduboy2 arduboy;
  uint8_t lastLevel = 0;
  Level level;
};
