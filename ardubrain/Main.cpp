#include "Main.hpp"
#include "MemoryGrid.hpp"
#include "Reflex.hpp"
#include "SquarePuzzle.hpp"

void Main::init() {
  /* initialize the random seed with noise */
  srand(arduboy.generateRandomSeed());

  /* initiate arduboy instance */
  arduboy.begin();

  /* set the framerate */
  arduboy.setFrameRate(frame_rate);

  /* start the music */
  arduboy.audio.begin();
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
        switch (currentMainSelection) {
          case MainSelections::reflex:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::planning:
            currentMainSelection = MainSelections::reflex;
            break;
          case MainSelections::cognitive:
            break;
          case MainSelections::auditory:
            break;
          case MainSelections::focus:
            break;
          case MainSelections::memory:
            currentMainSelection = MainSelections::planning;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::memory;
            break;
        }
      }
      if (arduboy.justPressed(DOWN_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::reflex:
            currentMainSelection = MainSelections::planning;
            break;
          case MainSelections::planning:
            currentMainSelection = MainSelections::memory;
            break;
          case MainSelections::cognitive:
            break;
          case MainSelections::auditory:
            break;
          case MainSelections::focus:
            break;
          case MainSelections::memory:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::reflex;
            break;
        }
      }
      if (arduboy.justPressed(RIGHT_BUTTON)) {
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
      }
      if (arduboy.justPressed(A_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::reflex:
            if (test != nullptr) {
              delete test;
            }
            test = new Reflex(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::planning:
            if (test != nullptr) {
              delete test;
            }
            test = new SquarePuzzle(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::cognitive:
            break;
          case MainSelections::auditory:
            break;
          case MainSelections::focus:
            break;
          case MainSelections::memory:
            if (test != nullptr) {
              delete test;
            }
            test = new MemoryGrid(arduboy, tinyfont);
            currentMenu = Menus::test;
            break;
          case MainSelections::credits:
            currentMenu = Menus::credits;
            break;
        }
      }
      if (arduboy.justPressed(B_BUTTON)) {
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
                       bool selected) {
  tinyfont.setCursor(x + 1, y + 1);
  arduboy.fillRect(x, y, 64, 6, selected ? WHITE : BLACK);
  tinyfont.setTextColor(selected ? BLACK : WHITE);
}

void Main::render() {
  /* clear the whole screen to black */
  arduboy.clear();

  /* render the menus */
  switch (currentMenu) {
    case Menus::main: {
      setupEntry(arduboy, tinyfont, 0, 0, currentMainSelection == MainSelections::reflex);
      tinyfont.print(F("REFLEX"));

      setupEntry(arduboy, tinyfont, 0, 8, currentMainSelection == MainSelections::planning);
      tinyfont.print(F("PLANNING"));

      setupEntry(arduboy, tinyfont, 0, 16, currentMainSelection == MainSelections::memory);
      tinyfont.print(F("MEMORY"));

      setupEntry(arduboy, tinyfont, 0, 24, currentMainSelection == MainSelections::credits);
      tinyfont.print(F("CREDITS"));

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
