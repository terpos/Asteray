#include "Spaceship.h"



Spaceship::Spaceship(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Spaceship::~Spaceship()
{
}

int Spaceship::get_name_ID()
{
	return SPACESHIP;
}

int Spaceship::get_damage()
{
	return 10;
}

int Spaceship::get_score()
{
	return 100;
}

void Spaceship::ability(player* & p, ALLEGRO_EVENT e)
{
}
