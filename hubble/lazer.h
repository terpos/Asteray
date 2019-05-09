#include "Weapon.h"

#pragma once

class lazer: public Weapon
{
public:
	lazer(int x, int y);
	~lazer();

	
	void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3);
	void shoot(bool okay);
	int getx();
	int gety();
	int getweaponID();
	
	int get_damage();
	void set_damage(int damage);

	void setx(int x);
	void sety(int y);

private:
	Animate a;
	
	int x;
	int y;
	int frame = 0;
	int vel;
	int damage;
};

