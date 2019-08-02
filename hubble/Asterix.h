#pragma once
#include "enemies.h"

class Asterix: public enemies
{
public:
	Asterix(int x, int y, int vel, int health, int coord);
	~Asterix();

	int get_name_ID();
	int get_damage();
	int get_score();

	void ability(player* &p, ALLEGRO_EVENT e);

private:
	int x, y, vel, CID, health;
	bool life;
	bool not_paralyze;
};

