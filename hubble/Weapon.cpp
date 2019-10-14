#include "Weapon.h"


//initial variable assignment
Weapon::Weapon(int x, int y)
{
	setx(x);
	sety(y);
}


Weapon::~Weapon()
{
}

//sets whether weapon can shoot or not
void Weapon::shoot(bool okay)
{
	y -= vel * okay;
	frame++;
}

//gets x coordinate
int Weapon::getx()
{
	return this->x;
}

//gets y coordinate
int Weapon::gety()
{
	return this->y;
}

//gets the effect of the weapon when collides
//w/ enemy
int Weapon::effect()
{
	return NULL;
}

//gets amount of damage that the weapon
//can cause to the enemy's health 
int Weapon::get_damage()
{
	return this->damage;
}

//sets amount of damage that the weapon
//can cause to the enemy's health 
void Weapon::set_damage(int damage)
{
	this->damage = damage;
}

//renders and animate weapon image to the screen
void Weapon::draw(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2)
{
	a.two_frames_custom(bmp1, bmp2, getx(), gety(), frame, 13, 0, 6);
}
void Weapon::draw(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3)
{
	a.three_frames_animate(bmp1, bmp2, bmp3, getx(), gety(), frame);
}

//sets x coordinate
void Weapon::setx(int & x)
{
	this->x = x;
}

//sets y coordinate
void Weapon::sety(int & y)
{
	this->y = y;
}
