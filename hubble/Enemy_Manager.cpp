#include "Enemy_Manager.h"


Enemy_Manager::Enemy_Manager()
{
	this->damaged = false;
	sethit(this->damaged);
	attack_Move = -1;
	diamond_vel = 15;
	lazerb_shoot = 7;
	lazerb_action = false;
	this->dying = false;
	set_death(this->dying);
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
	Enemy.push_back(al_load_bitmap("wyrm.png"));
	Enemy.push_back(al_load_bitmap("Xybtofy.png"));

	Enemy_damaged.push_back(al_load_bitmap("blobby_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("Asterix_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("E_police_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("jupiball_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("Kamekoset_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("M_police_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("satusphere_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("spyder_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("spaceship_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("volcanon_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("wyrm_damaged.png"));
	Enemy_damaged.push_back(al_load_bitmap("Xybtofy_damaged.png"));

	Spartak[0] = al_load_bitmap("Spartak.png");
	Spartak[1] = al_load_bitmap("Spartak_energized.png");
	Spartak[2] = al_load_bitmap("Spartak_Damaged.png");

	Spartak_blows_up[0] = al_load_bitmap("Spartak_destroyed_1.png");
	Spartak_blows_up[1] = al_load_bitmap("Spartak_destroyed_2.png");

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

	Martianb_blows_up[0] = al_load_bitmap("Martian_B_destroyed_1.png");
	Martianb_blows_up[1] = al_load_bitmap("Martian_B_destroyed_2.png");

	Egg_bomb = al_load_bitmap("Martian_Egg.png");
	Sonic_Turbulance = al_load_bitmap("Sonic_Turbulance.png");
	LaserB = al_load_bitmap("Lazer_B.png");

	Kametkhan[0] = al_load_bitmap("kamet-khan.png");
	Kametkhan[1] = al_load_bitmap("kamet-khan2.png");
	Kametkhan[2] = al_load_bitmap("kamet-khan_damaged.png");

	Kametkhan_blows_up[0] = al_load_bitmap("Kamet-khan-destroyed-1.png");
	Kametkhan_blows_up[1] = al_load_bitmap("Kamet-khan-destroyed-2.png");

	kamet = al_load_bitmap("Kamet.png");
	Kamekhan_weapon = al_load_bitmap("kametkhan_Moltshot.png");

	Xorgana[0] = al_load_bitmap("Xorgana.png");
	Xorgana[1] = al_load_bitmap("Xorgana_damaged.png");


	Xorgana_blows_up[0] = al_load_bitmap("Xorgana_destroyed_1.png");
	Xorgana_blows_up[1] = al_load_bitmap("Xorgana_destroyed_2.png");

	SingleTwin = al_load_bitmap("singletwin_lazer.png");
	Xorgana_weapon = al_load_bitmap("final_boss_weapon.png");

	earth_gate = al_load_bitmap("E_defense_gate.png");
	
	mars_gate = al_load_bitmap("M_defense_gate.png");
	
	enemy_destroyed[0] = al_load_bitmap("Destroy_1.png");
	enemy_destroyed[1] = al_load_bitmap("Destroy_2.png");
	enemy_destroyed[2] = al_load_bitmap("Destroy_3.png");
	
	electricity[0] = al_load_bitmap("electricity.png");
	electricity[1] = al_load_bitmap("electricity2.png");

	Spyder_w = al_load_bitmap("spyder_weapon.png");
	Planet_w = al_load_bitmap("Satusphere_Jupiball_weapon.png");
	Blobby_w = al_load_bitmap("Blobby_weapon.png");
	Xybtofy_w = al_load_bitmap("xybtofy_weapon.png");
	Mpolice_w = al_load_bitmap("Mpolice_weapon.png");
	Asterix_w = al_load_bitmap("asterix_weapon.png");
	Spaceship_w = al_load_bitmap("spaceship_weapon.png");
	Volcanon_w = al_load_bitmap("Volcanon_weapon.png");

	E_Lazer = al_load_bitmap("lazervert.png");

	E_turret[0] = al_load_bitmap("turrets_E_gate.png");
	E_turret[1] = al_load_bitmap("turrets_E_gate_damaged.png");
	
	M_turret[0] = al_load_bitmap("turrets_M_gate.png");
	M_turret[1] = al_load_bitmap("turrets_M_gate_damaged.png");

	E_weapon = al_load_bitmap("E_turret_ammo.png");
	M_weapon = al_load_bitmap("M_turret_ammo.png");

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

void Enemy_Manager::spawn_minboss(std::vector <mini_boss*> &mb, std::vector <Turrets *> &turrets, Stages &s, int minibossID)
{
	ani.set_frame(0);
	if (minibossID == E)
	{
		mb.push_back(new mini_boss(winx - get_E_w(), 0, NULL, minibossID));
		mb.push_back(new mini_boss(0, 0, ALLEGRO_FLIP_HORIZONTAL, minibossID));
		
	}

	else if (minibossID == M)
	{
		mb.push_back(new mini_boss(winx - get_M_w(), 0, NULL, minibossID));
		mb.push_back(new mini_boss(0, 0, ALLEGRO_FLIP_HORIZONTAL, minibossID));
	}

	for (int i = 0; i < mb.size(); i++)
	{
		if (s.get_stage() == EARTH)
		{
			turrets.push_back(new Turrets(mb[i]->get_x() + 12, mb[i]->get_y() + 60, 4, 0));
		}
		else if (s.get_stage() == MARS)
		{
			turrets.push_back(new Turrets(mb[i]->get_x() + 15, mb[i]->get_y() + 70, 4, 0));
		}
	}
}

void Enemy_Manager::spawn_enemy(std::vector <enemies*> &e, int enemy_health[12], int CID, int lim, int enemyID)
{
	for (int i = 0; i < lim; i++)
	{
		switch (enemyID)
		{
		case BLOBBY:
			e.push_back(new blobby((rand() % 50) + 75 * i, -60, 1, enemy_health[BLOBBY], CID));
			break;

		case ASTERIX:
			e.push_back(new Asterix((rand() % 50) + 75 * i, -60, 1, enemy_health[ASTERIX], CID));
			break;

		case EPOLICE:
			e.push_back(new Epolice((rand() % 50) + 75 * i, -60, 1, enemy_health[EPOLICE], CID));
			break;

		case JUPIBALL:
			e.push_back(new Jupiball((rand() % 50) + 75 * i, -60, 1, enemy_health[JUPIBALL], CID));
			break;

		case KAMEKOSET:
			e.push_back(new Kamekoset((rand() % 50) + 75 * i, -60, 1, enemy_health[KAMEKOSET], CID));
			break;

		case MPOLICE:
			e.push_back(new Mpolice((rand() % 50) + 75 * i, -60, 1, enemy_health[MPOLICE], CID));
			break;

		case SATUSPHERE:
			e.push_back(new Satusphere((rand() % 50) + 75 * i, -60, 1, enemy_health[SATUSPHERE], CID));
			break;

		case SPACESHIP:
			e.push_back(new Spaceship((rand() % 50) + 75 * i, -60, 1, enemy_health[SPACESHIP], CID));
			break;

		case SPYDER:
			e.push_back(new Spyder((rand() % 50) + 75 * i, -60, 1, enemy_health[SPYDER], CID));
			break;

		case VOLCANON:
			e.push_back(new Volcanon((rand() % 50) + 75 * i, -60, 1, enemy_health[VOLCANON], CID));
			break;

		case WYRM:
			e.push_back(new Wyrm((rand() % 50) + 75 * i, -60, 1, enemy_health[WYRM], CID));
			break;

		case XYBTOFY:
			e.push_back(new Xybtofy((rand() % 50) + 75 * i, -60, 1, enemy_health[XYBTOFY], CID));
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
			e.push_back(new blobby((rand() % 50) + 75 *i, -60, vel, enemy_health[BLOBBY], CID));
			break;

		case ASTERIX:
			e.push_back(new Asterix((rand() % 50) + 75 * i, -60, vel, enemy_health[ASTERIX], CID));
			break;

		case EPOLICE:
			e.push_back(new Epolice((rand() % 50) + 75 * i, -60, vel, enemy_health[EPOLICE], CID));
			break;

		case JUPIBALL:
			e.push_back(new Jupiball((rand() % 50) + 75 * i, -60, vel, enemy_health[JUPIBALL], CID));
			break;

		case KAMEKOSET:
			e.push_back(new Kamekoset((rand() % 50) + 75 * i, -60, vel, enemy_health[KAMEKOSET], CID));
			break;

		case MPOLICE:
			e.push_back(new Mpolice((rand() % 50) + 75 * i, -60, vel, enemy_health[MPOLICE], CID));
			break;

		case SATUSPHERE:
			e.push_back(new Satusphere((rand() % 50) + 75 * i, -60, vel, enemy_health[SATUSPHERE], CID));
			break;

		case SPACESHIP:
			e.push_back(new Spaceship((rand() % 50) + 75 * i, -60, vel, enemy_health[SPACESHIP], CID));
			break;

		case SPYDER:
			e.push_back(new Spyder((rand() % 50) + 75 * i, -60, vel, enemy_health[SPYDER], CID));
			break;

		case VOLCANON:
			e.push_back(new Volcanon((rand() % 50) + 75 * i, -60, vel, enemy_health[VOLCANON], CID));
			break;

		case WYRM:
			e.push_back(new Wyrm((rand() % 50) + 75 * i, -60, vel, enemy_health[WYRM], CID));
			break;

		case XYBTOFY:
			e.push_back(new Xybtofy((rand() % 50) + 75 * i, -60, vel, enemy_health[XYBTOFY], CID));
			break;
		}

	}
}

void Enemy_Manager::spawn_enemy(std::vector<enemies*>& e, int enemy_health[12], int x, int y, int CID, int vel, int enemyID)
{
	switch (enemyID)
	{
	case BLOBBY:
		e.push_back(new blobby(x, y, vel, enemy_health[BLOBBY], CID));
		break;

	case ASTERIX:
		e.push_back(new Asterix(x, y, vel, enemy_health[ASTERIX], CID));
		break;

	case EPOLICE:
		e.push_back(new Epolice(x, y, vel, enemy_health[EPOLICE], CID));
		break;

	case JUPIBALL:
		e.push_back(new Jupiball(x, y, vel, enemy_health[JUPIBALL], CID));
		break;

	case KAMEKOSET:
		e.push_back(new Kamekoset(x, y, vel, enemy_health[KAMEKOSET], CID));
		break;

	case MPOLICE:
		e.push_back(new Mpolice(x, y, vel, enemy_health[MPOLICE], CID));
		break;

	case SATUSPHERE:
		e.push_back(new Satusphere(x, y, vel, enemy_health[SATUSPHERE], CID));
		break;

	case SPACESHIP:
		e.push_back(new Spaceship(x, y, vel, enemy_health[SPACESHIP], CID));
		break;

	case SPYDER:
		e.push_back(new Spyder(x, y, vel, enemy_health[SPYDER], CID));
		break;

	case VOLCANON:
		e.push_back(new Volcanon(x, y, vel, enemy_health[VOLCANON], CID));
		break;

	case WYRM:
		e.push_back(new Wyrm(x, y, vel, enemy_health[WYRM], CID));
		break;

	case XYBTOFY:
		e.push_back(new Xybtofy(x, y, vel, enemy_health[XYBTOFY], CID));
		break;
	}
}


void Enemy_Manager::update(std::vector<enemies*>& e, std::vector <boss*> &b, std::vector <mini_boss*> &mb, std::vector <Spartak_ball*> &ball, std::vector <Diamond_shot*> &ds,
	std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
	std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st,
	std::vector <Spartak_Laser*> &sl, std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, std::vector <Enemy_Lazer*> &lazer, std::vector <Turrets *> &turrets, Animate &a, Stages &s, Animate &hit)
{
	a.increment_frame();
	
	for (int tur = 0; tur < turrets.size(); tur++)
	{
		if (s.get_stage() == EARTH)
		{
			turrets[tur]->update(turrets[tur]->get_x() + 25, turrets[tur]->get_y());
		}

		else if (s.get_stage() == MARS)
		{
			turrets[tur]->update(turrets[tur]->get_x() + 14, turrets[tur]->get_y());
		}
	}

	for (int i = 0; i < e.size(); i++)
	{
		e[i]->shoot_probability();
		
		if (e[i]->get_name_ID() == EPOLICE)
		{
			e[i]->load_ammo(2);
		}

		else
		{
			e[i]->load_ammo(1);
		}
		
		e[i]->decrement_delay();

		e[i]->update();
		e[i]->countdown_duration();
		e[i]->release();
		e[i]->update_animation();		
	}

	for (int laz = 0; laz < lazer.size(); laz++)
	{
		lazer[laz]->set_shot(true);
		lazer[laz]->shoot();

		if (lazer[laz]->get_y() + al_get_bitmap_height(E_Lazer) > winy || lazer[laz]->get_x() + al_get_bitmap_width(E_Lazer) > winx)
		{
			lazer.erase(lazer.begin() + laz);
		}

		else if (lazer[laz]->get_y() < 0 || lazer[laz]->get_x() < 0)
		{
			lazer.erase(lazer.begin() + laz);
		}
	}	

	for (int j = 0; j < b.size(); j++)
	{

		if (b[j]->get_boss() == SPARTAK)
		{


			attack_Move = rand() % 2;


			std::cout << "LAZER FRAME: " << b[j]->get_frame() << std::endl;

			if (ishit())
			{
				b[j]->set_action(-1);
				b[j]->increment_frame();
				if (b[j]->get_y() < 0)
				{
					b[j]->set_y(0);
				}

				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->is_energizing(false);
					b[j]->set_frame(0);
					b[j]->set_coordID(rand() % 4);
					b[j]->set_action(MOVE);

				}
			}

			else if (!ishit() && !isdying())
			{
				b[j]->update(Spartak[0], attack_Move, lazerb_shoot);

				if (b[j]->get_energize())
				{
					b[j]->increment_frame();
				}


				if (attack_Move == BALL)
				{
					if (b[j]->get_frame() == 99)
					{
						ball.push_back(new Spartak_ball(b[j]->get_x() + 20, b[j]->get_y(), 10, DOWN));
					}
				}

				else if (attack_Move == DIAMONDS)
				{
					if (b[j]->get_frame() == 99)
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
				}


				if (b[j]->get_frame() == 200 && b[j]->get_energize())
				{
					al_stop_sample_instance(energized);
					b[j]->is_energizing(false);
					b[j]->set_frame(0);
					b[j]->set_coordID(rand() % 4);
					b[j]->set_action(MOVE);
				}


				for (int l = 0; l < ball.size(); l++)
				{
					if (b[j]->get_frame() == 199)
					{
						std::cout << "SHOT" << std::endl;
						ball[l]->set_shot(true);
						al_stop_sample_instance(energized);
						al_set_sample_instance_playmode(release, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(release);
					}

				}

				for (int diam = 0; diam < ds.size(); diam++)
				{
					if (b[j]->get_frame() == 199)
					{
						std::cout << "SHOT" << std::endl;
						ds[diam]->set_shot(true);
						al_stop_sample_instance(energized);

						//al_set_sample_instance_playmode(release, ALLEGRO_PLAYMODE_ONCE);
						//al_play_sample_instance(release);
					}

				}


			}

			else if (isdying())
			{
				b[j]->set_coordID(10);
				b[j]->increment_frame();
				if (b[j]->get_y() < 0)
				{
					b[j]->set_y(0);
				}
			}
		}

		else if (b[j]->get_boss() == MARTIANB)
		{

			std::cout << lazerb_shoot << std::endl;

			if (ishit())
			{
				b[j]->set_coordID(UP);
				b[j]->set_vel(15);

				b[j]->increment_frame();
				b[j]->update(Martianb[0], attack_Move, lazerb_shoot);
				b[j]->move();


				if (b[j]->get_frame() == 24)
				{
					sethit(false);
					b[j]->set_action(rand() % 4);
					b[j]->set_frame(0);
				}

				for (int m = 0; m < ST.size(); m++)
				{
					ST[m]->shootball();
				}

				for (int m = 0; m < EB.size(); m++)
				{
					EB[m]->shootball();
				}

				for (int m = 0; m < LB.size(); m++)
				{
					LB[m]->set_y(LB[m]->get_y() + LB[m]->get_vel());
				}
			}

			else if (!ishit() && !isdying())
			{
				b[j]->update(Martianb[0], attack_Move, lazerb_shoot);

				b[j]->increment_frame();
				b[j]->move();
				//lazerb_action = true;
				if (b[j]->get_action() == ATTACK)
				{

					if (attack_Move == CHARGE)
					{
						if (b[j]->get_coordID() == LEFT || b[j]->get_coordID() == RIGHT)
						{
							b[j]->set_coordID(DOWN);

						}

						b[j]->set_vel(15);
						//b[j]->move();
						lazerb_action = true;
						b[j]->set_action(MOVE);
					}

					else if (attack_Move == EGG)
					{
						EB.push_back(new Egg_Bomb(b[j]->get_x(), b[j]->get_y(), 10, DOWN));
						b[j]->set_action(MOVE);
						lazerb_action = true;
					}

					else if (attack_Move == TURBULENCE)
					{
						ST.push_back(new Sonic_Turbulence(b[j]->get_x(), b[j]->get_y(), 10, DOWN));
						b[j]->set_action(MOVE);
						lazerb_action = true;
					}

					else if (attack_Move == B_LAZER)
					{

						if (lazerb_action && lazerb_shoot > 4)
						{
							lazerb_shoot = 0;
							lazerb_action = false;
						}

						if (lazerb_shoot <= 4)
						{
							LB.push_back(new Lazer_B(b[j]->get_x() + 40, b[j]->get_y(), 10, DOWN));
							LB.push_back(new Lazer_B(b[j]->get_x() + get_boss_w(b[j]->get_boss()) - 40, b[j]->get_y(), 10, DOWN));
							b[j]->set_x(lazerb_shoot * get_boss_w(MARTIANB));
							std::cout << b[j]->get_x() << std::endl;
							b[j]->set_y(0);
							lazerb_shoot++;

						}

						else
						{
							attack_Move = rand() % 4;

							b[j]->set_action(rand() % 4);
							lazerb_action = false;
						}
					}
				}

				for (int m = 0; m < ST.size(); m++)
				{
					ST[m]->shootball();
				}

				for (int m = 0; m < EB.size(); m++)
				{
					EB[m]->shootball();
				}

				for (int m = 0; m < LB.size(); m++)
				{
					LB[m]->set_y(LB[m]->get_y() + LB[m]->get_vel());
				}

			}

			else if (isdying())
			{
				b[j]->set_coordID(10);
				b[j]->increment_frame();
				if (b[j]->get_y() < 0)
				{
					b[j]->set_y(0);
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
			}

			else if (!ishit() && !isdying())
			{
				b[j]->update(Kametkhan[0], attack_Move, lazerb_shoot);

				if (b[j]->get_action() == ATTACK || b[j]->get_action() > MOVE)
				{
					if (attack_Move == MOLTEN)
					{
						mball.push_back(new Molten_shot(b[j]->get_x() + 50, 0, 10, DOWN, true));
					}

					else if (attack_Move == KAMET)
					{
						K.push_back(new Kamet(b[j]->get_x(), b[j]->get_y(), 10, DOWN));
					}

					else if (attack_Move == HEAT)
					{
						if (hw.size() == 0)
						{
							hw.push_back(new Heat_Wave((b[j]->get_x() + get_boss_w(KAMETKHAN)) / 2, (b[j]->get_y() + get_boss_h(KAMETKHAN)) / 2, 5, NULL));
						}

						else if (hw.size() > 1)
						{
							hw.erase(hw.end());
						}
					}

					b[j]->set_action(MOVE);
				}

				for (int m = 0; m < mball.size(); m++)
				{
					mball[m]->shootball();
				}

				for (int m = 0; m < K.size(); m++)
				{
					K[m]->shootball();
				}

				for (int m = 0; m < hw.size(); m++)
				{

					hw[m]->set_x(hw[m]->get_x() + b[j]->get_vel());
					std::cout << "RADIUS: " << hw[m]->get_r() << std::endl;
					std::cout << hw[m]->get_x() << ", " << hw[m]->get_y() << std::endl;
					std::cout << "BOSS W: " << get_boss_w(KAMETKHAN) << std::endl;
					
					std::cout << "X = " << (b[j]->get_x() + get_boss_w(KAMETKHAN)) + (hw[m]->get_r() - get_boss_w(KAMETKHAN)) << std::endl;
					std::cout << "- X = " << (b[j]->get_x() + get_boss_w(KAMETKHAN) / 2) - (hw[m]->get_r()) << std::endl;


					hw[m]->grow_heat(b[j]->get_x() + (get_boss_w(KAMETKHAN) / 2), b[j]->get_y() + (get_boss_h(KAMETKHAN) / 2));
				}

			}

			else if (isdying())
			{
				b[j]->set_coordID(10);
				b[j]->increment_frame();
				if (b[j]->get_y() < 0)
				{
					b[j]->set_y(0);
				}
			}
		}

		else if (b[j]->get_boss() == XORGANA)
		{

			if (ishit())
			{
				b[j]->update(Xorgana[0], attack_Move, lazerb_shoot);

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

			else if (!ishit() && !isdying())
			{
				b[j]->update(Xorgana[0], attack_Move, lazerb_shoot);

				if (b[j]->get_action() == ATTACK || b[j]->get_action() > MOVE)
				{

					if (attack_Move == V)
					{
						v.push_back(new v_beam(b[j]->get_x(), 0, 10, DOWN, true));

					}

					else if (attack_Move == SINGTW)
					{
						single_twin_probability = rand() % 2;
						if (single_twin_probability == 0)
						{
							st.push_back(new Single_Twin(b[j]->get_x(), 0, 5, DOWN));
							st.push_back(new Single_Twin(b[j]->get_x() + get_boss_w(XORGANA) - al_get_bitmap_width(SingleTwin), 0, 5, DOWN));
						}

						else if (single_twin_probability == 1)
						{
							st.push_back(new Single_Twin(b[j]->get_x() + (get_boss_w(XORGANA) / 2), 0, 5, DOWN));
						}

					}

					b[j]->set_action(MOVE);
				}

				for (int n = 0; n < v.size(); n++)
				{
					v[n]->shootball();
				}

				for (int n = 0; n < st.size(); n++)
				{
					st[n]->shootball();
				}
			}


			else if (isdying())
			{
				b[j]->set_coordID(10);
				b[j]->increment_frame();
				if (b[j]->get_y() < 0)
				{
					b[j]->set_y(0);
				}
			}
		}

	}

	for (int k = 0; k < mb.size(); k++)
	{
		ani.increment_frame();
		mb[k]->update();
	}

	for (int l = 0; l < ball.size(); l++)
	{
		ball[l]->update();


		if (ball[l]->get_y() + get_ball_h() > winy - 100)
		{
			ball.erase(ball.begin() + l);
		}

		else if (ball[l]->get_y() < 0)
		{
			ball.erase(ball.begin() + l);
		}
	}

	for (int l = 0; l < ds.size(); l++)
	{
		ds[l]->shootball();


		if (ds[l]->get_y() + al_get_bitmap_height(Diamond) > winy || ds[l]->get_x() + al_get_bitmap_width(Diamond) > winx)
		{
			ds.erase(ds.begin() + l);
			
		}
		
		else if (ds[l]->get_y() < 0 || ds[l]->get_x() < 0)
		{
			ds.erase(ds.begin() + l);
		}
	}

	for (int l = 0; l < ST.size(); l++)
	{
		ST[l]->shootball();

		if (ST[l]->get_y() + al_get_bitmap_height(Sonic_Turbulance) > winy - 100)
		{
			ST.erase(ST.begin() + l);
		}

		else if (ST[l]->get_y() < 0)
		{
			ST.erase(ST.begin() + l);
		}
	}

	for (int l = 0; l < EB.size(); l++)
	{
		EB[l]->shootball();

		if (EB[l]->get_y() + al_get_bitmap_height(Egg_bomb) > winy - 100)
		{
			EB.erase(EB.begin() + l);
		}

		else if (EB[l]->get_y()  < 0)
		{
			EB.erase(EB.begin() + l);
		}
	}

	for (int l = 0; l < K.size(); l++)
	{
		K[l]->shootball();

		if (K[l]->get_y() + al_get_bitmap_height(kamet) > winy - 100)
		{
			K.erase(K.begin() + l);
		}

		else if (K[l]->get_y()  < 0)
		{
			K.erase(K.begin() + l);
		}
	}

	for (int l = 0; l < hw.size(); l++)
	{
		if (hw[l]->get_r() > 150)
		{
			hw.erase(hw.begin() + l);
		}
	}

	for (int m = 0; m < mball.size(); m++)
	{

		if (mball[m]->get_y() > winy - 100)
		{
			mball.erase(mball.begin() + m);
			//ball
		}
		else if (mball[m]->get_y() < 0)
		{
			mball.erase(mball.begin() + m);
		}
	}

	for (int n = 0; n < st.size(); n++)
	{
		st[n]->shootball();

		if (st[n]->get_y() + al_get_bitmap_height(SingleTwin) > winy)
		{
			st.erase(st.begin() + n);
		}
		else if (st[n]->get_y() < 0)
		{
			st.erase(st.begin() + n);
		}
	}

	for (int n = 0; n < v.size(); n++)
	{
		if (v[n]->get_y() > winy)
		{
			v.erase(v.begin() + n);
		}
		else if (v[n]->get_y() < 0)
		{
			v.erase(v.begin() + n);
		}
	}


}

void Enemy_Manager::update(std::vector<enemies*>& e, Animate &hit)
{
	for (int i = 0; i < e.size(); i++)
	{
		e[i]->shoot_probability();

		if (e[i]->get_name_ID() == EPOLICE)
		{
			e[i]->load_ammo(2);
		}

		else
		{
			e[i]->load_ammo(1);
		}

		e[i]->decrement_delay();

		e[i]->update();
		e[i]->countdown_duration();
		e[i]->release();
		e[i]->update_animation();

		
	}
}

void Enemy_Manager::renderenemy(std::vector <Enemy_Lazer*> &lazer)
{
	

}

void Enemy_Manager::renderenemy(std::vector<enemies*>& e, Animate &hit)
{

	for (int i = 0; i < e.size(); i++)
	{
		switch (e[i]->get_name_ID())
		{
		case BLOBBY:
			e[i]->draw_E_weapon(Blobby_w);
			break;
		case ASTERIX:
			e[i]->draw_E_weapon(Asterix_w);
			break;
		case JUPIBALL:
			e[i]->draw_E_weapon(Planet_w);
			break;
		case SATUSPHERE:
			e[i]->draw_E_weapon(Planet_w);
			break;
		case SPACESHIP:
			e[i]->draw_E_weapon(Spaceship_w);
			break;
		case XYBTOFY:
			e[i]->draw_E_weapon(Xybtofy_w);
			break;
		case SPYDER:
			e[i]->draw_E_weapon(Spyder_w);
			break;
		case MPOLICE:
			e[i]->draw_E_weapon(Mpolice_w);
			break;
		case EPOLICE:
			e[i]->draw_E_weapon(E_Lazer);
			break;
		case VOLCANON:
			e[i]->draw_E_weapon(Volcanon_w);
			break;
		default:
			e[i]->clear_weapon();
			break;

		}

		e[i]->draw(Enemy[e[i]->get_name_ID()], Enemy_damaged[e[i]->get_name_ID()]);
		e[i]->draw_destroy(enemy_destroyed[0], enemy_destroyed[1], enemy_destroyed[2]);
	}
}

void Enemy_Manager::renderboss(std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Diamond_shot*> &ds, 
	std::vector <Egg_Bomb*> &EB, std::vector <Sonic_Turbulence*> &ST, std::vector <Lazer_B*> &LB, std::vector <Kamet*> &K,
	std::vector <Heat_Wave*> &hw, std::vector <Single_Twin*> &st, std::vector <Spartak_Laser*> &sl,
	std::vector <Molten_shot*> &mball, std::vector <v_beam*> &v, std::vector <Enemy_Lazer*> &lazer, Animate a, ALLEGRO_SAMPLE_INSTANCE *destroy, int &frame)
{
	
	for (int i = 0; i < b.size(); i++)
	{
		if (isdying() && b[i]->get_health() <= 0)
		{
			switch (b[i]->get_boss())
			{
			case SPARTAK:	

				if (b[i]->get_frame() < 77)
				{
					a.two_frames_custom(Spartak[0], Spartak[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
				}

				else if (b[i]->get_frame() < 154)
				{
					a.two_frames_custom(Spartak_blows_up[0], Spartak_blows_up[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
					al_set_sample_instance_position(destroy, 0);
					al_set_sample_instance_playmode(destroy, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(destroy);
				}

				break;

			case MARTIANB:		
				if (b[i]->get_frame() < 77)
				{
					a.two_frames_custom(Martianb[0], Martianb[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
				}

				else if (b[i]->get_frame() < 154)
				{
					a.two_frames_custom(Martianb_blows_up[0], Martianb_blows_up[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
					al_set_sample_instance_position(destroy, 0);
					al_set_sample_instance_playmode(destroy, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(destroy);
				}

				break;

			case KAMETKHAN:
				if (b[i]->get_frame() < 77)
				{
					a.two_frames_custom(Kametkhan[0], Kametkhan[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);

				}

				else if (b[i]->get_frame() < 154)
				{
					a.two_frames_custom(Kametkhan_blows_up[0], Kametkhan_blows_up[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
					al_set_sample_instance_position(destroy, 0);
					al_set_sample_instance_playmode(destroy, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(destroy);
				}

				break;

			case XORGANA:
				if (b[i]->get_frame() < 77)
				{
					a.two_frames_custom(Xorgana[0], Xorgana[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
				}

				else if (b[i]->get_frame() < 154)
				{
					a.two_frames_custom(Xorgana_blows_up[0], Xorgana_blows_up[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 11, 0, 5);
					al_set_sample_instance_position(destroy, 0);
					al_set_sample_instance_playmode(destroy, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(destroy);
				}

				break;
			}
		}

		else if (b[i]->get_health() > 0)
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

					for (int m = 0; m < EB.size(); m++)
					{
						al_draw_bitmap(Egg_bomb, EB[m]->get_x(), EB[m]->get_y(), NULL);
					}

					for (int m = 0; m < ST.size(); m++)
					{
						al_draw_bitmap(Sonic_Turbulance, ST[m]->get_x(), ST[m]->get_y(), NULL);
					}
				}

				else
				{
					a.two_frames_custom(Martianb[0], Martianb[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 17, 0, 8);

					for (int m = 0; m < EB.size(); m++)
					{
						al_draw_bitmap(Egg_bomb, EB[m]->get_x(), EB[m]->get_y(), NULL);
					}

					for (int m = 0; m < ST.size(); m++)
					{
						al_draw_bitmap(Sonic_Turbulance, ST[m]->get_x(), ST[m]->get_y(), NULL);
					}

					for (int m = 0; m < LB.size(); m++)
					{
						al_draw_bitmap(LaserB, LB[m]->get_x(), LB[m]->get_y(), NULL);
					}
				}

				break;

			case KAMETKHAN:
				if (ishit())
				{
					for (int m = 0; m < mball.size(); m++)
					{
						al_draw_bitmap(Kamekhan_weapon, mball[m]->get_x(), mball[m]->get_y(), NULL);
					}

					for (int m = 0; m < K.size(); m++)
					{
						al_draw_bitmap(kamet, K[m]->get_x(), K[m]->get_y(), NULL);
					}

					a.two_frames_custom(Kametkhan[0], Kametkhan[2], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);
				}

				else
				{
					for (int m = 0; m < mball.size(); m++)
					{
						al_draw_bitmap(Kamekhan_weapon, mball[m]->get_x(), mball[m]->get_y(), NULL);
					}

					for (int m = 0; m < K.size(); m++)
					{
						al_draw_bitmap(kamet, K[m]->get_x(), K[m]->get_y(), NULL);
					}

					for (int m = 0; m < hw.size(); m++)
					{
						al_draw_filled_circle(hw[m]->get_x(), hw[m]->get_y(), hw[m]->get_r(), al_map_rgb(150, 0, 0));
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

					for (int n = 0; n < st.size(); n++)
					{
						al_draw_bitmap(SingleTwin, st[n]->get_x(), st[n]->get_y(), NULL);
					}

					a.two_frames_custom(Xorgana[0], Xorgana[1], b[i]->get_x(), b[i]->get_y(), b[i]->get_frame(), 5, 0, 2);
				}

				else
				{
					for (int n = 0; n < v.size(); n++)
					{
						al_draw_bitmap(Xorgana_weapon, v[n]->get_x(), v[n]->get_y(), NULL);
					}

					for (int n = 0; n < st.size(); n++)
					{
						al_draw_bitmap(SingleTwin, st[n]->get_x(), st[n]->get_y(), NULL);
					}

					al_draw_bitmap(Xorgana[0], b[i]->get_x(), b[i]->get_y(), NULL);
				}

				break;
			}

		}
	}
}

void Enemy_Manager::renderminiboss(std::vector<mini_boss*>& mb, std::vector<Turrets*>& turrets, Stages s, Animate a)
{
	for (int i = 0; i < mb.size(); i++)
	{
		if (mb[i]->get_miniboss() == E)
		{
			a.two_frames_custom(earth_gate, earth_gate, mb[i]->get_x(), mb[i]->get_y(), ani.get_frame(), 10, 3, 6);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), 0, a.get_frame(), 13, 0, 6);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), al_get_bitmap_height(electricity[0]), a.get_frame(), 13, 0, 6);
			a.two_frames_custom(electricity[0], electricity[1], get_E_w(), al_get_bitmap_height(electricity[0]) * 2, a.get_frame(), 13, 0, 6);
			turrets[i]->render(E_turret[0], E_turret[1]);
			turrets[i]->renderweapon(E_weapon);
		}

		else if (mb[i]->get_miniboss() == M)
		{
			al_draw_filled_rectangle(al_get_bitmap_width(mars_gate), 0, 420, al_get_bitmap_height(mars_gate), al_map_rgb(0, 255, 0));
			al_draw_bitmap(mars_gate, mb[i]->get_x(), mb[i]->get_y(), mb[i]->get_flag());
			turrets[i]->render(M_turret[0], M_turret[1]);
			turrets[i]->renderweapon(M_weapon);
		}
	}

	for (int j = 0; j < turrets.size(); j++)
	{
		if (s.get_stage() == EARTH)
		{
			turrets[j]->renderweapon(E_weapon);
			turrets[j]->render(E_turret[0], E_turret[1]);
			
		}

		else if (s.get_stage() == MARS)
		{
			turrets[j]->renderweapon(M_weapon);
			turrets[j]->render(M_turret[0], M_turret[1]);
			
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

	for (int i = 0; i < Enemy_damaged.size(); i++)
	{
		al_destroy_bitmap(Enemy_damaged[i]);
	}

	al_destroy_bitmap(enemy_destroyed[0]);
	al_destroy_bitmap(enemy_destroyed[1]);
	al_destroy_bitmap(enemy_destroyed[2]);

	al_destroy_bitmap(Spartak[0]);
	al_destroy_bitmap(Spartak[1]);
	al_destroy_bitmap(Spartak[2]);

	al_destroy_bitmap(Spartak_blows_up[0]);
	al_destroy_bitmap(Spartak_blows_up[1]);
	
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

	al_destroy_bitmap(Martianb_blows_up[0]);
	al_destroy_bitmap(Martianb_blows_up[1]);

	al_destroy_bitmap(Egg_bomb);
	al_destroy_bitmap(LaserB);
	al_destroy_bitmap(Sonic_Turbulance);

	al_destroy_bitmap(Kametkhan[0]);
	al_destroy_bitmap(Kametkhan[1]);
	al_destroy_bitmap(Kametkhan[2]);

	al_destroy_bitmap(Kametkhan_blows_up[0]);
	al_destroy_bitmap(Kametkhan_blows_up[1]);

	al_destroy_bitmap(kamet);

	al_destroy_bitmap(electricity[0]);
	al_destroy_bitmap(electricity[1]);
	al_destroy_bitmap(Spartakball);
	
	al_destroy_bitmap(Kamekhan_weapon);

	al_destroy_bitmap(Xorgana[0]);
	al_destroy_bitmap(Xorgana[1]);

	al_destroy_bitmap(Xorgana_blows_up[0]);
	al_destroy_bitmap(Xorgana_blows_up[1]);

	al_destroy_bitmap(Xorgana_weapon);
	al_destroy_bitmap(SingleTwin);

	al_destroy_bitmap(earth_gate);

	al_destroy_bitmap(mars_gate);

	al_destroy_bitmap(Spyder_w);
	al_destroy_bitmap(Planet_w);
	al_destroy_bitmap(Blobby_w);
	al_destroy_bitmap(Xybtofy_w);
	al_destroy_bitmap(Mpolice_w);
	al_destroy_bitmap(Asterix_w);
	al_destroy_bitmap(Spaceship_w);
	al_destroy_bitmap(Volcanon_w);

	al_destroy_bitmap(E_Lazer);
	
	al_destroy_bitmap(E_turret[0]);
	al_destroy_bitmap(E_turret[1]);

	al_destroy_bitmap(M_turret[0]);
	al_destroy_bitmap(M_turret[1]);
	
	al_destroy_bitmap(E_weapon);
	al_destroy_bitmap(M_weapon);

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

int Enemy_Manager::get_turret_h(int enemyID)
{
	if (enemyID == EARTH)
	{
		return al_get_bitmap_height(E_turret[0]);
	}

	else if (enemyID == MARS)
	{
		return al_get_bitmap_height(M_turret[0]);
	}
	return 0;
}

int Enemy_Manager::get_turretweapon_h(int enemyID)
{
	if (enemyID == EARTH)
	{
		return al_get_bitmap_height(E_weapon);
	}

	else if (enemyID == MARS)
	{
		return al_get_bitmap_height(M_weapon);
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

int Enemy_Manager::get_Eweapon_w(int enemyID)
{
	switch (enemyID)
	{
	case BLOBBY:
		return al_get_bitmap_width(Blobby_w);
		break;

	case ASTERIX:
		return al_get_bitmap_width(Asterix_w);
		break;

	case EPOLICE:
		return al_get_bitmap_width(E_Lazer);
		break;

	case JUPIBALL:
		return al_get_bitmap_width(Planet_w);
		break;

	case MPOLICE:
		return al_get_bitmap_width(Mpolice_w);
		break;

	case SATUSPHERE:
		return al_get_bitmap_width(Planet_w);
		break;

	case SPACESHIP:
		return al_get_bitmap_width(Spaceship_w);
		break;

	case SPYDER:
		return al_get_bitmap_width(Spyder_w);
		break;

	case WYRM:
		return al_get_bitmap_width(E_Lazer);
		break;

	case VOLCANON:
		return al_get_bitmap_width(Volcanon_w);
		break;

	case XYBTOFY:
		return al_get_bitmap_width(Xybtofy_w);
		break;
	}

	return 0;
}

int Enemy_Manager::get_turret_w(int enemyID)
{
	if (enemyID == EARTH)
	{
		return al_get_bitmap_width(E_turret[0]);
	}

	else if (enemyID == MARS)
	{
		return al_get_bitmap_width(M_turret[0]);
	}
	return 0;
}

int Enemy_Manager::get_turretweapon_w(int enemyID)
{
	if (enemyID == EARTH)
	{
		return al_get_bitmap_width(E_weapon);
	}

	else if (enemyID == MARS)
	{
		return al_get_bitmap_width(M_weapon);
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

int Enemy_Manager::get_EB_w()
{
	return al_get_bitmap_width(Egg_bomb);
}

int Enemy_Manager::get_Vshot_w()
{
	return al_get_bitmap_width(Xorgana_weapon);
}

int Enemy_Manager::get_mball_w()
{
	return al_get_bitmap_width(Kamekhan_weapon);
}

int Enemy_Manager::get_ds_w()
{
	return al_get_bitmap_width(Diamond);
}

int Enemy_Manager::get_lazerb_w()
{
	return al_get_bitmap_width(LaserB);
}

int Enemy_Manager::get_lazers_w()
{
	for (int i = 0; i < 6; i++)
	{
		return al_get_bitmap_width(S_laser[i]);

	}
	return al_get_bitmap_width(S_laser[5]);
}

int Enemy_Manager::get_st_w()
{
	return al_get_bitmap_width(Sonic_Turbulance);
}

int Enemy_Manager::get_elazer_w()
{
	return al_get_bitmap_width(E_Lazer);
}

int Enemy_Manager::get_K_w()
{
	return al_get_bitmap_width(kamet);
}



int Enemy_Manager::get_Eweapon_h(int enemyID)
{
	switch (enemyID)
	{
	case BLOBBY:
		return al_get_bitmap_height(Blobby_w);
		break;

	case ASTERIX:
		return al_get_bitmap_height(Asterix_w);
		break;

	case EPOLICE:
		return al_get_bitmap_height(E_Lazer);
		break;

	case JUPIBALL:
		return al_get_bitmap_height(Planet_w);
		break;

	case MPOLICE:
		return al_get_bitmap_height(Mpolice_w);
		break;

	case SATUSPHERE:
		return al_get_bitmap_height(Planet_w);
		break;

	case SPACESHIP:
		return al_get_bitmap_height(Spaceship_w);
		break;

	case SPYDER:
		return al_get_bitmap_height(Spyder_w);
		break;

	case WYRM:
		return al_get_bitmap_height(E_Lazer);
		break;

	case VOLCANON:
		return al_get_bitmap_height(Volcanon_w);
		break;

	case XYBTOFY:
		return al_get_bitmap_height(Xybtofy_w);
		break;
	}

	return 0;
}

int Enemy_Manager::get_EB_h()
{
	return al_get_bitmap_height(Egg_bomb);
}

int Enemy_Manager::get_Vshot_h()
{
	return al_get_bitmap_height(Xorgana_weapon);
}

int Enemy_Manager::get_mball_h()
{
	return al_get_bitmap_height(Kamekhan_weapon);
}

int Enemy_Manager::get_ds_h()
{
	return al_get_bitmap_height(Diamond);
}

int Enemy_Manager::get_lazerb_h()
{
	return al_get_bitmap_height(LaserB);
}

int Enemy_Manager::get_lazers_h()
{
	for (int i = 0; i < 6; i++)
	{
		return al_get_bitmap_height(S_laser[i]);

	}
	return al_get_bitmap_height(S_laser[5]);
}

int Enemy_Manager::get_st_h()
{
	return al_get_bitmap_height(Sonic_Turbulance);
}

int Enemy_Manager::get_elazer_h()
{
	return al_get_bitmap_height(E_Lazer);
}

int Enemy_Manager::get_K_h()
{
	return al_get_bitmap_height(kamet);
}



int Enemy_Manager::get_num_of_enemy(std::vector <enemies*> e)
{
	return e.size();
}

int Enemy_Manager::ishit()
{
	return this->damaged;
}

bool Enemy_Manager::isdying()
{
	return this->dying;
}

void Enemy_Manager::sethit(bool hit)
{
	this->damaged = hit;
}

void Enemy_Manager::set_death(bool dying)
{
	this->dying = dying;
}
