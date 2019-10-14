#include "Stages.h"



Stages::Stages()
{
	//initial variable
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
	//load assets for the stage
	stage[EARTH] = al_load_bitmap("Earth.png");
	stage[MARS] = al_load_bitmap("Mars.png");
	stage[AST] = al_load_bitmap("asteroid_belt.png");
	stage[SATURN] = al_load_bitmap("saturn's_ring.png");

	//load assets for the stage if disfig is true 
	stage_disfig[EARTH] = al_load_bitmap("Earth_disfigurement.png");
	stage_disfig[MARS] = al_load_bitmap("Mars_disfigurement.png");
	stage_disfig[AST] = al_load_bitmap("asteroid_belt_disfigurement.png");
	stage_disfig[SATURN] = al_load_bitmap("saturn's_ring_disfigurement.png");
}

void Stages::earth()
{
	//does animation if player gets disfigurement and is on earth
	if (get_disfig())
	{
		a.two_frames_custom(stage[EARTH], stage_disfig[EARTH], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	//displays Earth background
	else
	{
		al_draw_bitmap(stage[EARTH], 0, get_y(), NULL);
	}

}

void Stages::mars()
{
	//does animation if player gets disfigurement and is on mars
	if (get_disfig())
	{
		a.two_frames_custom(stage[MARS], stage_disfig[MARS], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	//displays Mars background
	else
	{
		al_draw_bitmap(stage[MARS], 0, get_y(), NULL);
	}
}

void Stages::astroid_belt()
{
	//does animation if player gets disfigurement and is on astroid belt
	if (get_disfig())
	{
		a.two_frames_custom(stage[AST], stage_disfig[AST], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	//displays Astroid Belt background
	else
	{
		al_draw_bitmap(stage[AST], 0, get_y(), NULL);
	}
}

void Stages::saturn()
{
	//does animation if player gets disfigurement and is on saturn
	if (get_disfig())
	{
		a.two_frames_custom(stage[SATURN], stage_disfig[SATURN], 0, get_y(), a.get_frame(), 5, 0, 2);
	}

	//displays Saturn background
	else
	{
		al_draw_bitmap(stage[SATURN], 0, get_y(), NULL);
	}
}

void Stages::stop_moving()
{
	//the stage moves the opposite by 1 px to stop the movement
	y -= 1;
}

//funtion not used
void Stages::set_spawn(bool spawn)
{
	this->spawn = spawn;
}

void Stages::scroll_down()
{
	//the background image moves by 1px
	this->y++;
}

void Stages::destroy_stages()
{
	//deallocates all assets memory
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(stage[i]);
		al_destroy_bitmap(stage_disfig[i]);
	}
}

//function not used
void Stages::set_pause(bool pause)
{
	this->pause = pause;
}

//sets y coordinate
void Stages::set_y(int y)
{
	this->y = y;
}


//function not used
bool Stages::get_spawn()
{
	return this->spawn;
}

//function not used
bool Stages::get_pause()
{
	return this->pause;
}

//returns whether player gets disfigurement
bool Stages::get_disfig()
{
	return this->disfig;
}

//returns stage number
int Stages::get_stage()
{
	return this->stagenum;
}

//returns y coordinate
int Stages::get_y()
{
	return this->y;
}

//returns bitmap height
int Stages::get_h()
{
	switch (get_stage())
	{
	case EARTH:
		return -al_get_bitmap_height(stage[EARTH]) + 400;
		break;

	case MARS:
		return -al_get_bitmap_height(stage[MARS]) + 400;
		break;

	case AST:
		return -al_get_bitmap_height(stage[AST]) + 400;
		break;

	case SATURN:
		return -al_get_bitmap_height(stage[SATURN]) + 400;
		break;
	}
	return 0;
}

//updates the animation
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

//displays the stage text
void Stages::display_stage(std::string Stagename, ALLEGRO_FONT * font)
{
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 425, NULL, Stagename.c_str());
}

//sets stage number
void Stages::set_stage(int stagenum)
{
	this->stagenum = stagenum;
}

//sets whether player gets disfigurement
void Stages::set_disfig(bool disfig)
{
	this->disfig = disfig;
}




