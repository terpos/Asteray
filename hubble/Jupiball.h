#include "enemies.h"

#pragma once
class Jupiball: public enemies
{
public:
	Jupiball(int x, int y, int vel, int coord);
	~Jupiball();

	int get_x();
	int get_y();
	int get_vel();
	int get_coord_ID();
	int get_name_ID();
	int get_health();
	int get_damage();

	void set_x(int x);
	void set_y(int y);

	void update();

	void set_coord_ID(int CID);

	void set_health(int health);
	void decrement_health(int damage);

	void moveleft();
	void moveright();
	void moveup();
	void movedown();

	void ability(player &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health;
};

