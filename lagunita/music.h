#pragma once

#include "ArduboyPlaytune.h"
#include "utility.h"
#include <stdint.h>

class Music {
public:
  Music(Arduboy2 &arduboy) : sound(arduboy.audio.enabled){};
  void init();
  void play();
  bool isPlaying() { return sound.playing(); };

private:
  ArduboyPlaytune sound;
};
