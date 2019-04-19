#include "player.h"

//direction
//enum {LEFT, RIGHT, UP, DOWN};



player::player()
{
	vel = 5;
	this->enable = true;
	set_enable(this->enable);
}


player::~player()
{

}

void player::load()
{
	ship = al_load_bitmap("ship.png");
}

void player::control(ALLEGRO_EVENT e)
{
	if (get_enable() == true)
	{
		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			}
		}



		if (e.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			}
		}

	}
	}

void player::update()
{
	if (get_enable())
	{
		x += vel * keys[RIGHT];
		x -= vel * keys[LEFT];
		y += vel * keys[DOWN];
		y -= vel * keys[UP];
	}
	
	
}

void player::render()
{
	al_draw_bitmap(ship, this->x, this->y, NULL);
}

void player::destroy()
{
	al_destroy_bitmap(ship);
	
}

int player::get_x()
{
	return this->x;
}

int player::get_y()
{
	return this->y;
}

int player::get_h()
{
	return al_get_bitmap_height(ship);
}

int player::get_w()
{
	return al_get_bitmap_width(ship);
}

int player::get_vel()
{
	return this->vel;
}

bool player::get_enable()
{
	return this->enable;
}

void player::set_movement(int num, bool val)
{
	keys[num] = val;
}

void player::set_coords(int x, int y)
{
	this->x = x;
	this->y = y;
}

void player::set_vel(int v)
{
	this->vel = v;
}

void player::set_x(int x)
{
	this->x = x;
}

void player::set_y(int y)
{
	this->y = y;
}

void player::set_enable(bool enable)
{
	this->enable = enable;
}
