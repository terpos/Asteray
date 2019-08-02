#include "Wyrm.h"



Wyrm::Wyrm(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Wyrm::~Wyrm()
{
}

int Wyrm::get_name_ID()
{
	return WYRM;
}

int Wyrm::get_damage()
{
	return 10;
}

int Wyrm::get_score()
{
	return 100;
}

void Wyrm::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_movement(false);
	p->set_special_condition(true);
	p->set_duration(100);
	p->set_ability_to_shoot(false);
}
