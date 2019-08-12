#pragma once

#include "screen_state.h"
#include "global.h"
#include "Enemy_Manager.h"
#include "weaponManager.h"
#include "collision.h"
#include "Tools_manager.h"

#include "boss.h"
#include "mini_boss.h"
//#include "blobby.h"

class game_loop
{
public:
	game_loop();
	~game_loop();

	void replay();
	void init();

	void load_stuff();
	void loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q, bool &loop);
	void stage_advance(player *&p);
	void forward(player *&p);
	void Event_listenter(ALLEGRO_EVENT &ev, ALLEGRO_EVENT_QUEUE * q);
	void update(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q);
	void render();
	void destroy_stuff();

private:
	
	bool done = false;
	bool draw;
	bool battle;
	bool bossdefeated;
	bool gameover;
	bool mouse;
	bool disfig;

	int key;
	int health;
	int lvl;
	int sc;
	int pauseCounter;
	int num_of_enemies;
	int stagenumber;
	int num_of_weapon;
	int disfig_index;
	int num_of_kills;

	int options;

	bool unlockweapon[6];
	int ammo[6];
	int maxammo[6];
	int enemy_health[12];

	std::vector <lazer*> laser;
	std::vector <Icet*> Ice;
	std::vector <Inferred*> Fire;
	std::vector <Ziggonet*> Lightning;
	std::vector <Haych*> h;
	std::vector <Haychba*> hbar;
	std::vector <Sonic_Wave*> wave;
	std::vector <Weapon*> w;

	std::vector <int> duration;

	std::vector <enemies*> foes;
	std::vector <enemies*> foes_scroll1;
	std::vector <enemies*> foes_scroll2;
	std::vector <enemies*> foes_scroll3;
	std::vector <enemies*> foes_scroll4;
	std::vector <enemies*> foes_scroll5;
	std::vector <enemies*> foes_scroll6;


	std::vector <boss*> b;
	std::vector <mini_boss*> mb;

	std::vector <Tools*> t;
	std::vector <Tools*> t2;
	std::vector <Tools*> t3;
	std::vector <Tools*> t4;
	std::vector <Tools*> t5;
	std::vector <Tools*> t6;


	std::vector <Ammo*> am;
	std::vector <Ammo*> am2;
	std::vector <Ammo*> am3;
	std::vector <Ammo*> am4;
	std::vector <Ammo*> am5;
	std::vector <Ammo*> am6;



	std::vector <player*> spaceship;

	std::vector <Spartak_ball*> ball;
	std::vector <Molten_shot*> mball;
	std::vector <v_beam*> v;
	std::vector <Diamond_shot*> ds;
	std::vector <Egg_Bomb*> EB;
	std::vector <Sonic_Turbulence*> ST;
	std::vector <Lazer_B*> LB;
	std::vector <Kamet*> K;
	std::vector <Heat_Wave*> hw;
	std::vector <Single_Twin*> st;
	std::vector <Enemy_Lazer*> elazer;
	std::vector <Boss_weapon*> bw;

	std::vector <Turrets *> turrets;

	Animate ani;
	Animate adestroy;
	Animate credit;
	Animate player_damaged;
	Animate enemy_damaged;
	Animate enemy_while_scroll_damaged;

	Tools_manager T;
	Tools_manager T2;
	Tools_manager T3;
	Tools_manager T4;
	Tools_manager T5;
	Tools_manager T6;


	Enemy_Manager E;
	Enemy_Manager E2;
	Enemy_Manager E3;
	Enemy_Manager E4;
	Enemy_Manager E5;
	Enemy_Manager E6;


	weaponManager shipWeapon;

	collision col;
	collision col2;
	collision col3;
	collision col4;
	collision col5;
	collision col6;


	
	Status stat;
	Stages s;

	ALLEGRO_FONT *status;
	ALLEGRO_FONT *pause;
	ALLEGRO_FONT *pause_options;

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
	ALLEGRO_SAMPLE *eh;
	ALLEGRO_SAMPLE *scm;

	ALLEGRO_SAMPLE *health_pickup;
	ALLEGRO_SAMPLE *ammo_pickup;
	ALLEGRO_SAMPLE *destroy_all;
	ALLEGRO_SAMPLE *Destroy;
	ALLEGRO_SAMPLE *Hit;
	ALLEGRO_SAMPLE *cre;
	ALLEGRO_SAMPLE *cntdwn;

	ALLEGRO_SAMPLE *PO;
	ALLEGRO_SAMPLE *POF;

	ALLEGRO_SAMPLE *Game_over;

	ALLEGRO_SAMPLE *Reflect;
	ALLEGRO_SAMPLE *Ballreflect;
	ALLEGRO_SAMPLE *Bosshit;
	ALLEGRO_SAMPLE *Bossdes;
	
	ALLEGRO_SAMPLE_INSTANCE *Earth;
	ALLEGRO_SAMPLE_INSTANCE *Earth_Factory;
	ALLEGRO_SAMPLE_INSTANCE *Boss;
	ALLEGRO_SAMPLE_INSTANCE *Mars;
	ALLEGRO_SAMPLE_INSTANCE *Mars_Nest;
	ALLEGRO_SAMPLE_INSTANCE *Astroid;
	ALLEGRO_SAMPLE_INSTANCE *Saturn;
	ALLEGRO_SAMPLE_INSTANCE *Final_Boss;

	ALLEGRO_SAMPLE_INSTANCE *lsr;
	ALLEGRO_SAMPLE_INSTANCE *ice;
	ALLEGRO_SAMPLE_INSTANCE *fire;
	ALLEGRO_SAMPLE_INSTANCE *lit;
	ALLEGRO_SAMPLE_INSTANCE *haa;
	ALLEGRO_SAMPLE_INSTANCE *wavey;

	ALLEGRO_SAMPLE_INSTANCE *pickup[3];

	ALLEGRO_SAMPLE_INSTANCE *destroy;

	ALLEGRO_SAMPLE_INSTANCE *hit;

	ALLEGRO_SAMPLE_INSTANCE *Pause_On;
	ALLEGRO_SAMPLE_INSTANCE *Pause_Off;

	ALLEGRO_SAMPLE_INSTANCE *game_over;

	ALLEGRO_SAMPLE_INSTANCE *reflect;
	ALLEGRO_SAMPLE_INSTANCE *ballreflect;
	ALLEGRO_SAMPLE_INSTANCE *bosshit;
	ALLEGRO_SAMPLE_INSTANCE *enemy_hit;
	ALLEGRO_SAMPLE_INSTANCE *Stage_Completed;
	ALLEGRO_SAMPLE_INSTANCE *Boss_destroyed;
	ALLEGRO_SAMPLE_INSTANCE *Credit;
	ALLEGRO_SAMPLE_INSTANCE *Countdown;

	bool startanimating;
	bool minibossdefeated;
	bool miniboss_battle;
	bool advance;
	bool boss_battle;

	int weaponsel;
	int frame;
	int textframe;
	float backgroundvol;
	int scorecounter;
	int increment;
};

