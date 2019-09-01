#pragma once

#include "bitmaps.hpp"
#include "buildings.hpp"
#include "events.hpp"
#include "utility.hpp"

class Level {
 public:
  Level(Arduboy2Base& arduboy, Tinyfont& tinyfont)
      : arduboy(arduboy), tinyfont(tinyfont) {}

  void init();
  bool isInProgress() { return inProgress; };

  void update();
  void onInput(Input dir);
  void render();
  bool gameOver() { return (earnings <= maintenance) && (money < 100); };
  void pause() { inProgress = false; };

 private:
  Arduboy2Base& arduboy;
  Tinyfont& tinyfont;

  Building::Status buildings[(uint8_t)Building::IDs::count] = {};

  const uint8_t* groundBmps[5] = {bmp_empty, bmp_ground, bmp_river, bmp_bridge};
  const uint8_t groundFrames[5] = {1, 1, 3, 1};
  const uint8_t* walkersBmps[2] = {bmp_man, bmp_bird};

  // Camera x position
  uint16_t camera = 0;
  uint8_t camera_off = 0;
  uint8_t camera_sign = 0;
  uint8_t camera_scrolls = 0;

  // Number of tiles
  static const uint8_t size = 255;

  /* Use bit array to pack more fields in a byte. */
  struct {
    Building::IDs building;
  } tiles[size] = {};

  uint16_t river_in = 0;  /*  X coordinate where the river goes into the lake */
  uint16_t river_out = 0; /* X coordinate where the river leaves the lake */

  uint16_t housing;
  uint16_t jobs;
  uint16_t food;
  uint16_t earnings;
  uint16_t maintenance;
  uint16_t happiness;
  uint16_t safety;
  uint16_t spirituality;
  uint16_t environment;

  // x coordinates for moving objects
  static const uint8_t npc_count = 16;
  uint16_t flying[npc_count];
  uint16_t walking[npc_count];

  // Currently selected object
  Building::IDs currBuil = Building::IDs::house;

  uint16_t money = 999;

  unsigned long timeLastUpdate = 0;
  unsigned long timeLastEvent = 0;

  EventState tutorials[Events::count] = {
      EventState::untriggered,
  };

  static const uint8_t tutorLen = 128; /* 5% of total RAM! */
  bool tutorVisible = false;
  uint8_t tutorChars = 0;
  char tutor[tutorLen] = {};

  uint16_t population = 0;
  bool inProgress = false;
  bool inStats = false;
};
