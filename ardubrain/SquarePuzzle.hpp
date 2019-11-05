#pragma once

#include "Test.hpp"

class SquarePuzzle: public Test {
 public:
  SquarePuzzle(Arduboy2Base& arduboy, Tinyfont& tinyfont) : arduboy(arduboy), tinyfont(tinyfont) {}

  void update() final;
  void render() final;
  bool complete(uint16_t& score) final;

 private:
  enum class Status : uint8_t { instructions, solving, score, done };

  Status status = Status::instructions;

  Arduboy2Base& arduboy;
  Tinyfont& tinyfont;

  uint16_t m_score = 0;
  uint16_t millis = 0;
};

