#include "level.h"
#include "bitmaps.h"

void Level::init() {}

void Level::onInput(Input dir) {
  if ((!is.moving) && (!is.falling)) {

    switch (dir) {
    case Input::up:
      break;
    case Input::down:
      break;
    case Input::left:
      break;
    case Input::right:
      break;
    }
  }
}

void Level::update() {}

void Level::render() {
  static uint8_t frame = 0;
  frame++;

  tinyfont.setCursor(2, 2);
  tinyfont.print(tutorial);
  /*
  arduboy.drawLine(0, 0, 127, 0);
  arduboy.drawLine(127, 0, 127, 63);
  arduboy.drawLine(127, 63, 0, 63);
  arduboy.drawLine(0, 63, 0, 0);
  */
  arduboy.drawBitmap(2 * 8, 0 * 8, &bmp_bird[((frame >> 2) % 4) * 8], 8, 8);
  arduboy.drawBitmap(0 * 8, 1 + 4 * 8, bmp_weed, 8, 8);
  arduboy.drawBitmap(1 * 8, 1 + 4 * 8, bmp_cactus, 8, 8);
  arduboy.drawBitmap(2 * 8, 1 + 4 * 8, &bmp_man[((frame >> 3) % 4) * 8], 8, 8);
  for (uint8_t i = 0; i < 16; i++)
    arduboy.drawBitmap(i * 8, 6 * 8 - 2, &bmp_lake[((frame >> 3) % 2) * 8], 8,
                       8);

  for (uint8_t i = 0; i < 13; i++)
    arduboy.drawBitmap(i * 8, 5 * 8 - 2, bmp_ground, 8, 8);
  arduboy.drawBitmap(13 * 8, 4 * 8 - 2, &bmp_river[((frame >> 2) % 3) * 8], 8,
                     8);
  arduboy.drawBitmap(13 * 8, 4 * 8, bmp_bridge, 8, 8);
  arduboy.drawBitmap(2 * 8, 1 + 4 * 8, &bmp_man[((frame >> 3) % 4) * 8], 8, 8);
  arduboy.drawBitmap(13 * 8, 5 * 8 - 2, &bmp_river[((frame >> 2) % 3) * 8], 8,
                     8);
  for (uint8_t i = 14; i < 16; i++)
    arduboy.drawBitmap(i * 8, 5 * 8 - 2, bmp_ground, 8, 8);

  arduboy.drawBitmap(0 * 8, 2 * 8, bmp_house, 16, 16);
  // arduboy.drawBitmap(13 * 8, 1 * 8, bmp_mine, 24, 24);
  arduboy.drawBitmap(13 * 8, 1 * 8, bmp_church, 24, 24);
  // arduboy.drawBitmap(2 * 8, 2 * 8, bmp_sheriff, 16, 16);
  // arduboy.drawBitmap(2 * 8, 2 * 8, bmp_bank, 16, 16);
  arduboy.drawBitmap(2 * 8, 2 * 8, bmp_tree, 16, 16);
  arduboy.drawBitmap(4 * 8, 1 * 8, bmp_water, 8, 24);
  arduboy.drawBitmap(5 * 8, 1 * 8, bmp_saloon, 24, 24);
  arduboy.drawBitmap(8 * 8, 1 * 8, bmp_mill, 8, 24);
  arduboy.drawBitmap(9 * 8, 2 * 8, bmp_farm, 32, 16);

  tinyfont.setCursor(0 * 8, 6 * 8 + 6);
  tinyfont.print("SHERIFF $999\nAVAIL $999");
}
