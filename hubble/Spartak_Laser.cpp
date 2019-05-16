#include "Spartak_Laser.h"



Spartak_Laser::Spartak_Laser(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(false);
}


Spartak_Laser::~Spartak_Laser()
{
}

int Spartak_Laser::get_x()
{
	return this->x;
}

int Spartak_Laser::get_y()
{
	return this->y;
}

int Spartak_Laser::get_vel()
{
	return this->vel;
}

int Spartak_Laser::get_coord_ID()
{
	return this->cid;
}

bool Spartak_Laser::isshot()
{
	return this->shot;
}

void Spartak_Laser::set_x(int x)
{
	this->x = x;
}

void Spartak_Laser::set_y(int y)
{
	this->y = y;
}

void Spartak_Laser::set_vel(int vel)
{
	this->vel = vel;
}

void Spartak_Laser::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Spartak_Laser::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Spartak_Laser::shootball()
{
	if (isshot())
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
			set_x(this->x);
		}

		if (get_coord_ID() == RIGHT)
		{
			this->x += get_vel();
			set_x(this->x);
		}
	}
}
