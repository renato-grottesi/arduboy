#include "lagunita.hpp"

void Lagunita::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 32 FPS
  arduboy.setFrameRate(32);

  // start the music
  arduboy.audio.begin();
}

void Lagunita::loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame())) {
    return;
  }
  // update the scene
  update();
  // render the scene
  render();
}

void Lagunita::update() {
  arduboy.pollButtons();

  // keep the music in a loop
  if (!music.isPlaying()) {
    music.play();
  }

  switch (currentMenu) {
    case Menus::main:
      if (arduboy.justPressed(UP_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::play;
            break;
          case MainSelections::help:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::audio:
            currentMainSelection = MainSelections::help;
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
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::audio:
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
          case MainSelections::audio:
            arduboy.audio.toggle();
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
  // clear the whole screen to black
  arduboy.clear();

  // render the menus
  switch (currentMenu) {
    case Menus::main:
      arduboy.drawBitmap(4, 4, bmp_lagunita, 105, 16);
      tinyfont.setCursor(42, 50 - 6 * 3);
      if (level.isInProgress()) {
        tinyfont.print(F("RESUME"));
      } else {
        tinyfont.print(F("PLAY"));
      }
      tinyfont.setCursor(42, 50 - 6 * 2);
      tinyfont.print(F("CREDITS"));
      tinyfont.setCursor(42, 50 - 6 * 1);
      tinyfont.print(F("HELP"));
      tinyfont.setCursor(42, 50 - 6 * 0);
      if (arduboy.audio.enabled()) {
        tinyfont.print(F("AUDIO: ON"));
      } else {
        tinyfont.print(F("AUDIO: OFF"));
      }
      switch (currentMainSelection) {
        case MainSelections::play:
          arduboy.drawBitmap(32, 48 - 6 * 3, bmp_bullet, 8, 8);
          break;
        case MainSelections::credits:
          arduboy.drawBitmap(32, 48 - 6 * 2, bmp_bullet, 8, 8);
          break;
        case MainSelections::help:
          arduboy.drawBitmap(32, 48 - 6 * 1, bmp_bullet, 8, 8);
          break;
        case MainSelections::audio:
          arduboy.drawBitmap(32, 48 - 6 * 0, bmp_bullet, 8, 8);
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
                       "LAGUNITA WAS CREATED BY  \n" /**/
                       "    RENATO GROTTESI      \n" /**/
                       "                         \n" /**/
                       "PROGRAMMING              \n" /**/
                       "    RENATO GROTTESI      \n" /**/
                       "    GUUS SLIEPEN         \n" /**/
                       "                         \n" /**/
                       "MUSIC BY                 \n" /**/
                       "    JOAKIM SIMONSSON     \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
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
