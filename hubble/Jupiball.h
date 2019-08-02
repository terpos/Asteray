#include "enemies.h"

#pragma once
class Jupiball: public enemies
{
public:
	Jupiball(int x, int y, int vel, int health, int coord);
	~Jupiball();

	int get_name_ID();
	int get_damage();
	int get_score();

	void gravity(player *p);

	void ability(player* &p, ALLEGRO_EVENT e);

private:
	int x, y, vel, CID, health;
};

