#pragma once

#include "global.h"
#include "game_loop.h"

enum { PLAY, HOWTO, PLOT, QUIT};


class Main_menu
{
public:
	Main_menu();
	~Main_menu();

	//return choice number
	int getChoice();

	//returns the true/false value of selected if the enter button is pressed
	bool isselected();
	
	//sets the value of sel variable
	void set_sel_event(bool sel);

	//sets choice number
	void setChoice(int choice);
	
	//sets screen state in menu with the exception of play and quit
	void setscreen(int screen);

	//loads bitmaps, fonts, and sound; also, initialize variables
	void load(game_loop &g);

	//handles keyboard/mouse events
	void event_listener(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q);

	//handles choice number when enter is pressed
	void dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE * q, game_loop &g, bool &loop);

	//updates variables
	void update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop &g, bool & loop);

	//renders the bitmap and text to the screen and plays sounds
	void draw();

	//deallocates the bitmaps, fonts, and sounds
	void destory();


private:

	//this takes in values based on the choice you make
	//in the main menu
	int choice;

	//this variable is for choices and and title menu
	int fontSize[2];

	//takes in value of different screen states in the menu with exceptions
	//of play and quit
	int screen;

	//this variable is used as a part of 
	//alleviate the cpu
	bool render;

	//this variable serves that if a mouse moves this variable returns true
	bool mouse;

	//this variable turns true when enter is pressed
	bool sel;

	//using notification
	Status stat;

	//loads bitmap assets
	ALLEGRO_BITMAP *menuBG;
	
	//allegro fonts asset
	ALLEGRO_FONT *menuSel[2];
	ALLEGRO_FONT *Screen_title;
	ALLEGRO_FONT *How_to;
	ALLEGRO_FONT *plot;

	//loads sample and sample instance assets
	ALLEGRO_SAMPLE *mt;

	ALLEGRO_SAMPLE_INSTANCE *Main_Theme;
};

