#include "enemies.h"

#pragma once
class Spyder:public enemies
{
public:
	Spyder(int x, int y, int vel, int health, int coord);
	~Spyder();
	
	int get_name_ID();
	
	int get_damage();
	int get_score();
	void weapon_ability(player * &p);

	void ability(player* &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health;
};
