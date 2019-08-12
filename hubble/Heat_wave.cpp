#include "Heat_Wave.h"

Heat_Wave::Heat_Wave(int x, int y, int vel, int cid) : Boss_weapon(x, y, vel, cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
	r = 0;
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

int Heat_Wave::get_r()
{
	return this->r;
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

int Heat_Wave::get_kinds_of_weapon()
{
	return HEAT;
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

void Heat_Wave::grow_heat(int x, int y)
{
	r += get_vel();

	set_x(x);
	set_y(y);
}



