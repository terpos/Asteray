#include "Volcanon.h"



Volcanon::Volcanon(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Volcanon::~Volcanon()
{
}

int Volcanon::get_x()
{
	return this->x;
}

int Volcanon::get_y()
{
	return this->y;
}

int Volcanon::get_vel()
{
	return this->vel;
}

int Volcanon::get_coord_ID()
{
	return this->CID;
}

int Volcanon::get_name_ID()
{
	return VOLCANON;
}

int Volcanon::get_health()
{
	return this->health;
}

int Volcanon::get_damage()
{
	return 5;
}

void Volcanon::set_x(int x)
{
	this->x = x;
}

void Volcanon::set_y(int y)
{
	this->y = y;
}

void Volcanon::update()
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

void Volcanon::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Volcanon::set_health(int health)
{
	this->health = health;
}

void Volcanon::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Volcanon::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Volcanon::moveright()
{
	this->x++;
	set_x(this->x);
}

void Volcanon::moveup()
{
	this->y--;
	set_y(this->y);
}

void Volcanon::movedown()
{
	this->x++;
	set_y(this->y);
}

void Volcanon::ability(player & p, ALLEGRO_EVENT e)
{
}
