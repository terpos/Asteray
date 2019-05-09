#include "Weapon.h"

#pragma once

class Inferred: public Weapon
{
public:
	Inferred(int x, int y);
	~Inferred();


	void shoot(bool okay);
	int getx();
	int gety();
	int effect();
	int getweaponID();

	int get_damage();
	void set_damage(int damage);

	void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	void setx(int &x);
	void sety(int &y);

private:
	int x, y;
	int vel;
	int frame;
	int damage;

	Animate a;
};

