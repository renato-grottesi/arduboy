#pragma once

#include "bitmaps.h"
#include "components.h"
#include "event.h"
#include "utility.h"

class Level {
public:
  Level(Arduboy2 &arduboy, Tinyfont &tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont) {}

  void init();
  bool isInProgress() { return inProgress; };

  void update();
  void onInput(Input dir);
  void render();

private:
  Arduboy2 &arduboy;
  Tinyfont &tinyfont;

  bool buildingEnabled[(uint8_t)Building::IDs::count] = {
      false,
  };

  const uint8_t *groundBmps[5] = {bmp_empty, bmp_ground, bmp_river, bmp_bridge};
  const uint8_t groundFrames[5] = {1, 1, 3, 1};
  const uint8_t *walkersBmps[2] = {bmp_man, bmp_bird};

  // Camera x position
  uint16_t camera = 0;

  // Number of tiles
  static const uint8_t size = 255;
  /* Use bit array to pack more fields in a byte. */
  struct {
    Building::IDs building : 4; /* max 16 different types of building */
    Grounds top : 2;            /* max 4 types of grounds */
    Grounds low : 2;            /* max 4 types of grounds */
  } tiles[size] = {
      {Building::IDs::empty, Grounds::empty, Grounds::ground},
  };

  // x coordinates of 4 flying objects
  uint16_t flying[4];

  // x coordinates of 4 walking objects
  uint16_t walking[4];

  // Currently selected object
  Building::IDs currBuil = Building::IDs::farm;

  uint16_t money = 999;

  unsigned long timeToUpdate = 0;

  static const uint8_t tutorialCount = 13;
  EventWrapper tutorials[tutorialCount] = {};

  char tutor[156] = {
      '\0',
  };

  uint16_t population = 0;
  bool inProgress = false;
};
