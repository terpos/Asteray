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
	srand(time(0));
	scrn = al_load_bitmap("ss.png");
	font = al_load_font("ariblk.ttf", 32, NULL);
	status = al_load_ttf_font("bahnschrift.ttf", 15, NULL);
	randomtips = rand() % 17;
	splashscrn = al_create_display(500, 250);

	al_set_display_flag(splashscrn, ALLEGRO_NOFRAME, true);

	al_draw_bitmap(scrn, 0, 0, NULL);

	al_draw_text(font, al_map_rgb(255, 255, 255), 170, 100, NULL, "ASTERAY");

	switch (randomtips)
	{
	case 0:
		stat.setnotification("TIP: PRESS (ESC) IF YOU WANT TO QUIT", status, 130, 2, al_map_rgb(255, 255, 255));
		break;
	case 1:
		stat.setnotification("TIP: PRESS (P) IF YOU WANT TO CONTINUE OR PAUSE", status, 80, 2, al_map_rgb(255, 255, 255));
		break;
	case 2:
		stat.setnotification("TIP: PRESS (R) TO RESET THE GAME (ONLY IN PAUSE MENU)", status, 50, 2, al_map_rgb(255, 255, 255));
		break;
	case 3:
		stat.setnotification("TIP: PRESS (DIRECTIONAL KEY) TO MOVE THE PLAYER", status, 100, 2, al_map_rgb(255, 255, 255));
		break;
	case 4:
		stat.setnotification("TIP: PRESS (Z) TO SHOOT LAZERS", status, 150, 2, al_map_rgb(255, 255, 255));
		break;
	case 5:
		stat.setnotification("TIP: PRESS (X) TO SHOOT SPECIAL WEAPONS", status, 120, 2, al_map_rgb(255, 255, 255));
		break;
	case 6:
		stat.setnotification("TIP: PRESS (A) or (S) TO SWITCH SPECIAL WEAPONS", status, 80, 2, al_map_rgb(255, 255, 255));
		break;

	case 7:
		stat.setnotification("A TERP GAME", status, 200, 2, al_map_rgb(255, 255, 255));
		break;

	case 8:
		stat.setnotification("JUST HAVE FUN", status, 200, 2, al_map_rgb(255, 255, 255));
		break;

	case 9:
		stat.setnotification("A SPACE SHOOTING GAME", status, 170, 2, al_map_rgb(255, 255, 255));
		break;

	case 10:
		stat.setnotification("TIP: FREEZE YOUR ENEMIES WITH ICET", status, 130, 2, al_map_rgb(255, 255, 255));
		break;

	case 11:
		stat.setnotification("TIP: BURN YOUR ENEMIES WITH INFERRED", status, 120, 2, al_map_rgb(255, 255, 255));
		break;

	case 12:
		stat.setnotification("TIP: STUN YOUR ENEMIES WITH ZIGGONET", status, 120, 2, al_map_rgb(255, 255, 255));
		break;

	case 13:
		stat.setnotification("TIP: THE WRENCH REFILLS YOUR HEALTH", status, 110, 2, al_map_rgb(255, 255, 255));
		break;

	case 14:
		stat.setnotification("TIP: THE DIAMOND SHAPE THINGY DESTROYS ALL ENEMIES", status, 60, 2, al_map_rgb(255, 255, 255));
		break;

	case 15:
		stat.setnotification("TIP: HEAR THE GUN RELOADS? YEAH, YOU JUST GOT AN AMMO! YAY!", status, 22, 2, al_map_rgb(255, 255, 255));
		break;

	case 16:
		stat.setnotification("TIP: HAYCH AND HAYCHBA ARE UNPREDICTIBLE", status, 100, 2, al_map_rgb(255, 255, 255));
		break;
	case 17:
		stat.setnotification("TIP: SONIC WAVE STUNS ALL ENEMIES! NIFTY HUH?", status, 80, 2, al_map_rgb(255, 255, 255));
		break;
	}
	
	al_flip_display();
	al_rest(delay);

	al_destroy_font(font);
	al_destroy_font(status);
	al_destroy_bitmap(scrn);
	al_destroy_display(splashscrn);
}
