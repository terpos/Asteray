#include "Sonic_Turbulence.h"



Sonic_Turbulence::Sonic_Turbulence(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}


Sonic_Turbulence::~Sonic_Turbulence()
{
}

int Sonic_Turbulence::get_x()
{
	return this->x;
}

int Sonic_Turbulence::get_y()
{
	return this->y;
}

int Sonic_Turbulence::get_vel()
{
	return this->vel;
}

int Sonic_Turbulence::get_coord_ID()
{
	return this->cid;
}

bool Sonic_Turbulence::isshot()
{
	return this->shot;
}

void Sonic_Turbulence::set_x(int x)
{
	this->x = x;
}

void Sonic_Turbulence::set_y(int y)
{
	this->y = y;
}

void Sonic_Turbulence::set_vel(int vel)
{
	this->vel = vel;
}

void Sonic_Turbulence::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Sonic_Turbulence::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Sonic_Turbulence::shootball()
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

