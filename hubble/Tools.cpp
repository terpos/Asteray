#include "Tools.h"



Tools::Tools(int x, int y, int ID)
{
	set_x(x);
	set_y(y);
	set_tool_ID(ID);
}

Tools::~Tools()
{
}

int Tools::get_tool_ID()
{
	return this->toolsID;
}

int Tools::get_x()
{
	return this->x;
}

int Tools::get_y()
{
	return this->y;
}

void Tools::set_x(int x)
{
	this->x = x;
}

void Tools::set_y(int y)
{
	this->y = y;
}

void Tools::set_tool_ID(int ID)
{
	this->toolsID = ID;
}
