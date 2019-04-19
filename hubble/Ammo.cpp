#include "Ammo.h"



Ammo::Ammo()
{
}


Ammo::~Ammo()
{
}

int Ammo::get_ammo_ID()
{
	return this->ammoID;
}

int Ammo::get_x()
{
	return this->x;
}

int Ammo::get_y()
{
	return this->y;
}

void Ammo::set_ammo_ID(int ID)
{
	this->ammoID = ID;
}

void Ammo::set_x(int x)
{
	this->x = x;
}

void Ammo::set_y(int y)
{
	this->y = y;
}