#include "enemies.h"



enemies::enemies(int x, int y, int vel, int coord)
{
	this->x = x;
	this->y = y;
	this->vel = vel;
	set_hit(false);
	init();
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

void enemies::gravity(player* & p)
{
}

void enemies::init()
{
	animate.set_frame(0);
	destroying.set_frame(0);
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
	switch (get_coord_ID())
	{
	case UP:
		y--;
		//y = sin((20 * 3.14)*(y - 1));
		set_y(y);
		break;

	case DOWN:
		y++;
		//y = sin((20*3.14)*(y+1));
		set_y(y);
		break;

	case LEFT:
		x--;
		//x = sin((20 * 3.14)*(x + 1));
		set_x(x);
		break;

	case RIGHT:
		x++;
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

void enemies::set_coord_ID(int coordID)
{
	this->coordID = coordID;
}

void enemies::set_hit(bool hit)
{
	this->hit = hit;
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

void enemies::draw_destroy(ALLEGRO_BITMAP * bmp, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3)
{
	if (this->health <= 0)
	{
		destroying.three_frames_custom(bmp, bmp2, bmp3, get_x(), get_y(), get_destroy_frame(), 20, 5, 10, 15);
	}
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
		this->coordID = rand() % 4;
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
