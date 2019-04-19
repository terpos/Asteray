#pragma once

#include "global.h"
#include "game_loop.h"

class Main_menu
{
public:
	Main_menu();
	~Main_menu();

	int getChoice();
	
	void setChoice(int choice);

	void load();

	void loop(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	void dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE * q, game_loop g);

	//void choice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop g);

	void update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	void draw();

	void destory();


private:
	int choice;
	int fontSize[2];

	bool render;

	ALLEGRO_BITMAP *menuBG;
	
	ALLEGRO_FONT *menuSel[2];

};

