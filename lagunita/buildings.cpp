#include "buildings.hpp"
#include "bitmaps.hpp"

static const char names[(uint8_t)Building::IDs::count][8] PROGMEM = {
    "CLEAR",   /* CLEAR    */
    "HOUSE",   /* HOUSE    */
    "WATER",   /* WATER    */
    "SALOON",  /* SALOON   */
    "FARM",    /* FARM     */
    "MILL",    /* MILL     */
    "MINE",    /* MINE     */
    "CHURCH",  /* CHURCH   */
    "SHERIFF", /* SHERIFF  */
    "BANK",    /* BANK     */
    "WEED",    /* WEED     */
    "CACTUS",  /* CACTUS   */
    "TREE",    /* TREE     */
};

static const uint8_t _jobs[(uint8_t)Building::IDs::count] PROGMEM = {
    0,  /* CLEAR    */
    1,  /* HOUSE    */
    0,  /* WATER    */
    8,  /* SALOON   */
    8,  /* FARM     */
    1,  /* MILL     */
    30, /* MINE     */
    1,  /* CHURCH   */
    2,  /* SHERIFF  */
    4,  /* BANK     */
    0,  /* WEED     */
    0,  /* CACTUS   */
    0,  /* TREE     */
};

static const uint8_t _cost[(uint8_t)Building::IDs::count] PROGMEM = {
    4,   /* CLEAR    */
    5,   /* HOUSE    */
    10,  /* WATER    */
    50,  /* SALOON   */
    20,  /* FARM     */
    20,  /* MILL     */
    100, /* MINE     */
    150, /* CHURCH   */
    20,  /* SHERIFF  */
    50,  /* BANK     */
    2,   /* WEED     */
    2,   /* CACTUS   */
    4,   /* TREE     */
};

static const uint8_t _width[(uint8_t)Building::IDs::count] PROGMEM = {
    1, /* CLEAR    */
    2, /* HOUSE    */
    1, /* WATER    */
    3, /* SALOON   */
    4, /* FARM     */
    1, /* MILL     */
    3, /* MINE     */
    3, /* CHURCH   */
    2, /* SHERIFF  */
    2, /* BANK     */
    1, /* WEED     */
    1, /* CACTUS   */
    2, /* TREE     */
};

static const uint8_t _height[(uint8_t)Building::IDs::count] PROGMEM = {
    1, /* CLEAR    */
    2, /* HOUSE    */
    3, /* WATER    */
    3, /* SALOON   */
    2, /* FARM     */
    3, /* MILL     */
    3, /* MINE     */
    3, /* CHURCH   */
    2, /* SHERIFF  */
    2, /* BANK     */
    1, /* WEED     */
    1, /* CACTUS   */
    2, /* TREE     */
};

static const uint8_t _maintenance[(uint8_t)Building::IDs::count] PROGMEM = {
    0, /* CLEAR    */
    1, /* HOUSE    */
    0, /* WATER    */
    0, /* SALOON   */
    0, /* FARM     */
    0, /* MILL     */
    0, /* MINE     */
    2, /* CHURCH   */
    2, /* SHERIFF  */
    5, /* BANK     */
    0, /* WEED     */
    0, /* CACTUS   */
    0, /* TREE     */
};

static const uint8_t _profit[(uint8_t)Building::IDs::count] PROGMEM = {
    0,  /* CLEAR    */
    0,  /* HOUSE    */
    1,  /* WATER    */
    1,  /* SALOON   */
    10, /* FARM     */
    1,  /* MILL     */
    30, /* MINE     */
    0,  /* CHURCH   */
    0,  /* SHERIFF  */
    0,  /* BANK     */
    0,  /* WEED     */
    0,  /* CACTUS   */
    0,  /* TREE     */
};

static const uint8_t* const _bitmap[(uint8_t)Building::IDs::count] PROGMEM = {
    bmp_empty,   /* CLEAR    */
    bmp_house,   /* HOUSE    */
    bmp_water,   /* WATER    */
    bmp_saloon,  /* SALOON   */
    bmp_farm,    /* FARM     */
    bmp_mill,    /* MILL     */
    bmp_mine,    /* MINE     */
    bmp_church,  /* CHURCH   */
    bmp_sheriff, /* SHERIFF  */
    bmp_bank,    /* BANK     */
    bmp_weed,    /* WEED     */
    bmp_cactus,  /* CACTUS   */
    bmp_tree,    /* TREE     */
};

void Building::strncpyName(char dest[8], const uint8_t id) {
  strncpy_P(dest, names[(uint8_t)(id)], 8);
}

const uint8_t Building::jobs(const uint8_t id) {
  return pgm_read_byte(&(_jobs[(uint8_t)(id)]));
}

const uint8_t Building::cost(const uint8_t id) {
  return pgm_read_byte(&(_cost[(uint8_t)(id)]));
}

const uint8_t Building::width(const uint8_t id) {
  return pgm_read_byte(&(_width[(uint8_t)(id)]));
}

const uint8_t Building::height(const uint8_t id) {
  return pgm_read_byte(&(_height[(uint8_t)(id)]));
}

const uint8_t Building::maintenance(const uint8_t id) {
  return pgm_read_byte(&(_maintenance[(uint8_t)(id)]));
}

const uint8_t Building::profit(const uint8_t id) {
  return pgm_read_byte(&(_profit[(uint8_t)(id)]));
}

const uint8_t* Building::bitmap(const uint8_t id) {
  return pgm_read_ptr(&(_bitmap[(uint8_t)(id)]));
}
