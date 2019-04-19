#include "screen_manager.h"

enum { PLAY, QUIT };

screen_manager::screen_manager()
{
}


screen_manager::~screen_manager()
{
}

void screen_manager::initilize_loop()
{
	
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	
	//splash screen

	
	ss.init();

	display = al_create_display(winx, winy);
	queue = al_create_event_queue();

	timer = al_create_timer(1 / fps);

	play.load_stuff();
	menu.load();

	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	

	
}

void screen_manager::display_loop()
{
	menu.setChoice(PLAY);
	al_start_timer(timer);
	while (bool go = true)
	{
		al_wait_for_event(queue, &e);

		//play.loop(e, queue);
		menu.loop(e, queue);

		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{			
			if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
			{
				break;
			}
		}

		menu.update(e, queue);
		
	}
	menu.dochoice(e, queue, play);
}



void screen_manager::destroy_stuff()
{
	al_destroy_display(display);
	al_destroy_event_queue(queue);
	play.destroy_stuff();
	menu.destory();
}