#include "Main_menu.h"



enum { TITLE, CHOICE };


Main_menu::Main_menu()
{
	fontSize[TITLE] = 32;
	fontSize[CHOICE] = 24;
	
	render = false;
	mouse = false;
	sel = false;

	screen = 0;
}


Main_menu::~Main_menu()
{
}

int Main_menu::getChoice()
{
	return this->choice;
}

bool Main_menu::isselected()
{
	return this->sel;
}

void Main_menu::set_sel_event(bool sel)
{
	this->sel = sel;
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

void Main_menu::event_listener(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q)
{
	//al_wait_for_event(q, &e);
	if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 0)
	{
		mouse = true;
		if (e.mouse.x >= 160 && e.mouse.x <= 160 + al_get_text_width(menuSel[CHOICE], "PLAY") 
			&& e.mouse.y >= 150 && e.mouse.y <= 150 + al_get_font_line_height(menuSel[CHOICE]))
		{
			setChoice(PLAY);
		}

		else if (e.mouse.x >= 160 && e.mouse.x <= 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY")
			&& e.mouse.y >= 200 && e.mouse.y <= 200 + al_get_font_line_height(menuSel[CHOICE]))
		{
			setChoice(HOWTO);
		}

		else if (e.mouse.x >= 160 && e.mouse.x <= 160 + al_get_text_width(menuSel[CHOICE], "QUIT")
			&& e.mouse.y >= 250 && e.mouse.y <= 250 + al_get_font_line_height(menuSel[CHOICE]))
		{
			setChoice(PLOT);
		}

		else if (e.mouse.x >= 160 && e.mouse.x <= 160 + al_get_text_width(menuSel[CHOICE], "QUIT")
			&& e.mouse.y >= 300 && e.mouse.y <= 300 + al_get_font_line_height(menuSel[CHOICE]))
		{
			setChoice(QUIT);
		}

		else
		{
			setChoice(-1);
		}

		std::cout << e.mouse.x << ", " << e.mouse.y << std::endl;
	}

	else if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 1)
	{

		mouse = true;
		if (e.mouse.x >= 170 && e.mouse.x <= 180 + al_get_text_width(status, "BACK TO MAIN MENU") &&
			e.mouse.y >= 500 - 2 * al_get_font_line_height(status) && e.mouse.y <= 500)
		{
			sel = false;
			setChoice(4);
		}

		else
		{
			setChoice(-1);
		}

	}

	else if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 2)
	{

		mouse = true;
		if (e.mouse.x >= 170 && e.mouse.x <= 180 + al_get_text_width(status, "BACK TO MAIN MENU") &&
			e.mouse.y >= 500 - 2 * al_get_font_line_height(status) && e.mouse.y <= 500)
		{
			sel = false;
			setChoice(4);
		}

		else
		{
			setChoice(-1);
		}

	}


	if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && screen == 0)
	{
		if (e.mouse.button == 1 && getChoice() > -1)
		{
			this->sel = true;
		}
	}

	else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && screen == 1)
	{
		if (e.mouse.button == 1 && getChoice() > -1)
		{
			this->sel = true;
		}
	}
	
	else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && screen == 2)
	{
		if (e.mouse.button == 1 && getChoice() > -1)
		{
			this->sel = true;
		}
	}


	if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 0)
	{
		mouse = false;
		switch (e.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

		case ALLEGRO_KEY_DOWN:
			this->choice = (this->choice + 1) % 4;
			setChoice(this->choice);
			this->sel = false;
			break;

		case ALLEGRO_KEY_UP:
			choice = (this->choice - 1) % 4;
			if (choice < 0)
			{
				choice = 3;
			}
			setChoice(this->choice);
			this->sel = false;
			break;

		case ALLEGRO_KEY_ENTER:
			this->sel = true;
			break;
		}


	}

	else if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 1)
	{
		mouse = false;
		switch (e.keyboard.keycode)
		{

		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

		case ALLEGRO_KEY_SPACE:
			screen = 0;
			this->sel = true;
			break;
		}
	}

	else if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 2)
	{
		mouse = false;
		switch (e.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

		case ALLEGRO_KEY_SPACE:
			screen = 0;
			this->sel = true;
			break;
		}
	}
}

void Main_menu::dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop g, bool &loop)
{
	if (getChoice() == PLAY)
	{
		al_stop_sample_instance(Main_Theme);
		g.loop(e, q, loop);
		this->sel = false;

	}

	else if (getChoice() == HOWTO)
	{
		screen = 1;
		setChoice(-1);
		this->sel = false;

	}

	else if (getChoice() == PLOT)
	{
		screen = 2;
		setChoice(-1);
		this->sel = false;

	}

	else if (getChoice() == QUIT)
	{
		g.destroy_stuff();
		destory();
		exit(EXIT_SUCCESS);
		this->sel = false;
	}

	else if (getChoice() == 4)
	{
		screen = 0;
		setChoice(-1);
		this->sel = false;
	}
}

