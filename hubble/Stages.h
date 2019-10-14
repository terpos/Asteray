#include "global.h"
#include "Animate.h"

#pragma once
enum {EARTH, MARS, AST, SATURN};

class Stages
{
public:
	Stages();
	~Stages();

	//loads assets for stages
	void load_stages();
	
	//displays earth stage
	void earth ();

	//displays mars stage
	void mars();

	//displays astroid belt stage
	void astroid_belt();

	//displays saturn stage
	void saturn();

	//the stage stop scrolling
	void stop_moving();

	//function not used
	void set_spawn(bool spawn);

	//the stage scrolls
	void scroll_down();

	//deallocates assets memories
	void destroy_stages();	

	//sets the y coordinates 
	void set_y(int y);

	//function not used
	bool get_spawn();
	bool get_pause();
	void set_pause(bool pause);

	//returns whether the player gets disfigurement
	bool get_disfig();

	//returns the stage 
	int get_stage();

	//returns the y coordinate for the bitmap
	int get_y();

	//returns the height of the bitmap
	int get_h();

	//updates the animation for the bitmaps
	void update_animation();

	//sets the stage
	void set_stage(int stagenum);
	
	//sets whether the player gets disfigurement
	void set_disfig(bool disfig);

	//displays the stage name
	void display_stage(std::string Stagename, ALLEGRO_FONT *font);

private:
	//assets
	ALLEGRO_BITMAP *stage[4] = { NULL };
	ALLEGRO_BITMAP *stage_disfig[4] = { NULL };

	//int and bool variables
	int y, stagenum;
	bool pause, spawn, disfig;
	
	//object variable
	Animate a;
};

