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

#include <avr/io.h>
#include <avr/pgmspace.h>

extern "C" {
#include <stdint.h>
}

enum class Input : uint8_t { left, right, up, down, a, b };

class Cell {
public:
  Cell() : x(0), y(0){};
  Cell(uint8_t x, uint8_t y) : x(x), y(y){};
  uint8_t x : 4;
  uint8_t y : 4;
  void set(uint8_t _x, uint8_t _y) {
    x = _x;
    y = _y;
  }
  bool intersects(Cell &c) { return c.x == x && c.y == y; }
  bool intersects(uint16_t tilemap[8]) { return tilemap[x] & (1 << (15 - y)); }
  void resetTilemap(uint16_t tilemap[8]) { tilemap[x] &= ~(1 << (15 - y)); }
};
