#pragma once

#include "utility.h"
#include <stdint.h>
#include "ArduboyTones.h"

class Music {
public:
  Music(Arduboy2& arduboy) : sound(arduboy.audio.enabled) {};
  void play() const;
private:
  ArduboyTones sound;
};

