#include "buildings.hpp"
#include "bitmaps.hpp"

const Building buildings[(uint8_t)Building::IDs::count] PROGMEM = {
    // clang-format off
    /* name,    bitmap,   jobs, cost, w, h, maintenance, profit */
    {"CLEAR",   bmp_empty,   0,    4, 1, 1, 0,  0},
    {"HOUSE",   bmp_house,   0,    5, 2, 2, 1,  0},
    {"WATER",   bmp_water,   0,   10, 1, 3, 0,  1},
    {"SALOON",  bmp_saloon,  8,   50, 3, 3, 0,  1},
    {"FARM",    bmp_farm,    8,   20, 4, 2, 0, 10},
    {"MILL",    bmp_mill,    1,   20, 1, 3, 0,  1},
    {"MINE",    bmp_mine,   30,  100, 3, 3, 0, 30},
    {"CHURCH",  bmp_church,  1,  150, 3, 3, 2,  0},
    {"SHERIFF", bmp_sheriff, 2,   20, 2, 2, 2,  0},
    {"BANK",    bmp_bank,    4,   50, 2, 2, 5,  0},
    {"STABLE",  bmp_stable,  2,  200, 4, 3, 4,  0},
    {"WEED",    bmp_weed,    0,    2, 1, 1, 0,  0},
    {"CACTUS",  bmp_cactus,  0,    2, 1, 1, 0,  0},
    {"TREE",    bmp_tree,    0,    4, 2, 2, 0,  0},
    // clang-format on
};

void Building::strncpyName(char dest[8]) const {
  strncpy_P(dest, name, 8);
}

const uint8_t Building::jobs() const {
  return pgm_read_byte(&_jobs);
}

const uint8_t Building::cost() const {
  return pgm_read_byte(&_cost);
}

const uint8_t Building::width() const {
  return pgm_read_byte(&_width);
}

const uint8_t Building::height() const {
  return pgm_read_byte(&_height);
}

const uint8_t Building::maintenance() const {
  return pgm_read_byte(&_maintenance);
}

const uint8_t Building::profit() const {
  return pgm_read_byte(&_profit);
}

const uint8_t* Building::bitmap() const {
  return pgm_read_ptr(&_bitmap);
}

void Building::strncpyName(char dest[8], const uint8_t id) {
  buildings[(uint8_t)id].strncpyName(dest);
}

const uint8_t Building::jobs(const uint8_t id) {
  return buildings[(uint8_t)id].jobs();
}

const uint8_t Building::cost(const uint8_t id) {
  return buildings[(uint8_t)id].cost();
}

const uint8_t Building::width(const uint8_t id) {
  return buildings[(uint8_t)id].width();
}

const uint8_t Building::height(const uint8_t id) {
  return buildings[(uint8_t)id].height();
}

const uint8_t Building::maintenance(const uint8_t id) {
  return buildings[(uint8_t)id].maintenance();
}

const uint8_t Building::profit(const uint8_t id) {
  return buildings[(uint8_t)id].profit();
}

const uint8_t* Building::bitmap(const uint8_t id) {
  return buildings[(uint8_t)id].bitmap();
}
