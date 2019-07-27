#pragma once

#include "utility.h"
#include "worm.h"

class Onychophora {
public:
  Onychophora() = default;
  void init();
  void loop();

private:
  void update();
  void render();

private:
  Arduboy2 arduboy;
  uint8_t lastLevel = 0;
};
