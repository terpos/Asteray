#include "enemies.h"
#pragma once
class Wyrm:public enemies
{
public:
	Wyrm(int x, int y, int vel, int health, int coord);
	~Wyrm();

	
	int get_name_ID();
	int get_damage();
	int get_score();

	void ability(player* &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health;
};
