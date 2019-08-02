#include "Asterix.h"



Asterix::Asterix(int x, int y, int vel, int health, int coord): enemies(x, y, vel, health, coord)
{
	
}

Asterix::~Asterix()
{
}

int Asterix::get_name_ID()
{
	return ASTERIX;
}

int Asterix::get_damage()
{
	return 20;
}

int Asterix::get_score()
{
	return 200;
}

void Asterix::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_duration(100);
	p->set_ability_to_shoot(false);
	
	
}
