#pragma once
class Ammo
{
public:
	Ammo(int x, int y, int ID);
	~Ammo();

	int get_ammo_ID();
	int get_x();
	int get_y();

	void set_ammo_ID(int ID);
	void set_x(int x);
	void set_y(int y);

private:
	int ammoID;
	int x, y;
};

