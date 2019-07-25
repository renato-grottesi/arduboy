#include "onychophora.h"

Onychophora onychophora;

void setup()
{
	onychophora.init();
}

void loop()
{
	onychophora.update();
	onychophora.render();
}

