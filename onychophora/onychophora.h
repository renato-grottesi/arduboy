#include <SPI.h>
#include <Arduboy2.h>
#include <Arduboy2Beep.h>
#include <Sprites.h>
#include <Arduboy2Audio.h>
#include <Arduboy2Core.h>
#include <SpritesB.h>
#include <SpritesCommon.h>
#include <EEPROM.h>
#include <Arduboy2.h>

class Onychophora
{
public:
	Onychophora() = default;
	void init();
	void update();
	void render();
private:
	Arduboy2 arduboy;
};

