#include "Animate.h"
#include "global.h"

#pragma once
class Haychba
{
public:
	Haychba(int x, int y);
	~Haychba();

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

