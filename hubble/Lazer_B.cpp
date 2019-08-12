#include "Lazer_B.h"



Lazer_B::Lazer_B(int x, int y, int vel, int cid) : Boss_weapon(x, y, vel, cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(shot);
}


Lazer_B::~Lazer_B()
{
}

int Lazer_B::get_x()
{
	return this->x;
}

int Lazer_B::get_y()
{
	return this->y;
}

int Lazer_B::get_vel()
{
	return this->vel;
}

int Lazer_B::get_coord_ID()
{
	return this->cid;
}

bool Lazer_B::isshot()
{
	return this->shot;
}

int Lazer_B::get_kinds_of_weapon()
{
	return B_LAZER;
}

void Lazer_B::set_x(int x)
{
	this->x = x;
}

void Lazer_B::set_y(int y)
{
	this->y = y;
}

void Lazer_B::set_vel(int vel)
{
	this->vel = vel;
}

void Lazer_B::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Lazer_B::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Lazer_B::shootball()
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

