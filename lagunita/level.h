#pragma once

#include "bitmaps.h"
#include "utility.h"

class Level {
public:
  Level(Arduboy2 &arduboy, Tinyfont &tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont) {}

  void init();

  void update();
  void onInput(Input dir);
  void render();

  // Number of tiles
  static const uint8_t size = 32;

private:
  Arduboy2 &arduboy;
  Tinyfont &tinyfont;

  enum class Buildable : uint8_t {
    empty,
    weed,
    cactus,
    tree,
    house,
    mine,
    church,
    sheriff,
    bank,
    water,
    saloon,
    mill,
    farm,
    count
  };
  const uint8_t buildableCount = (uint8_t)(Buildable::count);
  const uint8_t buildableCost[16] = {0, 0, 0, 0, 2, 20, 20, 8, 15, 1, 5, 1, 6};
  const uint8_t buildableWidth[16] = {1, 1, 1, 2, 2, 3, 3, 2, 2, 1, 3, 1, 4};
  const uint8_t buildableHeight[16] = {1, 1, 1, 2, 2, 3, 3, 2, 2, 3, 3, 3, 2};
  const uint8_t buildableMaintenance[16] = {0, 0, 0, 0, 1, 0, 2,
                                            2, 5, 0, 0, 0, 0};
  const uint8_t buildableProfit[16] = {0, 0, 0, 0, 0, 10, 0, 0, 0, 1, 0, 1, 5};
  const uint8_t *buildableBmps[16] = {
      bmp_empty,  bmp_weed,   bmp_cactus,  bmp_tree, bmp_house,
      bmp_mine,   bmp_church, bmp_sheriff, bmp_bank, bmp_water,
      bmp_saloon, bmp_mill,   bmp_farm};
  const char *buildableNames[16] = {
      "CLEAR",   "WEED", "CACTUS", "TREE",   "HOUSE", "MINE", "CHURCH",
      "SHERIFF", "BANK", "WATER",  "SALOON", "MILL",  "FARM"};

  enum class Ground : uint8_t { empty, lake, ground, river, bridge };
  const uint8_t *groundBmps[8] = {bmp_empty, bmp_lake, bmp_ground, bmp_river,
                                  bmp_bridge};
  const uint8_t groundFrames[8] = {1, 2, 1, 3, 1};

  enum class Walkers : uint8_t { man, bird };
  const uint8_t *walkersBmps[8] = {bmp_man, bmp_bird};

  // Camera x position
  uint16_t camera = 0;

  Buildable buildings[size] = {
      Buildable::empty,  Buildable::empty, Buildable::empty, Buildable::weed,
      Buildable::cactus, Buildable::tree,  Buildable::empty, Buildable::house,
      Buildable::empty,  Buildable::mine,  Buildable::empty, Buildable::empty,
      Buildable::church, Buildable::empty, Buildable::empty, Buildable::sheriff,
      Buildable::empty,  Buildable::bank,  Buildable::empty, Buildable::water,
      Buildable::saloon, Buildable::empty, Buildable::empty, Buildable::mill,
      Buildable::farm,   Buildable::empty, Buildable::empty,
  };

  Ground ground_top[Level::size];
  Ground ground_low[Level::size];

  // x coordinates of 4 flying objects
  uint16_t flying[4];

  // x coordinates of 4 walking objects
  uint16_t walking[4];

  // Currently selected object
  Buildable currBuil = Buildable::empty;

  uint16_t money = 1000;

  unsigned long timeToUpdate = 0;
};
