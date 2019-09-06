#pragma once

#include "global.h"
#include <string>
#include <iostream>
#include <stdlib.h>

class Status
{
public:
	Status();
	~Status();

	int gethealth();
	int getmaxhealth();
	std::string getnotification();
	int getlvl();
	int getweapon();
	int getscore();

	void sethealth(int &health, ALLEGRO_FONT *font);
	void setmaxehealth(int maxhealth);
	void setnotification(std::string notification, ALLEGRO_FONT *font);
	void setnotification(std::string notification, ALLEGRO_FONT * font, int x, int y, ALLEGRO_COLOR c);
	void setnotification(std::string notification, ALLEGRO_FONT *font, int x, int y, int &frame);
	void setnotification(std::string notification, ALLEGRO_FONT *font, int x, int y);
	void setlvl(int lvl, ALLEGRO_FONT *font);
	void setweapon(int weapon);
	void setscore(int score, ALLEGRO_FONT *font);

	void setscore(int score, ALLEGRO_FONT * font, int x, int y);
	void setscore(int score, ALLEGRO_FONT * font, std::string sctype, int x, int y);


	void set_health_bar(int x, int y, int x2, int y2);
	void Status_box(int x, int y, int x2, int y2);
	void prime_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f);

	void secondary_Weapon_box(ALLEGRO_BITMAP * weapon, ALLEGRO_FONT * f, int ammo);

	void empty_Weapon_box(ALLEGRO_FONT * f, int ammo);

	void Notify(int kill_goal, int enemies_killed, std::string notification);
	void level_up(int num_of_enemies, int level);

	

private:
	int health;
	int maxhealth;
	int lvl;
	int weapon;
	int score;
	int damage;

	std::string notification;

	
};

