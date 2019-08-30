#pragma once

#include "buildings.hpp"

/* Represents the state of an event. */
enum class EventState : uint8_t { untriggered, justTriggered, triggered };

/* Represent an immutable event. */
class Event {
public:
  /* Constructor. */
  Event(uint16_t money, uint16_t population, Building::IDs unlocks,
        const char *text)
      : onMoney(money), onPopulation(population), unlocks(unlocks), text(text) {
  }

  /* Return the buildings that gets unlocked by this event. */
  uint8_t buildingUnlocked() const { return (uint8_t)unlocks; }

  /* Return the text of this event. */
  const char *getText() const { return text; }

  /* Update an EventState for this event's parameters. */
  EventState update(EventState ev, uint16_t population, uint16_t money) const {
    switch (ev) {
    case EventState::untriggered:
      if (money >= onMoney && population >= onPopulation) {
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

private:
  const uint16_t onMoney;      /* Minimum money that triggers the event. */
  const uint16_t onPopulation; /* Minimum population that triggers the event. */
  const Building::IDs unlocks; /* Buildings that gets unlocked by the event. */
  const char *text; /* Pointer to text in PROGMEM that describe the event. */
};
