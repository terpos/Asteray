#include "Status.h"



Status::Status()
{
	
}


Status::~Status()
{
}

int Status::gethealth()
{
	//returns player's health
	return this->health;
}

int Status::getmaxhealth()
{
	//returns player's max health
	return this->maxhealth;
}

std::string Status::getnotification()
{
	//returns notification
	return this->notification;
}

int Status::getlvl()
{
	//returns level
	return this->lvl;
}

int Status::getweapon()
{
	//returns weapon
	return this->weapon;
}

int Status::getscore()
{
	//returns score
	return this->score;
}

void Status::sethealth(int &health, ALLEGRO_FONT *font)
{
	//sets health and displays it on the windows
	this->health = health;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 230, 455, NULL, "Health: %i", health);
}

void Status::setmaxehealth(int maxhealth)
{
	//sets max health
	this->maxhealth = maxhealth;
}

//sets notification and displays it on the windows
void Status::setnotification(std::string notification, ALLEGRO_FONT *font)
{
	
	this->notification = notification;
	al_draw_text(font, al_map_rgb(0, 0, 255), 200, 400,NULL, notification.c_str());
}

void Status::setnotification(std::string notification, ALLEGRO_FONT *font, int x, int y, ALLEGRO_COLOR c)
{
	this->notification = notification;

	al_draw_text(font, c, x, y, NULL, notification.c_str());
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



//sets notification and displays it on the windows
void Status::setlvl(int lvl, ALLEGRO_FONT *font)
{
	this->lvl = lvl;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 50, 440, NULL, "LEVEL %i", lvl);
}

//sets weapons
void Status::setweapon(int weapon)
{
	this->weapon = weapon;
}

//sets score and displays it on the windows
void Status::setscore(int score, ALLEGRO_FONT *font)
{
	this->score = score;
	al_draw_textf(font, al_map_rgb(0, 0, 0), 50, 455, NULL, "SCORE: %i", score);
}

void Status::setscore(int score, ALLEGRO_FONT *font, int x, int y)
{
	this->score = score;
	al_draw_textf(font, al_map_rgb(0, 0, 0), x, y, NULL, "SCORE: %i", score);
}

void Status::setscore(int score, ALLEGRO_FONT * font, std::string sctype, int x, int y)
{
	this->score = score;
	al_draw_textf(font, al_map_rgb(0, 0, 0), x, y, NULL, "%s %i", sctype.c_str(), score);
}



//displays health bar
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

//this function is not used
void Status::Notify(int kill_goal, int enemies_killed, std::string notification)
{
	if (kill_goal == enemies_killed)
	{
		//setnotification(notification);
		
		//std::cout << getnotification() << std::endl;
	}

	
}

//this function is not used
void Status::level_up(int num_of_enemies, int level)
{
	if (num_of_enemies == 0)
	{
		level = level + 1;
		//setlvl(level);
	}
}

//displays status
void Status::Status_box(int x, int y, int x2, int y2)
{
	al_draw_filled_rectangle(x, y, x2, y2, al_map_rgb(255, 140, 0));

}


//displays primary weapon box
void Status::prime_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f)
{
	al_draw_filled_rectangle(350, 415, 375, 480, al_map_rgb(200,200,0));
	al_draw_bitmap(weapon, 357, 427, NULL);
	al_draw_text(f, al_map_rgb(0, 0, 0), 358, 415, NULL, "Z");
}

//displays secondary weapon box
void Status::secondary_Weapon_box(ALLEGRO_BITMAP *weapon, ALLEGRO_FONT *f, int ammo)
{
	al_draw_filled_rectangle(380, 415, 410, 490, al_map_rgb(255, 10, 0));
	al_draw_bitmap(weapon, 382, 427, NULL);
	al_draw_text(f, al_map_rgb(0, 0, 0), 390, 415, NULL, "X");
	al_draw_textf(f, al_map_rgb(0, 0, 0), 390, 480, NULL, "%i", ammo);
}

//displays empty weapon box
void Status::empty_Weapon_box(ALLEGRO_FONT *f, int ammo)
{
	al_draw_filled_rectangle(380, 415, 410, 490, al_map_rgb(255, 10, 0));
	al_draw_text(f, al_map_rgb(0, 0, 0), 390, 415, NULL, "X");
}



