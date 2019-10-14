#include "Tools.h"


//initial position and identity
Tools::Tools(int x, int y, int ID)
{
	set_x(x);
	set_y(y);
	set_tool_ID(ID);
}

Tools::~Tools()
{
}

//returns tool's identity
int Tools::get_tool_ID()
{
	return this->toolsID;
}

//returns x coordinate
int Tools::get_x()
{
	return this->x;
}

//returns y coordinate
int Tools::get_y()
{
	return this->y;
}

//set x position
void Tools::set_x(int x)
{
	this->x = x;
}

//set y position
void Tools::set_y(int y)
{
	this->y = y;
}

//set tool's identity
void Tools::set_tool_ID(int ID)
{
	this->toolsID = ID;
}
