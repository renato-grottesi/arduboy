#pragma once

enum class Grounds : uint8_t { empty, lake, ground, river, bridge };
enum class Walkers : uint8_t { man, bird };

class Building {
public:
  enum class IDs : uint8_t {
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
  Building(const IDs id, const uint8_t inhabitants, const uint8_t cost,
           const uint8_t width, const uint8_t height, const uint8_t maintenance,
           const uint8_t profit, const char *name, const uint8_t *bitmap)
      : id(id), inhabitants(inhabitants), cost(cost), width(width),
        height(height), maintenance(maintenance), profit(profit), name(name),
        bitmap(bitmap){};

  const IDs id;
  const uint8_t inhabitants;
  const uint8_t cost;
  const uint8_t width;
  const uint8_t height;
  const uint8_t maintenance;
  const uint8_t profit;
  const char *name;
  const uint8_t *bitmap;
};

static const Building buildings[(uint8_t)Building::IDs::count] = {
    Building(Building::IDs::empty, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                 // width, height, maintenance, profit
             "CLEAR", bmp_empty),
    Building(Building::IDs::weed, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                // width, height, maintenance, profit
             "WEED", bmp_weed),
    Building(Building::IDs::cactus, 0, 0, // inhabitants, cost
             1, 1, 0, 0,                  // width, height, maintenance, profit
             "CACTUS", bmp_cactus),
    Building(Building::IDs::tree, 0, 0, // inhabitants, cost
             2, 2, 0, 0,                // width, height, maintenance, profit
             "TREE", bmp_tree),
    Building(Building::IDs::house, 4, 2, // inhabitants, cost
             2, 2, 1, 0,                 // width, height, maintenance, profit
             "HOUSE", bmp_house),
    Building(Building::IDs::mine, 0, 20, // inhabitants, cost
             3, 3, 0, 9,                 // width, height, maintenance, profit
             "MINE", bmp_mine),
    Building(Building::IDs::church, 1, 20, // inhabitants, cost
             3, 3, 2, 0,                   // width, height, maintenance, profit
             "CHURCH", bmp_church),
    Building(Building::IDs::sheriff, 1, 8, // inhabitants, cost
             2, 2, 2, 0,                   // width, height, maintenance, profit
             "SHERIFF", bmp_sheriff),
    Building(Building::IDs::bank, 0, 15, // inhabitants, cost
             2, 2, 5, 0,                 // width, height, maintenance, profit
             "BANK", bmp_bank),
    Building(Building::IDs::water, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                 // width, height, maintenance, profit
             "WATER", bmp_water),
    Building(Building::IDs::saloon, 0, 5, // inhabitants, cost
             3, 3, 0, 0,                  // width, height, maintenance, profit
             "SALOON", bmp_saloon),
    Building(Building::IDs::mill, 0, 1, // inhabitants, cost
             1, 3, 0, 1,                // width, height, maintenance, profit
             "MILL", bmp_mill),
    Building(Building::IDs::farm, 3, 6, // inhabitants, cost
             4, 2, 0, 5,                // width, height, maintenance, profit
             "FARM", bmp_farm),
};

class Buildings {
private:
  Buildings();

public:
  static const Building at(const Building::IDs id) {
    return buildings[(uint8_t)id];
  }
  static const Building at(const uint8_t id) { return buildings[id]; }
  static const uint8_t count() { return (uint8_t)Building::IDs::count; }
};
