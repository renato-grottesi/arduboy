#include "level.h"

const char t01[] PROGMEM = "            \n"  /**/
                           "WELCOME TO  \n"  /**/
                           "LAGUNITA,   \n"  /**/
                           "A SMALL LAKE\n"  /**/
                           "IN THE WILD \n"  /**/
                           "WILD WEST.  \n"  /**/
                           "            \n"  /**/
                           "BUILD A FARM\n"  /**/
                           "TO GENERATE \n"  /**/
                           "SOME INCOME.\n"; /**/
const char t02[] PROGMEM = "            \n"  /**/
                           "BUILD SOME  \n"  /**/
                           "HOUSES TO   \n"  /**/
                           "INCREASE THE\n"  /**/
                           "POPULATION. \n"  /**/
                           "            \n"  /**/
                           "ARROW UP    \n"  /**/
                           "TO SWITCH   \n"  /**/
                           "BUILDING.   \n"; /**/
const char t03[] PROGMEM = "            \n"  /**/
                           "MORE PEOPLE \n"  /**/
                           "WOULD MOVE  \n"  /**/
                           "IN, IF THE  \n"  /**/
                           "HOUSES ARE  \n"  /**/
                           "SERVICED    \n"  /**/
                           "WITH WATER. \n"  /**/
                           "            \n"  /**/
                           "TRY BUILDING\n"  /**/
                           "SOME WATER  \n"  /**/
                           "TOWERS.     \n"; /**/
const char t04[] PROGMEM = "            \n"  /**/
                           "THE COWBOYS \n"  /**/
                           "ARE GETTING \n"  /**/
                           "RESTLESS.   \n"  /**/
                           "            \n"  /**/
                           "BUILD A NEW \n"  /**/
                           "SALOON TO   \n"  /**/
                           "ENTERTAIN   \n"  /**/
                           "THEM AND    \n"  /**/
                           "COLLECT SOME\n"  /**/
                           "TAXES.      \n"; /**/
const char t05[] PROGMEM = "            \n"  /**/
                           "THE GOLD    \n"  /**/
                           "FEVER       \n"  /**/
                           "REACHED     \n"  /**/
                           "LAGUNITA!   \n"  /**/
                           "\nBUILD A   \n"  /**/
                           "MINE TO     \n"  /**/
                           "INCRESE     \n"  /**/
                           "THE INCOME. \n"  /**/
                           "            \n"; /**/
const char t06[] PROGMEM = "            \n"  /**/
                           "THERE IS NO \n"  /**/
                           "SPACE LEFT  \n"  /**/
                           "TO STORE ALL\n"  /**/
                           "THE MONEY!  \n"  /**/
                           "            \n"  /**/
                           "BUILD A BANK\n"  /**/
                           "TO INCREASE \n"  /**/
                           "GOLD STORAGE\n"  /**/
                           "BY 5000$.   \n"  /**/
                           "            \n"; /**/
const char t07[] PROGMEM = "            \n"  /**/
                           "THE BANDITS \n"  /**/
                           "COULD SMELL \n"  /**/
                           "YOUR MONEY  \n"  /**/
                           "AND THEY ARE\n"  /**/
                           "COMING TO   \n"  /**/
                           "ASSAULT THE \n"  /**/
                           "BANK!       \n"  /**/
                           "BUILD A POST\n"  /**/
                           "FOR THE     \n"  /**/
                           "SHERIFF.    \n"; /**/
const char t08[] PROGMEM = "            \n"  /**/
                           "AS THE TOWN \n"  /**/
                           "GROWS, THE  \n"  /**/
                           "COST FOR    \n"  /**/
                           "IMPORTING   \n"  /**/
                           "FOOD GETS   \n"  /**/
                           "PROBLEMATIC.\n"  /**/
                           "            \n"  /**/
                           "BUILD A MILL\n"  /**/
                           "TO FEED THE \n"  /**/
                           "LAGUNITIANS.\n"; /**/
