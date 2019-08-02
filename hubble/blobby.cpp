#include "blobby.h"

blobby::blobby(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


blobby::~blobby()
{
}

int blobby::get_name_ID()
{
	return BLOBBY;
}

int blobby::get_damage()
{
	return 15;
}

int blobby::get_score()
{
	return 150;
}

void blobby::weapon_ability(player *& p)
{
	p->set_special_condition(true);
	p->set_duration(100);
}

void blobby::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_movement(false);
	p->set_duration(100);
}

