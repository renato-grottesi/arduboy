#include "components.h"
#include "bitmaps.h"

// The following signature is necessary to pack the names in an array
const char names[][8] PROGMEM = {
    "CLEAR",   "WEED", "CACTUS", "TREE",   "HOUSE", "MINE", "CHURCH",
    "SHERIFF", "BANK", "WATER",  "SALOON", "MILL",  "FARM",
};

// TODO: save 7(bytes)*13(building = 91 bytes by moving the constant fields
//       as PROGMEM arrays that are accessed with a getter.
const Building Building::buildings[(uint8_t)Building::IDs::count] = {
    /* id, jobs, cost/5, width, height, maintenance, profit, bitmap, */
    Building(Building::IDs::empty, 0, 4, 1, 1, 0, 0, bmp_empty),
    Building(Building::IDs::weed, 0, 2, 1, 1, 0, 0, bmp_weed),
    Building(Building::IDs::cactus, 0, 2, 1, 1, 0, 0, bmp_cactus),
    Building(Building::IDs::tree, 0, 4, 2, 2, 0, 0, bmp_tree),
    Building(Building::IDs::house, 1, 5, 2, 2, 1, 0, bmp_house),
    Building(Building::IDs::mine, 30, 100, 3, 3, 0, 30, bmp_mine),
    Building(Building::IDs::church, 1, 150, 3, 3, 2, 0, bmp_church),
    Building(Building::IDs::sheriff, 2, 20, 2, 2, 2, 0, bmp_sheriff),
    Building(Building::IDs::bank, 4, 50, 2, 2, 5, 0, bmp_bank),
    Building(Building::IDs::water, 0, 10, 1, 3, 0, 1, bmp_water),
    Building(Building::IDs::saloon, 8, 50, 3, 3, 0, 1, bmp_saloon),
    Building(Building::IDs::mill, 1, 20, 1, 3, 0, 1, bmp_mill),
    Building(Building::IDs::farm, 8, 20, 4, 2, 0, 10, bmp_farm),
};

Building::Building(const IDs id, const uint8_t jobs, const uint8_t cost,
                   const uint8_t width, const uint8_t height,
                   const uint8_t maintenance, const uint8_t profit,
                   const uint8_t *bitmap)
    : id(id), jobs(jobs), cost(cost), width(width), height(height),
      maintenance(maintenance), profit(profit), bitmap(bitmap){};

void Building::strncpyName(char dest[8]) const {
  strncpy_P(dest, names[(uint8_t)(id)], 8);
};
