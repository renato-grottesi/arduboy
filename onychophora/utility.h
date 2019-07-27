#pragma once

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

enum direction { left, right, up, down };
