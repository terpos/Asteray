#include "global.h"
#include "Enemy_Manager.h"

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
	int get_stage();
	int get_y();

	void set_stage(int stagenum);
	void display_stage(std::string Stagename, ALLEGRO_FONT *font);

private:
	
	ALLEGRO_BITMAP *stage[4] = { NULL };
	int y, stagenum;
	bool pause, spawn;
};

