#include "global.h"
#include "enemies.h"
#include "Tools.h"
#include "Ammo.h"

#pragma once

enum {TOOLS, AMMO};

class Tools_manager
{
public:
	Tools_manager();
	~Tools_manager();

	int get_tool_ID();
	int get_x();
	int get_x2();
	int get_y();
	int get_y2();

	void load();
	void draw(int ID, int toolsID, int ammoID, bool weaponammo[6], int x, int y, int x2, int y2);
	void draw(int toolsID, int x, int y);
	void draw(int ammoID, bool weaponammo[6], int x, int y);
	void destroy();

	void set_tool_ID(int ID);

	void set_x(int x);
	void set_x2(int x2);
	void set_y(int y);
	void set_y2(int y2);

private:
	ALLEGRO_BITMAP *tools[2];
	ALLEGRO_BITMAP *ammo[6];
	
	int toolsID;
	int x, y, x2, y2;
};

