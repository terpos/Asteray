#include "Status.h"



Status::Status()
{
	
}


Status::~Status()
{
}

int Status::gethealth()
{
	return this->health;
}

int Status::getmaxhealth()
{
	return this->maxhealth;
}

std::string Status::getnotification()
{
	return this->notification;
}

int Status::getlvl()
{
	return this->lvl;
}

int Status::getweapon()
{
	return this->weapon;
}

int Status::getscore()
{
	return this->score;
}

void Status::sethealth(int &health, ALLEGRO_FONT *font)
{
	this->health = health;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 230, 455, NULL, "Health: %i", health);
}

void Status::setmaxehealth(int maxhealth)
{
	this->maxhealth = maxhealth;
}


void Status::setnotification(std::string notification, ALLEGRO_FONT *font)
{
	this->notification = notification;

	al_draw_text(font, al_map_rgb(0, 0, 255), 200, 400,NULL, notification.c_str());
}

void Status::setnotification(std::string notification, ALLEGRO_FONT * font, int x, int y, int & frame)
{
	this->notification = notification;
	if (frame % 41 >= 0 && frame % 41 <= 20)
	{
		al_draw_text(font, al_map_rgb(0, 0, 255), x, y, NULL, notification.c_str());
	}
}

void Status::setnotification(std::string notification, ALLEGRO_FONT * font, int x, int y)
{
	this->notification = notification;

	al_draw_text(font, al_map_rgb(0, 0, 255), x, y, NULL, notification.c_str());
}



void Status::setlvl(int lvl, ALLEGRO_FONT *font)
{
	this->lvl = lvl;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 50, 440, NULL, "LEVEL %i", lvl);
}

void Status::setweapon(int weapon)
{
	this->weapon = weapon;
}

void Status::setscore(int score, ALLEGRO_FONT *font)
{
	this->score = score;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 50, 455, NULL, "SCORE: %i", score);
}

void Status::set_health_bar(int x, int y, int x2, int y2)
{
	al_draw_filled_rectangle(x, y, x2, y2, al_map_rgb(255, 0, 0));

	if (gethealth() > 100)
	{
		al_draw_filled_rectangle(x, y, x + 100, y2, al_map_rgb(0, 255, 0));
	}
	else
	{
		al_draw_filled_rectangle(x, y, x + gethealth(), y2, al_map_rgb(0, 255, 0));

	}

}

void Status::Notify(int kill_goal, int enemies_killed, std::string notification)
{
	if (kill_goal == enemies_killed)
	{
		//setnotification(notification);
		
		//std::cout << getnotification() << std::endl;
	}

	
}

void Status::level_up(int num_of_enemies, int level)
{
	if (num_of_enemies == 0)
	{
		level = level + 1;
		//setlvl(level);
	}
}

void Status::Status_box(int x, int y, int x2, int y2)
{
	al_draw_filled_rectangle(x, y, x2, y2, al_map_rgb(255, 140, 0));

}

void Status::prime_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f)
{
	al_draw_filled_rectangle(350, 415, 375, 480, al_map_rgb(200,200,0));
	al_draw_bitmap(weapon, 357, 427, NULL);
	al_draw_text(f, al_map_rgb(0, 0, 0), 358, 415, NULL, "Z");
}

void Status::secondary_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f, int ammo)
{
	al_draw_filled_rectangle(380, 415, 410, 490, al_map_rgb(255, 10, 0));
	al_draw_bitmap(weapon, 382, 427, NULL);
	al_draw_text(f, al_map_rgb(0, 0, 0), 390, 415, NULL, "X");
	al_draw_textf(f, al_map_rgb(0, 0, 0), 390, 480, NULL, "%i", ammo);
}




