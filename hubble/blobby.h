#pragma once

#include "enemies.h"


class blobby: public enemies
{
public:
	blobby(int x, int y, int vel, int coord);
	~blobby();

	void update();
	
	int get_x();
	int get_y();
	int get_vel();
	int get_health();
	int get_name_ID();
	int get_damage();
	int get_coord_ID();

	void set_x(int x);
	void set_y(int y);
	void set_vel(int vel);
	void set_health(int health);
	void decrement_health(int damage);

	void set_coord_ID(int CID);

	void ability(player &p, ALLEGRO_EVENT e);


	void moveleft();
	void moveright();
	void moveup();
	void movedown();


private:
	int x, y, CID, vel, health;
	
};