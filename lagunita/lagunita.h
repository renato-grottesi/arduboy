#pragma once

#include "level.h"
#include "utility.h"

class Lagunita {
public:
  Lagunita()
      : tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height()),
        level(arduboy, tinyfont) {}
  void init();
  void loop();

private:
  void update();
  void render();

private:
  enum class Menus : uint8_t { main, game, credits, help };
  enum class MainSelections : uint8_t { play, credits, help };

  Arduboy2 arduboy;
  Tinyfont tinyfont;
  Level level;
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};