#include "global.h"

#pragma once

class boss
{
public:
	boss(int x, int y, int vel, int bossID, int health, int cid);
	~boss();

	void load();

	void draw_boss(int x, int y);
	void energize_spartak(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	void update(ALLEGRO_BITMAP *bmp, int &attackmove, int &lazerb_shoot);
	void destroy();
	void move();

	int get_action();
	int get_boss();
	int get_x();
	int get_y();
	int get_vel();
	int get_coordID();
	int get_energize();
	int get_frame();
	int get_health();

	void set_action(int action);
	void set_boss(int bossnum);
	void set_x(int x);
	void set_y(int y);
	void set_vel(int vel);
	void set_coordID(int cid);
	void set_frame(int frame);
	void is_energizing(bool energize);
	void set_health(int health);

	void increment_frame();

private:
	ALLEGRO_BITMAP *Spartak[2];
	ALLEGRO_BITMAP *Spartakball;
	ALLEGRO_BITMAP *Martianb[2];
	ALLEGRO_BITMAP *Kametkhan[2];
	ALLEGRO_BITMAP *Xorgana;

	Animate a;

	bool horiz, vert, energize;
	
	int x, y, vel, bossnum, cid, action, health;
	int frame = 0;
};

