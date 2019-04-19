#include "Enemy_Manager.h"


Enemy_Manager::Enemy_Manager()
{
	this->damaged = false;
	sethit(this->damaged);
}

Enemy_Manager::~Enemy_Manager()
{

}


void Enemy_Manager::load_enemy_img()
{
	Enemy.push_back(al_load_bitmap("blobby.png"));
	Enemy.push_back(al_load_bitmap("Asterix.png"));
	Enemy.push_back(al_load_bitmap("E_police.png"));
	Enemy.push_back(al_load_bitmap("jupiball.png"));
	Enemy.push_back(al_load_bitmap("Kamekoset.png"));
	Enemy.push_back(al_load_bitmap("M_police.png"));
	Enemy.push_back(al_load_bitmap("satusphere.png"));
	Enemy.push_back(al_load_bitmap("spyder.png"));
	Enemy.push_back(al_load_bitmap("spaceship.png"));
	Enemy.push_back(al_load_bitmap("volcanon.png"));
	Enemy.push_back(al_load_bitmap("Xybtofy.png"));
	Enemy.push_back(al_load_bitmap("wyrm.png"));

	Spartak[0] = al_load_bitmap("Spartak.png");
	Spartak[1] = al_load_bitmap("Spartak_energized.png");
	Spartak[2] = al_load_bitmap("Spartak_Damaged.png");

	Spartakball = al_load_bitmap("Enerball.png");

	Martianb[0] = al_load_bitmap("Martian_B.png");
	Martianb[1] = al_load_bitmap("Martian_B2.png");
	Martianb[2] = al_load_bitmap("Martian_B_damaged.png");

	Kametkhan[0] = al_load_bitmap("kamet-khan.png");
	Kametkhan[1] = al_load_bitmap("kamet-khan2.png");
	Kametkhan[2] = al_load_bitmap("kamet-khan_damaged.png");

	Kamekhan_weapon = al_load_bitmap("kametkhan_Moltshot.png");

	Xorgana[0] = al_load_bitmap("Xorgana.png");
	Xorgana[1] = al_load_bitmap("Xorgana_damaged.png");

	Xorgana_weapon = al_load_bitmap("final_boss_weapon.png");

	earth_gate = al_load_bitmap("E_defense_gate.png");
	mars_gate = al_load_bitmap("M_defense_gate.png");
	electricity[0] = al_load_bitmap("electricity.png");
	electricity[1] = al_load_bitmap("electricity2.png");

	Energized = al_load_sample("Spartak_energizing.ogg");
	Release = al_load_sample("159399__noirenex__power-down.ogg");

	energized = al_create_sample_instance(Energized);
	release = al_create_sample_instance(Release);
	
	al_attach_sample_instance_to_mixer(energized, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(release, al_get_default_mixer());

	al_set_sample_instance_gain(release, 2);
	al_set_sample_instance_gain(energized, .5);
}

void Enemy_Manager::spawn_boss(std::vector <boss*> &b, int bossID)
{
	if (bossID == SPARTAK)
	{
		b.push_back(new boss(winx / 3, 0, 1, bossID, 5, (rand() % 4)));
	}

	else if (bossID == MARTIANB)
	{
		b.push_back(new boss(winx / 3, 0, 1, bossID, 5, (rand() % 2) + 2));

	}

	else if (bossID == KAMETKHAN)
	{
		b.push_back(new boss(winx / 3, 0, 1, bossID, 10, (rand() % 2) + 2));

	}

	else if (bossID == XORGANA)
	{
		b.push_back(new boss(winx / 3, 0, 1, bossID, 15, (rand() % 2) + 2));

	}

	for (int i = 0 ; i < b.size(); i++)
	{
		b[i]->is_energizing(false);
	}
}

void Enemy_Manager::spawn_minboss(std::vector <mini_boss*> &mb, int minibossID)
{
	
	mb.push_back(new mini_boss(winx - get_E_w(), 0, NULL, minibossID));	
	mb.push_back(new mini_boss(0, 0, ALLEGRO_FLIP_HORIZONTAL, minibossID));
}

void Enemy_Manager::spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, int lim, int enemyID)
{
	for (int i = 0; i < lim; i++)
	{
		switch (enemyID)
		{
		case BLOBBY:
			e.push_back(new blobby(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[BLOBBY]);
			break;

		case ASTERIX:
			e.push_back(new Asterix(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[ASTERIX]);
			break;

		case EPOLICE:
			e.push_back(new Epolice(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[EPOLICE]);
			break;

		case JUPIBALL:
			e.push_back(new Jupiball(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[JUPIBALL]);
			break;

		case KAMEKOSET:
			e.push_back(new Kamekoset(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[KAMEKOSET]);
			break;

		case MPOLICE:
			e.push_back(new Mpolice(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[MPOLICE]);
			break;

		case SATUSPHERE:
			e.push_back(new Satusphere(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[SATUSPHERE]);
			break;

		case SPACESHIP:
			e.push_back(new Spaceship(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[SPACESHIP]);
			break;

		case SPYDER:
			e.push_back(new Spyder(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[SPYDER]);
			break;

		case VOLCANON:
			e.push_back(new Volcanon(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[VOLCANON]);
			break;

		case WYRM:
			e.push_back(new Wyrm(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[WYRM]);
			break;

		case XYBTOFY:
			e.push_back(new Xybtofy(rand() % 450, rand() % 50, 1, CID));
			e[i]->set_health(enemy_health[XYBTOFY]);
			break;
		}

	}
}

void Enemy_Manager::spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, int vel, int lim, int enemyID)
{
	for (int i = 0; i < lim; i++)
	{
		switch (enemyID)
		{
		case BLOBBY:
			e.push_back(new blobby(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[BLOBBY]);
			break;

		case ASTERIX:
			e.push_back(new Asterix(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[ASTERIX]);
			break;

		case EPOLICE:
			e.push_back(new Epolice(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[EPOLICE]);
			break;

		case JUPIBALL:
			e.push_back(new Jupiball(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[JUPIBALL]);
			break;

		case KAMEKOSET:
			e.push_back(new Kamekoset(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[KAMEKOSET]);
			break;

		case MPOLICE:
			e.push_back(new Mpolice(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[MPOLICE]);
			break;

		case SATUSPHERE:
			e.push_back(new Satusphere(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[SATUSPHERE]);
			break;

		case SPACESHIP:
			e.push_back(new Spaceship(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[SPACESHIP]);
			break;

		case SPYDER:
			e.push_back(new Spyder(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[SPYDER]);
			break;

		case VOLCANON:
			e.push_back(new Volcanon(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[VOLCANON]);
			break;

		case WYRM:
			e.push_back(new Wyrm(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[WYRM]);
			break;

		case XYBTOFY:
			e.push_back(new Xybtofy(rand() % 450, rand() % 50, vel, CID));
			e[i]->set_health(enemy_health[XYBTOFY]);
			break;
		}

	}
}


void Enemy_Manager::update(std::vector<enemies*>& e, std::vector <boss*> &b, std::vector <mini_boss*> &mb, std::vector <Spartak_ball*> &ball, std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, Animate &a)
{
	a.increment_frame();

	for (int i = 0; i < e.size(); i++)
	{
		e[i]->update();
		e[i]->countdown_duration();
		e[i]->release();
	}

	for (int j = 0; j < b.size(); j++)
	{

		if (b[j]->get_boss() == SPARTAK)
		{

			if (ishit())
			{
				b[j]->set_action(-1);
				b[j]->increment_frame();
				//b[j]->set_coordID(10);
				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);
					//b[j]->set_coordID(rand()%4);

					if (b[j]->get_y() < 0)
					{
						b[j]->set_y(b[j]->get_y() + get_boss_h(SPARTAK));
					}

				}
			}

			else
			{
				b[j]->update(Spartak[0]);



				if (b[j]->get_frame() == 200 && b[j]->get_energize())
				{

					al_stop_sample_instance(energized);
				}

				for (int l = 0; l < ball.size(); l++)
				{
					if (b[j]->get_frame() == 0)
					{
						ball[l]->set_shot(true);
						al_stop_sample_instance(energized);

						al_set_sample_instance_playmode(release, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(release);
					}



				}
			}
		}

		else if (b[j]->get_boss() == MARTIANB)
		{

			if (ishit())
			{
				b[j]->increment_frame();
				b[j]->update(Martianb[0]);

				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);
				}
			}
			else
			{
				b[j]->update(Martianb[0]);

			}

		}

		else if (b[j]->get_boss() == KAMETKHAN)
		{

			if (ishit())
			{
				b[j]->set_action(-1);
				b[j]->increment_frame();

				//b[j]->set_coordID(10);
				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);
					//b[j]->set_coordID(rand()%4);

					if (b[j]->get_y() < 0)
					{
						b[j]->set_y(b[j]->get_y() + get_boss_h(KAMETKHAN));
					}

				}

				for (int m = 0; m < mball.size(); m++)
				{
					mball[m]->shootball();
				}
			}

			else
			{
				b[j]->update(Kametkhan[0]);

				if (b[j]->get_action() == ATTACK || b[j]->get_action() > MOVE)
				{
					mball.push_back(new Molten_shot(b[j]->get_x() + 50, 0, 10, DOWN, true));
					b[j]->set_action(MOVE);
				}

				for (int m = 0; m < mball.size(); m++)
				{
					mball[m]->shootball();
				}

			}

		}

		else if (b[j]->get_boss() == XORGANA)
		{

			if (ishit())
			{
				b[j]->update(Xorgana[0]);

				b[j]->set_action(-1);
				b[j]->increment_frame();

				//b[j]->set_coordID(10);
				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);
					//b[j]->set_coordID(rand()%4);

					if (b[j]->get_y() < 0)
					{
						b[j]->set_y(b[j]->get_y() + get_boss_h(XORGANA));
					}

				}

				for (int n = 0; n < v.size(); n++)
				{
					v[n]->shootball();
				}
			}

			else
			{
				b[j]->update(Xorgana[0]);
				//b[j]->set_action(rand() % 50);
				if (b[j]->get_action() == ATTACK || b[j]->get_action() > MOVE)
				{
					v.push_back(new v_beam(b[j]->get_x(), 0, 10, DOWN, true));
					b[j]->set_action(MOVE);
				}

				for (int n = 0; n < v.size(); n++)
				{
					v[n]->shootball();
				}

			}

		}

	}

	for (int k = 0; k < mb.size(); k++)
	{
		mb[k]->update();
	}

	for (int l = 0; l < ball.size(); l++)
	{
		ball[l]->update();


		if (ball[l]->get_y() > winy)
		{
			ball.erase(ball.begin() + l);
			//ball
		}
		else if (ball[l]->get_y() < 0)
		{
			ball.erase(ball.begin() + l);
		}
	}

	for (int m = 0; m < mball.size(); m++)
	{



		if (mball[m]->get_y() > winy)
		{
			mball.erase(mball.begin() + m);
			//ball
		}
		else if (mball[m]->get_y() < 0)
		{
			mball.erase(mball.begin() + m);
		}
	}

	for (int n = 0; n < v.size(); n++)
	{



		if (v[n]->get_y() > winy)
		{
			v.erase(v.begin() + n);
			//ball
		}
		else if (v[n]->get_y() < 0)
		{
			v.erase(v.begin() + n);
		}
	}

}

void Enemy_Manager::renderenemy(std::vector<enemies*>& e)
{
	for (int i = 0; i < e.size(); i++)
	{
		switch (e[i]->get_name_ID())
		{
		case BLOBBY:
			al_draw_bitmap(Enemy[BLOBBY], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case ASTERIX:
			e[i]->draw(Enemy[ASTERIX]);
			break;
		case EPOLICE:
			al_draw_bitmap(Enemy[EPOLICE], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case JUPIBALL:
			al_draw_bitmap(Enemy[JUPIBALL], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case KAMEKOSET:
			e[i]->draw(Enemy[KAMEKOSET]);			
			break;
		case MPOLICE:
			al_draw_bitmap(Enemy[MPOLICE], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case SATUSPHERE:
			al_draw_bitmap(Enemy[SATUSPHERE], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case SPACESHIP:
			al_draw_bitmap(Enemy[SPACESHIP], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case SPYDER:
			al_draw_bitmap(Enemy[SPYDER], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case VOLCANON:
			al_draw_bitmap(Enemy[VOLCANON], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case WYRM:
			al_draw_bitmap(Enemy[WYRM], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		case XYBTOFY:
			al_draw_bitmap(Enemy[XYBTOFY], e[i]->get_x(), e[i]->get_y(), NULL);
			break;
		}
		
	}
}

void Enemy_Manager::renderboss(std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, Animate a, int &frame)
{
	for (int i = 0; i < b.size(); i++)
	{
		switch (b[i]->get_boss())
		{
		case SPARTAK:

			if (ishit())
			{
				a.two_frames_custom(Spartak[0], Spartak[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);

			}

			else
			{
				if (b[i]->get_energize())
				{
					std::cout << "DRAW" << std::endl;
					if (b[i]->get_frame() >= 0 && b[i]->get_frame() < 50)
					{
						a.two_frames_custom(Spartak[0], Spartak[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 25, 0, 12);
						al_set_sample_instance_gain(energized, .5);
						al_set_sample_instance_speed(energized, 1);
						al_play_sample_instance(energized);
					}

					else if (b[i]->get_frame() >= 50 && b[i]->get_frame() < 100)
					{
						a.two_frames_custom(Spartak[0], Spartak[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 13, 0, 6);
						al_set_sample_instance_gain(energized, 1);
						al_set_sample_instance_speed(energized, 2);
						al_play_sample_instance(energized);
					}


					else if (b[i]->get_frame() >= 100 && b[i]->get_frame() < 200)
					{
						a.two_frames_custom(Spartak[0], Spartak[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 7, 0, 3);
						al_set_sample_instance_gain(energized, 2);
						al_set_sample_instance_speed(energized, 3);
						al_play_sample_instance(energized);
					}

					if (b[i]->get_frame() == 99)
					{
						ball.push_back(new Spartak_ball(b[i]->get_x(), b[i]->get_y(), 10, DOWN));
					}
				}

				else
				{
					al_draw_bitmap(Spartak[0], b[i]->get_x(), b[i]->get_y(), NULL);
				}

				for (int j = 0; j < ball.size(); j++)
				{
					al_draw_bitmap(Spartakball, ball[j]->get_x() + 20, ball[j]->get_y(), NULL);
				}
			}
			
			break;

		case MARTIANB:

			if (ishit())
			{
				a.two_frames_custom(Martianb[0], Martianb[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);

			}

			else
			{
				a.two_frames_custom(Martianb[0], Martianb[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 17, 0, 8);

			}

			break;

		case KAMETKHAN:
			if (ishit())
			{
				for (int m = 0; m < mball.size(); m++)
				{
					al_draw_bitmap(Kamekhan_weapon, mball[m]->get_x(), mball[m]->get_y(), NULL);
				}

				a.two_frames_custom(Kametkhan[0], Kametkhan[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);
			}

			else
			{
				for (int m = 0; m < mball.size(); m++)
				{
					al_draw_bitmap(Kamekhan_weapon, mball[m]->get_x(), mball[m]->get_y(), NULL);
				}
				

				a.two_frames_custom(Kametkhan[0], Kametkhan[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 17, 0, 8);
			}
			
			break;

		case XORGANA:
			if (ishit())
			{
				for (int n = 0; n < v.size(); n++)
				{
					al_draw_bitmap(Xorgana_weapon, v[n]->get_x(), v[n]->get_y(), NULL);
				}

				a.two_frames_custom(Xorgana[0], Xorgana[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);
			}

			else
			{
				for (int n = 0; n < v.size(); n++)
				{
					al_draw_bitmap(Xorgana_weapon, v[n]->get_x(), v[n]->get_y(), NULL);
				}

				al_draw_bitmap(Xorgana[0], b[i]->get_x(), b[i]->get_y(), NULL);
			}
			
			break;
		}
	}
}

void Enemy_Manager::renderminiboss(std::vector<mini_boss*>& mb, Animate a)
{
	for (int i = 0; i < mb.size(); i++)
	{
		if (mb[i]->get_miniboss() == E)
		{
			al_draw_bitmap(earth_gate, mb[i]->get_x(), mb[i]->get_y(), NULL);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), 0, a.get_frame(), 13, 0, 6);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), al_get_bitmap_height(electricity[0]), a.get_frame(), 13, 0, 6);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), al_get_bitmap_height(electricity[0])*2, a.get_frame(), 13, 0, 6);

		}

		else if (mb[i]->get_miniboss() == M)
		{
			al_draw_filled_rectangle(al_get_bitmap_width(mars_gate), 0, 400, al_get_bitmap_height(mars_gate), al_map_rgb(0, 255, 0));
			al_draw_bitmap(mars_gate, mb[i]->get_x(), mb[i]->get_y(), mb[i]->get_flag());

		}
	}
}

void Enemy_Manager::destroy_enemy(std::vector <enemies*>& e, int index)
{
	e.erase(e.begin() + index);
		
}

void Enemy_Manager::clear_enemy(std::vector<enemies*>& e)
{
	e.clear();
}

void Enemy_Manager::destroy_enemy_img()
{
	for (int i = 0; i < Enemy.size(); i++)
	{
		al_destroy_bitmap(Enemy[i]);
	}

	al_destroy_bitmap(Spartak[0]);
	al_destroy_bitmap(Spartak[1]);
	al_destroy_bitmap(Spartak[2]);
	
	al_destroy_bitmap(Martianb[0]);
	al_destroy_bitmap(Martianb[1]);
	al_destroy_bitmap(Martianb[2]);

	al_destroy_bitmap(Kametkhan[0]);
	al_destroy_bitmap(Kametkhan[1]);
	al_destroy_bitmap(Kametkhan[2]);

	al_destroy_bitmap(electricity[0]);
	al_destroy_bitmap(electricity[1]);
	al_destroy_bitmap(Spartakball);
	
	al_destroy_bitmap(Kamekhan_weapon);

	al_destroy_bitmap(Xorgana[0]);
	al_destroy_bitmap(Xorgana[1]);

	al_destroy_bitmap(Xorgana_weapon);

	al_destroy_bitmap(earth_gate);
	al_destroy_bitmap(mars_gate);
	
	al_destroy_sample(Energized);
	al_destroy_sample(Release);

	al_destroy_sample_instance(energized);
	al_destroy_sample_instance(release);
}


int Enemy_Manager::get_h(int enemyID)
{
	switch (enemyID)
	{
	case BLOBBY:
		return al_get_bitmap_height(Enemy[BLOBBY]);
		break;

	case ASTERIX:
		return al_get_bitmap_height(Enemy[ASTERIX]);
		break;

	case EPOLICE:
		return al_get_bitmap_height(Enemy[EPOLICE]);
		break;

	case JUPIBALL:
		return al_get_bitmap_height(Enemy[JUPIBALL]);
		break;

	case KAMEKOSET:
		return al_get_bitmap_height(Enemy[KAMEKOSET]);
		break;

	case MPOLICE:
		return al_get_bitmap_height(Enemy[MPOLICE]);
		break;

	case SATUSPHERE:
		return al_get_bitmap_height(Enemy[SATUSPHERE]);
		break;

	case SPACESHIP:
		return al_get_bitmap_height(Enemy[SPACESHIP]);
		break;

	case SPYDER:
		return al_get_bitmap_height(Enemy[SPYDER]);
		break;

	case VOLCANON:
		return al_get_bitmap_height(Enemy[VOLCANON]);
		break;

	case WYRM:
		return al_get_bitmap_height(Enemy[WYRM]);
		break;

	case XYBTOFY:
		return al_get_bitmap_height(Enemy[XYBTOFY]);
		break;
	}


	return 0;
}

int Enemy_Manager::get_E_h()
{
	return al_get_bitmap_height(earth_gate);
}

int Enemy_Manager::get_M_h()
{
	return al_get_bitmap_height(mars_gate);
}

int Enemy_Manager::get_boss_h(int bossID)
{
	for (int i = 0; i < 2; i++)
	{
		switch (bossID)
		{
		case SPARTAK:
			return al_get_bitmap_height(Spartak[i]);
			break;
		case MARTIANB:
			return al_get_bitmap_height(Martianb[i]);
			break;
		case KAMETKHAN:
			return al_get_bitmap_height(Kametkhan[i]);
			break;
		case XORGANA:
			return al_get_bitmap_height(Xorgana[i]);
			break;
		}
	}
}

int Enemy_Manager::get_ball_h()
{
	return al_get_bitmap_height(Spartakball);
}


int Enemy_Manager::get_w(int enemyID)
{
	switch (enemyID)
	{
	case BLOBBY:
		return al_get_bitmap_width(Enemy[BLOBBY]);
		break;

	case ASTERIX:
		return al_get_bitmap_width(Enemy[ASTERIX]);
		break;

	case EPOLICE:
		return al_get_bitmap_width(Enemy[EPOLICE]);
		break;

	case JUPIBALL:
		return al_get_bitmap_width(Enemy[JUPIBALL]);
		break;

	case KAMEKOSET:
		return al_get_bitmap_width(Enemy[KAMEKOSET]);
		break;

	case MPOLICE:
		return al_get_bitmap_width(Enemy[MPOLICE]);
		break;

	case SATUSPHERE:
		return al_get_bitmap_width(Enemy[SATUSPHERE]);
		break;

	case SPACESHIP:
		return al_get_bitmap_width(Enemy[SPACESHIP]);
		break;

	case SPYDER:
		return al_get_bitmap_width(Enemy[SPYDER]);
		break;

	case VOLCANON:
		return al_get_bitmap_width(Enemy[VOLCANON]);
		break;

	case WYRM:
		return al_get_bitmap_width(Enemy[WYRM]);
		break;

	case XYBTOFY:
		return al_get_bitmap_width(Enemy[XYBTOFY]);
		break;
	}

	return 0;
}

int Enemy_Manager::get_E_w()
{
	return al_get_bitmap_width(earth_gate);
}

int Enemy_Manager::get_M_w()
{
	return al_get_bitmap_width(mars_gate);
}

int Enemy_Manager::get_boss_w(int bossID)
{
	for (int i = 0; i < 2; i++)
	{
		switch (bossID)
		{
		case SPARTAK:
			return al_get_bitmap_width(Spartak[i]);
			break;
		case MARTIANB:
			return al_get_bitmap_width(Martianb[i]);			
			break;
		case KAMETKHAN:
			return al_get_bitmap_width(Kametkhan[i]);			
			break;
		case XORGANA:
			return al_get_bitmap_width(Xorgana[i]);			
			break;
		}
	}
}

int Enemy_Manager::get_ball_w()
{
	return al_get_bitmap_width(Spartakball);
}


int Enemy_Manager::get_num_of_enemy(std::vector <enemies*> e)
{
	return e.size();
}

int Enemy_Manager::ishit()
{
	return this->damaged;
}

void Enemy_Manager::sethit(bool hit)
{
	this->damaged = hit;
}
