#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

#pragma once
class Animate
{
public:
	Animate();
	~Animate();

	//function not used
	void three_frames_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3, int x, int y, int &frame);
	
	//function not used
	void two_frames_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, int x, int y, int &frame);
	
	//three bitmaps change with each delays in between; you can configure number of frames and delays for each bitmap that is changing
	void three_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo, int framenothree);

	//two bitmaps change with each delays in between; you can configure number of frames and delays for each bitmap that is changing
	void two_frames_custom(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo);

	//updates animation frames frames
	void increment_frame();

	//function not used
	void increment_frame(bool & start);

	//gets the frame position
	int get_frame();

	//sets the frame position
	void set_frame(int frame);

private:
	int frame;
};

