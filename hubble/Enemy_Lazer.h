#include "global.h"

#pragma once
class Enemy_Lazer
{
public:
	//initial variable declaration
	Enemy_Lazer(int x, int y, int vel, int cid);
	~Enemy_Lazer();

	//returns x coordinate
	int get_x();

	//returns y coordinate
	int get_y();

	//returns speed
	int get_vel();

	//returns direction
	int get_coord_ID();

	//returns whether the weapon
	//is shot or not
	bool isshot();

	//sets x coordinate
	void set_x(int x);

	//sets y coordinate
	void set_y(int y);

	//sets speed
	void set_vel(int vel);

	//sets direction
	void set_coord_ID(int cid);

	//sets wether the weapon will
	//be shot or not
	void set_shot(bool isshot);

	//updates weapon coordinates
	void shoot();

	//displays images to the screen
	void render_shot(ALLEGRO_BITMAP *bmp, int x, int y);


private:
	//int variables
	int x, y, vel, cid;
	
	//boolean variable
	bool shot;
};

