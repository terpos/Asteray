#pragma once

#include "global.h"

class player
{
public:
	player();
	~player();

	void load();
	void update();
	void destroy();
	void control(ALLEGRO_EVENT e);
	void render();


	int get_x();
	int get_y();
	int get_h();
	int get_w();
	int get_vel();
	bool get_enable();


	void set_movement(int num, bool val);
	void set_vel(int v);
	void set_coords(int x, int y);
	void set_x(int x);
	void set_y(int y);
	void set_enable(bool enable);

private:
	ALLEGRO_BITMAP *ship = NULL;
	
	int x, y, vel;
	bool enable;

	bool keys[4] = { false };
};

