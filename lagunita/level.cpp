#include "level.hpp"

void Level::init() {
  camera = 0;
  camera_off = 0;
  camera_scrolls = 0;
  camera_sign = 0;
  housing = 0;
  jobs = 0;
  earnings = 0;
  maintenance = 0;
  happiness = 100;
  safety = 100;
  spirituality = 100;
  environment = 100;
  exports = 0;
  currBuil = Building::IDs::house;
  money = 999;
  tutor[0] = '\0';
  tutorVisible = false;
  population = 0;
  inProgress = false;
  inStats = false;
  river_in = 5;
  river_out = size / 2;

  for (uint8_t i = 0; i < (uint8_t)Events::count; i++) {
    tutorials[i] = EventState::untriggered;
  }

  for (uint8_t i = 0; i < (uint8_t)Building::IDs::count; i++) {
    buildings[i].enabled = false;
    buildings[i].built = false;
  }

  /* Make an exception for the house */
  buildings[(uint8_t)(Building::IDs::house)].enabled = true;
  buildings[(uint8_t)(Building::IDs::house)].built = true;

  timeLastUpdate = millis();
  timeLastEvent = millis();
  arduboy.initRandomSeed();
  srand(arduboy.generateRandomSeed());

  /* Add some random vegetation. */
  uint8_t mask = 0x0f;
  for (uint16_t i = 0; i < size; i++) {
    tiles[i].building = Building::IDs::empty;
    uint8_t r = (rand() % 256) & mask;
    mask = 0x0f;
    switch (r) {
      case 1:
        tiles[i].building = Building::IDs::cactus;
        break;
      case 2:
        tiles[i].building = Building::IDs::weed;
        break;
      /* Trees are non removable and add to the strategy: let's double them. */
      case 3:
      case 4:
        tiles[i].building = Building::IDs::tree;
        /* After a tree there must be a blank space, so reset the mask. */
        mask = 0x00;
        break;
      default:
        break;
    }
  }

  /* Exceptions for rivers and first tile that may overlap two trees. */
  tiles[0].building = Building::IDs::empty;
  tiles[river_in].building = Building::IDs::empty;
  tiles[river_out].building = Building::IDs::empty;

  /* Init the random walkers and birds */
  for (uint8_t i = 0; i < npc_count; i++) {
    walking[i] = rand() % (size * 8);
    flying[i] = rand() % (size * 8);
  }

  inProgress = true;
}

