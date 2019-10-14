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

	//returns tool's identity
	int get_tool_ID();

	//returns x coordinate
	int get_x();
	int get_x2();

	//returns y coordinate
	int get_y();
	int get_y2();

	//sets x coordinate
	void set_x(int x);
	void set_x2(int x2);

	//sets y coordinate
	void set_y(int y);
	void set_y2(int y2);

	//loads assets
	void load();

	//displays or plays assets to the screen
	void draw(int ID, int toolsID, int ammoID, bool weaponammo[6], int x, int y, int x2, int y2);
	void draw(int toolsID, int x, int y);
	void draw(int ammoID, bool weaponammo[6], int x, int y);

	//deallocates assets
	void destroy();

	//updates coordinates
	void update(std::vector <Ammo *> &a, std::vector <Tools *> &t);

	//returns width based on identity
	int get_ammo_w(int ammo_ID);
	int get_tools_w(int tools_ID);

	//returns height based on identity
	int get_ammo_h(int ammo_ID);
	int get_tools_h(int tools_ID);

	//sets tool's identity
	void set_tool_ID(int ID);

	

private:
	//assets
	ALLEGRO_BITMAP *tools[2];
	ALLEGRO_BITMAP *ammo[7];
	
	//int variables
	int toolsID;
	int x, y, x2, y2;
};

