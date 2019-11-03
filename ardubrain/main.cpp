#include "main.hpp"
#include "reflex.hpp"

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
          case MainSelections::credits:
            currentMainSelection = MainSelections::reflex;
            break;
        }
      }
      if (arduboy.justPressed(DOWN_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::reflex:
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
              free(test);
            }
            test = new Reflex(arduboy, tinyfont);
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
      if (arduboy.justPressed(UP_BUTTON)) {
      } else if (arduboy.justPressed(DOWN_BUTTON)) {
      } else if (arduboy.justPressed(LEFT_BUTTON)) {
      } else if (arduboy.justPressed(RIGHT_BUTTON)) {
      } else if (arduboy.justPressed(A_BUTTON)) {
      } else if (arduboy.justPressed(B_BUTTON)) {
      }
      test->update();
      break;
    case Menus::credits:
      if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
        currentMenu = Menus::main;
      }
      break;
  }
}

void Main::render() {
  /* clear the whole screen to black */
  arduboy.clear();

  /* render the menus */
  switch (currentMenu) {
    case Menus::main: {
      tinyfont.setCursor(0, 0);
      tinyfont.print(F("REFLEX"));
      tinyfont.setCursor(0, 8);
      tinyfont.print(F("CREDITS"));
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
