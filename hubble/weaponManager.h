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

	void load_weapon_img();
	void printout();
	
	void load_ammo(std::vector <Weapon*> &w, int ID, int x, int y, int lim);
	
	void update(std::vector <Weapon*> &w);

	void renderweapon(std::vector <Weapon*> &w, int ID, Status s, int ammo);
	void renderweaponinbox(int ID, Status s, int ammo);
	void destroy_ammo(std::vector <Weapon*> &w);

	
	void destroy_weapon_img();
	void select_keys(int keys, int p_or_s);

	int getweaponID();
	int geth(int ID);
	int getw(int ID);

private:
	ALLEGRO_BITMAP *shiplaser[3] = { NULL };
	ALLEGRO_BITMAP *inferred[2] = { NULL };
	ALLEGRO_BITMAP *icet[2] = { NULL };
	ALLEGRO_BITMAP *ziggonet = NULL;
	ALLEGRO_BITMAP *haych[2] = { NULL };
	ALLEGRO_BITMAP *haychba[2] = { NULL };
	ALLEGRO_BITMAP *sonic_wave = NULL;

	ALLEGRO_FONT *font;
};

