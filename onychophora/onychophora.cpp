#include "onychophora.h"
#include "bitmaps.h"

void Onychophora::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 16 to save battery
  arduboy.setFrameRate(16);

  uint8_t o = EEPROM.read(EEPROM_STORAGE_SPACE_START + 0);
  uint8_t n = EEPROM.read(EEPROM_STORAGE_SPACE_START + 1);
  uint8_t y = EEPROM.read(EEPROM_STORAGE_SPACE_START + 2);
  if (o == 'o' && n == 'n' && y == 'y') {
    lastLevel = EEPROM.read(EEPROM_STORAGE_SPACE_START + 3);
  } else {
    lastLevel = 0;

    EEPROM.write(EEPROM_STORAGE_SPACE_START + 0, 'o');
    EEPROM.write(EEPROM_STORAGE_SPACE_START + 1, 'n');
    EEPROM.write(EEPROM_STORAGE_SPACE_START + 2, 'y');
    EEPROM.write(EEPROM_STORAGE_SPACE_START + 3, 0);
  }

  level.init(0);
}

void Onychophora::loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame())) {
    return;
  }
  update();
  render();
}

void Onychophora::update() {
  arduboy.pollButtons();

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
    if (arduboy.justPressed(UP_BUTTON)) {
      level.update(Direction::up);
    }
    if (arduboy.justPressed(DOWN_BUTTON)) {
      level.update(Direction::down);
    }
    if (arduboy.justPressed(RIGHT_BUTTON)) {
      level.update(Direction::right);
    }
    if (arduboy.justPressed(LEFT_BUTTON)) {
      level.update(Direction::left);
    }
    if (arduboy.justPressed(A_BUTTON)) {
      /* Reserved for reset level, maybe... */
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

void Onychophora::render() {
  // clear the screen to black
  arduboy.clear();

  switch (currentMenu) {
  case Menus::main:
    arduboy.setCursor(20, 15);
    arduboy.print(F("Play"));
    arduboy.setCursor(20, 30);
    arduboy.print(F("Help"));
    arduboy.setCursor(20, 45);
    arduboy.print(F("Credits"));
    switch (currentMainSelection) {
    case MainSelections::play:
      arduboy.drawBitmap(10, 15, bmp_food, 8, 8);
      break;
    case MainSelections::credits:
      arduboy.drawBitmap(10, 30, bmp_food, 8, 8);
      break;
    case MainSelections::help:
      arduboy.drawBitmap(10, 45, bmp_food, 8, 8);
      break;
    }
    break;
  case Menus::game:
    level.render();
    break;
  case Menus::credits:
    arduboy.setCursor(4, 9);
    arduboy.print(F("Made by Renato!"));
    break;
  case Menus::help:
    arduboy.setCursor(4, 9);
    arduboy.print(F("Use intuition!"));
    break;
  }

  // tell the arduboy to swap buffers
  arduboy.display();
}
