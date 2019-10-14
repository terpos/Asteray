#include "Turrets.h"



Turrets::Turrets(int x, int y, int health, int delay)
{
	//initializations of variables
	set_x(x);
	set_y(y);
	set_health(health);
	set_delay(delay);
	set_hit(false);
	a.set_frame(0);
}


Turrets::~Turrets()
{

}

//returns x coordinates
int Turrets::get_x()
{
	return this->x;
}

//returns y coordinates
int Turrets::get_y()
{
	return this->y;
}

//returns x coordinates of weapon depending on index
int Turrets::get_weaponx(int index)
{
	return l[index]->get_x();
}

//returns y coordinates of weapon depending on index
int Turrets::get_weapony(int index)
{
	return l[index]->get_y();
}

//returns health of turrets
int Turrets::get_health()
{
	return this->health;
}

//return delays of turrets if it shoots
int Turrets::get_delay()
{
	return this->delay;
}

//return the value of whether the turret is hit by the player or not
bool Turrets::is_hit()
{
	return this->hit;
}

//returns vector size of weapon
int Turrets::weapon_size()
{
	return l.size();
}

//sets x coordinates
void Turrets::set_x(int x)
{
	this->x = x;
}

//sets y coordinates
void Turrets::set_y(int y)
{
	this->y = y;
}

//sets health
void Turrets::set_health(int health)
{
	this->health = health;
}

//sets delay if turret shoots
void Turrets::set_delay(int delay)
{
	this->delay = delay;
}

//sets hit 
void Turrets::set_hit(bool hit)
{
	this->hit = hit;
}

//if weapon goes out of screen, vector is deleted
void Turrets::killweapon(int index)
{
	l.erase(l.begin() + index);
}

//counts down delay until it reaches zero
void Turrets::decrement_delay()
{
	if (this->delay > 0)
	{
		this->delay--;
	}
}

//if the turret got shot, its health decrease
void Turrets::decrement_health()
{
	if (this->health > 0)
	{
		this->health--;
		set_health(this->health);
	}
}

//randomizes its ability to shoot
void Turrets::probability_shooting()
{
	shooting_probability = rand() % 301;
}

//loads the weapon
void Turrets::load_ammo(int x, int y)
{
	if (shooting_probability < 100 && get_delay() == 0)
	{
		l.push_back(new Enemy_Lazer(x, y, 10, DOWN));
		set_delay(30);
	}
}

//updates the coordinates, frames, and weapon movement
void Turrets::update(int x, int y)
{
	probability_shooting();
	load_ammo(x, y);
	decrement_delay();
	
	if (a.get_frame() == 50)
	{
		set_hit(false);
		a.set_frame(0);
	}

	if (is_hit())
	{
		a.increment_frame();
	}

	for (int i = 0; i < l.size(); i++)
	{
		l[i]->set_shot(true);
		l[i]->shoot();
	}
}

//displays turrets and turrets when damaged
void Turrets::render(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2)
{
	if (is_hit())
	{
		a.two_frames_custom(bmp1, bmp2, get_x(), get_y(), a.get_frame(), 9, 0, 4);
	}
	else
	{
		al_draw_bitmap(bmp1, get_x(), get_y(), NULL);
	}
}

//renders weapon
void Turrets::renderweapon(ALLEGRO_BITMAP * bmp)
{
	for (int i = 0; i < l.size(); i++)
	{
		al_draw_bitmap(bmp, l[i]->get_x(), l[i]->get_y(), NULL);
	}
}
