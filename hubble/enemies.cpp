#include "enemies.h"


//initial variable assignment
enemies::enemies(int x, int y, int vel, int health, int coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	this->coordID = coord;
	this->health = health;
	set_hit(false);
	init();
	this->delay = 0;
	animate.set_frame(0);
	destroying.set_frame(0);
}


enemies::~enemies()
{
}

//returns x value
int enemies::get_x()
{
	return this->x;
}

//returns y value
int enemies::get_y()
{
	return this->y;
}

//returns enemy's speed
int enemies::get_vel()
{
	return this->vel;
}

//returns enemy's direction
int enemies::get_coord_ID()
{
	return this->coordID;
}

//returns enemy's identity
int enemies::get_name_ID()
{
	return this->enemyID;
}

//returns enemy's health
int enemies::get_health()
{
	return this->health;
}

//returns the time enemy is 
//frozen, burned, and stunned
int enemies::get_duration()
{
	return this->duration;
}

//returns damage done to player
int enemies::get_damage()
{
	return 0;
}

//returns score when enemy is killed
int enemies::get_score()
{
	return 50;
}

//returns whether the enemy is hit or not
int enemies::get_hit()
{
	return this->hit;
}

//returns damage frame position
int enemies::get_frame()
{
	return animate.get_frame();
}

//returns destroy frame position
int enemies::get_destroy_frame()
{
	return destroying.get_frame();
}

//returns the time when enemies are not allowed to shoot
int enemies::get_delay()
{
	return this->delay;
}

//returns weapon x coordinate
int enemies::get_weaponx(int index)
{
	return l[index]->get_x();
}

//returns weapon y coordinate
int enemies::get_weapony(int index)
{

	return l[index]->get_y();
}

//returns the vector size of weapon
int enemies::get_weaponsize()
{
	return l.size();
}


//player gets sucked into the enemy
//[jupiball and satusphere use this function]
void enemies::gravity(player* & p)
{
}

//function not used
void enemies::init()
{
	
}

//deletes the weapon index
void enemies::killweapon(int index)
{
	l.erase(l.begin() + index);
}

//if player got hit by enemy's weapon, the player
//gets status change
void enemies::weapon_ability(player *& p)
{
}

//decreases enemy's health
void enemies::decrement_health(int damage)
{

}

//function not used
bool enemies::getlife()
{
	return enemylife;
}

//updates enemies coordinates [all enemies use this function
//except: volcanon]
void enemies::update()
{
	for (int i = 0; i < l.size(); i++)
	{
		//allows the weapon to shoot
		l[i]->set_shot(true);
		
		//updates the weapon position 
		l[i]->shoot();
		
		//deletes the weapon after it goes off screen
		if (l[i]->get_y() > winy)
		{
			l.erase(l.begin() + i);
		}
	}

	//updates the enemy coordinate depending on what direction
	//they are going
	switch (get_coord_ID())
	{
	case UP:
		y-=this->vel;
		//y = sin((20 * 3.14)*(y - 1));
		set_y(y);
		break;

	case DOWN:
		y+=this->vel;
		//y = sin((20*3.14)*(y+1));
		set_y(y);
		break;

	case LEFT:
		x-=this->vel;
		//x = sin((20 * 3.14)*(x + 1));
		set_x(x);
		break;

	case RIGHT:
		x+=this->vel;
		set_x(x);
		break;
	}
}

//function not used
void enemies::setlife(bool life)
{
	enemylife = life;
}

//sets x coordinate
void enemies::set_x(int x)
{
	this->x = x;
}

//sets y coordinate
void enemies::set_y(int y)
{
	this->y = y;
}

//sets speed
void enemies::set_vel(int vel)
{
	this->vel = vel;
}

//enemy moves left
void enemies::moveleft()
{
	this->x--;
	set_x(this->x);
}

//enemy moves right
void enemies::moveright()
{
	this->x++;
	set_x(this->x);
}

//enemy moves up
void enemies::moveup()
{
	this->y--;
	set_y(this->y);
}

