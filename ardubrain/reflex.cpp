#include "reflex.hpp"

void Reflex::update() {}

void Reflex::render() {
  tinyfont.setCursor(0, 0);
  tinyfont.print(F("REFLEX TEST"));
}
