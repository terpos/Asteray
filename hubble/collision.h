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
#include "Animate.h"

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
	void Enemy_boundary_collision(Enemy_Manager EN, std::vector <enemies*> &foe, int destroy_or_rebound);
	void Boss_boundary_collision(Enemy_Manager EN, std::vector<boss*>& foe);
	
	void enemy_gets_damaged(Enemy_Manager EN, weaponManager W, Tools_manager &tm, std::vector <Ammo*> &a, std::vector <Tools*> &t,
		std::vector <enemies*> &f, std::vector <Weapon*> &l, Status &s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_SAMPLE_INSTANCE *hit_sound, 
		ALLEGRO_FONT *font, Animate &hit, int &score);

	void enemy_dies( ALLEGRO_FONT *font, Animate &d, Status &s, int &numkills, int &score, Tools_manager & tm, std::vector<Ammo*>& a, std::vector<Tools*>& t,
		std::vector<enemies*>& f, bool weaponunlock[6], ALLEGRO_SAMPLE_INSTANCE * instance);

	void enemy_gets_damaged(Enemy_Manager EN, std::vector <Tools*> &t, std::vector <enemies*> &f, Status &s, ALLEGRO_FONT *font);

	void boss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector <boss*> &b, std::vector <Boss_weapon*> &bw, std::vector <Weapon*> &f,
		ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_SAMPLE_INSTANCE *instance2, bool &bossdefeated);

	void Ball_gets_redirected(Enemy_Manager &EN, weaponManager W, std::vector <Boss_weapon*> &bw, std::vector<Weapon*>& f,
		ALLEGRO_SAMPLE_INSTANCE *instance, bool & bossdefeated);

	void Ball_gets_destroyed(Enemy_Manager & EN, weaponManager W, Tools_manager & tm, std::vector <Boss_weapon*> &bw, std::vector<Weapon*>& f, std::vector <Ammo*> &a,
		ALLEGRO_SAMPLE_INSTANCE * instance, bool & bossdefeated);

	void Boss_weapon_immune_to_weapon(Enemy_Manager & EN, Stages s, std::vector <enemies*> e, weaponManager W, std::vector <Enemy_Lazer*> &lazer,
		std::vector<Weapon*>& f, std::vector <Turrets*> turrets, std::vector <Boss_weapon*> &bw, ALLEGRO_SAMPLE_INSTANCE * instance, bool & bossdefeated);

	void Boss_weapon_immune_to_weapon(Enemy_Manager & EN, weaponManager W, std::vector <enemies*> e, std::vector<Weapon*>& f, ALLEGRO_SAMPLE_INSTANCE * instance, 
		bool & bossdefeated);

	void miniboss_gets_damaged(Enemy_Manager &EN, Stages s, weaponManager W, std::vector<mini_boss*>& mb, 
		std::vector <Turrets *> &turrets, std::vector<Weapon*>& f, ALLEGRO_SAMPLE_INSTANCE * hit, ALLEGRO_SAMPLE_INSTANCE *die, bool & bossdefeated);

	void player_gets_damaged(Enemy_Manager &EN, std::vector <mini_boss*> &mb, std::vector <boss*> &b, std::vector <enemies*> &f, 
		std::vector <player*> &p, Status s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, Animate &hit, int &health);

	void player_gets_damaged(Enemy_Manager &EN, std::vector<enemies*>& foes, std::vector <Enemy_Lazer*> &lazer, std::vector<player*>& p, 
		Status s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, Animate &hit, int &health);

	void check_position(Enemy_Manager E, std::vector <enemies*> &f);

	void player_gets_damaged(Enemy_Manager &EN, Stages stage, std::vector <enemies*> &foes, std::vector <Enemy_Lazer*> &lazer, std::vector <Turrets *> turrets,
		std::vector<player*>& p, std::vector <Boss_weapon*> &bw, Status s, ALLEGRO_SAMPLE_INSTANCE * instance, ALLEGRO_FONT * font, ALLEGRO_EVENT e, 
		Animate &hit, int & health);
	
	void player_gets_tool(std::vector <player*> &p, Enemy_Manager EN, std::vector <enemies*> &fo, std::vector <Tools*> &t, std::vector <Ammo*> &a, Tools_manager tm,
		Status s, Stages &stage, ALLEGRO_SAMPLE_INSTANCE *instance[3], ALLEGRO_FONT *f, int &health, int(&ammo)[6], bool &killonce);

	void destroy_foes_inside(Enemy_Manager EN, std::vector <enemies*> &f);

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

