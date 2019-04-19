#include "Sonic_Wave.h"

Sonic_Wave::Sonic_Wave(int x, int y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}

Sonic_Wave::~Sonic_Wave()
{
}

void Sonic_Wave::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Sonic_Wave::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Sonic_Wave::gety()
{
	return this->y;
}

int Sonic_Wave::effect()
{
	return STUNNED;
}

int Sonic_Wave::get_damage()
{
	return this->damage;
}

void Sonic_Wave::set_damage(int damage)
{
	this->damage = damage;
}

int Sonic_Wave::getx()
{
	return this->x;
}

void Sonic_Wave::setx(int &x)
{
	this->x = x;
}

void Sonic_Wave::sety(int &y)
{
	this->y = y;
}
