#include "Asterix.h"



Asterix::Asterix(int x, int y, int vel, int coord): enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);
	not_paralyze = true;
}

Asterix::~Asterix()
{
}

int Asterix::get_x()
{
	return this->x;
}

int Asterix::get_y()
{
	return this->y;
}

int Asterix::get_vel()
{
	return this->vel;
}

int Asterix::get_coord_ID()
{
	return this->CID;
}

int Asterix::get_name_ID()
{
	return ASTERIX;
}

int Asterix::get_health()
{
	return this->health;
}

int Asterix::get_damage()
{
	return 5;
}

int Asterix::get_score()
{
	return 200;
}

void Asterix::set_x(int x)
{
	this->x = x;
}

void Asterix::set_y(int y)
{
	this->y = y;
}

void Asterix::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Asterix::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Asterix::moveright()
{
	this->x++;
	set_x(this->x);
}

void Asterix::moveup()
{
	this->y--;
	set_y(this->y);
}

void Asterix::movedown()
{
	this->y++;
	set_y(this->y);
}

void Asterix::randomize_CID()
{
	this->CID = (this->CID * 2) % 4;
	set_coord_ID(this->CID);
}

void Asterix::set_health(int health)
{
	this->health = health;
}

void Asterix::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Asterix::setlife(bool life)
{
	this->life = life;
}

void Asterix::update()
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

void Asterix::ability(player* & p, ALLEGRO_EVENT e)
{
	p->set_duration(100);
	p->set_ability_to_shoot(false);
	
	
}
