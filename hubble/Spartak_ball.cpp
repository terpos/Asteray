#include "Spartak_ball.h"



Spartak_ball::Spartak_ball(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(false);
	set_reflect(false);

}


Spartak_ball::~Spartak_ball()
{
}

int Spartak_ball::get_x()
{
	return this->x;
}

int Spartak_ball::get_y()
{
	return this->y;
}

int Spartak_ball::get_vel()
{
	return this->vel;
}

int Spartak_ball::get_coord_ID()
{
	return this->cid;
}

bool Spartak_ball::isreflected()
{
	return this->reflected;
}


bool Spartak_ball::isshot()
{
	return this->shot;
}

void Spartak_ball::set_x(int x)
{
	this->x = x;
}

void Spartak_ball::set_y(int y)
{
	this->y = y;
}

void Spartak_ball::set_vel(int vel)
{
	this->vel = vel;
}

void Spartak_ball::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Spartak_ball::set_reflect(bool isreflected)
{
	this->reflected = isreflected;
}

void Spartak_ball::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Spartak_ball::shootball()
{
	if (get_coord_ID() == DOWN)
	{
		this->y+=get_vel();
		set_y(this->y);
	}
		
	if (get_coord_ID() == UP)
	{
		this->y-=get_vel();
		set_y(this->y);
	}

	if (get_coord_ID() == LEFT)
	{
		this->x-=get_vel();
		set_y(this->x);
	}

	if (get_coord_ID() == RIGHT)
	{
		this->x+=get_vel();
		set_y(this->x);
	}
}

void Spartak_ball::reflect()
{
	if (get_coord_ID() == DOWN)
	{
		this->y-=get_vel();
		set_y(this->y);
	}

	if (get_coord_ID() == UP)
	{
		this->y+=get_vel();
		set_y(this->y);
	}

	if (get_coord_ID() == LEFT)
	{
		this->x+=get_vel();
		set_y(this->x);
	}

	if (get_coord_ID() == RIGHT)
	{
		this->x-=get_vel();
		set_y(this->x);
	}
}

void Spartak_ball::update()
{
	if (isshot())
	{
		shootball();
	}

	

}


