#pragma once

class Event {
public:
  Event(uint16_t money, uint16_t population, uint8_t unlocks, const char *text)
      : onMoney(money), onPopulation(population), unlocks(unlocks), text(text) {
  }

  uint8_t buildingUnlocked() const { return unlocks; }
  const char *getText() const { return text; }

public:
  const uint16_t onMoney;
  const uint16_t onPopulation;
  const uint8_t unlocks;
  const char *text;
};

class EventWrapper {
public:
  EventWrapper() : triggered(0) {}
  void update(const Event &ev, uint16_t population, uint16_t money) {
    if (!triggered && (money >= ev.onMoney && population >= ev.onPopulation)) {
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

private:
  uint8_t triggered = 0;
};
