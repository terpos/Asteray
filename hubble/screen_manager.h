#pragma once

#include "game_loop.h"
#include "Main_menu.h"
#include "Splash_Screen.h"

#include "global.h"

class screen_manager
{
public:
	screen_manager();
	
	~screen_manager();
	
	//displays assets into the screen and plays sounds
	void display_loop();
	
	//initializes the variables as well as registering
	//event sources, starting a timer, loading icons,
	//and installing addons and hardware
	void initilize_loop();
		
	//deallocates assets, displays, timers, events, and event_queue
	void destroy_stuff();

private:
	//this is used as part of the game loop
	bool loop;

	//event variable
	ALLEGRO_EVENT e;
	
	//object variables
	game_loop play;
	Main_menu menu;
	Splash_Screen ss;

	//bitmap assets for icon
	ALLEGRO_BITMAP *icon;
	
	//event queue variable
	ALLEGRO_EVENT_QUEUE *queue = NULL;

	//display variable
	ALLEGRO_DISPLAY *display = NULL;

	//timer variable
	ALLEGRO_TIMER *timer = NULL;
	
	//this will give 60fps for the game
	double fps = 60.0;


};

