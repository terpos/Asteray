#include "Spyder.h"



Spyder::Spyder(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Spyder::~Spyder()
{
}

int Spyder::get_name_ID()
{
	return SPYDER;
}

int Spyder::get_damage()
{
	return 5;
}

int Spyder::get_score()
{
	return 150;
}

void Spyder::weapon_ability(player *& p)
{
	p->set_movement(false);
	p->set_duration(100);
}

void Spyder::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_special_condition(true);
	p->set_duration(100);
	p->set_ability_to_shoot(false);
}
