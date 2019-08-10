#include "components.h"
#include "bitmaps.h"

// TODO: save 7(bytes)*13(building = 91 bytes by moving the constant fields
//       as PROGMEM arrays that are accessed with a getter.

// The following signature is necessary to pack the names in an array
const char names[][8] PROGMEM = {
    "CLEAR",   "WEED", "CACTUS", "TREE",   "HOUSE", "MINE", "CHURCH",
    "SHERIFF", "BANK", "WATER",  "SALOON", "MILL",  "FARM",
};

const Building Building::buildings[(uint8_t)Building::IDs::count] = {
    Building(Building::IDs::empty, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                 // width, height, maintenance, profit
             bmp_empty),
    Building(Building::IDs::weed, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                // width, height, maintenance, profit
             bmp_weed),
    Building(Building::IDs::cactus, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                  // width, height, maintenance, profit
             bmp_cactus),
    Building(Building::IDs::tree, 0, 0, // inhabitants, cost
             2, 2, 0, 0,                // width, height, maintenance, profit
             bmp_tree),
    Building(Building::IDs::house, 4, 2, // inhabitants, cost
             2, 2, 1, 0,                 // width, height, maintenance, profit
             bmp_house),
    Building(Building::IDs::mine, 0, 20, // inhabitants, cost
             3, 3, 0, 9,                 // width, height, maintenance, profit
             bmp_mine),
    Building(Building::IDs::church, 1, 20, // inhabitants, cost
             3, 3, 2, 0,                   // width, height, maintenance, profit
             bmp_church),
    Building(Building::IDs::sheriff, 1, 8, // inhabitants, cost
             2, 2, 2, 0,                   // width, height, maintenance, profit
             bmp_sheriff),
    Building(Building::IDs::bank, 0, 15, // inhabitants, cost
             2, 2, 5, 0,                 // width, height, maintenance, profit
             bmp_bank),
    Building(Building::IDs::water, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                 // width, height, maintenance, profit
             bmp_water),
    Building(Building::IDs::saloon, 0, 5, // inhabitants, cost
             3, 3, 0, 1,                  // width, height, maintenance, profit
             bmp_saloon),
    Building(Building::IDs::mill, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                // width, height, maintenance, profit
             bmp_mill),
    Building(Building::IDs::farm, 3, 6, // inhabitants, cost
             4, 2, 0, 5,                // width, height, maintenance, profit
             bmp_farm),
};

Building::Building(const IDs id, const uint8_t inhabitants, const uint8_t cost,
                   const uint8_t width, const uint8_t height,
                   const uint8_t maintenance, const uint8_t profit,
                   const uint8_t *bitmap)
    : id(id), inhabitants(inhabitants), cost(cost), width(width),
      height(height), maintenance(maintenance), profit(profit),
      bitmap(bitmap){};

void Building::strncpyName(char *dest) const {
  strncpy_P(dest, names[(uint8_t)(id)], 8);
};
