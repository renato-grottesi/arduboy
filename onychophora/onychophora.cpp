#include "onychophora.h"

void Onychophora::init() {
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 16 to save battery
  arduboy.setFrameRate(16);

  uint8_t o = EEPROM.read(0);
  uint8_t n = EEPROM.read(1);
  uint8_t y = EEPROM.read(2);
  if (o == 'o' && n == 'n' && y == 'y') {
    lastLevel = EEPROM.read(3);
  } else {
    lastLevel = 0;

    EEPROM.write(0, 'o');
    EEPROM.write(1, 'n');
    EEPROM.write(2, 'y');
    EEPROM.write(3, 0);
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

void Onychophora::update() {}

void Onychophora::render() {
  // clear the screen to black
  arduboy.clear();

  // print text at a position
  arduboy.setCursor(4, 9);
  arduboy.print(F("Hello, world!"));

  level.render();
  worm.render();

  // tell the arduboy to swap buffers
  arduboy.display();
}
