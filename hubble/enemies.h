/* 
This class is a polymorphic class that uses virtual function.
All classes that inherit this class use the same function(s).
*/

#include "global.h"
#include "player.h"
#include "Enemy_Lazer.h"

#pragma once

class enemies
{
public:

	//initial declaration
	enemies(int x, int y, int vel, int health, int coord);
	~enemies();
	
	//funciton not used
	virtual bool getlife();

	//updates enemies 
	//[all enemies use this function except: volcanon]
	virtual void update();

	//returns x coordinates
	virtual int get_x();

	//returns y coordinates
	virtual int get_y();

	//returns the speed of the enemies
	virtual int get_vel();

	//returns the direction of the enemies
	virtual int get_coord_ID();

	//returns the identity of the enemies
	virtual int get_name_ID();

	//returns enemies' health
	virtual int get_health();

	//returns the time an enemy is either frozen, burned, or stunned
	virtual int get_duration();

	//returns the damage done on the player when collided with enemies
	virtual int get_damage();

	//returns the score of the enemies when killed
	virtual int get_score();

	//returns whether enemy is hit or not [wierd it is not boolean]
	virtual int get_hit();

	//returns the frame of the enemy when damaged
	virtual int get_frame();

	//returns the frame when enemy gets killed
	virtual int get_destroy_frame();

	//returns the time when enemy is not shooting
	virtual int get_delay();

	//returns the x coordinate of enemies' weapon
	//depending on index
	virtual int get_weaponx(int index);
	
	//returns the y coordinate of enemies' weapon
	//depending on index
	virtual int get_weapony(int index);
	
	//returns the size of the weapon
	virtual int get_weaponsize();

	//pulls the player towards enemies
	//[Jupiball and satusphere use this function]
	virtual void gravity(player* & p);

	//initialize the variables for enemies
	virtual void init();

	//deletes the enemy weapon vector
	virtual void killweapon(int index);
	
	//if the player gets hit by enemies' weapon,
	//the player gets poisoned 
	//[Classes that use this function:
	//blobby, spyder, mpolice]
	virtual void weapon_ability(player * &p);

	//decreases enemies' health
	virtual void decrement_health(int damage);

	//function not used
	virtual void setlife(bool life);
	
	//sets x coordinate
	virtual void set_x(int x);

	//sets y coordinate
	virtual void set_y(int y);

	//sets enemies' speed
	virtual void set_vel(int vel);
	
	//enemies move left
	virtual void moveleft();
	
	//enemies move right
	virtual void moveright();
	
	//enemies move up
	virtual void moveup();

	//enemies move down
	virtual void movedown();

	//randomize probabilty of enemy being 
	//able to shoot
	virtual void shoot_probability();
	
	//loads the enemy weapon vector
	virtual void load_ammo(int sing_twin);

	//randomizes direction of the enemy
	virtual void randomize_CID();

	//updates the animation for enemy damaged
	virtual void update_animation();

	//updates the animation for enemies when destroyed
	virtual void update_destroy_animation();

	//decreases the time when enemy is not allowed to shoot
	virtual void decrement_delay();

	//sets enemy's identity
	virtual void set_name_ID(int nameID);

	//sets enemy's health
	virtual void set_health(int health);
	
	//sets the time the enemy are frozen, burned, or stunned
	virtual void set_duration(int duration);

	//sets enemy's direction
	virtual void set_coord_ID(int coordID);
	
	//sets whether enemy is hit or not
	virtual void set_hit(bool hit);

	//sets the time enemy is not allowed to shoot
	virtual void set_delay(int delay);

	//renders enemy's images on screen
	virtual void draw(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2);

	//renders enemy's weapon to the screen
	virtual void draw_E_weapon(ALLEGRO_BITMAP* bmp);

	//deallocates enemy's assets
	virtual void draw_destroy(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2, 
		ALLEGRO_BITMAP * bmp3);

	//deletes all enemy's weapon vector index
	virtual void clear_weapon();

	//when player collided with an enemy, player gets status changes
	//[Classes that use this function:
	//blobby, spyder, mpolice, asterix, wyrm]
	virtual void ability(player* &p, ALLEGRO_EVENT e);

	//decreases the time enemies are frozen, burned, or stunned
	virtual void countdown_duration();

	//when the duration is zero, the enemy is not longer
	//frozen, burned, or stunned
	virtual void release();

private:
	//int variables
	int x, y;
	int coordID, enemyID, vel, health, duration;
	int probability_of_shooting;
	int delay;

	//boolean variables
	bool enemylife, hit;

	//object vector variable
	std::vector <Enemy_Lazer*> l;

	//object variables
	Animate animate;
	Animate destroying;
};