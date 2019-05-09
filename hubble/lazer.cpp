#include "lazer.h"

lazer::lazer(int x, int y) : Weapon(x, y)
{
	setx(x);
	sety(y);
	frame = 0;
	vel = 10;
}

lazer::~lazer()
{
	
}

void lazer::shoot(bool okay)
{
	y -= vel*okay;
	frame++;
}

void lazer::draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3)
{
	a.three_frames_animate(bmp1, bmp2, bmp3, getx(), gety(), frame);
}

int lazer::gety()
{
	return this->y;
}

int lazer::getweaponID()
{
	return LAZER;
}

int lazer::getx()
{
	return this->x;
}

void lazer::setx(int x)
{
	this->x = x;
}

void lazer::sety(int y)
{
	this->y = y;
}

int lazer::get_damage()
{
	return this->damage;
}

void lazer::set_damage(int damage)
{
	this->damage = damage;
}
