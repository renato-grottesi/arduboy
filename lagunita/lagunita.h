#pragma once

#include "level.h"
#include "music.h"
#include "utility.h"

class Lagunita {
public:
  Lagunita()
      : tinyfont(arduboy.sBuffer, Arduboy2Base::width(),
                 Arduboy2Base::height()),
        music(arduboy), level(arduboy, tinyfont) {}
  void init();
  void loop();

private:
  void update();
  void render();

private:
  enum class Menus : uint8_t { main, game, credits, help, lost };
  enum class MainSelections : uint8_t { play, credits, help, audio };

  Arduboy2Base arduboy;
  Tinyfont tinyfont;
  Music music;
  Level level;
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::play;
};
