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

	//returns the player's health
	int gethealth();

	//returns player's max health (not used)
	int getmaxhealth();

	//returns the notification of new weapon
	std::string getnotification();

	//returns the level
	int getlvl();

	//returns kinds of weapon
	int getweapon();

	//returns the score
	int getscore();

	//sets player's health
	void sethealth(int &health, ALLEGRO_FONT *font);

	//sets player's max health (not used)
	void setmaxehealth(int maxhealth);

	//sets notifications
	void setnotification(std::string notification, ALLEGRO_FONT *font);
	void setnotification(std::string notification, ALLEGRO_FONT * font, int x, int y, ALLEGRO_COLOR c);
	void setnotification(std::string notification, ALLEGRO_FONT *font, int x, int y, int &frame);
	void setnotification(std::string notification, ALLEGRO_FONT *font, int x, int y);

	//sets levels
	void setlvl(int lvl, ALLEGRO_FONT *font);

	//sets kinds of weapon
	void setweapon(int weapon);

	//sets scores
	void setscore(int score, ALLEGRO_FONT *font);
	void setscore(int score, ALLEGRO_FONT * font, int x, int y);
	void setscore(int score, ALLEGRO_FONT * font, std::string sctype, int x, int y);

	//sets the geometry of health bar
	void set_health_bar(int x, int y, int x2, int y2);

	//sets the rectangle of status box
	void Status_box(int x, int y, int x2, int y2);

	//displays primary weapon
	void prime_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f);

	//displays secondary weapon
	void secondary_Weapon_box(ALLEGRO_BITMAP * weapon, ALLEGRO_FONT * f, int ammo);

	//shows that there is no empty weapon
	void empty_Weapon_box(ALLEGRO_FONT * f, int ammo);

	//notifies the player of how many enemies killed (not used)
	void Notify(int kill_goal, int enemies_killed, std::string notification);
	
	//levels up along with increase of enemies (not used)
	void level_up(int num_of_enemies, int level);

	

private:
	//int variables for status
	int health;
	int maxhealth;
	int lvl;
	int weapon;
	int score;
	int damage;

	//string variables for status
	std::string notification;

	
};

