#pragma once

class Event {
public:
  Event(uint16_t money, uint16_t population, uint8_t unlocks, const char *text)
      : onMoney(money), onPopulation(population), unlocks(unlocks), text(text) {
  }

  void update(uint16_t population, uint16_t money) {
    if (!triggered && (money > onMoney || population > onPopulation)) {
      triggered = 1;
    }
  }

  bool justTriggered() {
    if (triggered == 1) {
      triggered = 2;
      return true;
    }
    return false;
  }

  uint8_t buildingUnlocked() const { return unlocks; }

  const char *getText() const { return text; }

private:
  uint8_t id = 0;

  const uint16_t onMoney;
  const uint16_t onPopulation;
  const uint8_t unlocks;
  const char *text;
  uint8_t triggered = 0;
};
