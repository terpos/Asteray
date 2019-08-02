#include "enemies.h"
#pragma once
class Volcanon:public enemies
{
public:
	Volcanon(int x, int y, int vel, int health, int coord);
	~Volcanon();
	

	int get_name_ID();
	
	int get_damage();
	int get_score();

	int get_weaponx(int index);
	int get_weapony(int index);
	int get_weaponsize();

	void killweapon(int index);

	void shoot_probability();
	void load_ammo(int sing_twin);
	void update();

	void draw_E_weapon(ALLEGRO_BITMAP * bmp);

	void set_x(int x);
	void set_y(int y);


	void ability(player* &p, ALLEGRO_EVENT e);


private:
	int x, y, vel, CID, health, probability;
	std::vector <Enemy_Lazer*> l;
};
