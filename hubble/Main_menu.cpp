#include "Main_menu.h"



enum { TITLE, CHOICE };


Main_menu::Main_menu()
{
	fontSize[TITLE] = 32;
	fontSize[CHOICE] = 24;
	render = false;
	screen = 0;
}


Main_menu::~Main_menu()
{
}

int Main_menu::getChoice()
{
	return this->choice;
}

void Main_menu::setChoice(int choice)
{
	this->choice = choice;
}

void Main_menu::setscreen(int screen)
{
	this->screen = screen;
}

void Main_menu::load()
{
	menuSel[TITLE] = al_load_font("ariblk.ttf", fontSize[TITLE], NULL);
	menuSel[CHOICE] = al_load_font("pixellari.ttf", fontSize[CHOICE], NULL);
	menuBG = al_load_bitmap("Menu.png");
	mt = al_load_sample("Asteray_Main_Theme.ogg");
	Main_Theme = al_create_sample_instance(mt);

	pause = al_load_ttf_font("bahnschrift.ttf", 30, NULL);
	pause_options = al_load_ttf_font("bahnschrift.ttf", 20, NULL);
	status = al_load_ttf_font("bahnschrift.ttf", 15, NULL);


	al_attach_sample_instance_to_mixer(Main_Theme, al_get_default_mixer());
	al_set_sample_instance_playmode(Main_Theme, ALLEGRO_PLAYMODE_LOOP);
}

void Main_menu::loop(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q)
{
		if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 0)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				destory();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_DOWN:
				this->choice = (this->choice + 1) % 3;
				setChoice(this->choice);
				break;

			case ALLEGRO_KEY_UP:
				choice = (this->choice - 1) % 3;
				if (choice < 0)
				{
					choice = 2;
				}

				setChoice(this->choice);
				break;
			}
		}

		else if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 1)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_SPACE:
				screen = 0;
				break;
			}
		}
}

void Main_menu::dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop g)
{
	if (getChoice() == PLAY)
	{
		al_stop_sample_instance(Main_Theme);
		g.loop(e, q);
	}

	else if (getChoice() == HOWTO)
	{
		screen = 1;
	}


	else if (getChoice() == QUIT)
	{
		g.destroy_stuff();
		destory();
		exit(EXIT_SUCCESS);
	}
}

void Main_menu::update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q)
{
	if (e.type == ALLEGRO_EVENT_TIMER)
	{
		

		render = true;
		draw();
	}
}

void Main_menu::draw()
{
	if (render && screen == 0)
	{
		al_draw_text(menuSel[TITLE], al_map_rgb(255, 255, 255), 150, 50, NULL, "ASTERAY");


		

		al_draw_bitmap(menuBG, 0, 0, NULL);

		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 150, NULL, "PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 200, NULL, "HOW TO PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 250, NULL, "QUIT");

		al_play_sample_instance(Main_Theme);

		switch (getChoice())
		{
		case PLAY:
			al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 150, NULL, "PLAY");
			break;

		case HOWTO:

			al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 200, NULL, "HOW TO PLAY");


			break;

		case QUIT:
			al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 250, NULL, "QUIT");
			break;
		}

		render = false;
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	else if (render && screen == 1)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		stat.setnotification("HOW TO PLAY", pause, 150, 0, al_map_rgb(200, 0, 100));

		stat.setnotification("PRESS (ESC) IF YOU WANT TO QUIT", pause_options, 0, 100, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (P) IF YOU WANT TO CONTINUE OR PAUSE", pause_options, 0, 130, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (R) TO RESET THE GAME (ONLY IN PAUSE MENU)", pause_options, 0, 160, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (DIRECTIONAL KEY) TO MOVE THE PLAYER", pause_options, 0, 190, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (Z) TO SHOOT LAZERS", pause_options, 0, 220, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (X) TO SHOOT SPECIAL WEAPONS", pause_options, 0, 250, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (A) or (S) TO SWITCH SPECIAL WEAPONS", pause_options, 0, 280, al_map_rgb(50, 255, 255));

		stat.setnotification("[PRESS (SPACEBAR) TO GO BACK TO MAIN MENU]", status, 75, 500 - 30, al_map_rgb(255, 255, 255));

		al_flip_display();
	}
}

void Main_menu::destory()
{
	al_destroy_font(menuSel[TITLE]);
	al_destroy_font(menuSel[CHOICE]);
	al_destroy_bitmap(menuBG);
	al_destroy_sample(mt);
	al_destroy_sample_instance(Main_Theme);
}
