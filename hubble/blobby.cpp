#include "blobby.h"

blobby::blobby(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
}


blobby::~blobby()
{
}

void blobby::update()
{
	switch (get_coord_ID())
	{
	case UP:
		y--;
		set_y(y);
		break;

	case DOWN:
		y++;
		set_y(y);
		break;

	case LEFT:
		x--;
		set_x(x);
		break;

	case RIGHT:
		x++;
		set_x(x);
		break;
	}
}

int blobby::get_x()
{
	return this->x;
}

int blobby::get_y()
{
	return this->y;
}

int blobby::get_vel()
{
	return this->vel;
}

int blobby::get_health()
{
	return this->health;
}

int blobby::get_name_ID()
{
	return BLOBBY;
}

int blobby::get_damage()
{
	return 5;
}

int blobby::get_coord_ID()
{
	return this->CID;
}

int blobby::get_score()
{
	return 150;
}



void blobby::set_x(int x)
{
	this->x = x;
}

void blobby::set_y(int y)
{
	this->y = y;
}

void blobby::set_vel(int vel)
{
	this->vel = vel;
}

void blobby::set_health(int health)
{
	this->health = health;
}

void blobby::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void blobby::set_coord_ID(int CID)
{
	this->CID = CID;
}

void blobby::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_movement(false);
	p->set_duration(100);
}

void blobby::moveleft()
{
	this->x--;
	set_x(this->x);
}

void blobby::moveright()
{
	this->x++;
	set_x(this->x);
}

void blobby::moveup()
{
	this->y--;
	set_y(this->y);
}

void blobby::movedown()
{
	this->x++;
	set_y(this->y);
}
