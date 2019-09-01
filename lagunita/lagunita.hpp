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
  enum class MainSelections : uint8_t { play, credits, help, audio };

  Arduboy2Base arduboy;
  Tinyfont tinyfont = {arduboy.sBuffer, Arduboy2Base::width(),
                       Arduboy2Base::height()};
  Music music = {arduboy};
  Level level = {arduboy, tinyfont};
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};
