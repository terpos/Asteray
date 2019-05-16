#include "Enemy_Manager.h"


Enemy_Manager::Enemy_Manager()
{
	this->damaged = false;
	sethit(this->damaged);
	attack_Move = -1;
	diamond_vel = 15;
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

	Diamond = al_load_bitmap("Spartak_Weapon.png");

	S_laser[0] = al_load_bitmap("Spartak_lazer_beam.png");
	S_laser[1] = al_load_bitmap("Spartak_lazer_beam2.png");
	S_laser[2] = al_load_bitmap("Spartak_lazer_beam3.png");
	S_laser[3] = al_load_bitmap("Spartak_lazer_beam4.png");
	S_laser[4] = al_load_bitmap("Spartak_lazer_beam5.png");
	S_laser[5] = al_load_bitmap("Spartak_lazer_beam6.png");

	Martianb[0] = al_load_bitmap("Martian_B.png");
	Martianb[1] = al_load_bitmap("Martian_B2.png");
	Martianb[2] = al_load_bitmap("Martian_B_damaged.png");

	Egg_bomb = al_load_bitmap("Martian_Egg.png");
	Sonic_Turbulance = al_load_bitmap("Sonic_Turbulance.png");
	LaserB = al_load_bitmap("Lazer_B.png");

	Kametkhan[0] = al_load_bitmap("kamet-khan.png");
	Kametkhan[1] = al_load_bitmap("kamet-khan2.png");
	Kametkhan[2] = al_load_bitmap("kamet-khan_damaged.png");

	kamet = al_load_bitmap("Kamet.png");
	Kamekhan_weapon = al_load_bitmap("kametkhan_Moltshot.png");

	Xorgana[0] = al_load_bitmap("Xorgana.png");
	Xorgana[1] = al_load_bitmap("Xorgana_damaged.png");

	SingleTwin = al_load_bitmap("singletwin_lazer");
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

void Enemy_Manager::spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, 
	int vel, int lim, int enemyID)
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


