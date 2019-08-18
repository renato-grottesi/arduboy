#include "lagunita.h"

void Lagunita::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 16 to save battery
  arduboy.setFrameRate(32);

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
    if (level.gameOver()) {
      currentMenu = Menus::lost;
      level.pause();
      break;
    }
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
      level.onInput(Input::b);
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
  case Menus::lost:
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
  case Menus::lost:
    tinyfont.setCursor(2, 0);
    tinyfont.print(F(                              /**/
                     "                         \n" /**/
                     "      UNFORTUNATELY      \n" /**/
                     "      YOU RUN OUT        \n" /**/
                     "      OF MONEY.          \n" /**/
                     "                         \n" /**/
                     "      REMEMBER TO        \n" /**/
                     "      CHECK THE          \n" /**/
                     "      STATISTICS         \n" /**/
                     "      WHILE PLAYING      \n" /**/
                     "                         \n" /**/
                     "      TRY AGAIN!         \n" /**/
                     "                         \n" /**/
                     "                         \n" /**/
                     ));
    break;
  case Menus::credits:
    tinyfont.setCursor(2, 0);
    tinyfont.print(F(                              /**/
                     "                         \n" /**/
                     "      LAGUNITA WAS       \n" /**/
                     "      DEVELOPED BY       \n" /**/
                     "                         \n" /**/
                     "      RENATO             \n" /**/
                     "           GROTTESI      \n" /**/
                     "                         \n" /**/
                     "                         \n" /**/
                     "      MUSIC BY           \n" /**/
                     "                         \n" /**/
                     "      JOAKIM             \n" /**/
                     "          SIMONSSON      \n" /**/
                     "                         \n" /**/
                     ));
    break;
  case Menus::help:
    tinyfont.setCursor(2, 0);
    tinyfont.print(F(                              /**/
                     "      CONSTRUCT A        \n" /**/
                     "      TOWN AROUND        \n" /**/
                     "      THE LAGUNITA       \n" /**/
                     "      LAKE WITH AS       \n" /**/
                     "      MANY CITIZENS      \n" /**/
                     "      AS POSSILE.        \n" /**/
                     "      MAXIMIZE YOUR      \n" /**/
                     "      PROFIT TO          \n" /**/
                     "      UNLOCK NEW         \n" /**/
                     "      BUILDINGS AND      \n" /**/
                     "      HAVE FUN           \n" /**/
                     "      PLAYING!           \n" /**/
                     "                         \n" /**/
                     ));
    break;
  }

  // tell the arduboy to swap buffers
  arduboy.display();
}
