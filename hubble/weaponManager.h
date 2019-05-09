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
	/*void load_ammo(std::vector <lazer*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Icet*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Inferred*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Ziggonet*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Haych*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Haychba*> &laser, int x, int y, int lim);
	void load_ammo(std::vector <Sonic_Wave*> &laser, int x, int y, int lim);*/


	void update(std::vector <Weapon*> &w);

	void renderweapon(std::vector <Weapon*> &w, int ID, Status s, int ammo);
	void renderweaponinbox(int ID, Status s, int ammo);
	void destroy_ammo(std::vector <Weapon*> &w);

	/*void update(std::vector <lazer*> &laser);
	void update(std::vector <Icet*> &laser);
	void update(std::vector <Inferred*> &laser);
	void update(std::vector <Ziggonet*> &laser);
	void update(std::vector <Haych*> &laser);
	void update(std::vector <Haychba*> &laser);
	void update(std::vector <Sonic_Wave*> &laser);
	
	void renderweapon(std::vector <lazer*> &laser, Status s);
	void renderweapon(std::vector <Icet*> &laser, Status s, int ammo);
	void renderweapon(std::vector <Inferred*> &laser, Status s, int ammo);
	void renderweapon(std::vector <Ziggonet*> &laser, Status s, int ammo);
	void renderweapon(std::vector <Haych*> &laser, Status s, int ammo);
	void renderweapon(std::vector <Haychba*> &laser, Status s, int ammo);
	void renderweapon(std::vector <Sonic_Wave*> &laser, Status s, int ammo);
	
	void destroy_ammo(std::vector <lazer*> &laser);
	void destroy_ammo(std::vector <Icet*> &laser);
	void destroy_ammo(std::vector <Inferred*> &laser);
	void destroy_ammo(std::vector <Ziggonet*> &laser);
	void destroy_ammo(std::vector <Haych*> &laser);
	void destroy_ammo(std::vector <Haychba*> &laser);
	void destroy_ammo(std::vector <Sonic_Wave*> &laser);*/

	void destroy_weapon_img();
	void select_keys(int keys, int p_or_s);

	void setweaponID(int id);

	int getweaponID();

private:
	ALLEGRO_BITMAP *shiplaser[3] = { NULL };
	ALLEGRO_BITMAP *inferred[2] = { NULL };
	ALLEGRO_BITMAP *icet[2] = { NULL };
	ALLEGRO_BITMAP *ziggonet = NULL;
	ALLEGRO_BITMAP *haych[2] = { NULL };
	ALLEGRO_BITMAP *haychba[2] = { NULL };
	ALLEGRO_BITMAP *sonic_wave = NULL;



	ALLEGRO_FONT *font;

	int id;
};

