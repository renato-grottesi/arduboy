#include "lagunita.h"

void Lagunita::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 16 to save battery
  arduboy.setFrameRate(16);

  arduboy.audio.begin();
  arduboy.audio.on();
  music.init();
}

void Lagunita::loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame())) {
    return;
  }
  update();
  render();
}

void Lagunita::update() {
  arduboy.pollButtons();

  if (!music.isPlaying()) {
    music.play();
  }

  switch (currentMenu) {
  case Menus::main:
    if (arduboy.justPressed(UP_BUTTON)) {
      switch (currentMainSelection) {
      case MainSelections::play:
        currentMainSelection = MainSelections::help;
        break;
      case MainSelections::credits:
        currentMainSelection = MainSelections::play;
        break;
      case MainSelections::help:
        currentMainSelection = MainSelections::credits;
        break;
      }
    }
    if (arduboy.justPressed(DOWN_BUTTON)) {
      switch (currentMainSelection) {
      case MainSelections::play:
        currentMainSelection = MainSelections::credits;
        break;
      case MainSelections::credits:
        currentMainSelection = MainSelections::help;
        break;
      case MainSelections::help:
        currentMainSelection = MainSelections::play;
        break;
      }
    }
    if (arduboy.justPressed(A_BUTTON)) {
      switch (currentMainSelection) {
      case MainSelections::play:
        if (!level.isInProgress()) {
          level.init();
        }
        currentMenu = Menus::game;
        break;
      case MainSelections::credits:
        currentMenu = Menus::credits;
        break;
      case MainSelections::help:
        currentMenu = Menus::help;
        break;
      }
    }

    break;
  case Menus::game:
    level.update();
    if (arduboy.justPressed(UP_BUTTON)) {
      level.onInput(Input::up);
    }
    if (arduboy.justPressed(DOWN_BUTTON)) {
      level.onInput(Input::down);
    }
    if (arduboy.justPressed(RIGHT_BUTTON)) {
      level.onInput(Input::right);
    }
    if (arduboy.justPressed(LEFT_BUTTON)) {
      level.onInput(Input::left);
    }
    if (arduboy.justPressed(A_BUTTON)) {
      level.onInput(Input::a);
    }
    if (arduboy.justPressed(B_BUTTON)) {
      currentMenu = Menus::main;
    }
    break;
  case Menus::credits:
    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
      currentMenu = Menus::main;
    }
    break;
  case Menus::help:
    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
      currentMenu = Menus::main;
    }
    break;
  }
}

void Lagunita::render() {
  // clear the screen to black
  arduboy.clear();

  switch (currentMenu) {
  case Menus::main:
    arduboy.setCursor(42, 15);
    if (level.isInProgress()) {
      arduboy.print(F("Resume"));
    } else {
      arduboy.print(F("Play"));
    }
    arduboy.setCursor(42, 30);
    arduboy.print(F("Credits"));
    arduboy.setCursor(42, 45);
    arduboy.print(F("Help"));
    switch (currentMainSelection) {
    case MainSelections::play:
      arduboy.drawBitmap(32, 15, bmp_bullet, 8, 8);
      break;
    case MainSelections::credits:
      arduboy.drawBitmap(32, 30, bmp_bullet, 8, 8);
      break;
    case MainSelections::help:
      arduboy.drawBitmap(32, 45, bmp_bullet, 8, 8);
      break;
    }
    break;
  case Menus::game:
    level.render();
    break;
  case Menus::credits:
    arduboy.setCursor(32, 10);
    arduboy.print(F("Lagunita"));
    arduboy.setCursor(32, 20);
    arduboy.print(F("was made"));
    arduboy.setCursor(32, 30);
    arduboy.print(F("by Renato"));
    arduboy.setCursor(32, 40);
    arduboy.print(F("Grottesi"));
    break;
  case Menus::help:
    tinyfont.setCursor(2, 0);
    tinyfont.print(""                            /**/
                   "LEFT AND RIGHT TO MOVE\n"    /**/
                   "THE MAP AROUND THE LAKE.\n"  /**/
                   "UP AND DOWN TO CHANGE THE\n" /**/
                   "CURRENT TYPE OF BUILDING.\n" /**/
                   "(A) TO BUILD IT.\n"          /**/
                   "SOME BUILDINGS INCREASE\n"   /**/
                   "THE REVENUE PER SECOND,\n"   /**/
                   "WHILE OTHERS DECREASE IT.\n" /**/
                   "DON'T RUN OUT OF MONEY!\n"   /**/
                   "\n"                          /**/
                   "\n"                          /**/
                   "\nGOOD LUCK!\n"              /**/
    );
    break;
  }

  // tell the arduboy to swap buffers
  arduboy.display();
}
