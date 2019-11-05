#include "SquarePuzzle.hpp"

void SquarePuzzle::update() {
  millis += 31;  // 32 frames per second, so 31.25 ms are rounded to 31
  switch (status) {
    case Status::instructions:
      if (arduboy.justPressed(A_BUTTON)) {
      }
      break;
    case Status::solving:
      break;
    case Status::score:
      if (arduboy.justPressed(A_BUTTON)) {
        status = Status::done;
      }
      break;
    case Status::done:
      break;
  }
}

void SquarePuzzle::render() {
  switch (status) {
    case Status::instructions:
      tinyfont.setCursor(16, 16);
      tinyfont.print(F(                       /**/
                       "PRESS A WHEN THE\n"   /**/
                       "SQUARE TURNS WHITE\n" /**/
                       ));
      break;
    case Status::solving:
      break;
    case Status::score:
      tinyfont.setCursor(1, 1);
      tinyfont.print(F("FINAL SCORE:"));
      tinyfont.setCursor(1, 32);
      tinyfont.print(m_score);
      break;
    case Status::done:
      break;
  }
}

bool SquarePuzzle::complete(uint16_t& score) {
  score = m_score;
  return status == Status::done;
}

