#include "mini_boss.h"



mini_boss::mini_boss(int x, int y, int flag, int minibossID)
{
	//initial variable assignments
	frames = 0;

	//initial set variables
	set_x(x);
	set_y(y);
	set_flag(flag);
	set_miniboss(minibossID);
}


mini_boss::~mini_boss()
{
}

//sets the identity of miniboss
void mini_boss::set_miniboss(int minibossnum)
{
	this->minibossnum = minibossnum;
}

//sets x coordinate
void mini_boss::set_x(int x)
{
	this->x = x;
}

//sets y coordinate
void mini_boss::set_y(int y)
{
	this->y = y;
}

//sets flag
void mini_boss::set_flag(int flag)
{
	this->flag = flag;
}

//returns identity of miniboss
int mini_boss::get_miniboss()
{
	return this->minibossnum;
}

//returns x coordinate
int mini_boss::get_x()
{
	return this->x;
}

//returns y coordinate
int mini_boss::get_y()
{
	return this->y;
}

//returns height of the miniboss image
int mini_boss::get_h(ALLEGRO_BITMAP * bmp)
{
	return al_get_bitmap_height(bmp);
}

//returns width of the miniboss image
int mini_boss::get_w(ALLEGRO_BITMAP * bmp)
{
	return al_get_bitmap_width(bmp);
}

//returns flag
int mini_boss::get_flag()
{
	return this->flag;
}

//updates frames, x, & y coordinates
void mini_boss::update()
{
	frames++;
}

