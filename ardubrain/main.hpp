#pragma once

#include <Arduboy2.h>
#include "Tinyfont.hpp"
#include "test.hpp"

class Main {
 public:
  void init();
  void loop();

  static const uint16_t frame_rate = 32;

 private:
  void update();
  void render();

 private:
  enum class Menus : uint8_t { main, test, credits };
  enum class MainSelections : uint8_t {
    reflex,
    planning,
    cognitive,
    auditory,
    math,
    memory,
    credits
  };

  Test* test = nullptr;

  Arduboy2Base arduboy;
  Tinyfont tinyfont = {arduboy.sBuffer, Arduboy2Base::width(), Arduboy2Base::height()};
  Menus currentMenu = Menus::main;
  MainSelections currentMainSelection = MainSelections::reflex;
};