void Level::onInput(Input dir) {
  // Let the camera scrolling complete
  if (camera_off > 0) {
    return;
  }
  // If there is a tutorial displayed, only allow the b button
  if (tutorVisible && (dir != Input::b)) {
    return;
  }
  uint8_t sel = (uint8_t)(currBuil);
  switch (dir) {
    case Input::up:
      do {
        if (sel == 0)
          sel = Building::count() - 1;
        else
          sel--;
        currBuil = (Building::IDs)(sel);
      } while (buildings[sel].enabled == false);
      break;
    case Input::down:
      do {
        sel = (sel + 1) % Building::count();
        currBuil = (Building::IDs)(sel);
      } while (buildings[sel].enabled == false);
      break;
    case Input::a: {
      uint8_t idx = (uint8_t)(currBuil);
      if (money >= (Building::cost(idx) * 5)) {
        uint16_t cidx = (camera + 7) % size;
        bool replace = true;

        if (Building::IDs::empty == currBuil) {
          // Check if we are in the middle of another building that has to be
          // destroyed
          for (uint16_t i = 0; i < 4; i++) {
            uint16_t lidx = (cidx + size - i) % size;
            uint16_t ends = Building::width(tiles[lidx].building);
            if (((lidx + ends) % size) > cidx)
              tiles[lidx].building = Building::IDs::empty;
          }
        } else {
          // Check if we are in the middle of another building or tree
          for (uint16_t i = 0; i < 4; i++) {
            uint16_t lidx = (cidx + size - i) % size;
            uint16_t ends = Building::width(tiles[lidx].building);
            if (((lidx + ends) % size) > cidx) {
              Building::IDs id = tiles[lidx].building;
              if (Building::IDs::weed != id && Building::IDs::cactus != id &&
                  Building::IDs::empty != id) {
                replace = false;
              }
            }
          }

          // Check if there is another building or tree on the right
          for (uint16_t i = 0; i < Building::width(currBuil); i++) {
            Building::IDs id = tiles[(cidx + i) % size].building;
            if (Building::IDs::weed != id && Building::IDs::cactus != id &&
                Building::IDs::empty != id) {
              replace = false;
            }
          }
        }
        if (replace) {
          // Destroy everything on the path of this building
          for (uint16_t i = 0; i < Building::width(currBuil); i++) {
            tiles[(cidx + i) % size].building = Building::IDs::empty;
          }

          tiles[cidx].building = currBuil;
          buildings[(uint8_t)currBuil].built = true;
          money -= Building::cost(idx) * 5;
        }
      }
    } break;
    case Input::b:
      if (tutorVisible) {
        if (inStats) {
          snprintf_P(tutor, tutorLen,                                     /**/
                     PSTR("\nHAPPINESS\n%4d %%\nSAFETY\n%4d %%\n"         /**/
                          "SPIRITUALITY\n%4d %%\nENVIRONMENT\n%4d %%\n"), /**/
                     happiness, safety, spirituality, environment,
                     exports); /**/
          inStats = false;
        } else {
          if (tutorChars >= strlen(tutor)) {
            /* Pressing B when the text is all shown, closes the dialog. */
            tutorVisible = false;
          } else {
            /* Pressing B while the text is animating, shows all the text. */
            tutorChars = tutorLen;
          }
        }
      } else {
        inStats = true;
        tutorVisible = true;
        tutorChars = tutorLen; /* No text animation for stats. */

        snprintf_P(tutor, tutorLen,                                      /**/
                   PSTR("\nHOUSING\n%7d\nJOBS   FOOD\n%4d%7d\n"          /**/
                        "MAINTENANCE\n%7d $/s\nEARNINGS\n%4d $/s\n"      /**/
                        "EXPORTS\n%4d $/s"),                             /**/
                   housing, jobs, food, maintenance, earnings, exports); /**/
      }
      break;
    default:
      break;
  }
}

static void update_statistic(uint8_t& statistic,
                             uint8_t multiplier,
                             uint16_t count,
                             uint16_t denominator) {
  // Assume numerator <= size and multiplier < 65536 / size
  uint16_t numerator = count * multiplier;

  if (denominator < multiplier || numerator >= denominator) {
    statistic = 100;
    return;
  }

  while (uint32_t(100) * numerator < uint32_t(statistic) * denominator)
    statistic--;
  while (uint32_t(100) * numerator >= uint32_t(statistic + 1) * denominator &&
         statistic < 100)
    statistic++;
}

