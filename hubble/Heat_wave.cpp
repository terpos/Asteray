#include "Heat_Wave.h"

Heat_Wave::Heat_Wave(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}

Heat_Wave::~Heat_Wave()
{
}

int Heat_Wave::get_x()
{
	return this->x;
}

int Heat_Wave::get_y()
{
	return this->y;
}

int Heat_Wave::get_vel()
{
	return this->vel;
}

int Heat_Wave::get_coord_ID()
{
	return this->cid;
}

bool Heat_Wave::isshot()
{
	return this->shot;
}

void Heat_Wave::set_x(int x)
{
	this->x = x;
}

void Heat_Wave::set_y(int y)
{
	this->y = y;
}

void Heat_Wave::set_vel(int vel)
{
	this->vel = vel;
}

void Heat_Wave::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Heat_Wave::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Heat_Wave::shootball()
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

