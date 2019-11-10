#include "Major.hpp"
#include "Bitmaps.hpp"
#include "Words.hpp"

void Major::shuffle() {
  do {
    for (uint8_t i = 0; i < 4; i++) {
      options[i] = (rand() % (Words::wordsCount - 10)) + 10;
    }
  } while (options[0] == options[1] || options[0] == options[2] || options[0] == options[3] ||
           options[1] == options[2] || options[1] == options[3] || options[2] == options[3]);

  correct = rand() % 4;
}

void Major::update() {
  millis += 31;  // 32 frames per second, so 31.25 ms are rounded to 31
  switch (status) {
    case Status::instructions:
      if (arduboy.justPressed(A_BUTTON)) {
        shuffle();
        status = Status::testing;
        millis = 0;
      }
      break;
    case Status::testing: {
      bool done = false;
      if (arduboy.justPressed(LEFT_BUTTON)) {
        if (correct == 0) {
          mScore++;
          shuffle();
        } else {
          done = true;
        }
      } else if (arduboy.justPressed(DOWN_BUTTON)) {
        if (correct == 1) {
          mScore++;
          shuffle();
        } else {
          done = true;
        }
      } else if (arduboy.justPressed(UP_BUTTON)) {
        if (correct == 2) {
          mScore++;
          shuffle();
        } else {
          done = true;
        }
      } else if (arduboy.justPressed(RIGHT_BUTTON)) {
        if (correct == 3) {
          mScore++;
          shuffle();
        } else {
          done = true;
        }
      } else if (arduboy.justPressed(B_BUTTON)) {
        done = true;
      }

      if (done) {
        mScore *= 8;
        status = Status::score;
      }
    } break;
    case Status::score:
      if (arduboy.justPressed(A_BUTTON)) {
        status = Status::done;
      }
      break;
    case Status::done:
      break;
  }
}

void Major::render() {
  switch (status) {
    case Status::instructions:
      tinyfont.setCursor(16, 16);
      tinyfont.print(F(                          /**/
                       "PRESS THE D-PAD ARROW\n" /**/
                       "THAT MAPS THE WORD TO\n" /**/
                       "THE NUMBER (OR VICE\n"   /**/
                       "VERSA) USING THE\n"      /**/
                       "MNEMONIC MAJOR\n"        /**/
                       "SYSTEM.\n"               /**/
                       "CHECK WIKIPEDIA.\n"      /**/
                       ));
      break;
    case Status::testing:
      tinyfont.setCursor(32, 2);
      tinyfont.print(options[correct]);

      arduboy.drawBitmap(22, 32, bmp_left, 8, 8);
      tinyfont.setCursor(32, 32);
      tinyfont.print(Words::word(options[0]));

      arduboy.drawBitmap(22, 40, bmp_down, 8, 8);
      tinyfont.setCursor(32, 40);
      tinyfont.print(Words::word(options[1]));

      arduboy.drawBitmap(22, 48, bmp_up, 8, 8);
      tinyfont.setCursor(32, 48);
      tinyfont.print(Words::word(options[2]));

      arduboy.drawBitmap(22, 56, bmp_right, 8, 8);
      tinyfont.setCursor(32, 56);
      tinyfont.print(Words::word(options[3]));
      break;
    case Status::score:
      tinyfont.setCursor(1, 1);
      tinyfont.print(F("FINAL SCORE:"));
      tinyfont.setCursor(1, 32);
      tinyfont.print(mScore);
      break;
    case Status::done:
      break;
  }
}

bool Major::complete(uint16_t& score) {
  score = mScore;
  return status == Status::done;
}
