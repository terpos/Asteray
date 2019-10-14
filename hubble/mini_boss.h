#include "global.h"
#include "Animate.h"
#pragma once



class mini_boss
{
public:
	//initialize and place miniboss in certain direction
	mini_boss(int x, int y, int flag, int minibossID);
	~mini_boss();

	//updates miniboss frames, coordinates, and health
	void update();
	
	//sets the identity of miniboss
	void set_miniboss(int minibossnum);

	//sets the x coordinate
	void set_x(int x);

	//sets the y coordinate
	void set_y(int y);

	//sets the flag
	void set_flag(int flag);
	
	//returns the identity of miniboss
	int get_miniboss();

	//returns x coordinate
	int get_x();
	
	//returns y coordinate
	int get_y();
	
	//functions not used
	int get_h(ALLEGRO_BITMAP *bmp);
	int get_w(ALLEGRO_BITMAP *bmp);
	
	//returns flag
	int get_flag();

private:
	//int variables
	int x, y, flag;
	int minibossnum;
	int frames;

	//object variable
	Animate a;
};

