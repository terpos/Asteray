#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

#pragma once
class Animate
{
public:
	Animate();
	~Animate();

	void three_frames_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3, int x, int y, int &frame);
	void two_frames_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, int x, int y, int &frame);
	void two_frames_custom(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo);

	void three_frames_custom(ALLEGRO_BITMAP * bmp1, ALLEGRO_BITMAP * bmp2, ALLEGRO_BITMAP * bmp3, int x, int y, int frame, int custom_frame, int framenoone, int framenotwo, int framenothree);

	void increment_frame();

	void increment_frame(bool & start);

	int get_frame();

	void set_frame(int frame);

private:
	int frame;
};

