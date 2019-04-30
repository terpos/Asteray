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

#include "boss.h"
#include "mini_boss.h"

#include "Animate.h"

#include "global.h"

class Enemy_Manager
{
public:
	Enemy_Manager();
	~Enemy_Manager();

	void load_enemy_img();
	
	void spawn_boss(std::vector <boss*> &b, int bossID);
	void spawn_minboss(std::vector<mini_boss*>& mb, int minibossID);
	void spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, int lim, int enemyID);

	void spawn_enemy(std::vector<enemies*>& e, int enemy_health[12], int CID, int vel, int lim, int enemyID);
	
	void update(std::vector <enemies*> &e, std::vector <boss*> &b, std::vector <mini_boss*> &mb, std::vector <Spartak_ball*> &ball, std::vector <Molten_shot*> &mball,
		std::vector <v_beam*> &v, Animate &a);

	void update(std::vector<enemies*>& e);
	
	void renderenemy(std::vector <enemies*> &e);
	void renderboss(std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, Animate a, int &frame);
	void renderminiboss(std::vector <mini_boss*> &mb, Animate a);
	
	void destroy_enemy(std::vector <enemies*>& e, int index);
	void clear_enemy(std::vector <enemies*>& e);
	
	void destroy_enemy_img();

	int get_h(int enemyID);
	int get_w(int enemyID);

	int get_E_w();
	int get_M_w();
	int get_boss_w(int bossID);
	int get_ball_w();


	int get_E_h();
	int get_M_h();
	int get_boss_h(int bossID);
	int get_ball_h();


	int get_num_of_enemy(std::vector <enemies*> e);

	int ishit();
	void sethit(bool hit);

private:

	std::vector <ALLEGRO_BITMAP*> Enemy;

	ALLEGRO_BITMAP *Spartak[3];
	ALLEGRO_BITMAP *Spartakball;
	ALLEGRO_BITMAP *Martianb[3];
	ALLEGRO_BITMAP *Kametkhan[3];
	ALLEGRO_BITMAP *Xorgana[2];
	ALLEGRO_BITMAP *Kamekhan_weapon;
	ALLEGRO_BITMAP *Xorgana_weapon;

	ALLEGRO_BITMAP *earth_gate;
	ALLEGRO_BITMAP *mars_gate;
	ALLEGRO_BITMAP *electricity[2];

	ALLEGRO_SAMPLE *Energized;
	ALLEGRO_SAMPLE *Release;

	ALLEGRO_SAMPLE_INSTANCE *energized;
	ALLEGRO_SAMPLE_INSTANCE *release;

	bool damaged;

};

