#include "global.h"

#pragma once
class Heat_Wave
{
public:
	Heat_Wave(int x, int y, int vel, int cid);
	~Heat_Wave();

	int get_x();
	int get_y();
	int get_r();
	int get_vel();
	int get_coord_ID();
	bool isshot();

	void set_x(int x);
	void set_y(int y);
	void set_vel(int vel);
	void set_coord_ID(int cid);
	void set_shot(bool isshot);

	void grow_heat(int x, int y);

private:
	int x, y, r, vel, cid;
	bool reflected, shot;

};

