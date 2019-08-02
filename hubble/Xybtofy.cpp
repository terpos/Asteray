#include "Xybtofy.h"



Xybtofy::Xybtofy(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Xybtofy::~Xybtofy()
{
}

int Xybtofy::get_name_ID()
{
	return XYBTOFY;
}



int Xybtofy::get_damage()
{
	return 5;
}

int Xybtofy::get_score()
{
	return 50;
}

void Xybtofy::ability(player* & p, ALLEGRO_EVENT e)
{
}
