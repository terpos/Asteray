#include "Xybtofy.h"



Xybtofy::Xybtofy(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Xybtofy::~Xybtofy()
{
}

int Xybtofy::get_x()
{
	return this->x;
}

int Xybtofy::get_y()
{
	return this->y;
}

int Xybtofy::get_vel()
{
	return this->vel;
}

int Xybtofy::get_coord_ID()
{
	return this->CID;
}

int Xybtofy::get_name_ID()
{
	return WYRM;
}

int Xybtofy::get_health()
{
	return this->health;
}

int Xybtofy::get_damage()
{
	return 5;
}

void Xybtofy::set_x(int x)
{
	this->x = x;
}

void Xybtofy::set_y(int y)
{
	this->y = y;
}

void Xybtofy::update()
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

void Xybtofy::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Xybtofy::set_health(int health)
{
	this->health = health;
}

void Xybtofy::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Xybtofy::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Xybtofy::moveright()
{
	this->x++;
	set_x(this->x);
}

void Xybtofy::moveup()
{
	this->y--;
	set_y(this->y);
}

void Xybtofy::movedown()
{
	this->x++;
	set_y(this->y);
}

void Xybtofy::ability(player & p, ALLEGRO_EVENT e)
{
}
