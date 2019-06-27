#pragma once

#include "global.h"
#include "game_loop.h"

enum { PLAY, HOWTO, QUIT };


class Main_menu
{
public:
	Main_menu();
	~Main_menu();

	int getChoice();
	bool isselected();
	
	void set_sel_event(bool sel);
	void setChoice(int choice);
	void setscreen(int screen);
	void load();

	void event_listener(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	void dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE * q, game_loop g, bool &loop);

	void update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop g, bool & loop);

	void draw();

	void destory();


private:
	int choice;
	int fontSize[2];
	int screen;

	bool render;
	bool mouse;
	bool sel;

	Status stat;

	ALLEGRO_BITMAP *menuBG;
	
	ALLEGRO_FONT *menuSel[2];
	ALLEGRO_FONT *pause;
	ALLEGRO_FONT *pause_options;
	ALLEGRO_FONT *status;


	ALLEGRO_SAMPLE *mt;

	ALLEGRO_SAMPLE_INSTANCE *Main_Theme;
};

