#pragma once

#include <Arduboy2.h>
#include "Test.hpp"
#include "Tinyfont.hpp"

class Main {
 public:
  void init();
  void loop();

  static const uint16_t frame_rate = 32;

 private:
  void update();
  void render();
  void loadHighScore();
  void saveHighScore();

 private:
  enum class Menus : uint8_t { main, test, credits };
  enum class MainSelections : uint8_t { reflex, planning, focus, memory, verbal, count };

  static const uint8_t selectionsCount = static_cast<uint8_t>(MainSelections::count);

  uint16_t hiScores[selectionsCount] = {};

  Test* test = nullptr;

  Arduboy2Base arduboy;
  Tinyfont tinyfont = {arduboy.sBuffer, Arduboy2Base::width(), Arduboy2Base::height()};
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::reflex;
};
