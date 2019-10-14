#pragma once

#include "screen_state.h"
#include "global.h"
#include "Enemy_Manager.h"
#include "weaponManager.h"
#include "collision.h"
#include "Tools_manager.h"

#include "boss.h"
#include "mini_boss.h"

class game_loop
{
public:
	game_loop();
	~game_loop();

	//replays the game when the player
	//decides to replay or dies in the game
	void replay();

	//intializes variables
	void init();

	//loads asset and initializes the assets
	void load_stuff();

	//does a game loop
	void loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q, bool &loop);
	
	//when a player defeats minibosses, the key is 
	//not used but the ship gets into position to
	//advance
	void stage_advance(player *&p);

	//the ship advances after getting into position
	void forward(player *&p);

	//handles keyboard and mouse events based on 
	//different screen states
	void Event_listenter(ALLEGRO_EVENT &ev, ALLEGRO_EVENT_QUEUE * q);

	//updates the variables
	void update(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q);

	//renders assets to the screen
	void render();

	//deallocates assets
	void destroy_stuff();

private:
	//this variable controls the game loop
	bool done = false;

	//this variable determines if that can be drawn 
	//on the screen 
	bool draw;

	//this is used at the end of level (except bosses and minibosses)
	bool battle;

	//takes value of whether boss is defeated or not
	bool bossdefeated;

	//takes value of whether game is over or not
	bool gameover;

	//takes value of whether mouse is moving or not
	bool mouse;

	//takes value of whether all enemy inside the screen
	//are destroyed or not (if the player touches the disfigurement tools)
	bool disfig;

	//health of the player
	int health;

	//level of the stage
	int lvl;

	//player's score
	int sc;

	//screen state
	int pauseCounter;

	//number of enemies dead
	int num_of_enemies;
	
	//which stage that the player is in
	int stagenumber;
	
	//how many weapons that are unlocked
	int num_of_weapon;

	//idk what this variables does
	int disfig_index;
	
	//number of kills 
	int num_of_kills;

	bool startanimating;

	//takes value of whether miniboss
	//is defeated or not
	bool minibossdefeated;

	//takes value of whether miniboss
	//and player are battling
	bool miniboss_battle;

	//takes the value of whether 
	//the player advances or not
	bool advance;

	//takes the value of whether boss
	//and player are battling or not
	bool boss_battle;

	//takes the value of different selection
	//of special weapons
	int weaponsel;
	int frame;
	int textframe;

	//volumes of background music for earth,
	//earth factory, mars, mars nest, astroid,
	//saturn, boss, final boss, stage completed,
	//and credit
	float backgroundvol;
	
	//stage completed score
	int scorecounter;

	//decrement the score
	//TODO:change the name of the var
	int increment;


	int advance_increment;

	//takes the values for different pause options
	int options;

	//bool value of whether a certain special weapon is unlocked or not
	bool unlockweapon[7];

	//value of how many ammos in each special weapons
	int ammo[7];

	//value of how many hits enemies can take before it can die
	int enemy_health[12];

	//objects variable
	std::vector <lazer*> laser;
	std::vector <Icet*> Ice;
	std::vector <Inferred*> Fire;
	std::vector <Ziggonet*> Lightning;
	std::vector <Haych*> h;
	std::vector <Haychba*> hbar;
	std::vector <Sonic_Wave*> wave;
	std::vector <Weapon*> w;
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


	//font assets
	ALLEGRO_FONT *status;
	ALLEGRO_FONT *pause;
	ALLEGRO_FONT *pause_options;


	//bitmap assets
	ALLEGRO_BITMAP *frozen;
	ALLEGRO_BITMAP *burned_red;
	ALLEGRO_BITMAP *burned_yellow;


	//sound assets
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

	

	std::vector <int> duration;
};

