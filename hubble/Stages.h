#include "global.h"
#include "Animate.h"

#pragma once
enum {EARTH, MARS, AST, SATURN};

class Stages
{
public:
	Stages();
	~Stages();

	void load_stages();
	
	void earth ();
	void mars();
	void astroid_belt();
	void saturn();
	void stop_moving();
	void set_spawn(bool spawn);

	void scroll_down();
	void destroy_stages();
	void set_pause(bool pause);

	void set_y(int y);

	bool get_spawn();
	bool get_pause();
	bool get_disfig();
	int get_stage();
	int get_y();

	void update_animation();

	void set_stage(int stagenum);
	void set_disfig(bool disfig);
	void display_stage(std::string Stagename, ALLEGRO_FONT *font);

private:
	
	ALLEGRO_BITMAP *stage[4] = { NULL };
	ALLEGRO_BITMAP *stage_disfig[4] = { NULL };

	int y, stagenum;
	bool pause, spawn, disfig;
	
	Animate a;
};

