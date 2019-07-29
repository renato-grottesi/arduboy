#pragma once

#include "Tinyfont.h"
#include <Arduboy2.h>
#include <Arduboy2Audio.h>
#include <Arduboy2Beep.h>
#include <Arduboy2Core.h>
#include <EEPROM.h>
#include <SPI.h>
#include <Sprites.h>
#include <SpritesB.h>
#include <SpritesCommon.h>

extern "C" {
#include <stdint.h>
}

enum class Direction : uint8_t { left, right, up, down };

class Cell {
public:
  uint8_t x : 4;
  uint8_t y : 4;
  void set(uint8_t _x, uint8_t _y) {
    x = _x;
    y = _y;
  }
};
