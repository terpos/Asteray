#include "Jupiball.h"



Jupiball::Jupiball(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	
}


Jupiball::~Jupiball()
{
}

int Jupiball::get_name_ID()
{
	return JUPIBALL;
}

int Jupiball::get_damage()
{
	return 25;
}

int Jupiball::get_score()
{
	return 250;
}

void Jupiball::gravity(player * p)
{
	p->set_vel(3);

	if (p->get_coords_ID() == DOWN)
	{
		p->set_y(p->get_y() + p->get_vel());
		p->set_keys(p->get_coords_ID(), true);
	}

	else if (p->get_coords_ID() == UP)
	{
		p->set_y(p->get_y() - p->get_vel());
		p->set_keys(p->get_coords_ID(), true);
	}

	else if (p->get_coords_ID() == LEFT)
	{
		p->set_y(p->get_x() - p->get_vel());
		p->set_keys(p->get_coords_ID(), true);
	}

	else if (p->get_coords_ID() == RIGHT)
	{
		p->set_y(p->get_x() + p->get_vel());
		p->set_keys(p->get_coords_ID(), true);
	}


}

void Jupiball::ability(player* & p, ALLEGRO_EVENT e)
{
}
