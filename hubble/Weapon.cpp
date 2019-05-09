#include "Weapon.h"



Weapon::Weapon(int x, int y)
{
	setx(x);
	sety(y);
}


Weapon::~Weapon()
{
}

void Weapon::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

int Weapon::getx()
{
	return this->x;
}

int Weapon::gety()
{
	return this->y;
}

int Weapon::effect()
{
	return NULL;
}

int Weapon::get_damage()
{
	return this->damage;
}

void Weapon::set_damage(int damage)
{
	this->damage = damage;
}

void Weapon::draw(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}

void Weapon::draw(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3)
{
	a.three_frames_animate(bmp1, bmp2, bmp3, getx(), gety(), frame);
}

void Weapon::setx(int & x)
{
	this->x = x;
}

void Weapon::sety(int & y)
{
	this->y = y;
}
