#include "Tools_manager.h"



Tools_manager::Tools_manager()
{
	tools[0] = NULL;
	tools[1] = NULL;
	
	ammo[0] = NULL;
	ammo[1] = NULL;
	ammo[2] = NULL;
	ammo[3] = NULL;
	ammo[4] = NULL;
	ammo[5] = NULL;

}


Tools_manager::~Tools_manager()
{
}

int Tools_manager::get_tool_ID()
{
	return this->toolsID;
}

int Tools_manager::get_x()
{
	return this->x;
}

int Tools_manager::get_x2()
{
	return this->x2;
}

int Tools_manager::get_y()
{
	return this->y;
}

int Tools_manager::get_y2()
{
	return this->y2;
}

void Tools_manager::load()
{
	tools[0] = al_load_bitmap("health.png");
	tools[1] = al_load_bitmap("disfigurement.png");

	ammo[0] = al_load_bitmap("iceammo.png");
	ammo[1] = al_load_bitmap("fireammo.png");
	ammo[2] = al_load_bitmap("ziggonetammo.png");
	ammo[3] = al_load_bitmap("haych.png");
	ammo[4] = al_load_bitmap("haychbarammo.png");
	ammo[5] = al_load_bitmap("Sonic_wave_ammo.png");
}

void Tools_manager::draw(int ID, int toolsID, int ammoID, bool weaponammo[6], int x, int y, int x2, int y2)
{
	set_x(x);
	set_y(y);
	set_x2(x2);
	set_y2(y2);
	
	switch (ID)
	{
	case TOOLS:
		switch (toolsID % 4)
		{
		case HEALTH:
			al_draw_bitmap(tools[HEALTH], get_x(), get_y(), NULL);
			break;

		case DISFIG:
			al_draw_bitmap(tools[DISFIG], get_x(), get_y(), NULL);
			break;
		}
		break;

	case AMMO:
		switch (ammoID % 25)
		{
		case ICE:
			if (weaponammo[ICET])
				al_draw_bitmap(ammo[ICET], get_x2(), get_y2(), NULL);
			break;

		case FIRE:
			if (weaponammo[INFERRED])
				al_draw_bitmap(ammo[INFERRED], get_x2(), get_y2(), NULL);
			break;

		case ZIG:
			if (weaponammo[ZIGGONET])
				al_draw_bitmap(ammo[ZIGGONET], get_x2(), get_y2(), NULL);
			break;

		case H:
			if (weaponammo[HAYCH])
				al_draw_bitmap(ammo[HAYCH], get_x2(), get_y2(), NULL);
			break;

		case HBAR:
			if (weaponammo[HAYCHBA])
				al_draw_bitmap(ammo[HAYCHBA], get_x2(), get_y2(), NULL);
			break;

		case WAVE:
			if (weaponammo[SONICWAVE])
				al_draw_bitmap(ammo[SONICWAVE], get_x2(), get_y2(), NULL);
			break;
		}
		break;
	}

	
}

void Tools_manager::draw(int toolsID, int x, int y)
{
	set_x(x);
	set_y(y);
		
	switch (toolsID % 4)
	{
		case HEALTH:
			al_draw_bitmap(tools[HEALTH], get_x(), get_y(), NULL);
			break;

		case DISFIG:
			al_draw_bitmap(tools[DISFIG], get_x(), get_y(), NULL);
			break;
	}
		


}


void Tools_manager::draw(int ammoID, bool weaponammo[6], int x, int y)
{
	//set_x(x);
	//set_y(y);

	switch (ammoID)
	{
		case ICE:
			if (weaponammo[ICET] == true){
				al_draw_bitmap(ammo[ICET], x, y, NULL);
				
			}
			break;

		case FIRE:
			if (weaponammo[INFERRED]){
				al_draw_bitmap(ammo[INFERRED], x, y, NULL);
			}
			break;

		case ZIG:
			if (weaponammo[ZIGGONET]) {
				al_draw_bitmap(ammo[ZIGGONET], x, y, NULL);
			}
			break;

		case H:
			if (weaponammo[HAYCH]){
				al_draw_bitmap(ammo[HAYCH], x, y, NULL);
			}
			break;

		case HBAR:
			if (weaponammo[HAYCHBA]){
				al_draw_bitmap(ammo[HAYCHBA], x, y, NULL);
			}
			break;

		case WAVE:
			if (weaponammo[SONICWAVE]){
				al_draw_bitmap(ammo[SONICWAVE], get_x(), get_y(), NULL);
			}
			break;
	}
}

void Tools_manager::destroy()
{
	for (int i = 0; i < 2; i++)
	{
		al_destroy_bitmap(tools[i]);
	}
	
	for (int i = 0; i < 6; i++)
	{
		al_destroy_bitmap(ammo[i]);
	}
}

void Tools_manager::set_tool_ID(int ID)
{
	this->toolsID = ID;
}

void Tools_manager::set_x(int x)
{
	this->x = x;
}

void Tools_manager::set_x2(int x2)
{
	this->x2 = x2;
}

void Tools_manager::set_y(int y)
{
	this->y = y;
}

void Tools_manager::set_y2(int y2)
{
	this->y2 = y2;
}
