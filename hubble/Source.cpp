#include "screen_manager.h"
#include <fstream>


int main(int argc, char **argv)
{
	screen_manager hubble;
	srand(time(0));

	al_init();

	al_install_audio();

	al_install_keyboard();

	al_init_image_addon();



	hubble.initilize_loop();

	hubble.display_loop();

	hubble.destroy_stuff();

	//system("cls");

	std::cout << "press [ENTER] to close" << std::endl;

	std::cin.get();


	return 0;
}
