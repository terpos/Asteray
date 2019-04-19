#include "global.h"
#include "Animate.h"

#pragma once
class Icet
{
public:
	Icet(int x, int y);
	~Icet();

	void shoot(bool okay);
	int getx();
	int gety();
	int effect();

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

