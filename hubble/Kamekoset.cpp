#include "Kamekoset.h"



Kamekoset::Kamekoset(int x, int y, int vel, int coord) : enemies(x, y, vel, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_coord_ID(coord);

}


Kamekoset::~Kamekoset()
{
}

int Kamekoset::get_x()
{
	return this->x;
}

int Kamekoset::get_y()
{
	return this->y;
}

int Kamekoset::get_vel()
{
	return this->vel;
}

int Kamekoset::get_coord_ID()
{
	return this->CID;
}

int Kamekoset::get_name_ID()
{
	return KAMEKOSET;
}

int Kamekoset::get_health()
{
	return this->health;
}

int Kamekoset::get_damage()
{
	return 5;
}

int Kamekoset::get_score()
{
	return 50;
}

void Kamekoset::set_x(int x)
{
	this->x = x;
}

void Kamekoset::set_y(int y)
{
	this->y = y;
}

void Kamekoset::update()
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

void Kamekoset::set_coord_ID(int CID)
{
	this->CID = CID;
}

void Kamekoset::set_health(int health)
{
	this->health = health;
}

void Kamekoset::decrement_health(int damage)
{
	this->health = this->health - damage;
	set_health(this->health);
}

void Kamekoset::moveleft()
{
	this->x--;
	set_x(this->x);
}

void Kamekoset::moveright()
{
	this->x++;
	set_x(this->x);
}

void Kamekoset::moveup()
{
	this->y--;
	set_y(this->y);
}

void Kamekoset::movedown()
{
	this->x++;
	set_y(this->y);
}

void Kamekoset::ability(player* &p, ALLEGRO_EVENT e)
{
	
}

void Kamekoset::draw(ALLEGRO_BITMAP * bmp)
{
	al_draw_bitmap(bmp, get_x(), get_y(), NULL);
}