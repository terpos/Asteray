#include "Wyrm.h"



Wyrm::Wyrm(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


Wyrm::~Wyrm()
{
}

int Wyrm::get_x()
{
	return this->x;
}

int Wyrm::get_y()
{
	return this->y;
}

int Wyrm::get_vel()
{
	return this->vel;
}

int Wyrm::get_coord_ID()
{
	return this->CID;
}

int Wyrm::get_name_ID()
{
	return WYRM;
}

int Wyrm::get_health()
{
	return this->health;
}

int Wyrm::get_damage()
{
	return 5;
}

int Wyrm::get_score()
{
	return 100;
}

void Wyrm::set_x(int x)
{
	this->x = x;
}

void Wyrm::set_y(int y)
{
	this->y = y;
}

void Wyrm::update()
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

void Wyrm::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Wyrm::set_health(int health)
{
	this->health = health;
}

void Wyrm::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Wyrm::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Wyrm::moveright()
{
	this->x++;
	set_x(this->x);
}

void Wyrm::moveup()
{
	this->y--;
	set_y(this->y);
}

void Wyrm::movedown()
{
	this->x++;
	set_y(this->y);
}

void Wyrm::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_movement(false);
	p->set_duration(100);
	p->set_ability_to_shoot(false);
}
