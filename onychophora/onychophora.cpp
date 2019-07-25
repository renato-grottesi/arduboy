#include "onychophora.h"

void Onychophora::init()
{
  // initiate arduboy instance
  arduboy.begin();

  // set the framerate to 16 to save battery
  arduboy.setFrameRate(16);
}

void Onychophora::update()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
  {
    return;
  }
}

void Onychophora::render()
{
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
  {
    return;
  }

  // clear the screen to black
  arduboy.clear();

  // print text at a position
  arduboy.setCursor(4, 9);
  arduboy.print(F("Hello, world!"));

  // tell the arduboy to swap buffers
  arduboy.display();
}

