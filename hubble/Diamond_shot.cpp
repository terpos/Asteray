#include "Diamond_shot.h"



Diamond_shot::Diamond_shot(int x, int y, int vel, int cid): Boss_weapon(x, y, vel, cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(false);
}


Diamond_shot::~Diamond_shot()
{
}

int Diamond_shot::get_x()
{
	return this->x;
}

int Diamond_shot::get_y()
{
	return this->y;
}

int Diamond_shot::get_vel()
{
	return this->vel;
}

int Diamond_shot::get_coord_ID()
{
	return this->cid;
}

bool Diamond_shot::isshot()
{
	return this->shot;
}

int Diamond_shot::get_kinds_of_weapon()
{
	return DIAMONDS;
}

void Diamond_shot::set_x(int x)
{
	this->x = x;
}

void Diamond_shot::set_y(int y)
{
	this->y = y;
}

void Diamond_shot::set_vel(int vel)
{
	this->vel = vel;
}

void Diamond_shot::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Diamond_shot::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Diamond_shot::shootball()
{
	if (isshot())
	{
		if (get_coord_ID() == DOWN)
		{
			this->y += get_vel();
			set_y(this->y);
		}

		else if (get_coord_ID() == UP)
		{
			this->y -= get_vel();
			set_y(this->y);
		}

		else if (get_coord_ID() == LEFT)
		{
			this->x -= get_vel();
			set_x(this->x);
		}

		else if (get_coord_ID() == RIGHT)
		{
			this->x += get_vel();
			set_x(this->x);
		}

		else if (get_coord_ID() == UPLEFT)
		{
			this->x -= get_vel();
			this->y += get_vel();
			set_y(this->y);
			set_x(this->x);
		}

		else if (get_coord_ID() == UPRIGHT)
		{
			this->x += get_vel();
			this->y += get_vel();
			set_y(this->y);
			set_x(this->x);
		}

		else if (get_coord_ID() == DOWNLEFT)
		{
			this->x -= get_vel();
			this->y -= get_vel();
			set_y(this->y);
			set_x(this->x);
		}

		else if (get_coord_ID() == DOWNRIGHT)
		{
			this->x += get_vel();
			this->y -= get_vel();
			set_y(this->y);
			set_x(this->x);
		}
	}
}
