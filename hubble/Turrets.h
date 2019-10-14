#include "global.h"
#include "Enemy_Lazer.h"
#include "Animate.h"

#pragma once

class Turrets
{
public:
	//initializes coords, health, and delay 
	Turrets(int x, int y, int health, int delay);
	~Turrets();

	//returns x coordinates
	int get_x();
	
	//returns y coordinates
	int get_y();

	//returns x coordinates of weapon
	int get_weaponx(int index);
	
	//returns y coordinates of weapon
	int get_weapony(int index);
	
	//returns health of turrets
	int get_health();

	//return delays of turrets if it shoots
	int get_delay();
	
	//return the value of whether the turret is hit by the player or not
	bool is_hit();

	//returns vector size of weapon
	int weapon_size();

	//sets x coordinates
	void set_x(int x);

	//sets y coordinates
	void set_y(int y);

	//sets health
	void set_health(int health);

	//sets delay if turret shoots
	void set_delay(int delay);

	//sets hit 
	void set_hit(bool hit);

	//if weapon goes out of screen, vector is deleted
	void killweapon(int index);

	//counts down delay until it reaches zero
	void decrement_delay();

	//if the turret got shot, its health decrease
	void decrement_health();

	//randomizes its ability to shoot
	void probability_shooting();

	//loads the weapon
	void load_ammo(int x, int y);

	//updates the coordinates, frames, and weapon movement
	void update(int x, int y);

	//displays turrets and turrets when damaged
	void render(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);

	//renders weapon
	void renderweapon(ALLEGRO_BITMAP* bmp);

private:
	//int variables
	int x, y, health, delay, shooting_probability;
	
	//bool variables
	bool hit;

	//object vector
	std::vector <Enemy_Lazer *> l;
	
	//object variable
	Animate a;
};

