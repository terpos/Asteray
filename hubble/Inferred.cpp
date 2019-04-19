#include "Inferred.h"



Inferred::Inferred(int x, int y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}


Inferred::~Inferred()
{
}

void Inferred::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Inferred::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Inferred::gety()
{
	return this->y;
}

int Inferred::effect()
{
	return BURNED;
}

int Inferred::get_damage()
{
	return this->damage;
}

void Inferred::set_damage(int damage)
{
	this->damage = damage;
}

int Inferred::getx()
{
	return this->x;
}

void Inferred::setx(int &x)
{
	this->x = x;
}

void Inferred::sety(int &y)
{
	this->y = y;
}
