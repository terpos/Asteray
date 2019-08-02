#include "Mpolice.h"



Mpolice::Mpolice(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}

Mpolice::~Mpolice()
{
}

int Mpolice::get_name_ID()
{
	return MPOLICE;
}

int Mpolice::get_damage()
{
	return 10;
}

int Mpolice::get_score()
{
	return 100;
}

void Mpolice::weapon_ability(player *& p)
{
	p->set_special_condition(true);
	p->set_duration(100);
}

void Mpolice::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_duration(100);
	p->set_special_condition(true);
}
