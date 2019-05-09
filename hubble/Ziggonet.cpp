#include "Ziggonet.h"



Ziggonet::Ziggonet(int x, int y) : Weapon(x, y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}


Ziggonet::~Ziggonet()
{
}

void Ziggonet::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Ziggonet::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Ziggonet::gety()
{
	return this->y;
}

int Ziggonet::effect()
{
	return STUNNED;
}

int Ziggonet::getweaponID()
{
	return ZIGGONET;
}

int Ziggonet::get_damage()
{
	return this->damage;
}

void Ziggonet::set_damage(int damage)
{
	this->damage = damage;
}

int Ziggonet::getx()
{
	return this->x;
}

void Ziggonet::setx(int &x)
{
	this->x = x;
}

void Ziggonet::sety(int &y)
{
	this->y = y;
}
