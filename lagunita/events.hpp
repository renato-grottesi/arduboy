#pragma once

#include "buildings.hpp"

/* Represents the state of an event. */
enum class EventState : uint8_t { untriggered, justTriggered, triggered };

/* Represent an immutable event. */
class Events {
 public:
  /* Return the buildings that gets unlocked by this event. */
  static uint8_t buildingUnlocked(uint8_t id);

  /* Return the text of this event. */
  static const char* getText(uint8_t id);

  /* Update an EventState for this event's parameters. */
  static EventState update(EventState ev,
                           uint8_t id,
                           uint16_t population,
                           uint16_t money);

  static const uint8_t count = 13;

 private:
  /* Private default constructor. */
  Events(){};
};
