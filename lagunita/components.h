#pragma once

#include "utility.h"
#include <stdint.h>

enum class Grounds : uint8_t { empty, ground, river, bridge };
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

  Building(const IDs id, const uint8_t jobs, const uint8_t cost,
           const uint8_t width, const uint8_t height, const uint8_t maintenance,
           const uint8_t profit, const uint8_t *bitmap);

  const IDs id;
  const uint8_t jobs;
  const uint8_t cost;
  const uint8_t width;
  const uint8_t height;
  const uint8_t maintenance;
  const uint8_t profit;
  const uint8_t *bitmap;

  static const Building buildings[(uint8_t)Building::IDs::count];

  void strncpyName(char *dest) const;
};

class Buildings {
private:
  Buildings();

public:
  static const Building at(const Building::IDs id) {
    return Building::buildings[(uint8_t)id];
  }
  static const Building at(const uint8_t id) { return Building::buildings[id]; }
  static const uint8_t count() { return (uint8_t)Building::IDs::count; }
};
