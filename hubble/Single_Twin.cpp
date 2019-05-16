#include "Single_Twin.h"

Single_Twin::Single_Twin(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}

Single_Twin::~Single_Twin()
{
}

int Single_Twin::get_x()
{
	return this->x;
}

int Single_Twin::get_y()
{
	return this->y;
}

int Single_Twin::get_vel()
{
	return this->vel;
}

int Single_Twin::get_coord_ID()
{
	return this->cid;
}

bool Single_Twin::isshot()
{
	return this->shot;
}

void Single_Twin::set_x(int x)
{
	this->x = x;
}

void Single_Twin::set_y(int y)
{
	this->y = y;
}

void Single_Twin::set_vel(int vel)
{
	this->vel = vel;
}

void Single_Twin::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Single_Twin::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Single_Twin::shootball()
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