void Enemy_Manager::update(std::vector<enemies*>& e, std::vector <boss*> &b, std::vector <mini_boss*> &mb, std::vector <Spartak_ball*> &ball, std::vector <Diamond_shot*> &ds, 
	std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
	std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st,
	std::vector <Spartak_Laser*> &sl, std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, Animate &a)
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
		attack_Move = 2;

		if (b[j]->get_boss() == SPARTAK)
		{

			if (ishit())
			{
				
				b[j]->set_action(-1);
				b[j]->increment_frame();
				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_frame(0);
					b[j]->set_coordID(rand() % 4);
					b[j]->set_action(MOVE);

					if (b[j]->get_y() < 0)
					{
						b[j]->set_y(b[j]->get_y() + get_boss_h(SPARTAK));
					}

				}
			}

			else
			{
				b[j]->update(Spartak[0]);

				if (b[j]->get_energize())
				{
					b[j]->increment_frame();
				}

				if (b[j]->get_frame() == 99)
				{

					if (attack_Move == BALL)
					{
						ball.push_back(new Spartak_ball(b[j]->get_x() +20, b[j]->get_y(), 10, DOWN));
					}

					else if (attack_Move == DIAMONDS)
					{
						if (b[j]->get_health() > 3)
						{
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, RIGHT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, LEFT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, UP));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, DOWN));

						}

						else
						{
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, RIGHT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, LEFT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, UP));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, DOWN));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, UPRIGHT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, DOWNRIGHT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, UPLEFT));
							ds.push_back(new Diamond_shot(b[j]->get_x() + 20, b[j]->get_y(), diamond_vel, DOWNLEFT));
						}
						
						
					}

					else if (attack_Move == S_LAZER)
					{
						sl.push_back(new Spartak_Laser(b[j]->get_x(), b[j]->get_y() + get_boss_h(SPARTAK), 10, (rand() % 2) + 2));
					}
				}



				if (b[j]->get_frame() == 200 && b[j]->get_energize() && attack_Move != S_LAZER)
				{
					al_stop_sample_instance(energized);
					b[j]->is_energizing(false);
					b[j]->set_frame(0);
					b[j]->set_coordID(rand() % 4);
					b[j]->set_action(MOVE);
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

				for (int diam = 0; diam < ds.size(); diam++)
				{
					if (b[j]->get_frame() == 0)
					{
						ds[diam]->set_shot(true);
						al_stop_sample_instance(energized);

						//al_set_sample_instance_playmode(release, ALLEGRO_PLAYMODE_ONCE);
						//al_play_sample_instance(release);
					}

				}


				if (b[j]->get_frame() == 0)
				{
					b[j]->set_vel(1);
				}

				for (int l = 0; l < sl.size(); l++)
				{
					std::cout << sl[l]->get_x() << ", " << sl[l]->get_y() << std::endl;
					if (sl[l]->isshot())
					{
						b[j]->set_coordID(sl[l]->get_coord_ID());
						b[j]->set_vel(sl[l]->get_vel());
						b[j]->move();
					}
					if (sl[l]->get_x() > winx)
					{
						
						al_stop_sample_instance(energized);
						b[j]->is_energizing(false);
						b[j]->set_frame(0);
					//	b[j]->set_coordID(rand() % 4);
						b[j]->set_action(MOVE);

					}

					else if (sl[l]->get_x() < 0)
					{
						
						al_stop_sample_instance(energized);
						b[j]->is_energizing(false);
						b[j]->set_frame(0);
					//	b[j]->set_coordID(rand() % 4);
						b[j]->set_action(MOVE);
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

				if (b[j]->get_action() == ATTACK)
				{
					if (attack_Move == CHARGE)
					{

					}

					if (attack_Move == EGG)
					{
						EB.push_back(new Egg_Bomb(b[j]->get_x(), b[j]->get_y(), 10, DOWN));
					}

					else if (attack_Move == TURBULENCE)
					{
						ST.push_back(new Sonic_Turbulence((b[j]->get_x() / 2), b[j]->get_y(), 10, DOWN));
					}

					else if (attack_Move == B_LAZER)
					{
						LB.push_back(new Lazer_B((b[j]->get_x() / 2), b[j]->get_y(), 10, DOWN));
					}
				}

			}

		}

		else if (b[j]->get_boss() == KAMETKHAN)
		{

			if (ishit())
			{
				b[j]->set_action(-1);
				b[j]->increment_frame();

				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);

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
					if (attack_Move == MOLTEN)
					{
						mball.push_back(new Molten_shot(b[j]->get_x() + 50, 0, 10, DOWN, true));
					}

					else if (attack_Move == HEAT)
					{
						ds.push_back(new Diamond_shot((b[j]->get_x() / 2), b[j]->get_y(), 10, DOWN));
					}

					else if (attack_Move == KAMET)
					{
						K.push_back(new Kamet((b[j]->get_x() / 2), b[j]->get_y(), 10, DOWN));
					}
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

				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);

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
				
				if (b[j]->get_action() == ATTACK || b[j]->get_action() > MOVE)
				{
					if (attack_Move == SINGTW)
					{
						st.push_back(new Single_Twin(b[j]->get_x(), 0, 10, DOWN));

					}
					else if (attack_Move == V)
					{
						v.push_back(new v_beam(b[j]->get_x(), 0, 10, DOWN, true));

					}
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

	for (int l = 0; l < ds.size(); l++)
	{
		ds[l]->shootball();


		if (ds[l]->get_y() > winy)
		{
			ds.erase(ds.begin() + l);
			
		}
		
		else if (ds[l]->get_y() < 0)
		{
			ds.erase(ds.begin() + l);
		}
	}

	for (int l = 0; l < sl.size(); l++)
	{
		sl[l]->shootball();
		

		if (sl[l]->get_x()  > winx)
		{
			sl.erase(sl.begin() + l);


		}

		else if (sl[l]->get_x() + al_get_bitmap_width(S_laser[5]) < 0)
		{
			sl.erase(sl.begin() + l);
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

void Enemy_Manager::update(std::vector<enemies*>& e)
{
	//a.increment_frame();

	for (int i = 0; i < e.size(); i++)
	{
		e[i]->update();
		e[i]->countdown_duration();
		e[i]->release();
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

void Enemy_Manager::renderboss(std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Diamond_shot*> &ds, 
	std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
	std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st, std::vector <Spartak_Laser*> &sl,
	std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, Animate a, int &frame)
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
					for (int laz = 0; laz < sl.size(); laz++)
					{
						if (b[i]->get_frame() >= 200 && b[i]->get_frame() < 206)
						{
							a.two_frames_custom(S_laser[0], S_laser[1], sl[laz]->get_x(), sl[laz]->get_y(), a.get_frame(), 7, 0, 3);

						}

						else if (b[i]->get_frame() >= 206 && b[i]->get_frame() < 212)
						{
							a.two_frames_custom(S_laser[1], S_laser[2], sl[laz]->get_x(), sl[laz]->get_y(), a.get_frame(), 7, 0, 3);

						}

						else if (b[i]->get_frame() >= 212 && b[i]->get_frame() < 218)
						{
							a.two_frames_custom(S_laser[2], S_laser[3], sl[laz]->get_x(), sl[laz]->get_y(), a.get_frame(), 7, 0, 3);

						}

						else if (b[i]->get_frame() >= 218 && b[i]->get_frame() < 224)
						{
							a.two_frames_custom(S_laser[3], S_laser[4], sl[laz]->get_x(), sl[laz]->get_y(), a.get_frame(), 7, 0, 3);

						}

						else if (b[i]->get_frame() >= 224 && b[i]->get_frame() < 230)
						{
							a.two_frames_custom(S_laser[4], S_laser[5], sl[laz]->get_x(), sl[laz]->get_y(), a.get_frame(), 7, 0, 3);

						}

						else if (b[i]->get_frame() >= 230)
						{
							b[i]->set_frame(230);
							al_draw_bitmap(S_laser[5], sl[laz]->get_x(), sl[laz]->get_y(), NULL);
							sl[laz]->set_shot(true);
						}
					}

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

					else if (b[i]->get_frame() >= 200 && attack_Move == S_LAZER)
					{
						al_draw_bitmap(Spartak[0], b[i]->get_x(), b[i]->get_y(), NULL);

					}

				}

				else
				{
					al_draw_bitmap(Spartak[0], b[i]->get_x(), b[i]->get_y(), NULL);
				}

				for (int j = 0; j < ball.size(); j++)
				{
					al_draw_bitmap(Spartakball, ball[j]->get_x(), ball[j]->get_y(), NULL);
				}

				for (int diam = 0; diam < ds.size(); diam++)
				{
					al_draw_bitmap(Diamond, ds[diam]->get_x(), ds[diam]->get_y(), NULL);	
				}

				



			}
			
			break;

		case MARTIANB:
			//std::cout << "BOSS: " << al_get_bitmap_format(Martianb[0]) << std::endl;
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
	
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(S_laser[0]);
	al_destroy_bitmap(S_laser[1]);
	al_destroy_bitmap(S_laser[2]);
	al_destroy_bitmap(S_laser[3]);
	al_destroy_bitmap(S_laser[4]);
	al_destroy_bitmap(S_laser[5]);

	al_destroy_bitmap(Martianb[0]);
	al_destroy_bitmap(Martianb[1]);
	al_destroy_bitmap(Martianb[2]);

	al_destroy_bitmap(Egg_bomb);
	al_destroy_bitmap(LaserB);
	al_destroy_bitmap(Sonic_Turbulance);

	al_destroy_bitmap(Kametkhan[0]);
	al_destroy_bitmap(Kametkhan[1]);
	al_destroy_bitmap(Kametkhan[2]);

	al_destroy_bitmap(kamet);

	al_destroy_bitmap(electricity[0]);
	al_destroy_bitmap(electricity[1]);
	al_destroy_bitmap(Spartakball);
	
	al_destroy_bitmap(Kamekhan_weapon);

	al_destroy_bitmap(Xorgana[0]);
	al_destroy_bitmap(Xorgana[1]);

	al_destroy_bitmap(Xorgana_weapon);
	al_destroy_bitmap(SingleTwin);

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
