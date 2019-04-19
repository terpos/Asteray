#include "Icet.h"



Icet::Icet(int x, int y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}


Icet::~Icet()
{
}

void Icet::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Icet::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Icet::gety()
{
	return this->y;
}

int Icet::effect()
{
	return FROZEN;
}

int Icet::get_damage()
{
	return this->damage;
}

void Icet::set_damage(int damage)
{
	this->damage = damage;
}

int Icet::getx()
{
	return this->x;
}

void Icet::setx(int &x)
{
	this->x = x;
}

void Icet::sety(int &y)
{
	this->y = y;
}
