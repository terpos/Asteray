#include "mini_boss.h"



mini_boss::mini_boss(int x, int y, int flag, int minibossID)
{
	frames = 0;
	set_x(x);
	set_y(y);
	set_flag(flag);
	set_miniboss(minibossID);
}


mini_boss::~mini_boss()
{
}


void mini_boss::set_miniboss(int minibossnum)
{
	this->minibossnum = minibossnum;
}

void mini_boss::set_x(int x)
{
	this->x = x;
}

void mini_boss::set_y(int y)
{
	this->y = y;
}

void mini_boss::set_flag(int flag)
{
	this->flag = flag;
}

int mini_boss::get_miniboss()
{
	return this->minibossnum;
}

int mini_boss::get_x()
{
	return this->x;
}

int mini_boss::get_y()
{
	return this->y;
}

int mini_boss::get_h(ALLEGRO_BITMAP * bmp)
{
	return al_get_bitmap_height(bmp);
}

int mini_boss::get_w(ALLEGRO_BITMAP * bmp)
{
	return al_get_bitmap_width(bmp);
}

int mini_boss::get_flag()
{
	return this->flag;
}

void mini_boss::update()
{
	frames++;
}

