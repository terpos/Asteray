#include "Epolice.h"



Epolice::Epolice(int x, int y, int vel, int coord): enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Epolice::~Epolice()
{
}

int Epolice::get_x()
{
	return this->x;
}

int Epolice::get_y()
{
	return this->y;
}

int Epolice::get_vel()
{
	return this->vel;
}

int Epolice::get_coord_ID()
{
	return this->CID;
}

int Epolice::get_name_ID()
{
	return EPOLICE;
}

int Epolice::get_health()
{
	return this->health;
}

int Epolice::get_damage()
{
	return 5;
}

void Epolice::set_x(int x)
{
	this->x = x;
}

void Epolice::set_y(int y)
{
	this->y = y;
}

void Epolice::update()
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

void Epolice::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Epolice::set_health(int health)
{
	this->health = health;
}

void Epolice::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Epolice::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Epolice::moveright()
{
	this->x++;
	set_x(this->x);
}

void Epolice::moveup()
{
	this->y--;
	set_y(this->y);
}

void Epolice::movedown()
{
	this->x++;
	set_y(this->y);
}

void Epolice::ability(player & p, ALLEGRO_EVENT e)
{
}
