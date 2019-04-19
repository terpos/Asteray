#pragma once


#include "global.h"
#include "player.h"

class enemies
{
public:
	enemies(int x, int y, int vel, int coord);
	~enemies();
	
	virtual bool getlife();

	virtual void update();

	virtual int get_x();
	virtual int get_y();
	virtual int get_vel();
	virtual int get_coord_ID();
	virtual int get_name_ID();
	virtual int get_health();
	virtual int get_duration();
	virtual int get_damage();
	
	virtual void decrement_health(int damage);


	virtual void setlife(bool life);
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void moveleft();
	virtual void moveright();
	virtual void moveup();
	virtual void movedown();
	virtual void randomize_CID();

	virtual void set_name_ID(int nameID);
	virtual void set_health(int health);
	virtual void set_duration(int duration);
	virtual void set_coord_ID(int coordID);
	virtual void draw(ALLEGRO_BITMAP *bmp);

	virtual void ability(player &p, ALLEGRO_EVENT e);
	virtual void countdown_duration();
	virtual void release();

private:
	int x, y;
	bool enemylife;
	int coordID, enemyID, vel, health, duration;
	
};