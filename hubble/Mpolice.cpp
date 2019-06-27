#include "Mpolice.h"



Mpolice::Mpolice(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}

Mpolice::~Mpolice()
{
}

int Mpolice::get_x()
{
	return this->x;
}

int Mpolice::get_y()
{
	return this->y;
}

int Mpolice::get_vel()
{
	return this->vel;
}

int Mpolice::get_coord_ID()
{
	return this->CID;
}

int Mpolice::get_name_ID()
{
	return MPOLICE;
}

int Mpolice::get_health()
{
	return this->health;
}

int Mpolice::get_damage()
{
	return 5;
}

int Mpolice::get_score()
{
	return 100;
}

void Mpolice::set_x(int x)
{
	this->x = x;
}

void Mpolice::set_y(int y)
{
	this->y = y;
}

void Mpolice::update()
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

void Mpolice::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Mpolice::set_health(int health)
{
	this->health = health;
}

void Mpolice::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Mpolice::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Mpolice::moveright()
{
	this->x++;
	set_x(this->x);
}

void Mpolice::moveup()
{
	this->y--;
	set_y(this->y);
}

void Mpolice::movedown()
{
	this->x++;
	set_y(this->y);
}

void Mpolice::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_duration(100);
	p->set_special_condition(true);
}
