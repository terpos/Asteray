#include "Haych.h"



Haych::Haych(int x, int y): Weapon(x, y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}


Haych::~Haych()
{
}

void Haych::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Haych::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Haych::gety()
{
	return this->y;
}

int Haych::getweaponID()
{
	return HAYCH;
}

int Haych::effect()
{
	return (rand()%3)+3;
}

int Haych::get_damage()
{
	return this->damage;
}

void Haych::set_damage(int damage)
{
	this->damage = damage;
}

int Haych::getx()
{
	return this->x;
}

void Haych::setx(int &x)
{
	this->x = x;
}

void Haych::sety(int &y)
{
	this->y = y;
}
