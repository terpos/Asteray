#pragma once

#include "global.h"


class Event
{
public:
	Event();
	~Event();

	int event_keypress(int key, ALLEGRO_EVENT e);

};