void Main_menu::update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop g, bool &loop)
{
	if (e.type == ALLEGRO_EVENT_TIMER)
	{
		if (this->sel)
		{
			dochoice(e, q, g, loop);
			this->sel = false;
		}

		render = true;
		draw();
	}
}

void Main_menu::draw()
{
	if (render && screen == 0)
	{
		
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(menuSel[TITLE], al_map_rgb(255, 255, 255), 150, 50, NULL, "ASTERAY");

		al_draw_bitmap(menuBG, 0, 0, NULL);

		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 150, NULL, "PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 200, NULL, "HOW TO PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 250, NULL, "PLOT");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 300, NULL, "QUIT");

		al_play_sample_instance(Main_Theme);

		switch (getChoice())
		{
		case PLAY:
			if (mouse)
			{
				al_draw_filled_rectangle(160-5, 150-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 150 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160-5, 150-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 150 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 55, 0), 1);
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 150, NULL, "PLAY");
			}

			else
			{
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 150, NULL, "PLAY");
			}
			
			break;

		case HOWTO:
			if (mouse)
			{
				al_draw_filled_rectangle(160-5, 200-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 200 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160-5, 200-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 200 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 55, 0), 1);
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 200, NULL, "HOW TO PLAY");
			}

			else
			{
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 200, NULL, "HOW TO PLAY");
			}
			break;

		case PLOT:
			if (mouse)
			{
				al_draw_filled_rectangle(160-5, 250-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 250 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160-5, 250-5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 250 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 55, 0), 1);
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 250, NULL, "PLOT");
			}

			else
			{
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 250, NULL, "PLOT");
			}
			break;

		case QUIT:
			if (mouse)
			{
				al_draw_filled_rectangle(160 - 5, 300 - 5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 300 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 300 - 5, 160 + al_get_text_width(menuSel[CHOICE], "HOW TO PLAY") + 5, 300 + al_get_font_line_height(menuSel[CHOICE]), al_map_rgb(255, 55, 0), 1);
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 300, NULL, "QUIT");
			}

			else
			{
				al_draw_text(menuSel[CHOICE], al_map_rgb(250, 0, 0), 160, 300, NULL, "QUIT");
			}
			break;
		}
		al_flip_display();
		
		render = false;
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

		//stat.setnotification("[PRESS (SPACEBAR) TO GO BACK TO MAIN MENU]", status, 75, 500 - 30, al_map_rgb(255, 255, 255));

		al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0));
		stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255));
		stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(255, 255, 255));

		if (mouse && getChoice() == 4)
		{
			al_draw_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0), 1);
			al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(255, 255, 0));
			stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(155, 0, 0));
			stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(155, 0, 0));
		}

		al_flip_display();
	}

	else if (render && screen == 2)
	{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	stat.setnotification("THE PLOT", pause, 170, 0, al_map_rgb(200, 150, 100));

	stat.setnotification("In the year 2030, the space industry has been improving continously to the", status, 5, 100, al_map_rgb(150, 255, 255));
	stat.setnotification("point where all the 8 planets are safe for people to live in. This is all been", status, 5, 130, al_map_rgb(150, 255, 255));
	stat.setnotification("done by a man who is smart, easy going, and caring on the outside, but evil", status, 5, 160, al_map_rgb(150, 255, 255));
	stat.setnotification("inside. Most people voted him to be the leader of the galaxy and he became", status, 5, 190, al_map_rgb(150, 255, 255));
	stat.setnotification("the leader. Many changes happen in a bad way. He passed a law that people", status, 5, 220, al_map_rgb(150, 255, 255));
	stat.setnotification("who failed will be isolated to death. That is, people will be put in the worst", status, 5, 250, al_map_rgb(150, 255, 255));
	stat.setnotification("place possible, will not have any contact from society, and will not be given", status, 5, 280, al_map_rgb(150, 255, 255));
	stat.setnotification("food nor water which they will die from. This continued on for 5 years until", status, 5, 310, al_map_rgb(150, 255, 255));
	stat.setnotification("someone decided to rebel against the leader. His journey as a one man ", status, 5, 340, al_map_rgb(150, 255, 255));
	stat.setnotification("rebellion begins with the destruction of goverment's resources on earth.", status, 5, 370, al_map_rgb(150, 255, 255));


	//stat.setnotification("[PRESS (SPACEBAR) TO GO BACK TO MAIN MENU]", status, 75, 500 - 30, al_map_rgb(255, 255, 255));

	al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0));
	stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255));
	stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(255, 255, 255));

	if (mouse && getChoice() == 4)
	{
		al_draw_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0), 1);
		al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(255, 255, 0));
		stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(155, 0, 0));
		stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(155, 0, 0));
	}

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