//enemy moves down
void enemies::movedown()
{
	this->y++;
	set_y(this->y);
}

//randomizes the probability that the enemy 
//is allowed to shoot
void enemies::shoot_probability()
{
	this->probability_of_shooting = rand() % 501;
}

//loads the ammo depending on the enemy
//itself
void enemies::load_ammo(int sing_twin)
{
	if (this->probability_of_shooting <= 10 && this->delay == 0 && get_health() > 0 && sing_twin == 1 && this->coordID >= 0 && this->coordID <= 3)
	{
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, DOWN));
		set_delay(50);
	}

	else if (this->probability_of_shooting <= 10 && this->delay == 0 && get_health() > 0 && sing_twin == 2 && this->coordID >= 0 && this->coordID <= 3)
	{
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, DOWN));
		l.push_back(new Enemy_Lazer(get_x() + 23, get_y(), 10, DOWN));

		set_delay(50);
	}
	
}

//function not used
void enemies::randomize_CID()
{
}

//updates the damage animation
void enemies::update_animation()
{
	//if enemy got hit
	//animation starts
	if (get_hit())
	{
		animate.increment_frame();
	}

	//if frame position is 50
	//animation stops
	if (animate.get_frame() == 50)
	{
		animate.set_frame(0);
		this->hit = false;
		set_hit(this->hit);
	}
}

//updates the animation of enemy
//dying
void enemies::update_destroy_animation()
{
	destroying.increment_frame();
}

//decreases the time that the enemy
//is not allowed to shoot
void enemies::decrement_delay()
{
	if (get_delay() > 0)
	{
		this->delay--;
		set_delay(this->delay);
	}
}

//sets the direction
void enemies::set_coord_ID(int coordID)
{
	this->coordID = coordID;
}

//sets whether the enemy is hit or not
void enemies::set_hit(bool hit)
{
	this->hit = hit;
}

//sets the time that enemy is not allowed to shoot
void enemies::set_delay(int delay)
{
	this->delay = delay;
}

//renders enemy on the screen
void enemies::draw(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2)
{
	if (get_hit() && get_health() > 0)
	{
		animate.two_frames_custom(bmp, bmp2, get_x(), get_y(), animate.get_frame(), 7, 0, 3);
	}

	else if (!get_hit() && get_health() > 0)
	{
		al_draw_bitmap(bmp, get_x(), get_y(), NULL);
	}
}

//renders enemy's weapon on to the screen
void enemies::draw_E_weapon(ALLEGRO_BITMAP * bmp)
{
	for (int i = 0; i < l.size(); i++)
	{
		al_draw_bitmap(bmp, l[i]->get_x(), l[i]->get_y(), NULL);
	}
}

//renders enemy dying on to the screen
void enemies::draw_destroy(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3)
{
	if (this->health <= 0)
	{
		destroying.three_frames_custom(bmp, bmp2, bmp3, get_x(), get_y(), get_destroy_frame(), 20, 5, 10, 15);
	}
}

//deletes all weapon vector
void enemies::clear_weapon()
{
	l.clear();
}

//if player collides with enemy, 
//the player gets status change
void enemies::ability(player* & p, ALLEGRO_EVENT e)
{

}

//decreases the time enemies are frozen, burned, or stunned
void enemies::countdown_duration()
{
	if (get_duration() != 0)
	{
		this->duration--;
		set_duration(this->duration);
	}
}

//when the duration is zero, the enemy is not longer
//frozen, burned, or stunned
void enemies::release()
{
	if (get_duration() == 0 && get_coord_ID() > 3)
	{
		this->coordID = rand() % 2;
		set_coord_ID(this->coordID);
	}
}

//sets enemy's identity
void enemies::set_name_ID(int nameID)
{
	this->enemyID = nameID;
}

//sets health
void enemies::set_health(int health)
{
	this->health = health;
}

//sets the time the enemy are frozen, burned, or stunned
void enemies::set_duration(int duration)
{
	this->duration = duration;
}
