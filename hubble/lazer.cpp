#include "lazer.h"

lazer::lazer(int x, int y)
{
	setweaponx(x);
	setweapony(y);
	lazerlife = false;
	vel = 10;
}

lazer::~lazer()
{
	
}

void lazer::shoot(bool okay)
{
	lazery -= vel*okay;
	frame++;
}

void lazer::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3)
{
	a.three_frames_animate(bmp1, bmp2, bmp3, getweaponx(), getweapony(), frame);
}

int lazer::getweapony()
{
	return this->lazery;
}

int lazer::getweaponx()
{
	return this->lazerx;
}

void lazer::setweaponx(int x)
{
	this->lazerx = x;
}

void lazer::setweapony(int y)
{
	this->lazery = y;
}

void lazer::setweaponlifetime(bool &life)
{
	lazerlife = life;
}

bool lazer::getweaponlifetime()
{
	return lazerlife;
}

int lazer::get_damage()
{
	return this->damage;
}

void lazer::set_damage(int damage)
{
	this->damage = damage;
}
