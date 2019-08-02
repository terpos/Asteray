#include "Enemy_Lazer.h"



Enemy_Lazer::Enemy_Lazer(int x, int y, int vel, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_coord_ID(cid);
	set_shot(false);
}


Enemy_Lazer::~Enemy_Lazer()
{
}

int Enemy_Lazer::get_x()
{
	return this->x;
}

int Enemy_Lazer::get_y()
{
	return this->y;
}

int Enemy_Lazer::get_vel()
{
	return this->vel;
}

int Enemy_Lazer::get_coord_ID()
{
	return this->cid;
}

bool Enemy_Lazer::isshot()
{
	return this->shot;
}

void Enemy_Lazer::set_x(int x)
{
	this->x = x;
}

void Enemy_Lazer::set_y(int y)
{
	this->y = y;
}

void Enemy_Lazer::set_vel(int vel)
{
	this->vel = vel;
}

void Enemy_Lazer::set_coord_ID(int cid)
{
	this->cid = cid;
}

void Enemy_Lazer::set_shot(bool isshot)
{
	this->shot = isshot;
}

void Enemy_Lazer::shoot()
{
	if (isshot())
	{
		if (get_coord_ID() == DOWN)
		{
			this->y += get_vel();
			set_y(this->y);
		}

		if (get_coord_ID() == UP)
		{
			this->y -= get_vel();
			set_y(this->y);
		}

		if (get_coord_ID() == LEFT)
		{
			this->x -= get_vel();
			set_x(this->x);
		}

		if (get_coord_ID() == RIGHT)
		{
			this->x += get_vel();
			set_x(this->x);
		}
	}
}

void Enemy_Lazer::render_shot(ALLEGRO_BITMAP *bmp, int x, int y)
{
	al_draw_bitmap(bmp, x, y, NULL);
}

