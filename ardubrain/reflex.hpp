#pragma once

#include "test.hpp"

class Reflex : public Test {
 public:
  Reflex(Arduboy2Base& arduboy, Tinyfont& tinyfont) : arduboy(arduboy), tinyfont(tinyfont) {}

  void update() final;
  void render() final;

 private:
  Arduboy2Base& arduboy;
  Tinyfont& tinyfont;
};
