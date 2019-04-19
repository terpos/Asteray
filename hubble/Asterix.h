#pragma once
#include "enemies.h"

class Asterix: public enemies
{
public:
	Asterix(int x, int y, int vel, int coord);
	~Asterix();

	int get_x();
	int get_y();
	int get_vel();
	int get_coord_ID();
	int get_name_ID();
	int get_health();
	int get_damage();

	void set_x(int x);
	void set_y(int y);
	void set_coord_ID(int CID);

	void moveleft();
	void moveright();
	void moveup();
	void movedown();
	
	void randomize_CID();
	void set_health(int health);
	void decrement_health(int damage);

	void draw(ALLEGRO_BITMAP *bmp);
	void setlife(bool life);
	
	void update();
	void ability(player &p, ALLEGRO_EVENT e);

private:
	int x, y, vel, CID, health;
	bool life;
	bool not_paralyze;
};

