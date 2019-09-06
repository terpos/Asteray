#include "boss.h"

boss::boss(int x, int y, int vel, int bossID, int health, int cid)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_boss(bossID);
	set_coordID(cid);
	set_health(health);
	this->energize = false;
	is_energizing(this->energize);
	vert = horiz = false;
	action = -1;
	set_frame(0);
}

boss::~boss()
{
}

void boss::load()
{
}

void boss::draw_boss(int x, int y)
{
	set_x(x);
	set_y(y);

	switch (get_boss())
	{
	case SPARTAK:
		al_draw_bitmap(Spartak[0], get_x(), get_y(), NULL);
		break;

	case MARTIANB:
		a.two_frames_custom(Martianb[0], Martianb[1], get_x(), get_y(), frame, 25, 0, 12);
		break;

	case KAMETKHAN:
		a.two_frames_custom(Kametkhan[0], Kametkhan[1], get_x(), get_y(), frame, 25, 0, 12);
		break;

	case XORGANA:
		al_draw_bitmap(Xorgana, get_x(), get_y(), NULL);
		break;
	}
}

void boss::energize_spartak(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	//a.two_frames_custom(Spartak[0], Spartak[1], winx / 3, 0, frame, 13, 0, 6);
}

void boss::update(ALLEGRO_BITMAP * bmp, int &attackmove, int &lazerb_shoot)
{
	switch (get_boss())
	{
	case SPARTAK:

		move();

		if (get_coordID() == UP || get_coordID() == DOWN)
		{


			if (get_y() % al_get_bitmap_height(bmp) <= 5 && get_y() % al_get_bitmap_height(bmp) >= 0)
			{

				this->action = rand() % 4;
				set_action(this->action);

				if (get_action() == ATTACK)
				{
					this->cid = 10;
					set_coordID(this->cid);

					this->energize = true;
					is_energizing(this->energize);
				}

				else if (get_action() >= MOVE)
				{
					this->cid = rand() % 4;
					set_coordID(this->cid);
					move();
					//this->energize = false;
					//is_energizing(this->energize);
				}

			}
		}

		else if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{

			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				action = rand() % 8;
				set_action(this->action);


				if (get_action() == ATTACK)
				{
					this->cid = 10;
					set_coordID(this->cid);

					this->energize = true;
					is_energizing(this->energize);
				}

				else if (get_action() >= MOVE)
				{
					this->cid = rand() % 4;
					set_coordID(this->cid);
					move();
					this->action = rand() % 4;
					set_action(this->action);
					//this->energize = false;
					//is_energizing(this->energize);
				}

			}
		}

		break;

	case MARTIANB:
		//move();

		if (get_coordID() == DOWN || get_coordID() == UP)
		{

			if (get_y() + al_get_bitmap_height(bmp) > winy - 100)
			{

				this->cid = UP;
				set_coordID(this->cid);
				this->vel = 10;
				set_vel(this->vel);
				//
			}

			if (get_y() < 0 && this->cid == UP)
			{
				this->cid = rand() % 2 + 2;
				set_coordID(this->cid);
				this->vel = 1;
				set_vel(this->vel);
				set_y(0);
			}

		}

		else if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{

			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{

				if (lazerb_shoot <= 4)
				{
					this->action = ATTACK;
				}

				else
				{
					this->action = rand() % 4;
				}

				if (this->action == ATTACK)
				{
					if (lazerb_shoot <= 4)
					{
						attackmove = B_LAZER;
					}

					else
					{
						attackmove = (rand() % 4) + 3;
						move();
					}

				}

				else if (this->action >= MOVE)
				{

					if (attackmove != CHARGE)
					{
						this->cid = (rand() % 2) + 2;
						set_coordID(this->cid);
					}

					move();
				}
			}
		}

		break;

	case KAMETKHAN:
		this->frame++;
		set_frame(this->frame);
		move();


		if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{

			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				this->action = rand() % 10;

				if (this->action == ATTACK || this->action > MOVE)
				{
					is_energizing(true);
					attackmove = (rand() % 3) + 7;
					move();
				}

				else if (this->action == MOVE)
				{
					this->cid = (rand() % 2) + 2;
					set_coordID(this->cid);
					//this->vel = 3;
					//set_vel(3);
					move();
				}

			}
		}

		break;

	case XORGANA:

		move();


		if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{

			if (get_x() % al_get_bitmap_height(bmp) <= 10 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				this->action = rand() % 50;
				set_action(this->action);


				if (get_action() == ATTACK || get_action() > MOVE)
				{
					attackmove = (rand() % 2) + 10;

					move();
				}

				else if (this->action == MOVE)
				{
					this->cid = (rand() % 2) + 2;
					set_coordID(this->cid);
					move();
				}

			}
		}

		break;
	}

}

void boss::destroy()
{
	
}

void boss::move()
{
	switch (get_coordID())
	{
	case DOWN:
		this->y+= get_vel();
		set_y(this->y);
		break;

	case UP:
		this->y-= get_vel();
		set_y(this->y);
		break;

	case LEFT:
		this->x-= get_vel();
		set_x(this->x);
		break;

	case RIGHT:
		this->x+= get_vel();
		set_x(this->x);
		break;
	}
}

void boss::set_action(int action)
{
	this->action = action;
}

void boss::set_boss(int bossnum)
{
	this->bossnum = bossnum;
}

int boss::get_action()
{
	return this->action;
}

int boss::get_boss()
{
	return this->bossnum;
}

int boss::get_x()
{
	return this->x;
}

int boss::get_y()
{
	return this->y;
}

int boss::get_vel()
{
	return this->vel;
}

int boss::get_coordID()
{
	return this->cid;
}

int boss::get_energize()
{
	return this->energize;
}

int boss::get_frame()
{
	return this->frame;
}

int boss::get_health()
{
	return this->health;
}

void boss::is_energizing(bool energize)
{
	this->energize = energize;
}

void boss::set_health(int health)
{
	this->health = health;
}

void boss::increment_frame()
{
	this->frame++;
	set_frame(this->frame);
}

void boss::set_x(int x)
{
	this->x = x;
}

void boss::set_y(int y)
{
	this->y = y;
}

void boss::set_vel(int vel)
{
	this->vel = vel;
}

void boss::set_coordID(int cid)
{
	this->cid = cid;
}

void boss::set_frame(int frame)
{
	this->frame = frame;
}
