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
  enum class Menus : uint8_t { main, game, credits, help };
  enum class MainSelections : uint8_t { play, credits, help };

  Arduboy2 arduboy;
  uint8_t lastLevel = 0;
  Level level;
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};
