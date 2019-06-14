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
	
	void setChoice(int choice);
	void setscreen(int screen);
	void load();

	void loop(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	void dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE * q, game_loop g);

	void update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	void draw();

	void destory();


private:
	int choice;
	int fontSize[2];
	int screen;

	bool render;

	Status stat;

	ALLEGRO_BITMAP *menuBG;
	
	ALLEGRO_FONT *menuSel[2];
	ALLEGRO_FONT *pause;
	ALLEGRO_FONT *pause_options;
	ALLEGRO_FONT *status;


	ALLEGRO_SAMPLE *mt;

	ALLEGRO_SAMPLE_INSTANCE *Main_Theme;
};

