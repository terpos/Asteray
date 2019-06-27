#pragma once

#include "global.h"
#include "Status.h"
#include "Animate.h"

class player
{
public:
	player();
	~player();

	void load();
	void update();
	void destroy();
	void control(ALLEGRO_EVENT &e);
	void render(Animate &hit);

	void countdown_duration();
	void poisoned(Status &s, int &health, ALLEGRO_FONT *f);

	int get_x();
	int get_y();
	int get_h();
	int get_w();
	int get_vel();
	int get_duration();
	int get_coords_ID();
	bool get_movement();
	bool get_ability_to_shoot();
	bool get_special_condition();
	bool ishit();

	void set_movement(int num, bool val);
	void set_vel(int v);
	void set_coords(int x, int y);
	void set_x(int x);
	void set_y(int y);
	void set_coords_ID(int coords);
	void set_movement(bool movement);
	void set_special_condition(bool special_condition);
	void set_ability_to_shoot(bool ability_to_shoot);
	void set_duration(int duration);
	void set_keys(int coord, bool movement);
	void ship_hit(bool hit);


private:
	ALLEGRO_BITMAP *ship[3];
	
	int x, y, vel, coord, duration;
	bool movement, special_condition, ability_to_shoot, hit;

	bool keys[4] = { false };
};

