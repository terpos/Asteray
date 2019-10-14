#include "global.h"
#pragma once
class Ammo
{
public:
	//initial position and identity
	Ammo(int x, int y, int ID);
	~Ammo();

	//returns ammo's identity
	int get_ammo_ID();

	//return x coordinate
	int get_x();
	
	//return y coordinate
	int get_y();

	//sets the ammo's identity
	void set_ammo_ID(int ID);
	
	//sets x position
	void set_x(int x);

	//sets y position
	void set_y(int y);

private:
	//int variables
	int ammoID;
	int x, y;
};

