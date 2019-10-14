#include "Main_menu.h"


//this is for font size
enum { TITLE, CHOICE };


Main_menu::Main_menu()
{
	//initial values
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

void Main_menu::load(game_loop &g)
{
	g.load_stuff();

	menuSel[TITLE] = al_load_font("ariblk.ttf", fontSize[TITLE], NULL);
	menuSel[CHOICE] = al_load_font("pixellari.ttf", fontSize[CHOICE], NULL);
	menuBG = al_load_bitmap("Menu.png");
	mt = al_load_sample("Asteray_Main_Theme.ogg");
	Main_Theme = al_create_sample_instance(mt);

	Screen_title = al_load_ttf_font("bahnschrift.ttf", 30, NULL);
	How_to = al_load_ttf_font("bahnschrift.ttf", 20, NULL);
	plot = al_load_ttf_font("bahnschrift.ttf", 15, NULL);


	al_attach_sample_instance_to_mixer(Main_Theme, al_get_default_mixer());
	al_set_sample_instance_playmode(Main_Theme, ALLEGRO_PLAYMODE_LOOP);

}

void Main_menu::event_listener(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q)
{
	//al_wait_for_event(q, &e);
	//if mouse cursor moves in the menu screen 
	if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 0)
	{
		mouse = true;
		
		//if mouse cursor is on the coordinates where play text is, then PLAY enum value is stored on play
		//same thing goes for HOWTO, PLOT, and QUIT

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

		//if mouse moves away
		else
		{
			setChoice(-1);
		}

	}

	//if mouse moves while in the how to play screen
	else if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 1)
	{
		//mouse movement is enabled
		mouse = true;

		//if mouse cursor goes to the position where the back to main menu
		//box is located then 4 is stored to choice and sel becomes false
		if (e.mouse.x >= 170 && e.mouse.x <= 180 + al_get_text_width(plot, "BACK TO MAIN MENU") &&
			e.mouse.y >= 500 - 2 * al_get_font_line_height(plot) && e.mouse.y <= 500)
		{
			sel = false;
			setChoice(4);
		}

		//if mouse moves away
		else
		{
			setChoice(-1);
		}

	}

	//if mouse moves while in the plot screen
	else if (e.type == ALLEGRO_EVENT_MOUSE_AXES && screen == 2)
	{
		//mouse movement is enabled
		mouse = true;

		//if mouse cursor goes to the position where the back to main menu
		//box is located then 4 is stored to choice and sel becomes false
		if (e.mouse.x >= 170 && e.mouse.x <= 180 + al_get_text_width(plot, "BACK TO MAIN MENU") &&
			e.mouse.y >= 500 - 2 * al_get_font_line_height(plot) && e.mouse.y <= 500)
		{

			sel = false;
			setChoice(4);
		}

		//if mouse moves away
		else
		{
			setChoice(-1);
		}

	}

	//if mouse is clicked while in main menu,
	//how to play, or plot
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

	// if key is pressed while in main menu
	if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 0)
	{
		//mouse is disabled
		mouse = false;

		
		switch (e.keyboard.keycode)
		{
			//if escape is pressed the game close
		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

			//if down key is pressed, the choice value increases
		case ALLEGRO_KEY_DOWN:
			this->choice = (this->choice + 1) % 4;
			setChoice(this->choice);
			this->sel = false;
			break;

			//if up key is pressed, the choice value decreases
		case ALLEGRO_KEY_UP:
			choice = (this->choice - 1) % 4;
			//if up key is pressed and the choice value is play,
			//the quit value is stored to choice
			if (choice < 0)
			{
				choice = 3;
			}
			setChoice(this->choice);
			this->sel = false;
			break;

			//if enter is pressed, selection value is true
		case ALLEGRO_KEY_ENTER:
			this->sel = true;
			break;
		}


	}

	//if a key is pressed while in how to play
	else if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 1)
	{
		//mouse is disabled
		mouse = false;
		switch (e.keyboard.keycode)
		{
			//if escape is pressed the game close
		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

			//if space key is pressed, selection becomes false
			//and screen transition to the main menu
		case ALLEGRO_KEY_SPACE:
			screen = 0;
			this->sel = true;
			break;
		}
	}

	else if (e.type == ALLEGRO_EVENT_KEY_DOWN && screen == 2)
	{
		//mouse is disabled
		mouse = false;

		switch (e.keyboard.keycode)
		{
			//if escape is pressed the game close
		case ALLEGRO_KEY_ESCAPE:
			destory();
			exit(EXIT_SUCCESS);
			break;

			//if space key is pressed, selection becomes false
			//and screen transition to the main menu
		case ALLEGRO_KEY_SPACE:
			screen = 0;
			this->sel = true;
			break;
		}
	}
}

