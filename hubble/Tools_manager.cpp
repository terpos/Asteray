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
	set_x(x);
	set_y(y);

	switch (ammoID)
	{
		case ICE:
			if (weaponammo[ICET]){
				al_draw_bitmap(ammo[ICET], get_x(), get_y(), NULL);
				
			}
			break;

		case FIRE:
			if (weaponammo[INFERRED]){
				al_draw_bitmap(ammo[INFERRED], get_x(), get_y(), NULL);
			}
			break;

		case ZIG:
			if (weaponammo[ZIGGONET]) {
				al_draw_bitmap(ammo[ZIGGONET], get_x(), get_y(), NULL);
			}
			break;

		case H:
			if (weaponammo[HAYCH]){
				al_draw_bitmap(ammo[HAYCH], get_x(), get_y(), NULL);
			}
			break;

		case HBAR:
			if (weaponammo[HAYCHBA]){
				al_draw_bitmap(ammo[HAYCHBA], get_x(), get_y(), NULL);
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

void Tools_manager::update(std::vector<Ammo*>& a, std::vector<Tools*>& t)
{
	for (int i = 0; i < a.size(); i++)
	{
		a[i]->set_y(a[i]->get_y() + 2);
		if (a[i]->get_y() > winy)
		{
			a.erase(a.begin() + i);
		}
	}

	for (int i = 0; i < t.size(); i++)
	{
		t[i]->set_y(t[i]->get_y() + 2);
		if (t[i]->get_y() > winy)
		{
			t.erase(t.begin() + i);
		}
	}



}

int Tools_manager::get_ammo_w(int ammo_ID)
{
	switch (ammo_ID)
	{
	case ICE:
		al_get_bitmap_width(ammo[ICET]);
		break;

	case FIRE:
		al_get_bitmap_width(ammo[INFERRED]);
		break;

	case ZIG:
		al_get_bitmap_width(ammo[ZIGGONET]);
		break;

	case H:
		al_get_bitmap_width(ammo[HAYCH]);
		break;

	case HBAR:
		al_get_bitmap_width(ammo[HAYCHBA]);
		break;

	case WAVE:
		al_get_bitmap_width(ammo[SONICWAVE]);
		break;
	}
	return 0;
}

int Tools_manager::get_tools_w(int tools_ID)
{
	switch (tools_ID)
	{
	case HEALTH:
		al_get_bitmap_width(tools[HEALTH]);
		break;

	case DISFIG:
		al_get_bitmap_width(ammo[DISFIG]);
		break;
	}
	return 0;
}

int Tools_manager::get_ammo_h(int ammo_ID)
{
	switch (ammo_ID)
	{
	case ICE:
		al_get_bitmap_height(ammo[ICET]);
		break;

	case FIRE:
		al_get_bitmap_height(ammo[INFERRED]);
		break;

	case ZIG:
		al_get_bitmap_height(ammo[ZIGGONET]);
		break;

	case H:
		al_get_bitmap_height(ammo[HAYCH]);
		break;

	case HBAR:
		al_get_bitmap_height(ammo[HAYCHBA]);
		break;

	case WAVE:
		al_get_bitmap_height(ammo[SONICWAVE]);
		break;
	}
	return 0;
}

int Tools_manager::get_tools_h(int tools_ID)
{
	switch (tools_ID)
	{
	case HEALTH:
		al_get_bitmap_width(tools[HEALTH]);
		break;

	case DISFIG:
		al_get_bitmap_width(ammo[DISFIG]);
		break;
	}
	return 0;
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
