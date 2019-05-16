#include "Main_menu.h"


enum { PLAY, QUIT };
enum { TITLE, CHOICE };


Main_menu::Main_menu()
{
	fontSize[TITLE] = 32;
	fontSize[CHOICE] = 24;
	render = false;
	
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

void Main_menu::load()
{
	menuSel[TITLE] = al_load_font("ariblk.ttf", fontSize[TITLE], NULL);
	menuSel[CHOICE] = al_load_font("pixellari.ttf", fontSize[CHOICE], NULL);
	menuBG = al_load_bitmap("Menu.png");
	mt = al_load_sample("Asteray_Main_Theme.ogg");
	Main_Theme = al_create_sample_instance(mt);

	al_attach_sample_instance_to_mixer(Main_Theme, al_get_default_mixer());
	al_set_sample_instance_playmode(Main_Theme, ALLEGRO_PLAYMODE_LOOP);
}

void Main_menu::loop(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q)
{
		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				destory();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_DOWN:
				this->choice = (this->choice + 1) % 2;
				setChoice(this->choice);
				break;

			case ALLEGRO_KEY_UP:
				choice = abs(this->choice - 1) % 2;
				setChoice(this->choice);
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
	if (render)
	{
		al_draw_text(menuSel[TITLE], al_map_rgb(255, 255, 255), 110, 50, NULL, "ASTERAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 200, 100), 160, 150, NULL, "PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 200, 100), 160, 200, NULL, "QUIT");
		al_draw_bitmap(menuBG, 0, 0, NULL);

		al_play_sample_instance(Main_Theme);

		switch (getChoice())
		{
		case PLAY:
			al_draw_text(menuSel[CHOICE], al_map_rgb(255, 0, 0), 160, 150, NULL, "PLAY");
			break;

		case QUIT:
			al_draw_text(menuSel[CHOICE], al_map_rgb(255, 0, 0), 160, 200, NULL, "QUIT");
			break;

		default:
			al_draw_text(menuSel[CHOICE], al_map_rgb(255, 100, 100), 160, 150, NULL, "PLAY");
			al_draw_text(menuSel[CHOICE], al_map_rgb(255, 100, 100), 160, 200, NULL, "QUIT");
			break;
		}

		render = false;
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
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
