#include "global.h"

#pragma once
class Animation
{
public:
	Animation();
	~Animation();

	void three_bitmap_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3, int x, int y, int &frame);

private:
	
};

