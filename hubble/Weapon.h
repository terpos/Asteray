/*
This class is a polymorphic class that uses virtual function.
All classes that inherit this class use the same function(s).
*/

#include "global.h"

#pragma once

class Weapon
{
public:
	//initial variable decleration
	Weapon(int x, int y);
	~Weapon();
	
	//sets whether weapon can shoot or not
	virtual void shoot(bool okay);

	//returns x coordinate
	virtual int getx();

	//returns y coordinate
	virtual int gety();

	//returns the effect of the weapon when collides
	//w/ enemy
	virtual int effect();

	//returns weapon's identity
	virtual int getweaponID() = 0;//ABSTRACT CLASS

	//returns amount of damage that the weapon
	//can cause to the enemy's health 
	virtual int get_damage();

	//sets amount of damage that the weapon
	//can cause to the enemy's health 
	virtual void set_damage(int damage);

	//renders weapon image to the screen
	virtual void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	virtual void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3);
	
	//sets x coordinate
	virtual void setx(int &x);

	//sets y coordinate
	virtual void sety(int &y);

private:
	//int variables
	int x, y, vel, frame, damage;

	//object variable
	Animate a;
};

