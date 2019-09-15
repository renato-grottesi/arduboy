#include "events.hpp"

const char textHouse[] PROGMEM =
    "\n"             /**/
    "WELCOME TO\n"   /**/
    "LAGUNITA,\n"    /**/
    "A SMALL LAKE\n" /**/
    "IN THE WILD\n"  /**/
    "WILD WEST.\n"   /**/
    "\n"             /**/
    "BUILD SOME\n"   /**/
    "HOUSES TO\n"    /**/
    "INCREASE THE\n" /**/
    "POPULATION.\n"; /**/
const char textFarm[] PROGMEM =
    "\n"             /**/
    "BUILD A FARM\n" /**/
    "TO GIVE A\n"    /**/
    "JOB TO THE\n"   /**/
    "CITIZENS.\n"    /**/
    "\n"             /**/
    "ARROW UP\n"     /**/
    "TO SWITCH\n"    /**/
    "BUILDING.\n";   /**/
const char textWater[] PROGMEM =
    "\n"             /**/
    "MORE PEOPLE\n"  /**/
    "WILL MOVE\n"    /**/
    "IN, IF THE\n"   /**/
    "HOUSES ARE\n"   /**/
    "SERVICED\n"     /**/
    "WITH WATER.\n"  /**/
    "\n"             /**/
    "TRY BUILDING\n" /**/
    "SOME WATER\n"   /**/
    "TOWERS.\n";     /**/
const char textSaloon[] PROGMEM =
    "\n"            /**/
    "THE COWBOYS\n" /**/
    "ARE GETTING\n" /**/
    "RESTLESS.\n"   /**/
    "\n"            /**/
    "BUILD A NEW\n" /**/
    "SALOON TO\n"   /**/
    "ENTERTAIN\n"   /**/
    "THEM AND\n"    /**/
    "RAISE THEIR\n" /**/
    "HAPPINESS.\n"; /**/
const char textMine[] PROGMEM =
    "\n"             /**/
    "THE GOLD\n"     /**/
    "FEVER\n"        /**/
    "REACHED\n"      /**/
    "LAGUNITA!\n"    /**/
    "\nBUILD A\n"    /**/
    "MINE TO\n"      /**/
    "INCRESE\n"      /**/
    "THE INCOME.\n"; /**/
const char textBank[] PROGMEM =
    "\n"             /**/
    "THERE IS NO\n"  /**/
    "SPACE LEFT\n"   /**/
    "TO STORE ALL\n" /**/
    "THE MONEY!\n"   /**/
    "\n"             /**/
    "BUILD A BANK\n" /**/
    "TO INCREASE \n" /**/
    "GOLD STORAGE\n" /**/
    "BY 5000$.\n";   /**/
const char textSheriff[] PROGMEM =
    "\n"             /**/
    "THE BANDITS\n"  /**/
    "COULD SMELL\n"  /**/
    "YOUR MONEY\n"   /**/
    "AND THEY ARE\n" /**/
    "COMING TO\n"    /**/
    "ASSAULT THE\n"  /**/
    "BANK!\n"        /**/
    "BUILD A POST\n" /**/
    "FOR THE\n"      /**/
    "SHERIFF.\n";    /**/
const char textMill[] PROGMEM =
    "\n"              /**/
    "AS THE TOWN\n"   /**/
    "GROWS, THE\n"    /**/
    "COST FOR\n"      /**/
    "IMPORTING\n"     /**/
    "FOOD GETS\n"     /**/
    "PROBLEMATIC.\n"  /**/
    "\n"              /**/
    "BUILD A MILL\n"  /**/
    "TO FEED THE\n"   /**/
    "LAGUNITIANS.\n"; /**/
const char textChurch[] PROGMEM =
    "\n"             /**/
    "A PRIEST\n"     /**/
    "PASSING BY\n"   /**/
    "PROPOSES YOU\n" /**/
    "TO EDUCATE\n"   /**/
    "THE PEOPLE\n"   /**/
    "IF YOU BUILD\n" /**/
    "A SMALL\n"      /**/
    "CHURCH FOR\n"   /**/
    "HIM.\n";        /**/
const char textEmpty[] PROGMEM =
    "\n"            /**/
    "EVEN THE\n"    /**/
    "BEST OF US\n"  /**/
    "MAKE SOME\n"   /**/
    "MISTAKES.\n"   /**/
    "\n"            /**/
    "NOW YOU\n"     /**/
    "CAN REMOVE\n"  /**/
    "TREES AND\n"   /**/
    "BUILDINGS.\n"; /**/
const char textTree[] PROGMEM =
    "\n"              /**/
    "IT'S SO\n"       /**/
    "WARM...\n"       /**/
    "\n"              /**/
    "PLANT A FEW\n"   /**/
    "TREES TO\n"      /**/
    "PROVIDE\n"       /**/
    "SOME SHADE\n"    /**/
    "FOR THE\n"       /**/
    "LAGUNITIANS!\n"; /**/
