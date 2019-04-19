#include "Spyder.h"



Spyder::Spyder(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Spyder::~Spyder()
{
}

int Spyder::get_x()
{
	return this->x;
}

int Spyder::get_y()
{
	return this->y;
}

int Spyder::get_vel()
{
	return this->vel;
}

int Spyder::get_coord_ID()
{
	return this->CID;
}

int Spyder::get_name_ID()
{
	return SPYDER;
}

int Spyder::get_health()
{
	return this->health;
}

int Spyder::get_damage()
{
	return 5;
}

void Spyder::set_x(int x)
{
	this->x = x;
}

void Spyder::set_y(int y)
{
	this->y = y;
}

void Spyder::update()
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

void Spyder::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Spyder::set_health(int health)
{
	this->health = health;
}

void Spyder::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Spyder::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Spyder::moveright()
{
	this->x++;
	set_x(this->x);
}

void Spyder::moveup()
{
	this->y--;
	set_y(this->y);
}

void Spyder::movedown()
{
	this->x++;
	set_y(this->y);
}

void Spyder::ability(player & p, ALLEGRO_EVENT e)
{
}
