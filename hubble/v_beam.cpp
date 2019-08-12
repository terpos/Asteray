#include "v_beam.h"



v_beam::v_beam(int x, int y, int vel, int cid, bool shoot) : Boss_weapon(x, y, vel, cid)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	this->cid = cid;
	this->shot = shoot;

	set_x(this->x);
	set_y(this->y);
	set_vel(this->vel);
	set_coord_ID(this->cid);
	set_shot(this->shot);
}

v_beam::~v_beam()
{
}

int v_beam::get_x()
{
	return this->x;
}

int v_beam::get_y()
{
	return this->y;
}

int v_beam::get_vel()
{
	return this->vel;
}

int v_beam::get_coord_ID()
{
	return this->cid;
}

bool v_beam::isshot()
{
	return this->shot;
}

int v_beam::get_kinds_of_weapon()
{
	return V;
}

void v_beam::set_x(int x)
{
	this->x = x;
}

void v_beam::set_y(int y)
{
	this->x = x;
}

void v_beam::set_vel(int vel)
{
	this->vel = vel;
}

void v_beam::set_coord_ID(int cid)
{
	this->cid = cid;
}

void v_beam::set_shot(bool isshot)
{
	this->shot = isshot;
}

void v_beam::shootball()
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