void Main_menu::dochoice(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop &g, bool &loop)
{
	//if sel is true and player chooses to play, 
	//the screen transitions to game loop
	//also the main theme stops playing and variables are initialized
	if (getChoice() == PLAY)
	{
		al_stop_sample_instance(Main_Theme);
		g.init();
		g.loop(e, q, loop);
		this->sel = false;
	}

	//if sel is true and player chooses how to, 
	//the screen transitions to how to play
	else if (getChoice() == HOWTO)
	{
		screen = 1;
		setChoice(-1);
		this->sel = false;
	}

	//if sel is true and player chooses plot, 
	//the screen transitions to plot
	else if (getChoice() == PLOT)
	{
		screen = 2;
		setChoice(-1);
		this->sel = false;
	}

	//if sel is true and the player chooses to quit,
	//all assets are deallocated and the game closes
	else if (getChoice() == QUIT)
	{
		g.destroy_stuff();
		destory();
		exit(EXIT_SUCCESS);
		this->sel = false;
	}

	// if get choice is 4 the screen transitions to the main menu
	//(this only works in how to play and plot)
	else if (getChoice() == 4)
	{
		screen = 0;
		setChoice(-1);
		this->sel = false;
	}
}

void Main_menu::update(ALLEGRO_EVENT e, ALLEGRO_EVENT_QUEUE *q, game_loop &g, bool &loop)
{
	//if the event happens to equal allegro timer
	if (e.type == ALLEGRO_EVENT_TIMER)
	{
		//if selection is true
		if (this->sel)
		{
			//handles the screen transistion
			dochoice(e, q, g, loop);
			this->sel = false;
		}

		//render becomes true
		render = true;
		
		//renders assets
		draw();
	}
}

