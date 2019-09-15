#include "buildings.hpp"
#include "bitmaps.hpp"

const Building buildings[static_cast<uint8_t>(Building::IDs::count)] PROGMEM = {
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
    {"PAUSE",   bmp_empty,   0,    0, 1, 1, 0,  0},
    // clang-format on
};

const __FlashStringHelper* Building::name() const {
  return reinterpret_cast<const __FlashStringHelper*>(_name);
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

const __FlashStringHelper* Building::name(const uint8_t id) {
  return buildings[id].name();
}

const uint8_t Building::jobs(const uint8_t id) {
  return buildings[id].jobs();
}

const uint8_t Building::cost(const uint8_t id) {
  return buildings[id].cost();
}

const uint8_t Building::width(const uint8_t id) {
  return buildings[id].width();
}

const uint8_t Building::height(const uint8_t id) {
  return buildings[id].height();
}

const uint8_t Building::maintenance(const uint8_t id) {
  return buildings[id].maintenance();
}

const uint8_t Building::profit(const uint8_t id) {
  return buildings[id].profit();
}

const uint8_t* Building::bitmap(const uint8_t id) {
  return buildings[id].bitmap();
}

const char textHouse[] PROGMEM =
    "HOUSES NEAR\n"  /**/
    "VEGETATION\n"   /**/
    "ATTRACT MORE\n" /**/
    "PEOPLE.\n";     /**/
const char textFarm[] PROGMEM =
    "WORKERS ARE\n"  /**/
    "ALLOCATED\n"    /**/
    "TO FARMS\n"     /**/
    "FIRST.\n"       /**/
    "IF YOU BUILD\n" /**/
    "TOO MANY,\n"    /**/
    "OTHER JOBS\n"   /**/
    "WILL NOT BE\n"  /**/
    "TAKEN\n";       /**/
const char textWater[] PROGMEM =
    "WATER TOWERS\n" /**/
    "CAN HELP\n"     /**/
    "IRRIGATING\n"   /**/
    "THE FIELDS\n"   /**/
    "IN NEARBY\n"    /**/
    "FARMS AS\n"     /**/
    "WELL.\n";       /**/
const char textSaloon[] PROGMEM =
    "SALOONS\n"      /**/
    "INCREASE THE\n" /**/
    "HAPPINES OF\n"  /**/
    "LAGUNITIANS.\n" /**/
    "PRESS THE B\n"  /**/
    "BUTTON TO\n"    /**/
    "CHECK THE\n"    /**/
    "STATISTIC\n"    /**/
    "REPORT!\n";     /**/
const char textMine[] PROGMEM =
    "MINES ARE\n"     /**/
    "GREAT TO\n"      /**/
    "INCREASE THE\n"  /**/
    "AVAILABLE\n"     /**/
    "JOBS AND THE\n"  /**/
    "INCOME, BUT\n"   /**/
    "THEY MAY\n"      /**/
    "HURT THE\n"      /**/
    "ENVIRONMENT.\n"; /**/
const char textBank[] PROGMEM =
    "EACH BANK\n"    /**/
    "INCREASES\n"    /**/
    "THE MAXIMUM\n"  /**/
    "MONEY YOU\n"    /**/
    "CAN STORE,\n"   /**/
    "BUT THEY\n"     /**/
    "ATTRACT MORE\n" /**/
    "THIEVES.\n";    /**/
const char textSheriff[] PROGMEM =
    "REMEMBER TO\n"   /**/
    "CHECK THE\n"     /**/
    "STATISTICS\n"    /**/
    "TO KNOW WHEN\n"  /**/
    "THE SECURITY\n"  /**/
    "IS LOW AND\n"    /**/
    "IT'S TIME TO\n"  /**/
    "BUILD A NEW\n"   /**/
    "SHERIFF POST\n"; /**/
const char textMill[] PROGMEM =
    "MILLS REFINE\n" /**/
    "SEEDS FROM\n"   /**/
    "NEARBY FARMS\n" /**/
    "INTO FLOWER,\n" /**/
    "SO THEY ARE\n"  /**/
    "QUITE MORE\n"   /**/
    "EFFECTIVE\n"    /**/
    "WHEN PLACED\n"  /**/
    "NEAR FARMS.\n"; /**/
const char textChurch[] PROGMEM =
    "CHURCHS KEEP\n" /**/
    "LAGUNITAS\n"    /**/
    "TOGETHER,\n"    /**/
    "BUT THE\n"      /**/
    "CLERICS DO\n"   /**/
    "NOT LIKE\n"     /**/
    "TO BE AROUND\n" /**/
    "TOO NOISY\n"    /**/
    "BUILDINGS.\n";  /**/
const char textEmpty[] PROGMEM =
    "NOW YOU CAN\n"   /**/
    "CLEAR ANY\n"     /**/
    "TYPE OF\n"       /**/
    "VEGETATION\n"    /**/
    "AND ANY TYPE\n"  /**/
    "OF BUILDING.\n"; /**/
const char textTree[] PROGMEM =
    "TREES AROUND\n" /**/
    "CHURCHES AND\n" /**/
    "HOUSES MAKE\n"  /**/
    "THEM MORE\n"    /**/
    "ATTRACTIVE.\n"; /**/
const char textCactus[] PROGMEM =
    "DID YOU KNOW\n" /**/
    "THAT THE\n"     /**/
    "PLURAL FORM\n"  /**/
    "OF CACTUS\n"    /**/
    "IS CACTI?\n";   /**/
const char textWeed[] PROGMEM =
    "PLANTING\n"    /**/
    "WEED IS A\n"   /**/
    "GREAT WAY\n"   /**/
    "TO PAY YOUR\n" /**/
    "CO2 QUOTA.\n"; /**/
const char textStable[] PROGMEM =
    "EACH STABLE\n" /**/
    "ALLOWS YOU\n"  /**/
    "TO EXPORT\n"   /**/
    "ADDITIONAL\n"  /**/
    "EXCEEDING\n"   /**/
    "FOOD.\n"       /**/
    "PRESS B TO\n"  /**/
    "CHECK YOUR\n"  /**/
    "EXPORTS.\n";   /**/
#if 0
const char templ[] PROGMEM = 
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"  /**/
    "            \n"; /**/
#endif

const char* const descriptions[static_cast<uint8_t>(Building::IDs::count)] PROGMEM = {
    textEmpty,   /* EMPTY   */
    textHouse,   /* HOUSE   */
    textWater,   /* WATER   */
    textSaloon,  /* SALOON  */
    textFarm,    /* FARM    */
    textMill,    /* MILL    */
    textMine,    /* MINE    */
    textChurch,  /* CHURCH  */
    textSheriff, /* SHERIFF */
    textBank,    /* BANK    */
    textStable,  /* STABLE  */
    textWeed,    /* WEED    */
    textCactus,  /* CACTUS  */
    textTree,    /* TREE    */
};

const char* Building::description(const uint8_t id) {
  return pgm_read_ptr(&(descriptions[id]));
}
