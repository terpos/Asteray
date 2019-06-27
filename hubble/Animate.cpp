#include "Animate.h"



Animate::Animate()
{
	this->frame = 0;
	set_frame(this->frame);
}


Animate::~Animate()
{
}

void Animate::three_frames_animate(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3, int x, int y, int & frame)
{
	if (frame % 6 <= 5 && frame % 6 > 4)
	{
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % 6 <= 4 && frame % 6 > 2)
	{
		al_draw_bitmap(bmp2, x, y, NULL);
	}
	else if (frame % 6 <= 2 || frame % 6 >= 0)
	{
		al_draw_bitmap(bmp3, x, y, NULL);
	}
}

void Animate::two_frames_animate(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, int x, int y, int & frame)
{
	if (frame % 4 <= 3 && frame % 4 > 1)
	{
	al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % 4 == 0 || frame % 4 == 1)
	{
	al_draw_bitmap(bmp2, x, y, NULL);
	}
	
}

void Animate::two_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo)
{
	
	if (frame % custom_frame >= framenoone && frame % custom_frame < framenotwo)
	{
		//std::cout << frame % custom_frame << std::endl;
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % custom_frame >= framenotwo && frame % custom_frame <= custom_frame-1)
	{
		
		al_draw_bitmap(bmp2, x, y, NULL);
	}
}


void Animate::three_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3, 
	int x, int y, int frame, int custom_frame, int framenoone, int framenotwo, int framenothree)
{

	if (frame % custom_frame >= framenoone && frame % custom_frame < framenotwo)
	{
		//std::cout << frame % custom_frame << std::endl;
		al_draw_bitmap(bmp1, x, y, NULL);
	}

	else if (frame % custom_frame >= framenotwo && frame % custom_frame < framenothree)
	{
		//std::cout << frame % custom_frame << std::endl;
		al_draw_bitmap(bmp1, x, y, NULL);
	}

	else if (frame % custom_frame >= framenotwo && frame % custom_frame <= custom_frame - 1)
	{

		al_draw_bitmap(bmp2, x, y, NULL);
	}
}


void Animate::increment_frame()
{
	this->frame++;
	set_frame(this->frame);
}

void Animate::increment_frame(bool &start)
{
	if (start)
	{
		this->frame++;
		set_frame(this->frame);
	}
	
}

int Animate::get_frame()
{
	return this->frame;
}

void Animate::set_frame(int frame)
{
	this->frame = frame;
}
