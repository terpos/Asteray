#include "Splash_Screen.h"



Splash_Screen::Splash_Screen()
{
	splashscrn = NULL;
	font = NULL;
	delay = 3;
}


Splash_Screen::~Splash_Screen()
{
}

void Splash_Screen::init()
{
	scrn = al_load_bitmap("ss.png");
	font = al_load_font("ariblk.ttf", 32, NULL);
	splashscrn = al_create_display(500, 250);
	al_set_display_flag(splashscrn, ALLEGRO_NOFRAME, true);
	al_draw_bitmap(scrn, 0, 0, NULL);
	al_draw_text(font, al_map_rgb(255, 255, 255), 160, 100, NULL, "ASTERAY");
	al_flip_display();
	al_rest(delay);
	al_destroy_font(font);
	al_destroy_bitmap(scrn);
	al_destroy_display(splashscrn);
}
