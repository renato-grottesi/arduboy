#pragma once

#include <stdint.h>
#include "ArduboyTones.hpp"
#include "utility.hpp"

/* Class that plays the game music. */
class Music {
 public:
  Music(Arduboy2Base& arduboy) : sound(arduboy.audio.enabled){};
  void init();
  void play();
  bool isPlaying() { return sound.playing(); };

 private:
  ArduboyTones sound;
};
