#include "global.h"

#pragma once

class boss
{
public:
	//initializes coordinates, velocity, identity of the boss, health, and direction
	boss(int x, int y, int vel, int bossID, int health, int cid);
	~boss();

	//function not used
	void load();

	//function not used
	void draw_boss(int x, int y);
	
	void energize_spartak(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2);
	
	//updates action, coordinates, attackmoves (if boss decides to attack), and animation
	void update(ALLEGRO_BITMAP *bmp, int &attackmove, int &lazerb_shoot);
	
	//function not used
	void destroy();

	//moves the boss
	void move();

	//returns whether the boss wants to attack or move
	int get_action();

	//returns the identity of the boss
	int get_boss();

	//returns the x coordinates
	int get_x();
	
	//returns the y coordinates
	int get_y();

	//returns the speed of the boss
	int get_vel();

	//returns the direction of the boss
	int get_coordID();

	//returns whether spartak is attacking and energizing
	int get_energize();

	//returns frame position
	int get_frame();

	//returns health
	int get_health();

	//sets the action of the boss
	void set_action(int action);

	//sets identity of the boss
	void set_boss(int bossnum);

	//sets x coordinates
	void set_x(int x);

	//sets y coordinates
	void set_y(int y);

	//sets velocity
	void set_vel(int vel);

	//sets direction of the boss
	void set_coordID(int cid);

	//sets the frame position
	void set_frame(int frame);

	//sets whether the boss is energizing or not
	void is_energizing(bool energize);

	//sets health
	void set_health(int health);

	//increments the frame
	void increment_frame();

private:

	//assets
	ALLEGRO_BITMAP *Spartak[2];
	ALLEGRO_BITMAP *Spartakball;
	ALLEGRO_BITMAP *Martianb[2];
	ALLEGRO_BITMAP *Kametkhan[2];
	ALLEGRO_BITMAP *Xorgana;

	//object variable
	Animate a;

	//boolean variables
	bool horiz, vert, energize;
	
	//int variables
	int x, y, vel, bossnum, cid, action, health;
	int frame = 0;
};

