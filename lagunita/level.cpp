#include "level.h"

void Level::init() {

  for (uint8_t i = 0; i < size; i++) {
    ground_top[i] = Ground::empty;
    ground_low[i] = Ground::ground;
  }

  ground_top[5] = Ground::bridge;
  ground_low[5] = Ground::river;
}

void Level::onInput(Input dir) {
  switch (dir) {
  case Input::up:
    break;
  case Input::down:
    break;
  case Input::left:
    if (camera == 0)
      camera = size * 8;
    else
      camera--;
    break;
  case Input::right:
    camera++;
    if (camera > size * 8)
      camera = 0;
    break;
  case Input::a:
    break;
  case Input::b:
    break;
  }
}

void Level::update() {}

void Level::render() {
  static uint8_t frame = 0;
  frame++;

  for (uint8_t tile = 0; tile < 16; tile++) {
    uint8_t *bmp = groundBmps[(uint8_t)ground_top[tile]];
    arduboy.drawBitmap(tile * 8, 4 * 8 - 2, bmp, 8, 8);
  }

  for (uint8_t tile = 0; tile < 16; tile++) {
    uint8_t *bmp = groundBmps[(uint8_t)ground_low[tile]];
    arduboy.drawBitmap(tile * 8, 5 * 8 - 2, bmp, 8, 8);
  }

  for (uint8_t tile = 0; tile < 16; tile++) {
    uint8_t *bmp = &(bmp_lake[(frame >> 3) % 2]);
    arduboy.drawBitmap(tile * 8, 6 * 8 - 2, bmp, 8, 8);
  }

  arduboy.drawBitmap(2 * 8, 0 * 8, &bmp_bird[((frame >> 2) % 4) * 8], 8, 8);
  arduboy.drawBitmap(0 * 8, 1 + 4 * 8, bmp_weed, 8, 8);
  arduboy.drawBitmap(1 * 8, 1 + 4 * 8, bmp_cactus, 8, 8);
  arduboy.drawBitmap(2 * 8, 1 + 4 * 8, &bmp_man[((frame >> 3) % 4) * 8], 8, 8);
  arduboy.drawBitmap(2 * 8, 1 + 4 * 8, &bmp_man[((frame >> 3) % 4) * 8], 8, 8);

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
