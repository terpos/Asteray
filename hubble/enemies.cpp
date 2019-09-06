#include "enemies.h"



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

int enemies::get_x()
{
	return this->x;
}

int enemies::get_y()
{
	return this->y;
}

int enemies::get_vel()
{
	return this->vel;
}

int enemies::get_coord_ID()
{
	return this->coordID;
}

int enemies::get_name_ID()
{
	return this->enemyID;
}

int enemies::get_health()
{
	return this->health;
}

int enemies::get_duration()
{
	return this->duration;
}

int enemies::get_damage()
{
	return 0;
}

int enemies::get_score()
{
	return 50;
}

int enemies::get_hit()
{
	return this->hit;
}

int enemies::get_frame()
{
	return animate.get_frame();
}

int enemies::get_destroy_frame()
{
	return destroying.get_frame();
}

int enemies::get_delay()
{
	return this->delay;
}

int enemies::get_weaponx(int index)
{
	return l[index]->get_x();
}

int enemies::get_weapony(int index)
{

	return l[index]->get_y();
}

int enemies::get_weaponsize()
{
	return l.size();
}



void enemies::gravity(player* & p)
{
}

void enemies::init()
{
	
}

void enemies::killweapon(int index)
{
	l.erase(l.begin() + index);
}

void enemies::weapon_ability(player *& p)
{
}

void enemies::decrement_health(int damage)
{

}

bool enemies::getlife()
{
	return enemylife;
}

void enemies::update()
{
	for (int i = 0; i < l.size(); i++)
	{
		
		l[i]->set_shot(true);
		l[i]->shoot();
		
		if (l[i]->get_y() > winy)
		{
			l.erase(l.begin() + i);
		}
	}

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

void enemies::setlife(bool life)
{
	enemylife = life;
}

void enemies::set_x(int x)
{
	this->x = x;
}

void enemies::set_y(int y)
{
	this->y = y;
}

void enemies::set_vel(int vel)
{
	this->vel = vel;
}

void enemies::moveleft()
{
	this->x--;
	set_x(this->x);
}

void enemies::moveright()
{
	this->x++;
	set_x(this->x);
}

void enemies::moveup()
{
	this->y--;
	set_y(this->y);
}

void enemies::movedown()
{
	this->y++;
	set_y(this->y);
}

void enemies::shoot_probability()
{
	this->probability_of_shooting = rand() % 501;
}

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

void enemies::randomize_CID()
{
}

void enemies::update_animation()
{
	if (get_hit())
	{
		animate.increment_frame();
	}

	if (animate.get_frame() == 50)
	{
		animate.set_frame(0);
		this->hit = false;
		set_hit(this->hit);
	}
}

void enemies::update_destroy_animation()
{
	destroying.increment_frame();
}

void enemies::decrement_delay()
{
	if (get_delay() > 0)
	{
		this->delay--;
		set_delay(this->delay);
	}
}

void enemies::set_coord_ID(int coordID)
{
	this->coordID = coordID;
}

void enemies::set_hit(bool hit)
{
	this->hit = hit;
}

void enemies::set_delay(int delay)
{
	this->delay = delay;
}

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

void enemies::draw_E_weapon(ALLEGRO_BITMAP * bmp)
{
	for (int i = 0; i < l.size(); i++)
	{
		al_draw_bitmap(bmp, l[i]->get_x(), l[i]->get_y(), NULL);
	}
}

void enemies::draw_destroy(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3)
{
	if (this->health <= 0)
	{
		destroying.three_frames_custom(bmp, bmp2, bmp3, get_x(), get_y(), get_destroy_frame(), 20, 5, 10, 15);
	}
}

void enemies::clear_weapon()
{
	l.clear();
}

void enemies::ability(player* & p, ALLEGRO_EVENT e)
{

}

void enemies::countdown_duration()
{
	if (get_duration() != 0)
	{
		this->duration--;
		set_duration(this->duration);
	}
}

void enemies::release()
{
	if (get_duration() == 0 && get_coord_ID() > 3)
	{
		this->coordID = rand() % 2;
		set_coord_ID(this->coordID);
	}
}

void enemies::set_name_ID(int nameID)
{
	this->enemyID = nameID;
}

void enemies::set_health(int health)
{
	this->health = health;
}

void enemies::set_duration(int duration)
{
	this->duration = duration;
}
