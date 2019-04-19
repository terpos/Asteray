#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::three_bitmap_animate(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2, ALLEGRO_BITMAP *bmp3, int x, int y, int &frame)
{
	if (frame % 6 == 4)
	{
		al_draw_bitmap(bmp1, x, y, NULL);
	}
	else if (frame % 6 == 2)
	{
		al_draw_bitmap(bmp2, x, y, NULL);
	}
	else if (frame % 6 == 0)
	{
		al_draw_bitmap(bmp3, x, y, NULL);
	}
}
