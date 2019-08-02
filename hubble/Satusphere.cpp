#include "Satusphere.h"



Satusphere::Satusphere(int x, int y, int vel, int health, int coord): enemies(x, y, vel, health, coord)
{
	
}

Satusphere::~Satusphere()
{
}

int Satusphere::get_name_ID()
{
	return SATUSPHERE;
}

int Satusphere::get_damage()
{
	return 30;
}

int Satusphere::get_score()
{
	return 300;
}

void Satusphere::gravity(player* & p)
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

void Satusphere::ability(player* & p, ALLEGRO_EVENT e)
{
	
}
