#include "components.h"
#include "bitmaps.h"

#include <avr/io.h>
#include <avr/pgmspace.h>

const char name_empty[] PROGMEM = "CLEAR";
const char name_weed[] PROGMEM = "WEED";
const char name_cactus[] PROGMEM = "CACTUS";
const char name_tree[] PROGMEM = "TREE";
const char name_house[] PROGMEM = "HOUSE";
const char name_mine[] PROGMEM = "MINE";
const char name_church[] PROGMEM = "CHURCH";
const char name_sheriff[] PROGMEM = "SHERIFF";
const char name_bank[] PROGMEM = "BANK";
const char name_water[] PROGMEM = "WATER";
const char name_saloon[] PROGMEM = "SALOON";
const char name_mill[] PROGMEM = "MILL";
const char name_farm[] PROGMEM = "FARM";

const Building Building::buildings[(uint8_t)Building::IDs::count] = {
    Building(Building::IDs::empty, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                 // width, height, maintenance, profit
             name_empty, bmp_empty),
    Building(Building::IDs::weed, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                // width, height, maintenance, profit
             name_weed, bmp_weed),
    Building(Building::IDs::cactus, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                  // width, height, maintenance, profit
             name_cactus, bmp_cactus),
    Building(Building::IDs::tree, 0, 0, // inhabitants, cost
             2, 2, 0, 0,                // width, height, maintenance, profit
             name_tree, bmp_tree),
    Building(Building::IDs::house, 4, 2, // inhabitants, cost
             2, 2, 1, 0,                 // width, height, maintenance, profit
             name_house, bmp_house),
    Building(Building::IDs::mine, 0, 20, // inhabitants, cost
             3, 3, 0, 9,                 // width, height, maintenance, profit
             name_mine, bmp_mine),
    Building(Building::IDs::church, 1, 20, // inhabitants, cost
             3, 3, 2, 0,                   // width, height, maintenance, profit
             name_church, bmp_church),
    Building(Building::IDs::sheriff, 1, 8, // inhabitants, cost
             2, 2, 2, 0,                   // width, height, maintenance, profit
             name_sheriff, bmp_sheriff),
    Building(Building::IDs::bank, 0, 15, // inhabitants, cost
             2, 2, 5, 0,                 // width, height, maintenance, profit
             name_bank, bmp_bank),
    Building(Building::IDs::water, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                 // width, height, maintenance, profit
             name_water, bmp_water),
    Building(Building::IDs::saloon, 0, 5, // inhabitants, cost
             3, 3, 0, 0,                  // width, height, maintenance, profit
             name_saloon, bmp_saloon),
    Building(Building::IDs::mill, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                // width, height, maintenance, profit
             name_mill, bmp_mill),
    Building(Building::IDs::farm, 3, 6, // inhabitants, cost
             4, 2, 0, 5,                // width, height, maintenance, profit
             name_farm, bmp_farm),
};

Building::Building(const IDs id, const uint8_t inhabitants, const uint8_t cost,
                   const uint8_t width, const uint8_t height,
                   const uint8_t maintenance, const uint8_t profit,
                   const char *srcname, const uint8_t *bitmap)
    : id(id), inhabitants(inhabitants), cost(cost), width(width),
      height(height), maintenance(maintenance), profit(profit), bitmap(bitmap) {

  uint8_t k;
  for (k = 0; k < strlen_P(srcname) && k < (8 - 1); k++) {
    name[k] = pgm_read_byte_near(srcname + k);
  }
  for (; k < 8; k++) {
    name[k] = '\0';
  }
};
