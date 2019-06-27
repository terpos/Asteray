#include "enemies.h"

#pragma once
class Satusphere:public enemies
{
public:
	Satusphere(int x, int y, int vel, int coord);
	~Satusphere();

	int get_x();
	int get_y();
	int get_vel();
	int get_coord_ID();
	int get_name_ID();
	int get_health();
	int get_damage();
	int get_score();

	void set_x(int x);
	void set_y(int y);

	void update();

	void set_coord_ID(int CID);

	void set_health(int health);
	void decrement_health(int damage);
	void gravity(player* & p);

	void moveleft();
	void moveright();
	void moveup();
	void movedown();

	void ability(player* &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health;
};