const char t09[] PROGMEM = "            \n"  /**/
                           "A PRIEST    \n"  /**/
                           "PASSING BY  \n"  /**/
                           "PROPOSES YOU\n"  /**/
                           "TO EDUCATE  \n"  /**/
                           "THE PEOPLE  \n"  /**/
                           "IF YOU BUILD\n"  /**/
                           "A SMALL     \n"  /**/
                           "CHURCH FOR  \n"  /**/
                           "HIM.        \n"  /**/
                           "            \n"; /**/
const char t10[] PROGMEM = "            \n"  /**/
                           "EVEN THE    \n"  /**/
                           "BEST OF US  \n"  /**/
                           "MAKE SOME   \n"  /**/
                           "MISTAKES.   \n"  /**/
                           "            \n"  /**/
                           "NOW YOU CAN \n"  /**/
                           "REMOVE      \n"  /**/
                           "BUILDING.   \n"  /**/
                           "            \n"  /**/
                           "            \n"; /**/
const char t11[] PROGMEM = "            \n"  /**/
                           "IT'S SO     \n"  /**/
                           "WARM...     \n"  /**/
                           "            \n"  /**/
                           "PLANT A FEW \n"  /**/
                           "TREES TO    \n"  /**/
                           "PROVIDE     \n"  /**/
                           "SOME SHADE  \n"  /**/
                           "FOR THE     \n"  /**/
                           "LAGUNITIANS!\n"  /**/
                           "            \n"; /**/
const char t12[] PROGMEM = "            \n"  /**/
                           "DID YOU TRY \n"  /**/
                           "THE FRUITS  \n"  /**/
                           "FROM OUR    \n"  /**/
                           "LOCAL       \n"  /**/
                           "CACTUS TREE?\n"  /**/
                           "            \n"  /**/
                           "NOW YOU CAN \n"  /**/
                           "PLANT YOUR  \n"  /**/
                           "OWN!        \n"; /**/
const char t13[] PROGMEM = "            \n"  /**/
                           "DO YOU EVER \n"  /**/
                           "REGRET      \n"  /**/
                           "CUTTING ALL \n"  /**/
                           "THE WEED?   \n"  /**/
                           "            \n"  /**/
                           "TAKE SOME   \n"  /**/
                           "SEEDS.      \n"  /**/
                           "            \n"  /**/
                           "            \n"; /**/

const Event tutorialsData[] = {
    /**/
    Event(0, 0, (uint8_t)(Building::IDs::farm), t01),        /**/
    Event(1000, 0, (uint8_t)(Building::IDs::house), t02),    /**/
    Event(1050, 10, (uint8_t)(Building::IDs::water), t03),   /**/
    Event(1150, 20, (uint8_t)(Building::IDs::saloon), t04),  /**/
    Event(1550, 20, (uint8_t)(Building::IDs::mine), t05),    /**/
    Event(2500, 20, (uint8_t)(Building::IDs::bank), t06),    /**/
    Event(3500, 25, (uint8_t)(Building::IDs::sheriff), t07), /**/
    Event(4000, 50, (uint8_t)(Building::IDs::mill), t08),    /**/
    Event(4000, 100, (uint8_t)(Building::IDs::church), t09), /**/
    Event(5000, 200, (uint8_t)(Building::IDs::empty), t10),  /**/
    Event(5000, 250, (uint8_t)(Building::IDs::tree), t11),   /**/
    Event(7500, 300, (uint8_t)(Building::IDs::cactus), t12), /**/
    Event(7500, 350, (uint8_t)(Building::IDs::weed), t13),   /**/
};

