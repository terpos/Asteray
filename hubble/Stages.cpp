#include "Stages.h"



Stages::Stages()
{
	y = -2800;
	pause = false;
	
}


Stages::~Stages()
{

}

void Stages::load_stages()
{
	stage[EARTH] = al_load_bitmap("Earth.png");
	stage[MARS] = al_load_bitmap("Mars.png");
	stage[AST] = al_load_bitmap("asteroid_belt.png");
	stage[SATURN] = al_load_bitmap("saturn's_ring.png");
}

void Stages::earth()
{
	al_draw_bitmap(stage[EARTH], 0, get_y(), NULL);
}

void Stages::mars()
{
	al_draw_bitmap(stage[MARS], 0, get_y(), NULL);
}

void Stages::astroid_belt()
{
	al_draw_bitmap(stage[AST], 0, get_y(), NULL);
}

void Stages::saturn()
{
	al_draw_bitmap(stage[SATURN], 0, get_y(), NULL);
}

void Stages::stop_moving()
{
		y -= 1;
}

void Stages::set_spawn(bool spawn)
{
	this->spawn = spawn;
}

void Stages::scroll_down()
{
	this->y++;
}

void Stages::destroy_stages()
{
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(stage[i]);
	}
}

void Stages::set_pause(bool pause)
{
	this->pause = pause;
}

void Stages::set_y(int y)
{
	this->y = y;
}


bool Stages::get_spawn()
{
	return this->spawn;
}

bool Stages::get_pause()
{
	return this->pause;
}

int Stages::get_stage()
{
	return this->stagenum;
}

int Stages::get_y()
{
	return this->y;
}

void Stages::display_stage(std::string Stagename, ALLEGRO_FONT * font)
{
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 425, NULL, Stagename.c_str());
}

void Stages::set_stage(int stagenum)
{
	this->stagenum = stagenum;
}




