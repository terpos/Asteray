#include "global.h"
#include "Enemy_Lazer.h"
#include "Animate.h"

#pragma once

class Turrets
{
public:
	Turrets(int x, int y, int health, int delay);
	~Turrets();

	int get_x();
	int get_y();
	int get_weaponx(int index);
	int get_weapony(int index);
	int get_health();
	int get_delay();
	bool is_hit();
	int weapon_size();

	void set_x(int x);
	void set_y(int y);
	void set_health(int health);
	void set_delay(int delay);
	void set_hit(bool hit);
	void killweapon(int index);

	void decrement_delay();
	void decrement_health();
	void probability_shooting();
	void load_ammo(int x, int y);

	void update(int x, int y);

	void render(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	void renderweapon(ALLEGRO_BITMAP* bmp);

private:
	int x, y, health, delay, shooting_probability;
	bool hit;
	std::vector <Enemy_Lazer *> l;
	Animate a;
};

