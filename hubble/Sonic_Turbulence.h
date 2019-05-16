#include "global.h"

#pragma once
class Sonic_Turbulence
{
public:
	Sonic_Turbulence(int x, int y, int vel, int cid);
	~Sonic_Turbulence();

	int get_x();
	int get_y();
	int get_vel();
	int get_coord_ID();
	bool isshot();

	void set_x(int x);
	void set_y(int y);
	void set_vel(int vel);
	void set_coord_ID(int cid);
	void set_shot(bool isshot);

	void shootball();

private:
	int x, y, vel, cid;
	bool reflected, shot;

};

