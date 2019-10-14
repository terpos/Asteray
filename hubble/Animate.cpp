#include "Animate.h"



Animate::Animate()
{
	//initial variables and set function
	this->frame = 0;
	set_frame(this->frame);
}


Animate::~Animate()
{
}

//function not used
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

//function not used
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

//three bitmaps change with each delays in between; you can configure number of frames and delays for each bitmap that is changing
void Animate::two_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo)
{
	//bitmaps change based on the configured frame and delays that bitmap change
	if (frame % custom_frame >= framenoone && frame % custom_frame < framenotwo)
	{
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % custom_frame >= framenotwo && frame % custom_frame <= custom_frame-1)
	{
		
		al_draw_bitmap(bmp2, x, y, NULL);
	}
}

//two bitmaps change with each delays in between; you can configure number of frames and delays for each bitmap that is changing
void Animate::three_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3, 
	int x, int y, int frame, int custom_frame, int framenoone, int framenotwo, int framenothree)
{
	//bitmaps change based on the configured frame and delays that bitmap change
	if (frame % custom_frame >= framenoone && frame % custom_frame < framenotwo)
	{
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % custom_frame >= framenotwo && frame % custom_frame < framenothree)
	{
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % custom_frame >= framenotwo && frame % custom_frame <= custom_frame - 1)
	{
		al_draw_bitmap(bmp2, x, y, NULL);
	}
}

//updates frame
void Animate::increment_frame()
{
	this->frame++;
	set_frame(this->frame);
}

//function not in use
void Animate::increment_frame(bool &start)
{
	if (start)
	{
		this->frame++;
		set_frame(this->frame);
	}
	
}

//gets frame position
int Animate::get_frame()
{
	return this->frame;
}

//sets frame position
void Animate::set_frame(int frame)
{
	this->frame = frame;
}
