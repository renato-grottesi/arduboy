#include "lagunita.hpp"

void Lagunita::init() {
  // initialize the random seed with noise
  srand(arduboy.generateRandomSeed());

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
          case MainSelections::load:
            currentMainSelection = MainSelections::play;
            break;
          case MainSelections::save:
            if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
            break;
          case MainSelections::credits:
            if (canSave()) {
              currentMainSelection = MainSelections::save;
            } else if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
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
            if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else if (canSave()) {
              currentMainSelection = MainSelections::save;
            } else {
              currentMainSelection = MainSelections::credits;
            }
            break;
          case MainSelections::load:
            if (canSave()) {
              currentMainSelection = MainSelections::save;
            } else {
              currentMainSelection = MainSelections::credits;
            }
            break;
          case MainSelections::save:
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
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::load:
            currentMainSelection = MainSelections::help;
            break;
          case MainSelections::save:
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::play;
            break;
          case MainSelections::help:
            if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
            break;
          case MainSelections::audio:
            if (canSave()) {
              currentMainSelection = MainSelections::save;
            } else if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
            break;
        }
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            currentMainSelection = MainSelections::credits;
            break;
          case MainSelections::load:
            currentMainSelection = MainSelections::help;
            break;
          case MainSelections::save:
            currentMainSelection = MainSelections::audio;
            break;
          case MainSelections::credits:
            currentMainSelection = MainSelections::play;
            break;
          case MainSelections::help:
            if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
            break;
          case MainSelections::audio:
            if (canSave()) {
              currentMainSelection = MainSelections::save;
            } else if (canLoad()) {
              currentMainSelection = MainSelections::load;
            } else {
              currentMainSelection = MainSelections::play;
            }
            break;
        }
      }
      if (arduboy.justPressed(A_BUTTON)) {
        switch (currentMainSelection) {
          case MainSelections::play:
            if (!level.isInProgress()) {
              level.init();
            } else {
              level.resume();
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
          case MainSelections::load:
            load();
            break;
          case MainSelections::save:
            save();
            break;
        }
      }

      break;
    case Menus::game:
      if (level.isPaused()) {
        currentMenu = Menus::main;
      } else if (level.gameOver()) {
        level.quit();
        currentMenu = Menus::lost;
      } else if (arduboy.justPressed(UP_BUTTON)) {
        level.onInput(Input::up);
      } else if (arduboy.justPressed(DOWN_BUTTON)) {
        level.onInput(Input::down);
      } else if (arduboy.justPressed(LEFT_BUTTON)) {
        level.onInput(Input::left);
      } else if (arduboy.justPressed(RIGHT_BUTTON)) {
        level.onInput(Input::right);
      } else if (arduboy.justPressed(A_BUTTON)) {
        level.onInput(Input::a);
      } else if (arduboy.justPressed(B_BUTTON)) {
        level.onInput(Input::b);
      }
      level.update();
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
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        help_page++;
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        help_page--;
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
    case Menus::main: {
      static uint16_t frame = 0;
      frame++;
      level.renderBackground(frame);
      const uint8_t bl_y = 21;
      const uint8_t bl_x_l = 4;
      const uint8_t bl_x_r = 54;
      const uint8_t post_len = 104;
      arduboy.drawBitmap((128 - 105) / 2, 4 * 8, bmp_lagunita, 105, 16);
      arduboy.drawBitmap(0, 5 * 8, bmp_cactus, 8, 8);
      arduboy.drawBitmap(128 - 8, 5 * 8, bmp_weed, 8, 8);
      arduboy.fillRoundRect(bl_x_l - 2, 6, 46, 22, 4, BLACK);
      arduboy.fillRoundRect(bl_x_r - 2, 6, 46, 22, 4, BLACK);
      arduboy.drawRoundRect(bl_x_l - 2, 6, 46, 22, 4);
      arduboy.drawRoundRect(bl_x_r - 2, 6, 46, 22, 4);
      arduboy.drawFastHLine(0, 1, post_len);
      arduboy.drawFastHLine(0, 2, post_len);
      arduboy.drawCircle(bl_x_l + 5, 4, 1);
      arduboy.drawCircle(bl_x_l + 36, 4, 1);
      arduboy.drawCircle(bl_x_r + 5, 4, 1);
      arduboy.drawCircle(bl_x_r + 36, 4, 1);
      arduboy.drawBitmap(post_len, 0, bmp_decor, 16, 16);

      // Tumbleweed
      weed = (weed < 256) ? (weed + 1) : -rand() % 256;
      int16_t y_off = ((frame >> 2) % 16) - 8;
      y_off = (y_off < 0) ? (-y_off) : (y_off);
      drawing.drawBitmap(weed, 4 * 8 + y_off, &bmp_tumbleweed[((frame >> 3) % 8) * 8], 8, 8);

      drawing.waterReflection(frame / 2);

      tinyfont.setCursor(bl_x_l + 10, bl_y - 6 * 2);
      if (level.isInProgress()) {
        tinyfont.print(F("RESUME"));
      } else {
        tinyfont.print(F("PLAY"));
      }
      tinyfont.setCursor(bl_x_l + 10, bl_y - 6 * 1);
      if (canLoad()) {
        tinyfont.print(F("LOAD"));
      }
      tinyfont.setCursor(bl_x_l + 10, bl_y - 6 * 0);
      if (canSave()) {
        tinyfont.print(F("SAVE"));
      }
      tinyfont.setCursor(bl_x_r + 10, bl_y - 6 * 2);
      tinyfont.print(F("ABOUT"));
      tinyfont.setCursor(bl_x_r + 10, bl_y - 6 * 1);
      tinyfont.print(F("HELP"));
      tinyfont.setCursor(bl_x_r + 10, bl_y - 6 * 0);
      if (arduboy.audio.enabled()) {
        tinyfont.print(F("MUSIC"));
      } else {
        tinyfont.print(F("MUTED"));
      }

      switch (currentMainSelection) {
        case MainSelections::play:
          arduboy.drawBitmap(bl_x_l + 1, bl_y - 3 - 6 * 2, bmp_bullet, 8, 8);
          break;
        case MainSelections::credits:
          arduboy.drawBitmap(bl_x_r + 1, bl_y - 3 - 6 * 2, bmp_bullet, 8, 8);
          break;
        case MainSelections::help:
          arduboy.drawBitmap(bl_x_r + 1, bl_y - 3 - 6 * 1, bmp_bullet, 8, 8);
          break;
        case MainSelections::audio:
          arduboy.drawBitmap(bl_x_r + 1, bl_y - 3 - 6 * 0, bmp_bullet, 8, 8);
          break;
        case MainSelections::load:
          arduboy.drawBitmap(bl_x_l + 1, bl_y - 3 - 6 * 1, bmp_bullet, 8, 8);
          break;
        case MainSelections::save:
          arduboy.drawBitmap(bl_x_l + 1, bl_y - 3 - 6 * 0, bmp_bullet, 8, 8);
          break;
      }
      break;
    }
    case Menus::game:
      level.render();
      break;
    case Menus::lost:
      tinyfont.setCursor(2, 0);
      tinyfont.print(F(                         /**/
                       "\n"                     /**/
                       "      UNFORTUNATELY\n"  /**/
                       "      YOU RUN OUT\n"    /**/
                       "      OF MONEY.\n"      /**/
                       "\n"                     /**/
                       "      REMEMBER TO\n"    /**/
                       "      CHECK THE\n"      /**/
                       "      STATISTICS\n"     /**/
                       "      WHILE PLAYING!\n" /**/
                       "\n"                     /**/
                       "      TRY AGAIN!\n"     /**/
                       ));
      break;
    case Menus::credits:
      tinyfont.setCursor(2, 0);
      tinyfont.print(F(                            /**/
                       "\n"                        /**/
                       "LAGUNITA WAS CREATED BY\n" /**/
                       "    RENATO GROTTESI\n"     /**/
                       "\n"                        /**/
                       "PROGRAMMING\n"             /**/
                       "    RENATO GROTTESI\n"     /**/
                       "    GUUS SLIEPEN\n"        /**/
                       "\n"                        /**/
                       "MUSIC BY\n"                /**/
                       "    JOAKIM SIMONSSON\n"    /**/
                       ));
      break;
    case Menus::help:
      tinyfont.setCursor(2, 2);
      switch (help_page) {
        case 0:
          tinyfont.print(F(                            /**/
                           "BUILD A WILD WEST TOWN\n"  /**/
                           "ON THE SHORE OF LAKE\n"    /**/
                           "LAGUNITA WITH AS MANY\n"   /**/
                           "CITIZENS AS POSSIBLE.\n"   /**/
                           "\n"                        /**/
                           "INCREASE YOUR PROFIT TO\n" /**/
                           "KEEP UNLOCKING NEW AND\n"  /**/
                           "EXCITING BUILDINGS.\n"     /**/
                           "\n"                        /**/
                           "PRESS THE RIGHT ARROW\n"   /**/
                           "FOR MORE INSTRUCTIONS\n"   /**/
                           "OR B TO GO BACK.\n"        /**/
                           ));
          break;
        case 1:
          tinyfont.print(F(                             /**/
                           "YOU CAN MOVE AROUND THE\n"  /**/
                           "LEVEL WITH THE LEFT AND\n"  /**/
                           "RIGHT ARROWS. LONG PRESS\n" /**/
                           "FOR FAST SCROLLING.\n"      /**/
                           "DOUBLE CLICK TO MOVE TO\n"  /**/
                           "NEXT AVAILABLE SPOT TO\n"   /**/
                           "BUILD THE CURRENTLY\n"      /**/
                           "SELECTED BUILDING.\n"       /**/
                           "PRESS BOTH TO RECENTER.\n"  /**/
                           "\n"                         /**/
                           "PRESS THE RIGHT ARROW\n"    /**/
                           "FOR MORE INSTRUCTIONS.\n"   /**/
                           ));
          break;
        case 2:
          tinyfont.print(F(                              /**/
                           "PRESS THE UP AND DOWN\n"     /**/
                           "ARROWS TO CHANGE THE\n"      /**/
                           "CURRENTLY SELECTED ACTION\n" /**/
                           "OR BUILDING.\n"              /**/
                           "\n"                          /**/
                           "PRESS A TO DO THE ACTION\n"  /**/
                           "OR BUILD THE BUILDING.\n"    /**/
                           "\n"                          /**/
                           "PRESS B TO CHECK THE\n"      /**/
                           "STATISTICS.\n"               /**/
                           "\n"                          /**/
                           "PRESS B TO GO BACK.\n"       /**/
                           ));
          break;
        default:
          help_page = 0;
          currentMenu = Menus::main;
      }
      break;
  }

  // tell the arduboy to swap buffers
  arduboy.display();
}

