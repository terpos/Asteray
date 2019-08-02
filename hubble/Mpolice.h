#include "enemies.h"
#pragma once
class Mpolice: public enemies
{
public:
	Mpolice(int x, int y, int vel, int health, int coord);
	~Mpolice();
	
	int get_name_ID();
	int get_damage();
	int get_score();

	void weapon_ability(player *& p);

	void ability(player* &p, ALLEGRO_EVENT e);

private:
	int x, y, vel, CID, health;
};

