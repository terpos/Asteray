#include "Satusphere.h"



Satusphere::Satusphere(int x, int y, int vel, int coord): enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}

Satusphere::~Satusphere()
{
}

int Satusphere::get_x()
{
	return this->x;
}

int Satusphere::get_y()
{
	return this->y;
}

int Satusphere::get_vel()
{
	return this->vel;
}

int Satusphere::get_coord_ID()
{
	return this->CID;
}

int Satusphere::get_name_ID()
{
	return SATUSPHERE;
}

int Satusphere::get_health()
{
	return this->health;
}

int Satusphere::get_damage()
{
	return 5;
}

void Satusphere::set_x(int x)
{
	this->x = x;
}

void Satusphere::set_y(int y)
{
	this->y = y;
}

void Satusphere::update()
{
	switch (get_coord_ID())
	{
	case UP:
		y--;
		//y = sin((20 * 3.14)*(y - 1));
		set_y(y);
		break;

	case DOWN:
		y++;
		//y = sin((20*3.14)*(y+1));
		set_y(y);
		break;

	case LEFT:
		x--;
		//x = sin((20 * 3.14)*(x + 1));
		set_x(x);
		break;

	case RIGHT:
		x++;
		set_x(x);
		break;
	}
}

void Satusphere::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Satusphere::set_health(int health)
{
	this->health = health;
}

void Satusphere::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Satusphere::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Satusphere::moveright()
{
	this->x++;
	set_x(this->x);
}

void Satusphere::moveup()
{
	this->y--;
	set_y(this->y);
}

void Satusphere::movedown()
{
	this->x++;
	set_y(this->y);
}

void Satusphere::ability(player & p, ALLEGRO_EVENT e)
{
}
