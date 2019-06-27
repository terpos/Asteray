#include "player.h"

//direction
//enum {LEFT, RIGHT, UP, DOWN};



player::player()
{
	vel = 5;

	this->movement = true;
	this->ability_to_shoot = true;
	this->special_condition = false;

	set_movement(this->movement);
	set_ability_to_shoot(this->ability_to_shoot);
	set_special_condition(this->special_condition);
}


player::~player()
{

}

void player::load()
{
	ship[0] = al_load_bitmap("ship.png");
	ship[1] = al_load_bitmap("ship_damaged.png");
	ship[2] = al_load_bitmap("ship_poisoned.png");
}

void player::control(ALLEGRO_EVENT &e)
{
	if (get_movement())
	{
		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				this->coord = LEFT;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				this->coord = RIGHT;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				this->coord = UP;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				this->coord = DOWN;
				break;
			}
		}
		
		set_coords_ID(this->coord);

	}

	else
	{
		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
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

		set_coords_ID(this->coord);

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

void player::update()
{
	if (get_movement())
	{
		x += vel * keys[RIGHT];
		x -= vel * keys[LEFT];
		y += vel * keys[DOWN];
		y -= vel * keys[UP];
	}
	
	
}

void player::render(Animate &hit)
{
	if (!ishit())
	{
		al_draw_bitmap(ship[0], this->x, this->y, NULL);
	}

	else
	{
		hit.two_frames_custom(ship[0], ship[1], this->x, this->y, hit.get_frame(), 7, 0, 3);
	}

	if (get_special_condition())
	{
		al_draw_bitmap(ship[2], this->x, this->y, NULL);
	}
}

void player::countdown_duration()
{
	if (get_duration() > 0)
	{
		this->duration--;
		set_duration(this->duration);
	}
	else
	{
		set_ability_to_shoot(true);
		set_special_condition(false);
		set_movement(true);
	}
}

void player::poisoned(Status & s, int & health, ALLEGRO_FONT *f)
{
	if (get_duration() % 10 == 0 && get_special_condition() && get_duration() > 0)
	{
		health--;
		s.sethealth(health, f);
	}
}

void player::destroy()
{
	al_destroy_bitmap(ship[0]);
	al_destroy_bitmap(ship[1]);
	al_destroy_bitmap(ship[2]);
	
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
	return al_get_bitmap_height(ship[0]);
}

int player::get_w()
{
	return al_get_bitmap_width(ship[0]);
}

int player::get_vel()
{
	return this->vel;
}

int player::get_duration()
{
	return this->duration;
}

int player::get_coords_ID()
{
	return this->coord;
}

bool player::get_movement()
{
	return this->movement;
}

bool player::get_ability_to_shoot()
{
	return this->ability_to_shoot;
}

bool player::get_special_condition()
{
	return this->special_condition;
}

bool player::ishit()
{
	return this->hit;
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

void player::set_coords_ID(int coords)
{
	this->coord = coords;
}

void player::set_movement(bool movement)
{
	this->movement = movement;
}

void player::set_special_condition(bool special_condition)
{
	this->special_condition = special_condition;
}

void player::set_ability_to_shoot(bool ability_to_shoot)
{
	this->ability_to_shoot = ability_to_shoot;
}

void player::set_duration(int duration)
{
	this->duration = duration;
}

void player::set_keys(int coord, bool movement)
{
	keys[coord] = movement;
}

void player::ship_hit(bool hit)
{
	this->hit = hit;
}
