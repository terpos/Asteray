/*
Asteray
Hubble.sln
C++ 17 

External Library used:
Allegro 5

@Author: George Ebeid



*/

#include "screen_manager.h"
#include <fstream>


int main(int argc, char **argv)
{
	//object decleration
	screen_manager hubble;

	//sets random seed every second
	srand(time(0));

	al_init();

	//initialize assets
	hubble.initilize_loop();

	//updates and renders
	hubble.display_loop();

	//erases the assets when the game closes
	hubble.destroy_stuff();

	return 0;
}
