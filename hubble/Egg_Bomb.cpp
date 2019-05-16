#include "Egg_Bomb.h"



Egg_Bomb::Egg_Bomb(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}


Egg_Bomb::~Egg_Bomb()
{
}

int Egg_Bomb::get_x()
{
	return this->x;
}

int Egg_Bomb::get_y()
{
	return this->y;
}

int Egg_Bomb::get_vel()
{
	return this->vel;
}

int Egg_Bomb::get_coord_ID()
{
	return this->cid;
}

bool Egg_Bomb::isshot()
{
	return this->shot;
}

void Egg_Bomb::set_x(int x)
{
	this->x = x;
}

void Egg_Bomb::set_y(int y)
{
	this->y = y;
}

void Egg_Bomb::set_vel(int vel)
{
	this->vel = vel;
}

void Egg_Bomb::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Egg_Bomb::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Egg_Bomb::shootball()
{
	if (get_coord_ID() == DOWN)
	{
		this->y += get_vel();
		set_y(this->y);
	}

	if (get_coord_ID() == UP)
	{
		this->y -= get_vel();
		set_y(this->y);
	}

	if (get_coord_ID() == LEFT)
	{
		this->x -= get_vel();
		set_y(this->x);
	}

	if (get_coord_ID() == RIGHT)
	{
		this->x += get_vel();
		set_y(this->x);
	}
}
