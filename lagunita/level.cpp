#include "level.h"

void Level::init() {
  timeToUpdate = millis();
  arduboy.initRandomSeed();

  // Add some random plants
  for (uint8_t i = 0; i < size; i++) {
    unsigned long r = arduboy.generateRandomSeed();
    if ((r % 7) == 0) {
      buildings[i] = Building::IDs::cactus;
      i++;
    }
    if ((r % 7) == 1) {
      buildings[i] = Building::IDs::weed;
      i++;
    };
    if ((r % 9) == 2) {
      buildings[i] = Building::IDs::tree;
      i++;
    };
  }

  // Init ground
  for (uint8_t i = 0; i < size; i++) {
    ground_low[i] = Grounds::ground;
  }

  // Add a river
  ground_top[5] = Grounds::bridge;
  ground_low[5] = Grounds::river;

  // Add some random walkers and birds

  for (uint8_t i = 0; i < 4; i++) {
    walking[i] = random() % 1024;
    flying[i] = random() % 1024;
  }
}

void Level::onInput(Input dir) {
  uint8_t sel = (uint8_t)(currBuil);
  switch (dir) {
  case Input::up:
    if (sel == 0)
      sel = Buildings::count() - 1;
    else
      sel--;
    currBuil = (Building::IDs)(sel);
    break;
  case Input::down:
    sel = (sel + 1) % Buildings::count();
    currBuil = (Building::IDs)(sel);
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
  case Input::a: {
    uint8_t idx = (uint8_t)(currBuil);
    if (tutor != nullptr) {
      tutor = nullptr;
      break;
    }
    if (money >= (Buildings::at(idx).cost * 5)) {

      uint8_t cidx = (camera + 7) % size;

      // Check if we are in the middle of another building that has to be
      // destroyed
      for (uint8_t i = 0; i < 4; i++) {
        uint8_t lidx = ((uint16_t)cidx + (uint16_t)size - (uint16_t)i) % size;
        uint8_t ends = Buildings::at(buildings[lidx]).width;
        if (((lidx + ends) % size) > cidx)
          buildings[lidx] = Building::IDs::empty;
      }

      // Check if there is another building on the right that has to be
      // destroyed
      for (uint8_t i = 0; i < Buildings::at(currBuil).width; i++) {
        buildings[(cidx + i) % size] = Building::IDs::empty;
      }

      buildings[cidx] = currBuil;
      money -= Buildings::at(idx).cost * 5;
    }
  } break;
  case Input::b:
    break;
  }
}

void Level::update() {
  unsigned long time = millis();
  if ((time - timeToUpdate) > 1000) {
    timeToUpdate = time;
    population = 0;
    for (uint8_t obj = 0; obj < size; obj++) {
      money += Buildings::at(buildings[obj]).profit;
      money -= Buildings::at(buildings[obj]).maintenance;
      population += Buildings::at(buildings[obj]).inhabitants;
    }
  }

  for (uint8_t t = 0; t < tutorialCount; t++) {
    tutorials[t].update(0, money);
    if (tutorials[t].justTriggered()) {
      // uint8_t b = tutorials[t].buildingUnlocked();
      tutor = tutorials[t].getText();
    }
  }
}

void Level::render() {
  static uint8_t frame = 0;
  frame++;

  for (uint8_t i = 0; i < 4; i++) {
    walking[i] = (walking[i] + 1) % (1024);
    flying[i] = (flying[i] + 1) % (1024);

    // Flying objects
    arduboy.drawBitmap((flying[i]), 0 * 8, &bmp_bird[((frame >> 2) % 4) * 8], 8,
                       8);

    // Walking objects
    arduboy.drawBitmap((walking[i] >> 2), 1 + 4 * 8,
                       &bmp_man[((frame >> 3) % 4) * 8], 8, 8);
  }

  // Lake area
  for (uint8_t tile = 0; tile < 16; tile++) {
    const uint8_t *bmp = &(bmp_lake[(frame >> 3) % 2]);
    arduboy.drawBitmap(tile * 8, 6 * 8 - 2, bmp, 8, 8);
  }

  // Render the first partially visible building on the left
  if (buildings[camera] == Building::IDs::empty) {
    for (uint8_t i = 0; i < 4; i++) {
      uint8_t lidx = ((uint16_t)camera + (uint16_t)(size - i)) % size;
      uint8_t bidx = (uint8_t)(buildings[lidx]);
      uint8_t ends = Buildings::at(bidx).width;
      if (((lidx + ends) % size) > camera &&
          Building::IDs::empty != buildings[lidx]) {
        const uint8_t *bmp = Buildings::at(bidx).bitmap;
        uint8_t w = Buildings::at(bidx).width;
        uint8_t h = Buildings::at(bidx).height;

        arduboy.drawBitmap((-((int16_t)(i))) * 8, (4 - h) * 8, bmp, w * 8,
                           h * 8);
      }
    }
  }

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
    Building::IDs b = buildings[moved];

    uint8_t id = (uint8_t)(b);
    bmp = Buildings::at(id).bitmap;
    uint8_t w = Buildings::at(id).width;
    uint8_t h = Buildings::at(id).height;
    arduboy.drawBitmap(obj * 8, (4 - h) * 8, bmp, w * 8, h * 8);
  }

  {
    uint8_t sel = (uint8_t)(currBuil);

    // Current selection
    for (uint8_t tile = 7; tile < 7 + (Buildings::at(sel).width); tile++) {
      const uint8_t *bmp = bmp_selection;
      arduboy.drawBitmap(tile * 8, 0, bmp, 8, 8);
    }

    // Two lines of GUI
    char money_str[16];

    tinyfont.setCursor(32, 6 * 8 + 6);
    tinyfont.print(Buildings::at(sel).name);
    tinyfont.setCursor(70, 6 * 8 + 6);
    tinyfont.print(itoa(5 * Buildings::at(sel).cost, money_str, 10));

    tinyfont.setCursor(32, 6 * 8 + 6 + 6);
    tinyfont.print("$");
    tinyfont.setCursor(38, 6 * 8 + 6 + 6);
    tinyfont.print(itoa(money, money_str, 10));
    tinyfont.setCursor(64, 6 * 8 + 6 + 6);
    tinyfont.print("PPL");
    tinyfont.setCursor(82, 6 * 8 + 6 + 6);
    tinyfont.print(itoa(population, money_str, 10));
  }

  /* Temporary restrictions for the LOWREZJAM */
  arduboy.fillRect(0, 0, 32, 64, BLACK);
  arduboy.fillRect(32 + 64, 0, 32, 64, BLACK);

  if (tutor != nullptr) {
    arduboy.fillRect(32, 0, 64, 64, BLACK);
    arduboy.drawRoundRect(32, 0, 64, 64, 4, WHITE);
    tinyfont.setCursor(35, 3);
    tinyfont.print(tutor);
  }
}
