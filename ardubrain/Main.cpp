#include "Main.hpp"
#include "Bitmaps.hpp"
#include "Breathe.hpp"
#include "MemoryGrid.hpp"
#include "Reflex.hpp"
#include "SquarePuzzle.hpp"
#include "VerbalMemory.hpp"

void Main::init() {
  /* initialize the random seed with noise */
  srand(arduboy.generateRandomSeed());

  /* initiate arduboy instance */
  arduboy.begin();

  /* set the framerate */
  arduboy.setFrameRate(frame_rate);

  /* start the music */
  arduboy.audio.begin();

  /* load the high score */
  loadHighScore();
}

void Main::saveHighScore() {
  const uint16_t loc = EEPROM_STORAGE_SPACE_START;
  EEPROM.update(loc + 0, 'A');
  EEPROM.update(loc + 1, 'R');
  EEPROM.update(loc + 2, 'B');
  EEPROM.update(loc + 3, '0');
  EEPROM.update(loc + 4, '1');
  uint8_t* scores = reinterpret_cast<uint8_t*>(hiScores);
  for (uint16_t l = 0; l < sizeof(hiScores); l++) {
    EEPROM.update(loc + 10 + l, scores[l]);
  }
}

void Main::loadHighScore() {
  const uint16_t loc = EEPROM_STORAGE_SPACE_START;
  uint8_t h0 = EEPROM.read(loc + 0);
  uint8_t h1 = EEPROM.read(loc + 1);
  uint8_t h2 = EEPROM.read(loc + 2);
  uint8_t h3 = EEPROM.read(loc + 3);
  uint8_t h4 = EEPROM.read(loc + 4);
  if (h0 == 'A' && h1 == 'R' && h2 == 'B' && h3 == '0' && h4 == '1') {
    uint8_t* scores = reinterpret_cast<uint8_t*>(hiScores);
    for (uint16_t l = 0; l < sizeof(hiScores); l++) {
      scores[l] = EEPROM.read(loc + 10 + l);
    }
  }
}

void Main::loop() {
  /* pause render until it's time for the next frame */
  if (!(arduboy.nextFrame())) {
    return;
  }
  /* update the scene */
  update();
  /* render the scene */
  render();
}

void Main::update() {
  arduboy.pollButtons();

  switch (currentMenu) {
    case Menus::main:
      if (arduboy.justPressed(UP_BUTTON)) {
        uint8_t sel = static_cast<uint8_t>(currentMainSelection);
        sel = (sel + selectionsCount - 1) % selectionsCount;
        currentMainSelection = static_cast<MainSelections>(sel);
      }
      if (arduboy.justPressed(DOWN_BUTTON)) {
        uint8_t sel = static_cast<uint8_t>(currentMainSelection);
        sel = (sel + selectionsCount + 1) % selectionsCount;
        currentMainSelection = static_cast<MainSelections>(sel);
      }
      if (arduboy.justPressed(RIGHT_BUTTON)) {
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
      }
      if (arduboy.justPressed(A_BUTTON)) {
        if (test != nullptr) {
          delete test;
        }
        switch (currentMainSelection) {
          case MainSelections::reflex:
            test = new Reflex(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::planning:
            test = new SquarePuzzle(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::focus:
            test = new Breathe(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::memory:
            test = new MemoryGrid(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::verbal:
            test = new VerbalMemory(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          default:
            break;
        }
      }
      if (arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::credits;
      }
      break;
    case Menus::test:
      if (test != nullptr) {
        test->update();
        uint16_t score = 0;
        if (test->complete(score)) {
          delete test;
          test = nullptr;
          currentMenu = Menus::main;
          uint8_t sel = static_cast<uint8_t>(currentMainSelection);
          if (hiScores[sel] < score) {
            hiScores[sel] = score;
          }
          saveHighScore();
        }
      } else {
        currentMenu = Menus::main;
      }
      break;
    case Menus::credits:
      if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::main;
      }
      break;
  }
}

static void setupEntry(Arduboy2Base& arduboy,
                       Tinyfont& tinyfont,
                       uint8_t x,
                       uint8_t y,
                       bool selected,
                       uint16_t score) {
  tinyfont.setTextColor(selected ? BLACK : WHITE);
  arduboy.fillRect(x, y, WIDTH, 6, selected ? WHITE : BLACK);
  tinyfont.setCursor(x + 1 + 5 * 9, y + 1);
  if (score > 0) {
    tinyfont.print(score);
  }
  tinyfont.setCursor(x + 1, y + 1);
}

void Main::render() {
  /* clear the whole screen to black */
  arduboy.clear();

  /* render the menus */
  switch (currentMenu) {
    case Menus::main: {
      tinyfont.setCursor(1, 1);
      tinyfont.print(F("ARDU\n BRAIN"));
      arduboy.drawBitmap(1, 12, bmp_logo, 32, 32);
      tinyfont.setCursor(1, 12 + 34);
      tinyfont.print(F("TOTAL\n SCORE:"));
      tinyfont.setCursor(1, 12 + 34 + 10);
      uint16_t totalScore = 0;
      for (uint8_t s = 0; s < selectionsCount; s++) {
        totalScore += hiScores[s];
      }
      tinyfont.print(totalScore);

      setupEntry(arduboy, tinyfont, 38, 0, false, 0);
      tinyfont.print(F("TEST:    HI-SCORE:"));

      uint8_t sel = 0;

      sel = static_cast<uint8_t>(MainSelections::reflex);
      setupEntry(arduboy, tinyfont, 38, 8, currentMainSelection == MainSelections::reflex,
                 hiScores[sel]);
      tinyfont.print(F("REFLEX"));

      sel = static_cast<uint8_t>(MainSelections::planning);
      setupEntry(arduboy, tinyfont, 38, 16, currentMainSelection == MainSelections::planning,
                 hiScores[sel]);
      tinyfont.print(F("PLANNING"));

      sel = static_cast<uint8_t>(MainSelections::focus);
      setupEntry(arduboy, tinyfont, 38, 24, currentMainSelection == MainSelections::focus,
                 hiScores[sel]);
      tinyfont.print(F("FOCUS"));

      sel = static_cast<uint8_t>(MainSelections::memory);
      setupEntry(arduboy, tinyfont, 38, 32, currentMainSelection == MainSelections::memory,
                 hiScores[sel]);
      tinyfont.print(F("VIS.MEM."));

      sel = static_cast<uint8_t>(MainSelections::verbal);
      setupEntry(arduboy, tinyfont, 38, 40, currentMainSelection == MainSelections::verbal,
                 hiScores[sel]);
      tinyfont.print(F("VERB.MEM."));

      tinyfont.setTextColor(WHITE);

      break;
    }
    case Menus::test:
      test->render();
      break;
    case Menus::credits: {
      tinyfont.setCursor(2, 0);
      tinyfont.print(
          F("\nARDUBRAIN WAS MADE BY\n" /**/
            "\tRENATO GROTTESI\n"       /**/
            ));
      break;
      default:
        currentMenu = Menus::main;
    } break;
  }

  /* tell the arduboy to swap buffers */
  arduboy.display();
}
