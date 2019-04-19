#pragma once


#include "global.h"
#include "Animate.h"

class lazer
{
public:
	lazer(int x, int y);
	~lazer();

	
	void draw(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3);
	void shoot(bool okay);
	int getweaponx();
	int getweapony();
	bool getweaponlifetime();
	
	int get_damage();
	void set_damage(int damage);

	void setweaponx(int x);
	void setweapony(int y);
	void setweaponlifetime(bool &life);

private:
	Animate a;
	
	bool lazerlife;
	int lazerx;
	int lazery;
	int frame = 0;
	int vel;
	int damage;
};

