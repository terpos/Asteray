#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class screen_state
{
public:
	screen_state();
	~screen_state();
	
	//this is for all different kinds of loop
	virtual void loop();
	virtual void timer();

protected:
	bool done;


};

