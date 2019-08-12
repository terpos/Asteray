#include "global.h"
#include "Boss_weapon.h"

#pragma once
class Lazer_B: public Boss_weapon
{
public:
	Lazer_B(int x, int y, int vel, int cid);
	~Lazer_B();

	int get_x();
	int get_y();
	int get_vel();
	int get_coord_ID();
	bool isshot();
	int get_kinds_of_weapon();


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

