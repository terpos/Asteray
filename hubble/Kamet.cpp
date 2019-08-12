#include "Kamet.h"

Kamet::Kamet(int x, int y, int vel, int cid) : Boss_weapon(x, y, vel, cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}

Kamet::~Kamet()
{
}

int Kamet::get_x()
{
	return this->x;
}

int Kamet::get_y()
{
	return this->y;
}

int Kamet::get_vel()
{
	return this->vel;
}

int Kamet::get_coord_ID()
{
	return this->cid;
}

bool Kamet::isshot()
{
	return this->shot;
}

int Kamet::get_kinds_of_weapon()
{
	return KAMET;
}

void Kamet::set_x(int x)
{
	this->x = x;
}

void Kamet::set_y(int y)
{
	this->y = y;
}

void Kamet::set_vel(int vel)
{
	this->vel = vel;
}

void Kamet::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Kamet::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Kamet::shootball()
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

