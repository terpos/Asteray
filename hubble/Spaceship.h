#include "enemies.h"

#pragma once
class Spaceship:public enemies
{
public:
	Spaceship(int x, int y, int vel, int health, int coord);
	~Spaceship();
	
	int get_name_ID();
	
	int get_damage();
	int get_score();

	void ability(player* &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health;
};


