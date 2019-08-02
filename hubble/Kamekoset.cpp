#include "Kamekoset.h"



Kamekoset::Kamekoset(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Kamekoset::~Kamekoset()
{
}



int Kamekoset::get_name_ID()
{
	return KAMEKOSET;
}

int Kamekoset::get_damage()
{
	return 5;
}

int Kamekoset::get_score()
{
	return 50;
}

void Kamekoset::ability(player* &p, ALLEGRO_EVENT e)
{
	
}
