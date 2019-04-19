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
	
	void display_loop();
	
	void initilize_loop();
		
	void destroy_stuff();

private:
	bool close = false;
	
	ALLEGRO_EVENT e;
	
	game_loop play;
	Main_menu menu;
	Splash_Screen ss;
	
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	
	ALLEGRO_DISPLAY *display = NULL;
	
	ALLEGRO_TIMER *timer = NULL;
	
	double fps = 60.0;
	


};

