#include "lagunita.hpp"

/* The game instance. */
Lagunita game;

/* To save some memory. */
ARDUBOY_NO_USB

/* Initial setup */
void setup() { game.init(); }

/* Game loop */
void loop() { game.loop(); }
