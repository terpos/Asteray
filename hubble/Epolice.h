#include "enemies.h"
#pragma once

class Epolice:public enemies
{
public:
	Epolice(int x, int y, int vel, int health, int coord);
	~Epolice();

	
	int get_name_ID();
	int get_damage();
	int get_score();

	void ability(player* &p, ALLEGRO_EVENT e);

	


private:
	int x, y, vel, CID, health;
	int probability_of_shooting;
	int delay;
};

