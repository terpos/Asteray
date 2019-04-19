#include "global.h"
#include "Animate.h"
#pragma once



class mini_boss
{
public:
	mini_boss(int x, int y, int flag, int minibossID);
	~mini_boss();

	void update();
	
	void set_miniboss(int minibossnum);
	void set_x(int x);
	void set_y(int y);
	void set_flag(int flag);
	
	int get_miniboss();
	int get_x();
	int get_y();
	int get_h(ALLEGRO_BITMAP *bmp);
	int get_w(ALLEGRO_BITMAP *bmp);
	int get_flag();

private:
	int x, y, flag;

	Animate a;

	int minibossnum;
	int frames;
};

