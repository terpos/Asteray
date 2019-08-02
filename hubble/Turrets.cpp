#include "Turrets.h"



Turrets::Turrets(int x, int y, int health, int delay)
{
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

int Turrets::get_x()
{
	return this->x;
}

int Turrets::get_y()
{
	return this->y;
}

int Turrets::get_weaponx(int index)
{
	return l[index]->get_x();
}

int Turrets::get_weapony(int index)
{
	return l[index]->get_y();
}

int Turrets::get_health()
{
	return this->health;
}

int Turrets::get_delay()
{
	return this->delay;
}

bool Turrets::is_hit()
{
	return this->hit;
}

int Turrets::weapon_size()
{
	return l.size();
}

void Turrets::set_x(int x)
{
	this->x = x;
}

void Turrets::set_y(int y)
{
	this->y = y;
}

void Turrets::set_health(int health)
{
	this->health = health;
}

void Turrets::set_delay(int delay)
{
	this->delay = delay;
}

void Turrets::set_hit(bool hit)
{
	this->hit = hit;
}

void Turrets::killweapon(int index)
{
	l.erase(l.begin() + index);
}

void Turrets::decrement_delay()
{
	if (this->delay > 0)
	{
		this->delay--;
	}
}

void Turrets::decrement_health()
{
	if (this->health > 0)
	{
		this->health--;
		set_health(this->health);
	}
}

void Turrets::probability_shooting()
{
	shooting_probability = rand() % 301;
}

void Turrets::load_ammo(int x, int y)
{
	if (shooting_probability < 100 && get_delay() == 0)
	{
		l.push_back(new Enemy_Lazer(x, y, 10, DOWN));
		set_delay(30);
	}
}

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

void Turrets::renderweapon(ALLEGRO_BITMAP * bmp)
{
	for (int i = 0; i < l.size(); i++)
	{
		al_draw_bitmap(bmp, l[i]->get_x(), l[i]->get_y(), NULL);
	}
}