#if 0
      /* Template for full screen messages. */
      tinyfont.print(F(                              /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       "                         \n" /**/
                       ));
#endif

void Lagunita::load() {
  const uint16_t loc = EEPROM_STORAGE_SPACE_START;
  level.load(loc + 8);
  level.resume();
  currentMenu = Menus::game;
}

void Lagunita::save() {
  const uint16_t loc = EEPROM_STORAGE_SPACE_START;
  EEPROM.update(loc + 0, 'L');
  EEPROM.update(loc + 1, 'A');
  EEPROM.update(loc + 2, 'G');
  EEPROM.update(loc + 3, '0');
  EEPROM.update(loc + 4, '0');

  level.save(loc + 8);
}

bool Lagunita::canSave() {
  return level.isInProgress();
}

bool Lagunita::canLoad() {
  const uint16_t loc = EEPROM_STORAGE_SPACE_START;
  uint8_t h0 = EEPROM.read(loc + 0);
  uint8_t h1 = EEPROM.read(loc + 1);
  uint8_t h2 = EEPROM.read(loc + 2);
  uint8_t h3 = EEPROM.read(loc + 3);
  uint8_t h4 = EEPROM.read(loc + 4);
  return h0 == 'L' && h1 == 'A' && h2 == 'G' && h3 == '0' && h4 == '0';
}