void Level::init() {
  timeToUpdate = millis();
  arduboy.initRandomSeed();

  // Add some random plants
  for (uint8_t i = 0; i < size; i++) {
    unsigned long r = arduboy.generateRandomSeed();
    if ((r % 7) == 0) {
      tiles[i].building = Building::IDs::cactus;
      i++;
    }
    if ((r % 7) == 1) {
      tiles[i].building = Building::IDs::weed;
      i++;
    };
    if ((r % 9) == 2) {
      tiles[i].building = Building::IDs::tree;
      i++;
    };
  }

  // Init ground
  for (uint8_t i = 0; i < size; i++) {
    tiles[i].low = Grounds::ground;
  }

  // Add a river
  tiles[5].top = Grounds::bridge;
  tiles[5].low = Grounds::river;

  // Add some random walkers and birds
  for (uint8_t i = 0; i < npc_count; i++) {
    walking[i] = random() % ((uint16_t)size * 8);
    flying[i] = random() % ((uint16_t)size * 8);
  }

  inProgress = true;
}

void Level::onInput(Input dir) {
  if (camera_off > 0) {
    return;
  }
  uint8_t sel = (uint8_t)(currBuil);
  switch (dir) {
  case Input::up:
    do {
      if (sel == 0)
        sel = Buildings::count() - 1;
      else
        sel--;
      currBuil = (Building::IDs)(sel);
    } while (buildingEnabled[sel] == false);
    break;
  case Input::down:
    do {
      sel = (sel + 1) % Buildings::count();
      currBuil = (Building::IDs)(sel);
    } while (buildingEnabled[sel] == false);
    break;
  case Input::left:
    if (camera == 0)
      camera = size - 1;
    else
      camera--;
    camera_off = 8;
    camera_sign = 0;
    break;
  case Input::right:
    camera = (camera + 1) % size;
    camera_off = 8;
    camera_sign = 1;
    break;
  case Input::a: {
    uint8_t idx = (uint8_t)(currBuil);
    if (strlen(tutor)) {
      tutor[0] = '\0';
      break;
    }
    if (money >= (Buildings::at(idx).cost * 5)) {

      uint8_t cidx = (camera + 7) % size;

      // Check if we are in the middle of another building that has to be
      // destroyed
      for (uint8_t i = 0; i < 4; i++) {
        uint8_t lidx = ((uint16_t)cidx + (uint16_t)size - (uint16_t)i) % size;
        uint8_t ends = Buildings::at(tiles[lidx].building).width;
        if (((lidx + ends) % size) > cidx)
          tiles[lidx].building = Building::IDs::empty;
      }

      // Check if there is another building on the right that has to be
      // destroyed
      for (uint8_t i = 0; i < Buildings::at(currBuil).width; i++) {
        tiles[(cidx + i) % size].building = Building::IDs::empty;
      }

      tiles[cidx].building = currBuil;
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
    uint16_t max_money = 2500;
    uint16_t jobs = 1;
    for (uint8_t obj = 0; obj < size; obj++) {
      money += Buildings::at(tiles[obj].building).profit;
      if (money > Buildings::at(tiles[obj].building).maintenance) {
        money -= Buildings::at(tiles[obj].building).maintenance;
      } else {
        money = 0;
      }
      jobs += Buildings::at(tiles[obj].building).jobs;
      if (tiles[obj].building == Building::IDs::house) {
        population += 4;
        for (int16_t i = (obj + size - 16); i < (obj + size + 16); i++) {
          if (tiles[i % size].building == Building::IDs::water) {
            population += 4;
          }
        }
      }
      if (tiles[obj].building == Building::IDs::bank) {
        max_money += 5000;
      }
    }
    if (money > max_money) {
      money = max_money;
    }
    if (population > jobs) {
      population = jobs;
    }
  }

  if (strlen(tutor) == 0) {
    for (uint8_t t = 0; t < tutorialCount; t++) {
      tutorials[t].update(tutorialsData[t], population, money);
      if (tutorials[t].justTriggered()) {
        uint8_t b = tutorialsData[t].buildingUnlocked();
        buildingEnabled[b] = true;
        const char *src = tutorialsData[t].getText();
        strncpy_P(tutor, src, 156);
        break;
      }
    }
  }
}

void Level::render() {
  static uint8_t frame = 0;
  frame++;

  int8_t x_off = (camera_sign ? (1) : (-1)) * ((int8_t)(camera_off));

  for (uint8_t i = 0; i < npc_count; i++) {
    if (!(frame % 1)) {
      flying[i] = (flying[i] + 1) % ((uint16_t)size * 8);
    }
    if (!(frame % 4)) {
      walking[i] = (walking[i] + 1) % ((uint16_t)size * 8);
    }

    // Flying objects
    arduboy.drawBitmap(flying[i] - camera * 8 + x_off, 0 * 8,
                       &bmp_bird[((frame >> 2) % 4) * 8], 8, 8);

    // Walking objects
    arduboy.drawBitmap(walking[i] - camera * 8 + x_off, 1 + 4 * 8,
                       &bmp_man[((frame >> 3) % 4) * 8], 8, 8);
  }

  // Lake area
  for (int8_t tile = -1; tile < 17; tile++) {
    const uint8_t *bmp = &(bmp_lake[(frame >> 3) % 2]);
    arduboy.drawBitmap(x_off + tile * 8, 6 * 8 - 2, bmp, 8, 8);
  }

  // Camera affected objects
  for (int8_t obj = -5; obj < 17; obj++) {
    uint8_t moved = (obj + size + camera) % size;

    // Area where characters walk
    const uint8_t *bmp = groundBmps[(uint8_t)(tiles[moved].top)];
    arduboy.drawBitmap(x_off + obj * 8, 4 * 8 - 2, bmp, 8, 8);

    // Lake shore area
    uint8_t frames = groundFrames[(uint8_t)(tiles[moved].low)];
    bmp = groundBmps[(uint8_t)(tiles[moved].low)] + 8 * ((frame >> 2) % frames);
    arduboy.drawBitmap(x_off + obj * 8, 5 * 8 - 2, bmp, 8, 8);

    // Building area
    Building::IDs b = tiles[moved].building;

    uint8_t id = (uint8_t)(b);
    bmp = Buildings::at(id).bitmap;
    uint8_t w = Buildings::at(id).width;
    uint8_t h = Buildings::at(id).height;
    arduboy.drawBitmap(x_off + obj * 8, (4 - h) * 8, bmp, w * 8, h * 8);
  }

  {
    uint8_t sel = (uint8_t)(currBuil);

    // Current selection
    for (uint8_t tile = 7; tile < 7 + (Buildings::at(sel).width); tile++) {
      const uint8_t *bmp = bmp_selection;
      arduboy.drawBitmap(tile * 8, 0, bmp, 8, 8);
    }

    // Two lines of GUI
    char tmp_str[16];

    tinyfont.setCursor(32, 6 * 8 + 6);
    Buildings::at(sel).strncpyName(tmp_str);
    tinyfont.print(tmp_str);
    tinyfont.setCursor(70, 6 * 8 + 6);
    tinyfont.print(itoa(5 * Buildings::at(sel).cost, tmp_str, 10));

    tinyfont.setCursor(32, 6 * 8 + 6 + 6);
    tinyfont.print("$");
    tinyfont.setCursor(38, 6 * 8 + 6 + 6);
    tinyfont.print(itoa(money, tmp_str, 10));
    tinyfont.setCursor(64, 6 * 8 + 6 + 6);
    tinyfont.print("PPL");
    tinyfont.setCursor(82, 6 * 8 + 6 + 6);
    tinyfont.print(itoa(population, tmp_str, 10));
  }

  /* Temporary restrictions for the LOWREZJAM */
  arduboy.fillRect(0, 0, 32, 64, BLACK);
  arduboy.fillRect(32 + 64, 0, 32, 64, BLACK);

  if (strlen(tutor)) {
    arduboy.fillRect(32, 0, 64, 64, BLACK);
    arduboy.drawRoundRect(32, 0, 64, 64, 4, WHITE);
    tinyfont.setCursor(35, 3);
    tinyfont.print(tutor);
  }

  if (camera_off > 0) {
    camera_off--;
  }
}
