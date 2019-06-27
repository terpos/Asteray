#include "screen_manager.h"
#include <fstream>


int main(int argc, char **argv)
{
	screen_manager hubble;
	srand(time(0));

	al_init();

	hubble.initilize_loop();

	hubble.display_loop();

	hubble.destroy_stuff();

	//system("cls");

	system("pause");


	return 0;
}
