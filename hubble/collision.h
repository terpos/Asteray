#pragma once

#include "global.h"
#include "player.h"
#include "blobby.h"
#include "enemies.h"
#include "lazer.h"
#include "Enemy_Manager.h"
#include "Tools.h"
#include "Ammo.h"
#include "Icet.h"
#include "Inferred.h"
#include "Ziggonet.h"
#include "Sonic_Wave.h"
#include "Haychba.h"
#include "Haych.h"
#include "Tools_manager.h"
#include "boss.h"
#include "mini_boss.h"
#include "weaponManager.h"

#include <vector>
#include <iostream>
#include <algorithm>

enum {REBOUND, DESTROY};

class collision
{
public:
	collision();
	~collision();

	//if about to go outside of the border the object does not move
	void win_collsion (std::vector <player*> &p);
	void Enemy_boundary_collision(std::vector <enemies*> &foe, int destroy_or_rebound);
	void Boss_boundary_collision(Enemy_Manager EN, std::vector<boss*>& foe);
	
	void enemy_gets_damaged(Enemy_Manager EN, weaponManager W, Tools_manager &tm, std::vector <Ammo*> &a, std::vector <Tools*> &t,
		std::vector <enemies*> &f, std::vector <Weapon*> &l, Status &s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, int &score);

	void enemy_dies(Tools_manager & tm, std::vector<Ammo*>& a, std::vector<Tools*>& t, std::vector<enemies*>& f, ALLEGRO_SAMPLE_INSTANCE * instance);



	void enemy_gets_damaged(Enemy_Manager EN, std::vector <Tools*> &t, std::vector <enemies*> &f, Status &s, ALLEGRO_FONT *font);


	void boss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Weapon*> &f,
		ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_SAMPLE_INSTANCE *instance2, bool &bossdefeated);

	void Ball_gets_redirected(Enemy_Manager &EN, weaponManager W, std::vector<Spartak_ball*>& b, std::vector<Weapon*>& f,  ALLEGRO_SAMPLE_INSTANCE *instance, bool & bossdefeated);

	void Ball_gets_destroyed(Enemy_Manager & EN, weaponManager W, Tools_manager & tm, std::vector<Molten_shot*>& b, std::vector<Weapon*>& f, std::vector <Ammo*> &a, ALLEGRO_SAMPLE_INSTANCE * instance, bool & bossdefeated);

	void Boss_weapon_immune_to_weapon(Enemy_Manager & EN, weaponManager W, std::vector <Diamond_shot*> &ds,
		std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
		std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st, std::vector <Spartak_Laser*> &sl,
		std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, std::vector <Enemy_Lazer*> &lazer, std::vector<Weapon*>& f, ALLEGRO_SAMPLE_INSTANCE * instance, bool & bossdefeated);

	void miniboss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector<mini_boss*>& mb, std::vector<Weapon*>& f, bool & bossdefeated);

	void player_gets_damaged(Enemy_Manager &EN, std::vector <mini_boss*> &mb, std::vector <boss*> &b, std::vector <enemies*> &f, std::vector <player*> &p, Status s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, int &health);

	void player_gets_damaged(Enemy_Manager &EN, std::vector <Spartak_ball*> &b, std::vector <Diamond_shot*> &ds,
		std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
		std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st, std::vector <Spartak_Laser*> &sl,
		std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, std::vector <Enemy_Lazer*> &lazer, std::vector<player*>& p, Status s, ALLEGRO_SAMPLE_INSTANCE * instance, ALLEGRO_FONT * font, ALLEGRO_EVENT e, int & health);
	
	void player_gets_tool(std::vector <player*> &p, Enemy_Manager EN, std::vector <enemies*> &fo, std::vector <Tools*> &t, std::vector <Ammo*> &a, Status s, ALLEGRO_SAMPLE_INSTANCE *instance[3], ALLEGRO_FONT *f, int &health, int(&ammo)[6]);

	int get_num_of_kills();
	void set_num_of_kills(int kill);
	
private:
	bool ai_movement = true;

	std::vector <int> x, y;
	std::vector <int> stunned_enemy;
	std::vector <int> Freeze_duration;

	int cid;
	int haych_damaged;
	int num_of_kill;
	bool declare;

	

};

