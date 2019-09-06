#include "Haychba.h"



Haychba::Haychba(int x, int y) : Weapon(x, y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}


Haychba::~Haychba()
{
}

void Haychba::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Haychba::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Haychba::gety()
{
	return this->y;
}

int Haychba::effect()
{
	return STUNNED;
}

int Haychba::getweaponID()
{
	return HAYCHBA;
}

int Haychba::get_damage()
{
	return this->damage;
}

void Haychba::set_damage(int damage)
{
	this->damage = damage;
}

int Haychba::getx()
{
	return this->x;
}

void Haychba::setx(int &x)
{
	this->x = x;
}

void Haychba::sety(int &y)
{
	this->y = y;
}
