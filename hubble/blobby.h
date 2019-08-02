#pragma once

#include "enemies.h"


class blobby: public enemies
{
public:
	blobby(int x, int y, int vel, int health, int coord);
	~blobby();

	int get_name_ID();
	int get_damage();
	int get_score();
	void weapon_ability(player * &p);

	void ability(player* &p, ALLEGRO_EVENT e);

private:
	int x, y, CID, vel, health;
	
};