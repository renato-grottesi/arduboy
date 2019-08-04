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
  uint8_t sel = (uint8_t)(currBuil);
  switch (dir) {
  case Input::up:
    if (sel == 0)
      sel = buildableCount - 1;
    else
      sel--;
    currBuil = (Buildable)(sel);
    break;
  case Input::down:
    sel = (sel + 1) % buildableCount;
    currBuil = (Buildable)(sel);
    break;
  case Input::left:
    if (camera == 0)
      camera = size;
    else
      camera--;
    break;
  case Input::right:
    camera = (camera + 1) % size;
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

  // Lake area
  for (uint8_t tile = 0; tile < 16; tile++) {
    const uint8_t *bmp = &(bmp_lake[(frame >> 3) % 2]);
    arduboy.drawBitmap(tile * 8, 6 * 8 - 2, bmp, 8, 8);
  }

  // Flying objects
  arduboy.drawBitmap(2 * 8, 0 * 8, &bmp_bird[((frame >> 2) % 4) * 8], 8, 8);

  // Walking objects
  arduboy.drawBitmap(2 * 8, 1 + 4 * 8, &bmp_man[((frame >> 3) % 4) * 8], 8, 8);

  // Camera affected objects
  for (uint8_t obj = 0; obj < size; obj++) {
    uint8_t moved = (obj + camera) % size;

    // Area where characters walk
    const uint8_t *bmp = groundBmps[(uint8_t)ground_top[moved]];
    arduboy.drawBitmap(obj * 8, 4 * 8 - 2, bmp, 8, 8);

    // Lake shore area
    uint8_t frames = groundFrames[(uint8_t)(ground_low[moved])];
    bmp = groundBmps[(uint8_t)ground_low[moved]] + 8 * ((frame >> 2) % frames);
    arduboy.drawBitmap(obj * 8, 5 * 8 - 2, bmp, 8, 8);

    // Building area
    Buildable b = buildings[moved];
    // if(b == Buildable::empty) continue;
    uint8_t id = (uint8_t)(b);
    bmp = buildableBmps[id];
    uint8_t w = buildableWidth[id];
    uint8_t h = buildableHeight[id];
    arduboy.drawBitmap(obj * 8, (4 - h) * 8, bmp, w * 8, h * 8);
  }

  // Two lines of GUI
  {
    uint8_t sel = (uint8_t)(currBuil);
    tinyfont.setCursor(0 * 8, 6 * 8 + 6);
    tinyfont.print(buildableNames[sel]);
    tinyfont.setCursor(0 * 8, 6 * 8 + 6 + 6);
    tinyfont.print("AVAIL $999");
  }
}
