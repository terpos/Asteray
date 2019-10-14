#include "global.h"
#include "Status.h"

#include "Weapon.h"
#include "Icet.h"
#include "Inferred.h"
#include "Ziggonet.h"
#include "Haych.h"
#include "Haychba.h"
#include "Sonic_Wave.h"
#include "lazer.h"

#pragma once
class weaponManager
{
public:

	weaponManager();
	~weaponManager();

	//loads assets for weapon
	void load_weapon_img();

	//function not used
	void printout();
	
	//adds vector weapon depending on weapon identity
	void load_ammo(std::vector <Weapon*> &w, int ID, int x, int y, int lim);
	
	//updates the weapon coordinates and frames
	void update(std::vector <Weapon*> &w);

	//displays the weapon depending on type
	void renderweapon(std::vector <Weapon*> &w, int ID, Status s, int ammo);
	
	//displays secondary and primary weapon on the box
	void renderweaponinbox(int ID, Status s, int ammo[7]);

	//deletes the weapon vector when off screen or hits an enemy, boss, or miniboss
	void destroy_ammo(std::vector <Weapon*> &w);

	//deallocates assets
	void destroy_weapon_img();

	//function not used
	void select_keys(int keys, int p_or_s);

	//function not used
	int getweaponID();

	//returns the height of the sprite
	int geth(int ID);

	//returns the width of the sprite
	int getw(int ID);

private:

	//assets
	ALLEGRO_BITMAP *shiplaser[3] = { NULL };
	ALLEGRO_BITMAP *inferred[2] = { NULL };
	ALLEGRO_BITMAP *icet[2] = { NULL };
	ALLEGRO_BITMAP *ziggonet = NULL;
	ALLEGRO_BITMAP *haych[2] = { NULL };
	ALLEGRO_BITMAP *haychba[2] = { NULL };
	ALLEGRO_BITMAP *sonic_wave = NULL;

	ALLEGRO_FONT *font;
};

