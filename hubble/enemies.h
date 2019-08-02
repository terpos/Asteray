#pragma once


#include "global.h"
#include "player.h"
#include "Enemy_Lazer.h"

class enemies
{
public:
	enemies(int x, int y, int vel, int health, int coord);
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
	virtual int get_score();
	virtual int get_hit();
	virtual int get_frame();
	virtual int get_destroy_frame();
	virtual int get_delay();
	virtual int get_weaponx(int index);
	virtual int get_weapony(int index);
	virtual int get_weaponsize();

	virtual void gravity(player* & p);
	virtual void init();
	virtual void killweapon(int index);
	virtual void weapon_ability(player * &p);

	virtual void decrement_health(int damage);

	virtual void setlife(bool life);
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	
	virtual void moveleft();
	virtual void moveright();
	virtual void moveup();
	virtual void movedown();

	virtual void shoot_probability();
	virtual void load_ammo(int sing_twin);
	virtual void randomize_CID();
	virtual void update_animation();
	virtual void update_destroy_animation();
	virtual void decrement_delay();

	virtual void set_name_ID(int nameID);
	virtual void set_health(int health);
	virtual void set_duration(int duration);
	virtual void set_coord_ID(int coordID);
	virtual void set_hit(bool hit);
	virtual void set_delay(int delay);

	virtual void draw(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2);
	virtual void draw_E_weapon(ALLEGRO_BITMAP* bmp);
	virtual void draw_destroy(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3);
	virtual void clear_weapon();

	virtual void ability(player* &p, ALLEGRO_EVENT e);
	virtual void countdown_duration();
	virtual void release();

private:
	int x, y;
	bool enemylife, hit;
	int coordID, enemyID, vel, health, duration;
	int probability_of_shooting;
	int delay;

	std::vector <Enemy_Lazer*> l;

	Animate animate;
	Animate destroying;
};