const char textCactus[] PROGMEM =
    "\n"             /**/
    "DID YOU TRY\n"  /**/
    "THE FRUITS\n"   /**/
    "FROM OUR\n"     /**/
    "LOCAL CACTUS\n" /**/
    "PLANTS?\n"      /**/
    "\n"             /**/
    "NOW YOU CAN\n"  /**/
    "PLANT YOUR\n"   /**/
    "OWN!\n";        /**/
const char textWeed[] PROGMEM =
    "\n"            /**/
    "DO YOU EVER\n" /**/
    "REGRET\n"      /**/
    "CUTTING ALL\n" /**/
    "THE WEED?\n"   /**/
    "\n"            /**/
    "TAKE SOME\n"   /**/
    "SEEDS.\n";     /**/
const char textStable[] PROGMEM =
    "\n"             /**/
    "THE QUALITY\n"  /**/
    "OF YOUR FOOD\n" /**/
    "IS RENOWNED!\n" /**/
    "\n"             /**/
    "BUILD A\n"      /**/
    "STABLE TO\n"    /**/
    "EXPORT THE\n"   /**/
    "EXTRA FOOD.\n"; /**/
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

const char* const texts[Events::count] PROGMEM = {
    textHouse,   /* HOUSE   */
    textFarm,    /* FARM    */
    textWater,   /* WATER   */
    textSaloon,  /* SALOON  */
    textStable,  /* STABLE  */
    textMine,    /* MINE    */
    textSheriff, /* SHERIFF */
    textChurch,  /* CHURCH  */
    textBank,    /* BANK    */
    textMill,    /* MILL    */
    textEmpty,   /* CLEAR   */
    textTree,    /* TREE    */
    textCactus,  /* CACTUS  */
    textWeed,    /* WEED    */
};

static const uint16_t onMoney[Events::count] PROGMEM = {
    0,    /* HOUSE   */
    50,   /* FARM    */
    700,  /* WATER   */
    900,  /* SALOON  */
    1100, /* STABLE  */
    1300, /* MINE    */
    1500, /* SHERIFF */
    2000, /* CHURCH  */
    2500, /* BANK    */
    3000, /* MILL    */
    3500, /* CLEAR   */
    4000, /* TREE    */
    4500, /* CACTUS  */
    5000, /* WEED    */
};

static const uint16_t onPopulation[Events::count] PROGMEM = {
    0,   /* HOUSE   */
    1,   /* FARM    */
    10,  /* WATER   */
    15,  /* SALOON  */
    20,  /* STABLE  */
    25,  /* MINE    */
    30,  /* SHERIFF */
    35,  /* CHURCH  */
    50,  /* BANK    */
    100, /* MILL    */
    150, /* CLEAR   */
    200, /* TREE    */
    250, /* CACTUS  */
    300, /* WEED    */
};

static const Building::IDs unlocks[Events::count] PROGMEM = {
    Building::IDs::house,   /* HOUSE   */
    Building::IDs::farm,    /* FARM    */
    Building::IDs::water,   /* WATER   */
    Building::IDs::saloon,  /* SALOON  */
    Building::IDs::stable,  /* STABLE  */
    Building::IDs::mine,    /* MINE    */
    Building::IDs::sheriff, /* SHERIFF */
    Building::IDs::church,  /* CHURCH  */
    Building::IDs::bank,    /* BANK    */
    Building::IDs::mill,    /* MILL    */
    Building::IDs::empty,   /* CLEAR   */
    Building::IDs::tree,    /* TREE    */
    Building::IDs::cactus,  /* CACTUS  */
    Building::IDs::weed,    /* WEED    */
};

static const Building::IDs dependsOn[Events::count] PROGMEM = {
    Building::IDs::back,    /* HOUSE   */
    Building::IDs::house,   /* FARM    */
    Building::IDs::farm,    /* WATER   */
    Building::IDs::water,   /* SALOON  */
    Building::IDs::saloon,  /* STABLE  */
    Building::IDs::stable,  /* MINE    */
    Building::IDs::mine,    /* SHERIFF */
    Building::IDs::sheriff, /* CHURCH  */
    Building::IDs::church,  /* BANK    */
    Building::IDs::bank,    /* MILL    */
    Building::IDs::mill,    /* CLEAR   */
    Building::IDs::empty,   /* TREE    */
    Building::IDs::tree,    /* CACTUS  */
    Building::IDs::cactus,  /* WEED    */
};

const char* Events::getText(uint8_t id) {
  return pgm_read_ptr(&(texts[id]));
}

uint8_t Events::buildingUnlocked(uint8_t id) {
  return pgm_read_byte(&unlocks[id]);
}

EventState Events::update(
    EventState ev,
    uint8_t id,
    uint16_t population,
    uint16_t money,
    Building::Status buildings[static_cast<uint8_t>(Building::IDs::count)]) {
  switch (ev) {
    case EventState::untriggered:
      if (money >= pgm_read_word(&onMoney[id]) &&
          population >= pgm_read_word(&onPopulation[id]) &&
          (buildings[static_cast<uint8_t>(pgm_read_byte(&dependsOn[id]))].built > 0)) {
        return EventState::justTriggered;
      } else {
        return EventState::untriggered;
      }
      break;
    default:
      break;
  }

  return EventState::triggered;
}
