#pragma once

#include <Arduboy2.h>
#include "Tinyfont.hpp"

class Test {
 public:
  virtual void update() = 0;
  virtual void render() = 0;
};
