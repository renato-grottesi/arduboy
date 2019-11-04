#pragma once

#include "test.hpp"

class Reflex : public Test {
 public:
  Reflex(Arduboy2Base& arduboy, Tinyfont& tinyfont) : arduboy(arduboy), tinyfont(tinyfont) {}

  void update() final;
  void render() final;
  bool complete(uint16_t& score) final;

 private:
  enum class Status : uint8_t { instructions, black, white, pressed, score, done };

  uint16_t reactions[4] = {0, 0, 0, 0};
  uint16_t m_score = 0;
  uint16_t millis = 0;
  uint16_t waiting = 0;
  uint16_t attempt = 0;

  Status status = Status::instructions;

  Arduboy2Base& arduboy;
  Tinyfont& tinyfont;
};
