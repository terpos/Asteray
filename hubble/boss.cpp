#include "boss.h"

boss::boss(int x, int y, int vel, int bossID, int health, int cid)
{
	//initializes variables
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

//function not used
void boss::load()
{
}

//function not used
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

//function not used
void boss::energize_spartak(ALLEGRO_BITMAP *bmp1, ALLEGRO_BITMAP *bmp2)
{
	//a.two_frames_custom(Spartak[0], Spartak[1], winx / 3, 0, frame, 13, 0, 6);
}

//updates coordinates, attack moves, action, and direction depending on
//what kind of boss
void boss::update(ALLEGRO_BITMAP * bmp, int &attackmove, int &lazerb_shoot)
{
	switch (get_boss())
	{
	case SPARTAK:

		move();

		//if spartak either goes up or down
		if (get_coordID() == UP || get_coordID() == DOWN)
		{

			//every 5 px or less, spartak will decides if it will attack or move
			if (get_y() % al_get_bitmap_height(bmp) <= 5 && get_y() % al_get_bitmap_height(bmp) >= 0)
			{
				//action gets randomized and stores into the action function
				this->action = rand() % 4;
				set_action(this->action);

				//if spartak decides to attack, it stops and energize
				if (get_action() == ATTACK)
				{
					this->cid = 10;
					set_coordID(this->cid);

					this->energize = true;
					is_energizing(this->energize);
				}

				//if spartak decides to move, it keeps moving
				else if (get_action() >= MOVE)
				{
					this->cid = rand() % 4;
					set_coordID(this->cid);
					move();
				}

			}
		}

		//if spartak either goes left or right
		else if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{
			//every 5 px or less, spartak will decides if it will attack or move
			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{

				//action gets randomized and stores into the action function
				action = rand() % 8;
				set_action(this->action);

				//if spartak decides to attack, it stops and energize
				if (get_action() == ATTACK)
				{
					this->cid = 10;
					set_coordID(this->cid);

					this->energize = true;
					is_energizing(this->energize);
				}

				//if spartak decides to move, it keeps moving
				else if (get_action() >= MOVE)
				{
					this->cid = rand() % 4;
					set_coordID(this->cid);
					move();
					this->action = rand() % 4;
					set_action(this->action);
				}

			}
		}

		break;

	case MARTIANB:

		//if martianb either goes up or down
		if (get_coordID() == DOWN || get_coordID() == UP)
		{
			//if martianb is about to go to the status bar, it goes up
			if (get_y() + al_get_bitmap_height(bmp) > winy - 100)
			{
				this->cid = UP;
				set_coordID(this->cid);
				this->vel = 10;
				set_vel(this->vel);
			}

			//if martianb goes off screen it goes back to moving sideways
			if (get_y() < 0 && this->cid == UP)
			{
				this->cid = rand() % 2 + 2;
				set_coordID(this->cid);
				this->vel = 1;
				set_vel(this->vel);
				set_y(0);
			}

		}

		//if martianb either goes left or right
		else if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{
			//every 5 px or less, martianb will decides if it will attack or move
			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				//if martianb decides to shoot lasers and is not done shooting lasers
				if (lazerb_shoot <= 4)
				{
					this->action = ATTACK;
				}

				//if martianb decides not to shoot lasers it decides whether to attack or move
				else
				{
					this->action = rand() % 4;
				}

				//if martianb decides to attack
				if (this->action == ATTACK)
				{
					//if martianb decides to shoot lasers and is not done shooting lasers
					if (lazerb_shoot <= 4)
					{
						attackmove = B_LAZER;
					}

					//if martianb decides not to shoot lasers and still wants to attack, it will decide
					//other attack move
					else
					{
						attackmove = (rand() % 4) + 3;
						move();
					}

				}

				//if martianb decides to move, it will keep moving side ways
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
		//updates frame and movement for kametkhan
		this->frame++;
		set_frame(this->frame);
		move();

		//if kametkhan either goes left or right
		if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{
			//every 5 px or less, kametkhan will decides if it will attack or move
			if (get_x() % al_get_bitmap_height(bmp) <= 5 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				this->action = rand() % 10;

				//if kametkhan decides to attack, it will attack while moving 
				if (this->action == ATTACK || this->action > MOVE)
				{
					is_energizing(true);
					attackmove = (rand() % 3) + 7;
					move();
				}

				//if kametkhan decides to move and not attack, it will keep moving sideways
				else if (this->action == MOVE)
				{
					this->cid = (rand() % 2) + 2;
					set_coordID(this->cid);
					move();
				}

			}
		}

		break;

	case XORGANA:
		//updates movement
		move();

		//if xorgana either goes left or right
		if (get_coordID() == LEFT || get_coordID() == RIGHT)
		{
			//every 5 px or less, xorgana will decides if it will attack or move
			if (get_x() % al_get_bitmap_height(bmp) <= 10 && get_x() % al_get_bitmap_height(bmp) >= 0)
			{
				this->action = rand() % 50;
				set_action(this->action);

				//if xorgana decides to attack, it will attack while moving 
				if (get_action() == ATTACK || get_action() > MOVE)
				{
					attackmove = (rand() % 2) + 10;

					move();
				}

				//if xorgana decides to move and not attack, it will keep moving sideways
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

//function not used
void boss::destroy()
{
	
}

//moves the boss
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

//set whether the boss will attack or move
void boss::set_action(int action)
{
	this->action = action;
}

//sets the identity of the boss
void boss::set_boss(int bossnum)
{
	this->bossnum = bossnum;
}

//returns whether the boss will attack or move
int boss::get_action()
{
	return this->action;
}

//gets the identity of the boss
int boss::get_boss()
{
	return this->bossnum;
}

//returns x coordinate
int boss::get_x()
{
	return this->x;
}

//returns y coordinate
int boss::get_y()
{
	return this->y;
}

//returns the velocity
int boss::get_vel()
{
	return this->vel;
}

//returns direction of the boss
int boss::get_coordID()
{
	return this->cid;
}

//returns whether the boss will energize or not
int boss::get_energize()
{
	return this->energize;
}

//returns the frame position
int boss::get_frame()
{
	return this->frame;
}

//returns boss health
int boss::get_health()
{
	return this->health;
}

//sets whether the boss will energize or not 
void boss::is_energizing(bool energize)
{
	this->energize = energize;
}

//sets boss health
void boss::set_health(int health)
{
	this->health = health;
}

//frames counts up
void boss::increment_frame()
{
	this->frame++;
	set_frame(this->frame);
}

//sets x coord
void boss::set_x(int x)
{
	this->x = x;
}

//sets y coord
void boss::set_y(int y)
{
	this->y = y;
}

//sets speed of the boss
void boss::set_vel(int vel)
{
	this->vel = vel;
}

//sets direction of the boss
void boss::set_coordID(int cid)
{
	this->cid = cid;
}

//sets frame position
void boss::set_frame(int frame)
{
	this->frame = frame;
}
