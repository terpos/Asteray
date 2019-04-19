#include "Molten_shot.h"




Molten_shot::Molten_shot(int x, int y, int vel, int cid, bool shot)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);

}


Molten_shot::~Molten_shot()
{
}

int Molten_shot::get_x()
{
	return this->x;
}

int Molten_shot::get_y()
{
	return this->y;
}

int Molten_shot::get_vel()
{
	return this->vel;
}

int Molten_shot::get_coord_ID()
{
	return this->cid;
}

bool Molten_shot::isshot()
{
	return this->shot;
}

void Molten_shot::set_x(int x)
{
	this->x = x;
}

void Molten_shot::set_y(int y)
{
	this->y = y;
}

void Molten_shot::set_vel(int vel)
{
	this->vel = vel;
}

void Molten_shot::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Molten_shot::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Molten_shot::shootball()
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