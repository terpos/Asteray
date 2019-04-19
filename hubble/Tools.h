#pragma once
class Tools
{
public:
	Tools();
	~Tools();
	
	int get_tool_ID();
	int get_x();
	int get_y();


	void set_tool_ID(int ID);
	void set_x(int x);
	void set_y(int y);

private:
	int toolsID;
	int x, y;
};

