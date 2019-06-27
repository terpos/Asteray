#pragma once

#include "global.h"

class Splash_Screen
{
public:
	Splash_Screen();
	~Splash_Screen();

	void init();

private:
	int delay;

	int randomtips;

	ALLEGRO_DISPLAY *splashscrn;
	ALLEGRO_FONT *font;
	ALLEGRO_BITMAP *scrn;
	ALLEGRO_FONT *status;

	Status stat;
};

