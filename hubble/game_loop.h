#pragma once

#include "screen_state.h"
#include "global.h"
#include "Enemy_Manager.h"
#include "weaponManager.h"
#include "collision.h"
#include "Tools_manager.h"
#include "Stages.h"
#include "boss.h"
#include "mini_boss.h"
//#include "blobby.h"

class game_loop
{
public:
	game_loop();
	~game_loop();

	void load_stuff();
	void loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q);
	void stage(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q);
	void Event_listenter(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE * q);
	void update_loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q);
	void render();
	void destroy_stuff();

private:
	
	bool done = false;
	bool draw;
	bool update;
	bool battle;
	bool bossdefeated;
	bool gameover;

	int key;
	int health;
	int lvl;
	int sc;
	int pauseCounter;
	int num_of_enemies;
	int stagenumber;
	int num_of_weapon;

	bool unlockweapon[6];
	int ammo[6];
	int maxammo[6];
	int enemy_health[12];

	std::vector <blobby*> blob;
	std::vector <lazer*> laser;
	std::vector <Icet*> Ice;
	std::vector <Inferred*> Fire;
	std::vector <Ziggonet*> Lightning;
	std::vector <Haych*> h;
	std::vector <Haychba*> hbar;
	std::vector <Sonic_Wave*> wave;

	std::vector <int> duration;

	std::vector <enemies*> foes;
	std::vector <enemies*> foes_while_scroll;

	std::vector <boss*> b;
	std::vector <mini_boss*> mb;

	std::vector <Tools*> t;
	std::vector <Ammo*> am;

	std::vector <player*> spaceship;

	std::vector <Spartak_ball*> ball;
	std::vector <Molten_shot*> mball;
	std::vector <v_beam*> v;


	Animate ani;
	Tools_manager T;
	Enemy_Manager E;
	
	weaponManager shipWeapon;
	collision col;
	Status stat;
	Stages s;

	ALLEGRO_FONT *status;

	ALLEGRO_BITMAP *frozen;
	ALLEGRO_BITMAP *burned_red;
	ALLEGRO_BITMAP *burned_yellow;

	ALLEGRO_SAMPLE *earth;
	ALLEGRO_SAMPLE *earth_factory;
	ALLEGRO_SAMPLE *boss;
	ALLEGRO_SAMPLE *mars;
	ALLEGRO_SAMPLE *mars_nest;
	ALLEGRO_SAMPLE *astroid;
	ALLEGRO_SAMPLE *saturn;
	ALLEGRO_SAMPLE *final_boss;
	
	ALLEGRO_SAMPLE *ls;
	ALLEGRO_SAMPLE *ic;
	ALLEGRO_SAMPLE *fi;
	ALLEGRO_SAMPLE *li;
	ALLEGRO_SAMPLE *ha;
	ALLEGRO_SAMPLE *hab;
	ALLEGRO_SAMPLE *so;

	ALLEGRO_SAMPLE *health_pickup;
	ALLEGRO_SAMPLE *ammo_pickup;
	ALLEGRO_SAMPLE *destroy_all;
	ALLEGRO_SAMPLE *Destroy;
	ALLEGRO_SAMPLE *Hit;

	ALLEGRO_SAMPLE *Game_over;

	ALLEGRO_SAMPLE *Reflect;
	ALLEGRO_SAMPLE *Ballreflect;
	ALLEGRO_SAMPLE *Bosshit;
		

	ALLEGRO_SAMPLE_INSTANCE *lsr;
	ALLEGRO_SAMPLE_INSTANCE *ice;
	ALLEGRO_SAMPLE_INSTANCE *fire;
	ALLEGRO_SAMPLE_INSTANCE *lit;
	ALLEGRO_SAMPLE_INSTANCE *haa;
	ALLEGRO_SAMPLE_INSTANCE *wavey;

	ALLEGRO_SAMPLE_INSTANCE *pickup[3];

	ALLEGRO_SAMPLE_INSTANCE *destroy;

	ALLEGRO_SAMPLE_INSTANCE *hit;

	ALLEGRO_SAMPLE_INSTANCE *game_over;

	ALLEGRO_SAMPLE_INSTANCE *reflect;
	ALLEGRO_SAMPLE_INSTANCE *ballreflect;
	ALLEGRO_SAMPLE_INSTANCE *bosshit;

	int weaponsel;
	int frame;
	int textframe;
	float backgroundvol;
};

