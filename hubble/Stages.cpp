#include "Stages.h"



Stages::Stages()
{
	y = -2800;
	pause = false;
	a.set_frame(0);
	set_disfig(false);
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

	stage_disfig[EARTH] = al_load_bitmap("Earth_disfigurement.png");
	stage_disfig[MARS] = al_load_bitmap("Mars_disfigurement.png");
	stage_disfig[AST] = al_load_bitmap("asteroid_belt_disfigurement.png");
	stage_disfig[SATURN] = al_load_bitmap("saturn's_ring_disfigurement.png");
}

void Stages::earth()
{
	if (get_disfig())
	{
		a.two_frames_custom(stage[EARTH], stage_disfig[EARTH], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	else
	{
		al_draw_bitmap(stage[EARTH], 0, get_y(), NULL);
	}

}

void Stages::mars()
{
	if (get_disfig())
	{
		a.two_frames_custom(stage[MARS], stage_disfig[MARS], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	else
	{
		al_draw_bitmap(stage[MARS], 0, get_y(), NULL);
	}
}

void Stages::astroid_belt()
{
	if (get_disfig())
	{
		a.two_frames_custom(stage[AST], stage_disfig[AST], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	else
	{
		al_draw_bitmap(stage[AST], 0, get_y(), NULL);
	}
}

void Stages::saturn()
{
	if (get_disfig())
	{
		a.two_frames_custom(stage[SATURN], stage_disfig[SATURN], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	else
	{
		al_draw_bitmap(stage[SATURN], 0, get_y(), NULL);
	}
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
		al_destroy_bitmap(stage_disfig[i]);
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

bool Stages::get_disfig()
{
	return this->disfig;
}

int Stages::get_stage()
{
	return this->stagenum;
}

int Stages::get_y()
{
	return this->y;
}

void Stages::update_animation()
{
	if (get_disfig())
	{
		a.increment_frame();
	}

	if (a.get_frame() == 25)
	{
		a.set_frame(0);
		set_disfig(false);
	}
}

void Stages::display_stage(std::string Stagename, ALLEGRO_FONT * font)
{
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 425, NULL, Stagename.c_str());
}

void Stages::set_stage(int stagenum)
{
	this->stagenum = stagenum;
}

void Stages::set_disfig(bool disfig)
{
	this->disfig = disfig;
}




