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

  void update();
  void onInput(Input dir);
  void render();

  // Number of tiles
  static const uint8_t size = 128;

private:
  Arduboy2 &arduboy;
  Tinyfont &tinyfont;

  bool buildingEnabled[(uint8_t)Building::IDs::count] = {
      false,
  };

  const uint8_t *groundBmps[8] = {bmp_empty, bmp_lake, bmp_ground, bmp_river,
                                  bmp_bridge};
  const uint8_t groundFrames[8] = {1, 2, 1, 3, 1};
  const uint8_t *walkersBmps[8] = {bmp_man, bmp_bird};

  // Camera x position
  uint16_t camera = 0;

  Building::IDs buildings[size] = {
      Building::IDs::empty,
  };
  Grounds ground_top[size] = {
      Grounds::empty,
  };
  Grounds ground_low[size] = {
      Grounds::ground,
  };

  // x coordinates of 4 flying objects
  uint16_t flying[4];

  // x coordinates of 4 walking objects
  uint16_t walking[4];

  // Currently selected object
  Building::IDs currBuil = Building::IDs::empty;

  uint16_t money = 1000;

  unsigned long timeToUpdate = 0;

  static const uint8_t tutorialCount = 2;
  Event tutorials[tutorialCount]{
      /**/
      Event(0, 0, (uint8_t)(Building::IDs::farm), /**/
            "\nWELCOME TO\n"                      /**/
            "LAGUNITA,\n"                         /**/
            "A SMALL LAKE\n"                      /**/
            "IN THE WILD\n"                       /**/
            "WILD WEST.\n\n"                      /**/
            "BUILD A FARM\n"                      /**/
            "TO GENERATE\n"                       /**/
            "SOME INCOME."                        /**/
            ),
      Event(1001, 0, (uint8_t)(Building::IDs::house), /**/
            "\nBUILD SOME\n"                          /**/
            "HOUSES TO\n"                             /**/
            "INCREASE THE\n"                          /**/
            "POPULATION.\n"                           /**/
            )};

  const char *tutor = nullptr;

  uint16_t population = 0;
};
