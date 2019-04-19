#include "Event.h"



Event::Event()
{
}


Event::~Event()
{
}

int Event::event_keypress(int key, ALLEGRO_EVENT e)
{
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == key)
		{
			return key;
		}
	}
}