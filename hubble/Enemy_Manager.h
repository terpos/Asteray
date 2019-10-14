#pragma once

#include <vector>

#include "blobby.h"
#include "enemies.h"
#include "Asterix.h"
#include "Epolice.h"
#include "Jupiball.h"
#include "Kamekoset.h"
#include "Mpolice.h"
#include "Satusphere.h"
#include "Spaceship.h"
#include "Spyder.h"
#include "Volcanon.h"
#include "Wyrm.h"
#include "Xybtofy.h"
#include "Spartak_ball.h"
#include "Molten_shot.h"
#include "v_beam.h"
#include "Diamond_shot.h"
#include "Egg_Bomb.h"
#include "Sonic_Turbulence.h"
#include "Lazer_B.h"
#include "Kamet.h"
#include "Heat_wave.h"
#include "Single_Twin.h"
#include "Enemy_Lazer.h"
#include "Turrets.h"

#include "boss.h"
#include "mini_boss.h"

#include "Animate.h"

#include "Stages.h"

#include "global.h"

class Enemy_Manager
{
public:
	Enemy_Manager();
	~Enemy_Manager();

	//loads assets
	void load_enemy_img();
	
	//spawns boss at certain place depending on boss identity
	void spawn_boss(std::vector <boss*> &b, int bossID);
	
	//spawns mini boss at certain place depending on miniboss identity
	void spawn_minboss(std::vector<mini_boss*>& mb, std::vector <Turrets *> &turrets, Stages &s, int minibossID);
	
	//spawns enemy at a certain place depending on enemy identity
	void spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, int lim, int enemyID);
	void spawn_enemy(std::vector<enemies*>& e, int enemy_health[12], int CID, int vel, int lim, int enemyID);
	void spawn_enemy(std::vector<enemies*>& e, int enemy_health[12], int x, int y, int CID, int vel, int enemyID);
	
	//updates enemies, boss, and miniboss
	void update(std::vector <enemies*> &e, std::vector <boss*> &b, std::vector <mini_boss*> &mb, std::vector <Enemy_Lazer*> &lazer, std::vector <Turrets *> &turrets,
		std::vector <Boss_weapon*> &bw, Animate &a, Stages &s, Animate &hit);
	void update(std::vector<enemies*>& e, Animate &hit);
	
	//displays enemy to the screen
	void renderenemy(std::vector<enemies*>& e, Animate & hit);

	//displays boss to the screen
	void renderboss(std::vector <boss*> &b, std::vector <Enemy_Lazer*> &lazer, std::vector <Boss_weapon*> &bw, Animate a, ALLEGRO_SAMPLE_INSTANCE *destroy, int &frame);

	//displays miniboss to the screen
	void renderminiboss(std::vector <mini_boss*> &mb, std::vector<Turrets*>& turrets, Stages s, Animate a);
	
	//function not used
	void destroy_enemy(std::vector <enemies*>& e, int index);

	//deletes all enemies and make vector size to 0
	void clear_enemy(std::vector <enemies*>& e);
	
	//deallocates all assets
	void destroy_enemy_img();

	//gets width of enemies, boss, turrets, 
	//and miniboss, enemy weapon, turret weapon, and boss weapon
	int get_w(int enemyID);
	int get_Eweapon_w(int enemyID);
	int get_turret_w(int enemyID);
	int get_turretweapon_w(int enemyID);
	int get_E_w();
	int get_M_w();
	int get_boss_w(int bossID);
	int boss_weapon_w(int bossweaponID);
	int get_elazer_w();
	
	//gets height of enemies, boss, turrets, 
	//and miniboss, enemy weapon, turret weapon, and boss weapon
	int get_Eweapon_h(int enemyID);
	int get_turret_h(int enemyID);
	int get_turretweapon_h(int enemyID);
	int get_h(int enemyID);
	int get_E_h();
	int get_M_h();
	int get_boss_h(int bossID);
	int boss_weapon_h(int bossweaponID);
	
	
	//returns the size of enemies
	int get_num_of_enemy(std::vector <enemies*> e);

	//returns if boss got hit
	int ishit();

	//returns if boss is dead
	bool isdying();

	//sets whether boss is hit or not
	void sethit(bool hit);

	//sets whether boss is dead or not
	void set_death(bool dying);

private:
	//assets in vector variable
	std::vector <ALLEGRO_BITMAP*> Enemy;
	std::vector <ALLEGRO_BITMAP*> Enemy_damaged;

	//assets
	ALLEGRO_BITMAP *enemy_destroyed[3];
	ALLEGRO_BITMAP *Spartak[3];
	ALLEGRO_BITMAP *Spartak_blows_up[2];
	ALLEGRO_BITMAP *Spartakball;
	ALLEGRO_BITMAP *Diamond;
	ALLEGRO_BITMAP *S_laser[6];
	ALLEGRO_BITMAP *Martianb[3];
	ALLEGRO_BITMAP *Martianb_blows_up[2];
	ALLEGRO_BITMAP *Egg_bomb;
	ALLEGRO_BITMAP *Sonic_Turbulance;
	ALLEGRO_BITMAP *LaserB;
	ALLEGRO_BITMAP *Kametkhan[3];
	ALLEGRO_BITMAP *Kametkhan_blows_up[2];
	ALLEGRO_BITMAP *kamet;
	ALLEGRO_BITMAP *Xorgana[2];
	ALLEGRO_BITMAP *Xorgana_blows_up[2];
	ALLEGRO_BITMAP *SingleTwin;
	ALLEGRO_BITMAP *Kamekhan_weapon;
	ALLEGRO_BITMAP *Xorgana_weapon;
	ALLEGRO_BITMAP *earth_gate;
	ALLEGRO_BITMAP *mars_gate;
	ALLEGRO_BITMAP *electricity[2];
	ALLEGRO_BITMAP *Spyder_w;
	ALLEGRO_BITMAP *Planet_w;
	ALLEGRO_BITMAP *Blobby_w;
	ALLEGRO_BITMAP *Xybtofy_w;
	ALLEGRO_BITMAP *Mpolice_w;
	ALLEGRO_BITMAP *Asterix_w;
	ALLEGRO_BITMAP *Spaceship_w;
	ALLEGRO_BITMAP *Volcanon_w;
	ALLEGRO_BITMAP *E_Lazer;
	ALLEGRO_BITMAP *E_turret[2];
	ALLEGRO_BITMAP *M_turret[2];
	ALLEGRO_BITMAP *E_weapon;
	ALLEGRO_BITMAP *M_weapon;
	ALLEGRO_SAMPLE *Energized;
	ALLEGRO_SAMPLE *Release;
	ALLEGRO_SAMPLE_INSTANCE *energized;
	ALLEGRO_SAMPLE_INSTANCE *release;

	//object variable
	Animate ani;

	//boolean variable
	bool damaged;
	bool lazerb_action;
	bool dying;

	//int variable
	int attack_Move;
	int diamond_vel;
	int single_twin_probability;
	int lazerb_shoot;
	int enemy_shooting_probability;


};

