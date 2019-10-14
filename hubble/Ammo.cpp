#include "Ammo.h"

//initial position and identity
Ammo::Ammo(int x, int y, int ID)
{
	set_x(x);
	set_y(y);
	set_ammo_ID(ID);
}


Ammo::~Ammo()
{
}

//returns ammo's identity
int Ammo::get_ammo_ID()
{
	return this->ammoID;
}

//returns x coordinate
int Ammo::get_x()
{
	return this->x;
}

//returns y coordinate
int Ammo::get_y()
{
	return this->y;
}

//sets ammo's identity
void Ammo::set_ammo_ID(int ID)
{
	this->ammoID = ID;
}

//sets x position
void Ammo::set_x(int x)
{
	this->x = x;
}

//sets y position
void Ammo::set_y(int y)
{
	this->y = y;
}