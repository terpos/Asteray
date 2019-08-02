#include "enemies.h"
#pragma once
class Kamekoset: public enemies
{
public:
	Kamekoset(int x, int y, int vel, int health, int coord);
	~Kamekoset();

	int get_name_ID();
	int get_damage();
	int get_score();

	void ability(player* &p, ALLEGRO_EVENT e);

private:
	int x, y, vel, CID, health;
};
