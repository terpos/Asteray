#include "screen_manager.h"

//inital variable assignment
screen_manager::screen_manager()
{
	loop = true;
}


screen_manager::~screen_manager()
{
}

//initalize install the functionality to use allegro 5
void screen_manager::initilize_loop()
{
	//installs hardware
	al_install_audio();
	al_install_keyboard();
	al_install_mouse();

	//initializes addons
	//to use different shapes
	//and extentions not compatible for
	//allegro 5 itself
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	
	//loads icon bitmaps
	icon = al_load_bitmap("Asteray_icon.png");

	//initializes splash screen
	ss.tmp_splash_screen_display();

	//creates display with dimension of 500 x 500
	display = al_create_display(winx, winy);
	
	//creates event queue
	queue = al_create_event_queue();

	//creates timer with 60fps
	timer = al_create_timer(1 / fps);

	//loads all assets in menu
	menu.load(play);

	//registers event source for
	//mouse, display, timer, and keyboard
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));
	
	//displays icons
	al_set_display_icon(display, icon);
	
	//sets the selection to play before enter is pressed
	menu.setChoice(PLAY);

	//starts timer
	al_start_timer(timer);
	
}

void screen_manager::display_loop()
{
	
	//while loop to keep the window open until
	//loop becomes false
	while (loop)
	{
		//waits for an event
		al_wait_for_event(queue, &e);

		//if someone clicks on the x button
		if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			loop = false;
		}

		//handles the keyboard and mouse events in menu class
		menu.event_listener(e, queue);

		//updates variables in menu class
		menu.update(e, queue, play, loop);
	}
	
}


//destroys all assets in this class, game class, and menu class
void screen_manager::destroy_stuff()
{
	al_destroy_display(display);
	al_destroy_event_queue(queue);
	play.destroy_stuff();
	menu.destory();
}