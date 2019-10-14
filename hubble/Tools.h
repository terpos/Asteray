#include "global.h"
#pragma once
class Tools
{
public:
	//initial position and identity
	Tools(int x, int y, int ID);
	~Tools();
	
	//returns tool's identity
	int get_tool_ID();

	//return x coordinate
	int get_x();

	//return y coordinate
	int get_y();

	//sets the tool's identity
	void set_tool_ID(int ID);

	//sets x position
	void set_x(int x);

	//sets y position
	void set_y(int y);

private:
	//int variables
	int toolsID;
	int x, y;
};

