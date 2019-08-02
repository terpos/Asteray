#include "Epolice.h"



Epolice::Epolice(int x, int y, int vel, int health, int coord): enemies(x, y, vel, health, coord)
{
	
}


Epolice::~Epolice()
{
}



int Epolice::get_name_ID()
{
	return EPOLICE;
}



int Epolice::get_damage()
{
	return 10;
}

int Epolice::get_score()
{
	return 100;
}

void Epolice::ability(player* & p, ALLEGRO_EVENT e)
{
}



