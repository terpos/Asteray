#include "Spaceship.h"



Spaceship::Spaceship(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Spaceship::~Spaceship()
{
}

int Spaceship::get_x()
{
	return this->x;
}

int Spaceship::get_y()
{
	return this->y;
}

int Spaceship::get_vel()
{
	return this->vel;
}

int Spaceship::get_coord_ID()
{
	return this->CID;
}

int Spaceship::get_name_ID()
{
	return SPACESHIP;
}

int Spaceship::get_health()
{
	return this->health;
}

int Spaceship::get_damage()
{
	return 5;
}

void Spaceship::set_x(int x)
{
	this->x = x;
}

void Spaceship::set_y(int y)
{
	this->y = y;
}

void Spaceship::update()
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

void Spaceship::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Spaceship::set_health(int health)
{
	this->health = health;
}

void Spaceship::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Spaceship::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Spaceship::moveright()
{
	this->x++;
	set_x(this->x);
}

void Spaceship::moveup()
{
	this->y--;
	set_y(this->y);
}

void Spaceship::movedown()
{
	this->x++;
	set_y(this->y);
}

void Spaceship::ability(player & p, ALLEGRO_EVENT e)
{
}
