#pragma once

#include "level.h"
#include "utility.h"

class Onychophora {
public:
  Onychophora()
      : level(arduboy),
        tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height()) {}
  void init();
  void loop();

private:
  void update();
  void render();

private:
  enum class Menus : uint8_t { main, game, credits, help };
  enum class MainSelections : uint8_t { play, credits, help };

  Arduboy2 arduboy;
  Level level;
  Tinyfont tinyfont;
  uint8_t lastLevel = 0;
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};