void Level::update() {
  if (!tutorVisible && (camera_off == 0)) {
    if (arduboy.pressed(LEFT_BUTTON)) {
      if (camera == 0) {
        camera = size - 1;
      } else {
        camera--;
      }
      camera_off = 8;
      camera_scrolls = camera_scrolls < 32 ? camera_scrolls + 1 : 32;
      camera_sign = 0;
    } else if (arduboy.pressed(RIGHT_BUTTON)) {
      camera = (camera + 1) % size;
      camera_off = 8;
      camera_scrolls = camera_scrolls < 32 ? camera_scrolls + 1 : 32;
      camera_sign = 1;
    } else {
      camera_scrolls = 0;
    }
  }

  unsigned long time = millis();
  if ((time - timeLastUpdate) > 1000) {
    uint16_t max_money = 2500;
    uint16_t earnings_ratio = ((population + 1) * 100) / (jobs + 1);
    timeLastUpdate = time;
    housing = 0;
    maintenance = 0;
    earnings = 0;
    uint16_t vegetation = 0;
    uint16_t churches = 0;
    uint16_t sheriffs = 0;
    uint16_t saloons = 0;
    exports = 0;
    jobs = 1;
    food = 1;
    for (uint16_t obj = 0; obj < size; obj++) {
      earnings += Building::profit(tiles[obj].building);
      maintenance += Building::maintenance(tiles[obj].building);
      jobs += Building::jobs(tiles[obj].building);
      if (tiles[obj].building == Building::IDs::house) {
        housing += 4;
        for (uint16_t i = (obj + size - 16); i < (obj + size + 16); i++) {
          if (tiles[i % size].building == Building::IDs::water) {
            housing += 4;
          }
        }
      }
    }
    int16_t unemployed = housing;
    for (uint16_t obj = 0; obj < size; obj++) {
      if (tiles[obj].building == Building::IDs::bank) {
        max_money += 5000;
      }
      if (tiles[obj].building == Building::IDs::church) {
        churches++;
      }
      if (tiles[obj].building == Building::IDs::sheriff) {
        sheriffs++;
      }
      if (tiles[obj].building == Building::IDs::farm && unemployed > 0) {
        food += 22;
      }
      if (tiles[obj].building == Building::IDs::mill && unemployed > 0) {
        food += 11;
      }
      if (tiles[obj].building == Building::IDs::saloon) {
        saloons++;
      }
      if (tiles[obj].building == Building::IDs::tree ||
          tiles[obj].building == Building::IDs::cactus ||
          tiles[obj].building == Building::IDs::weed) {
        vegetation++;
      }
      unemployed -= Building::jobs(tiles[obj].building);
    }

    money += (earnings * earnings_ratio) / 100;
    if (money > maintenance) {
      money -= maintenance;
    } else {
      money = 0;
    }

    // Some vegetation for every 16 people
    update_statistic(environment, 16, vegetation, population);
    // A saloon for every 24 people
    update_statistic(happiness, 24, saloons, population);
    // A church for every 100 people
    update_statistic(spirituality, 100, churches, population);
    // A sheriff for every 100 people
    update_statistic(safety, 100, sheriffs, population);

    uint16_t stats = (environment + happiness + spirituality + safety) / 4;
    uint16_t max_housing = (housing * stats) / 100;

    max_housing = max_housing > jobs ? jobs : max_housing;

    if (population < max_housing) {
      population++;
    } else if (population > 1 && population > max_housing) {
      population--;
    }
    if (population > food) {
      population = food;
    }

    if (buildings[(uint8_t)(Building::IDs::stable)].built &&
        (food > population)) {
      /* If there is a stable, we can export surplus food for money. */
      money += exports = (food - population);
    }

    if (money > max_money) {
      money = max_money;
    }

    if (!tutorVisible) {
      /* Random events happen every 60 to 120 seconds. */
      if ((time - timeLastEvent) > (uint32_t)(rand() % 60000) + 60000) {
        timeLastEvent = time;
        uint16_t r = rand() % 2;

        if ((r == 0) && buildings[(uint8_t)(Building::IDs::sheriff)].enabled) {
          if (safety < 100) {
            /* If the safety is low, simulate a robbery. */
            r = rand() % (money / 2);
            snprintf_P(tutor, tutorLen,                         /**/
                       PSTR("\nYOU HAVE\nBEEN ROBBED!\n"        /**/
                            "\nTHE THIEVES\nSTOLE %4d$\n"       /**/
                            "\nBUILD MORE\nSHERIFF\nPOSTS!\n"), /**/
                       r);                                      /**/
          } else {
            /* Else inform that the sheriff saved the day. */
            snprintf_P(tutor, tutorLen,                   /**/
                       PSTR("\nTHE SHERIFF\nMANAGED TO\n" /**/
                            "PREVENT A\nBAND OF\n"        /**/
                            "BANDITS FROM\nSTEALING\n"    /**/
                            "YOUR MONEY!"                 /**/
                            ),                            /**/
                       r);                                /**/
          }
          tutorVisible = true;
          money -= r;
        } else if ((r == 1) &&
                   buildings[(uint8_t)(Building::IDs::church)].enabled) {
          if (spirituality < 100) {
            /* If the spirituality is low, simulate emigration. */
            r = rand() % (population / 2);
            snprintf_P(tutor, tutorLen,       /**/
                       PSTR("\n%4d PEOPLE\n"  /**/
                            "LOST FAITH\n"    /**/
                            "IN LAGUNITA\n"   /**/
                            "AND DECIDED\n"   /**/
                            "TO FOUND\n"      /**/
                            "THEIR OWN\n"     /**/
                            "TOWN.\n"         /**/
                            "BUILD MORE\n"    /**/
                            "CHURCHES TO\n"   /**/
                            "RISE FAITH!\n"), /**/
                       r);                    /**/
          } else {
            /* Else inform that the church is bringing people together. */
            snprintf_P(tutor, tutorLen,                    /**/
                       PSTR("\nLAGUNITIANS\nLOVE LIVING\n" /**/
                            "IN YOUR TOWN\nAND THEY\n"     /**/
                            "NEVER FELT\nAS UNITED!\n"     /**/
                            ),                             /**/
                       r);                                 /**/
          }
          tutorVisible = true;
          population -= r;
        }
      } else {
        /* Check if any tutorial event is ready to trigger. */
        for (uint8_t t = 0; t < Events::count; t++) {
          tutorials[t] =
              Events::update(tutorials[t], t, population, money, buildings);
          if (tutorials[t] == EventState::justTriggered) {
            uint8_t b = Events::buildingUnlocked(t);
            buildings[b].enabled = true;
            const char* src = Events::getText(t);
            strncpy_P(tutor, src, tutorLen);
            tutorVisible = true;
            break;
          }
        }
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
      flying[i] = (flying[i] + 1) % (size * 8);
    }

    int16_t pos = size + ((i % 2) ? (-flying[i]) : (flying[i]));

    // Birds
    drawing.drawBitmap((pos - camera * 8 + x_off) % (size * 8), 1 * 8,
                       &bmp_bird[((frame >> 2) % 4) * 8], 8, 8, i % 2);

    // Horses
    if (buildings[(uint8_t)(Building::IDs::stable)].built) {
      drawing.drawBitmap((size / 2 + pos - camera * 8 + x_off) % (size * 8),
                         6 + 4 * 8, &bmp_horse[((frame >> 2) % 4) * 16], 16, 8,
                         i % 2);
    }
  }
  uint8_t cowboys = population / 16;
  cowboys = cowboys > npc_count ? npc_count : cowboys;
  for (uint8_t i = 0; i < cowboys; i++) {
    if (!(frame % 4)) {
      walking[i] = (walking[i] + 1) % (size * 8);
    }

    int16_t pos = size + ((i % 2) ? (-walking[i]) : (walking[i]));

    // Walking objects
    drawing.drawBitmap((pos - camera * 8 + x_off) % (size * 8), 6 + 4 * 8,
                       &bmp_man[((frame >> 3) % 4) * 8], 8, 8, i % 2);
  }

  // Camera affected objects
  for (int8_t obj = -5; obj < 17; obj++) {
    uint16_t moved = (obj + size + camera) % size;

    const bool in_river = (moved == river_in || moved == river_out);

    // Area where characters walk
    const uint8_t* bmp = (in_river ? bmp_bridge : bmp_empty);
    arduboy.drawBitmap(x_off + obj * 8, 4 * 8 + 4, bmp, 8, 8);

    // Lake shore area
    /* The river has 3 frames of animation while the ground has only 1. */
    uint8_t frames = in_river ? 3 : 1;
    bmp = in_river ? bmp_river : bmp_ground;
    bmp = bmp + 8 * ((frame >> 2) % frames);
    arduboy.drawBitmap(x_off + obj * 8, 5 * 8, bmp, 8, 8);

    // Building area
    Building::IDs b = tiles[moved].building;

    uint8_t id = (uint8_t)(b);
    bmp = Building::bitmap(id);
    uint8_t w = Building::width(id);
    uint8_t h = Building::height(id);
    arduboy.drawBitmap(x_off + obj * 8, (4 - h) * 8 + 6, bmp, w * 8, h * 8);
  }

  uint8_t sel = (uint8_t)(currBuil);

  // Current selection
  for (uint8_t tile = 7; tile < 7 + (Building::width(sel)); tile++) {
    const uint8_t* bmp = bmp_selection;
    arduboy.drawBitmap(tile * 8, 0, bmp, 8, 8);
  }

  // Two lines of GUI
  char tmp_str[16];

  tinyfont.setCursor(0, 0);
  Building::strncpyName(tmp_str, sel);
  tinyfont.print(tmp_str);
  tinyfont.setCursor(0, 5);
  tinyfont.print(itoa(5 * Building::cost(sel), tmp_str, 10));

  snprintf_P(tmp_str, 16, PSTR("%9d$"), money);
  tinyfont.setCursor(78, 0);
  tinyfont.print(tmp_str);
  snprintf_P(tmp_str, 16, PSTR("%9dP"), population);
  tinyfont.setCursor(78, 5);
  tinyfont.print(tmp_str);

  /* Lake reflection effect. */
  for (uint16_t y = 0; y < 2; y++) {
    for (uint16_t x = 0; x < WIDTH; x++) {
      uint8_t dst_col = 0x00;

      uint8_t mirror[3] = {
          arduboy.sBuffer[(5 - y) * WIDTH + x - (x == 0 ? 0 : 1)],
          arduboy.sBuffer[(5 - y) * WIDTH + x],
          arduboy.sBuffer[(5 - y) * WIDTH + x + (x == (WIDTH - 1) ? 0 : 1)]};
      uint8_t src_col = 0x00;

      src_col = mirror[((frame >> 3) + 0) % 3];
      dst_col |= (src_col & 0x80) >> 7;
      src_col = mirror[((frame >> 3) + 1) % 3];
      dst_col |= (src_col & 0x40) >> 5;
      src_col = mirror[((frame >> 3) + 2) % 3];
      dst_col |= (src_col & 0x20) >> 3;
      src_col = mirror[((frame >> 3) + 1) % 3];
      dst_col |= (src_col & 0x10) >> 1;
      src_col = mirror[((frame >> 3) + 0) % 3];
      dst_col |= (src_col & 0x08) << 1;
      src_col = mirror[((frame >> 3) + 1) % 3];
      dst_col |= (src_col & 0x04) << 3;
      src_col = mirror[((frame >> 3) + 2) % 3];
      dst_col |= (src_col & 0x02) << 5;
      src_col = mirror[((frame >> 3) + 1) % 3];
      dst_col |= (src_col & 0x01) << 7;

      arduboy.sBuffer[(6 + y) * WIDTH + x] = dst_col;
    }
  }

  if (tutorVisible) {
    arduboy.fillRect(32, 0, 64, 64, BLACK);
    arduboy.drawRoundRect(32, 0, 64, 64, 4, WHITE);
    tinyfont.setCursor(35, 3, tutorChars);
    tinyfont.print(tutor);
    if (tutorChars < tutorLen) {
      tutorChars++;
    };
  } else {
    tutorChars = 0;
  }

  if (camera_off > 0) {
    camera_off -= camera_scrolls < 8 ? 1 : (camera_scrolls < 32 ? 2 : 4);
  }
}
