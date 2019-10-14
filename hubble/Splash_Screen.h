#pragma once

#include "global.h"

class Splash_Screen
{
public:
	Splash_Screen();
	~Splash_Screen();

	//initializes variables, creates displays, and loads assets
	//gives random tips
	//displays assets
	//rests for ~20 seconds
	//deallocates the assets
	void tmp_splash_screen_display();

private:
	//this variable takes the seconds as an int value
	int delay;

	//takes the value of what tips to put out
	int randomtips;

	//display variable
	ALLEGRO_DISPLAY *splashscrn;
	
	//font assets
	ALLEGRO_FONT *font;
	ALLEGRO_FONT *status;

	//bitmap assets
	ALLEGRO_BITMAP *scrn;

	//object variables
	Status stat;
};

