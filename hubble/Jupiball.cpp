#include "Jupiball.h"



Jupiball::Jupiball(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Jupiball::~Jupiball()
{
}

int Jupiball::get_x()
{
	return this->x;
}

int Jupiball::get_y()
{
	return this->y;
}

int Jupiball::get_vel()
{
	return this->vel;
}

int Jupiball::get_coord_ID()
{
	return this->CID;
}

int Jupiball::get_name_ID()
{
	return JUPIBALL;
}

int Jupiball::get_health()
{
	return this->health;
}

int Jupiball::get_damage()
{
	return 5;
}

void Jupiball::set_x(int x)
{
	this->x = x;
}

void Jupiball::set_y(int y)
{
	this->y = y;
}

void Jupiball::update()
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

void Jupiball::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Jupiball::set_health(int health)
{
	this->health = health;
}

void Jupiball::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Jupiball::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Jupiball::moveright()
{
	this->x++;
	set_x(this->x);
}

void Jupiball::moveup()
{
	this->y--;
	set_y(this->y);
}

void Jupiball::movedown()
{
	this->x++;
	set_y(this->y);
}

void Jupiball::ability(player & p, ALLEGRO_EVENT e)
{
}
