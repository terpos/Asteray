#include "global.h"


#pragma once
class Weapon
{
public:
	Weapon(int x, int y);
	~Weapon();
	
	virtual void shoot(bool okay);
	virtual int getx();
	virtual int gety();
	virtual int effect();
	virtual int getweaponID() = 0;

	virtual int get_damage();
	virtual void set_damage(int damage);

	virtual void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	virtual void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3);
	virtual void setx(int &x);
	virtual void sety(int &y);

private:
	int x, y, vel, frame, damage;

	Animate a;
};

