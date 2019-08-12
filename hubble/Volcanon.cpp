#include "Volcanon.h"



Volcanon::Volcanon(int x, int y, int vel, int health, int coord) : enemies(x, y, vel, health, coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	this->CID = coord;
	this->health = health;
	this->set_delay(100);
}


Volcanon::~Volcanon()
{
}

int Volcanon::get_name_ID()
{
	return VOLCANON;
}

int Volcanon::get_damage()
{
	return 5;
}

int Volcanon::get_score()
{
	return 0;
}

int Volcanon::get_weaponx(int index)
{
	return l[index]->get_x();
}

int Volcanon::get_weapony(int index)
{

	return l[index]->get_y();
}

int Volcanon::get_weaponsize()
{
	return l.size();
}

void Volcanon::killweapon(int index)
{
	l.erase(l.begin() + index);
}

void Volcanon::shoot_probability()
{
	this->probability = rand() % 301;
}

void Volcanon::load_ammo(int sing_twin)
{
	if (this->probability < 25 && get_delay() == 0 && get_health() > 0)
	{
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, UP));
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, DOWN));
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, LEFT));
		l.push_back(new Enemy_Lazer(get_x(), get_y(), 10, RIGHT));
		
		set_delay(150);
	}

	
	
}

void Volcanon::update()
{
	shoot_probability();
	
	load_ammo(1);
	
	for (int i = 0; i < l.size(); i++)
	{
		l[i]->set_shot(true);
		l[i]->shoot();
		if (l[i]->get_x() < -50 || l[i]->get_x() > winx || l[i]->get_y() < -50 || l[i]->get_y() > winy)
		{
			killweapon(i);
		}
	}

}

void Volcanon::draw_E_weapon(ALLEGRO_BITMAP * bmp)
{
	for (int i = 0; i < l.size(); i++)
	{
		al_draw_bitmap(bmp, l[i]->get_x(), l[i]->get_y(), NULL);
	}
}

void Volcanon::set_x(int x)
{
	this->x = x;
}

void Volcanon::set_y(int y)
{
	this->y = y;
}

void Volcanon::ability(player* & p, ALLEGRO_EVENT e)
{
}
