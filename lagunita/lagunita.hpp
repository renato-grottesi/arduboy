#pragma once

#include "level.hpp"
#include "music.hpp"
#include "utility.hpp"

class Lagunita {
 public:
  void init();
  void loop();

 private:
  void update();
  void render();

 private:
  enum class Menus : uint8_t { main, game, credits, help, lost };
  enum class MainSelections : uint8_t { play, load, credits, help, audio };
  uint8_t help_page = 0;
  int16_t weed = 0;

  Arduboy2Base arduboy;
  Drawing drawing = {arduboy.sBuffer};
  Tinyfont tinyfont = {arduboy.sBuffer, Arduboy2Base::width(), Arduboy2Base::height()};
  Music music = {arduboy};
  Level level = {arduboy, tinyfont, drawing};
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};