void Main_menu::draw()
{
	//if render is true and player is in the main menu
	if (render && screen == 0)
	{
		//background color is black
		al_clear_to_color(al_map_rgb(0, 0, 0));
		
		//title text
		al_draw_text(menuSel[TITLE], al_map_rgb(255, 255, 255), 150, 50, NULL, "ASTERAY");

		//menu background sprite
		al_draw_bitmap(menuBG, 0, 0, NULL);

		//choice list
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 150, NULL, "PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 200, NULL, "HOW TO PLAY");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 250, NULL, "PLOT");
		al_draw_text(menuSel[CHOICE], al_map_rgb(255, 255, 250), 160, 300, NULL, "QUIT");

		al_play_sample_instance(Main_Theme);

		//if a key is pressed the word becomes red
		//if a mouse is moved the word becomes red with a orange background box
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

		//displays all assets
		al_flip_display();
		

		//makes render false
		render = false;
	}


	//if space key is pressed, the screen transitions to main menu right away
	//if a mouse is moved to the box at the bottom, the background color
	//changes as well as text color
	else if (render && screen == 1)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		stat.setnotification("HOW TO PLAY", Screen_title, 150, 0, al_map_rgb(200, 0, 100));

		stat.setnotification("PRESS (ESC) IF YOU WANT TO QUIT", How_to, 0, 100, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (P) IF YOU WANT TO CONTINUE OR PAUSE", How_to, 0, 130, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (R) TO RESET THE GAME (ONLY IN PAUSE MENU)", How_to, 0, 160, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (DIRECTIONAL KEY) TO MOVE THE PLAYER", How_to, 0, 190, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (Z) TO SHOOT LAZERS", How_to, 0, 220, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (X) TO SHOOT SPECIAL WEAPONS", How_to, 0, 250, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (A) or (S) TO SWITCH SPECIAL WEAPONS", How_to, 0, 280, al_map_rgb(50, 255, 255));

		//stat.setnotification("[PRESS (SPACEBAR) TO GO BACK TO MAIN MENU]", status, 75, 500 - 30, al_map_rgb(255, 255, 255));

		al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0));
		stat.setnotification("BACK TO MAIN MENU", plot, 175, 500 - 2 * al_get_font_line_height(plot), al_map_rgb(255, 255, 255));
		stat.setnotification("[SPACEBAR]", plot, 200, 500 - al_get_font_line_height(plot), al_map_rgb(255, 255, 255));

		if (mouse && getChoice() == 4)
		{
			al_draw_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0), 1);
			al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(255, 255, 0));
			stat.setnotification("BACK TO MAIN MENU", plot, 175, 500 - 2 * al_get_font_line_height(plot), al_map_rgb(155, 0, 0));
			stat.setnotification("[SPACEBAR]", plot, 200, 500 - al_get_font_line_height(plot), al_map_rgb(155, 0, 0));
		}

		al_flip_display();
	}

	//if space key is pressed, the screen transitions to main menu right away
	//if a mouse is moved to the box at the bottom, the background color
	//changes as well as text color
	else if (render && screen == 2)
	{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	stat.setnotification("THE PLOT", Screen_title, 170, 0, al_map_rgb(200, 150, 100));

	stat.setnotification("In the year 2030, the space industry has been improving continuously to the", plot, 5, 100, al_map_rgb(150, 255, 255));
	stat.setnotification("point where all the 8 planets are safe for people to live in. This is all been", plot, 5, 130, al_map_rgb(150, 255, 255));
	stat.setnotification("done by a man who is smart, easy going, and caring on the outside, but evil", plot, 5, 160, al_map_rgb(150, 255, 255));
	stat.setnotification("inside. Most people voted him to be the leader of the galaxy and he became", plot, 5, 190, al_map_rgb(150, 255, 255));
	stat.setnotification("the leader. Many changes happen in a bad way. He passed a law that people", plot, 5, 220, al_map_rgb(150, 255, 255));
	stat.setnotification("who failed will be isolated to death. That is, people will be put in the worst", plot, 5, 250, al_map_rgb(150, 255, 255));
	stat.setnotification("place possible, will not have any contact from society, and will not be given", plot, 5, 280, al_map_rgb(150, 255, 255));
	stat.setnotification("food and water. This continued on for 5 years until a certain", plot, 5, 310, al_map_rgb(150, 255, 255));
	stat.setnotification("someone decided to rebel against the leader. His journey as a one man ", plot, 5, 340, al_map_rgb(150, 255, 255));
	stat.setnotification("rebellion begins with the destruction of government's resources on earth.", plot, 5, 370, al_map_rgb(150, 255, 255));


	//stat.setnotification("[PRESS (SPACEBAR) TO GO BACK TO MAIN MENU]", status, 75, 500 - 30, al_map_rgb(255, 255, 255));

	al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0));
	stat.setnotification("BACK TO MAIN MENU", plot, 175, 500 - 2 * al_get_font_line_height(plot), al_map_rgb(255, 255, 255));
	stat.setnotification("[SPACEBAR]", plot, 200, 500 - al_get_font_line_height(plot), al_map_rgb(255, 255, 255));

	if (mouse && getChoice() == 4)
	{
		al_draw_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0), 1);
		al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(plot), 180 + al_get_text_width(plot, "BACK TO MAIN MENU"), 500, al_map_rgb(255, 255, 0));
		stat.setnotification("BACK TO MAIN MENU", plot, 175, 500 - 2 * al_get_font_line_height(plot), al_map_rgb(155, 0, 0));
		stat.setnotification("[SPACEBAR]", plot, 200, 500 - al_get_font_line_height(plot), al_map_rgb(155, 0, 0));
	}

	al_flip_display();
	}
}

void Main_menu::destory()
{
	//destroys all assets
	al_destroy_font(menuSel[TITLE]);
	al_destroy_font(menuSel[CHOICE]);
	al_destroy_font(How_to);
	al_destroy_font(plot);
	al_destroy_bitmap(menuBG);
	al_destroy_sample(mt);
	al_destroy_sample_instance(Main_Theme);
}
