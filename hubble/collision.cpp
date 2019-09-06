#include "collision.h"



collision::collision()
{
	num_of_kill = 0;
	declare = false;
	cid = 0;
	haych_damaged = 0;
}


collision::~collision()
{

}



void collision::win_collsion(std::vector <player*> &p)
{
	for (int i = 0; i < p.size(); i++)
	{
		
		if (p[i]->get_x() > winx - 25)
		{
			p[i]->set_x(p[i]->get_x() - p[i]->get_vel());
		}

		if (p[i]->get_x() < -25)
		{
			p[i]->set_x(p[i]->get_x() + p[i]->get_vel());
		}

		if (p[i]->get_y() < -10)
		{
			p[i]->set_y(p[i]->get_y() + p[i]->get_vel());
		}

		if (p[i]->get_y() > winy - 150)
		{
			p[i]->set_y(p[i]->get_y() - p[i]->get_vel());
		}
	}

	
}

void collision::Enemy_boundary_collision(Enemy_Manager EN, std::vector <enemies*> &foe, int destroy_or_rebound)
{
	for (int i = 0; i < foe.size(); i++)
	{
		
		if (destroy_or_rebound == REBOUND)
		{
			if (foe[i]->get_x() + EN.get_w(foe[i]->get_name_ID()) > winx)
			{
				cid = LEFT;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = RIGHT;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_y() < 0)
			{
				cid = DOWN;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_y() + EN.get_h(foe[i]->get_name_ID()) > winy - 100)
			{
				cid = UP;
				foe[i]->set_coord_ID(cid);
				break;
			}
		}

		if (destroy_or_rebound == DESTROY)
		{
			if (foe[i]->get_x() + EN.get_w(foe[i]->get_name_ID()) > winx)
			{
				cid = DOWN;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = DOWN;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_y() < 0)
			{
				cid = DOWN;
				foe[i]->set_coord_ID(cid);
				break;
			}

			if (foe[i]->get_y() + EN.get_h(foe[i]->get_name_ID()) > winy)
			{
				foe.erase(foe.begin() + i);
				break;
			}

		}
	}

		
}

void collision::Boss_boundary_collision(Enemy_Manager EN, std::vector <boss*> &foe)
{
	for (int i = 0; i < foe.size(); i++)
	{
		if (foe[i]->get_boss() != MARTIANB)
		{
			if (foe[i]->get_x() + EN.get_boss_w(foe[i]->get_boss()) > winx)
			{
				cid = LEFT;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = RIGHT;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}

			if (foe[i]->get_y() < 0)
			{
				cid = DOWN;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}

			if (foe[i]->get_y() > winy - EN.get_boss_h(foe[i]->get_boss()) - 100)
			{
				cid = UP;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}
		}

		else
		{
			if (foe[i]->get_x() + EN.get_boss_w(foe[i]->get_boss()) > winx)
			{
				cid = LEFT;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = RIGHT;
				foe[i]->set_coordID(cid);
				foe[i]->set_action(rand() % 4);
				break;
			}
		}
	}
}

void collision::enemy_gets_damaged(Enemy_Manager EN, weaponManager W, Tools_manager & tm, std::vector<Ammo*>& a,
	std::vector<Tools*>& t, std::vector<enemies*>& f, std::vector<Weapon*>& l, 
	Status & s, ALLEGRO_SAMPLE_INSTANCE * instance, ALLEGRO_SAMPLE_INSTANCE *hit_sound, ALLEGRO_FONT * font, Animate &hit, int & score)
{
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < l.size(); j++)
		{
			if (f[i]->get_health() > 0)
			{
				if ((f[i]->get_x() < l[j]->getx() + W.getw(l[j]->getweaponID()) && f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) > l[j]->getx() &&
					f[i]->get_y() < l[j]->gety() + W.geth(l[j]->getweaponID()) && f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) > l[j]->gety()))
				{
					al_set_sample_instance_playmode(hit_sound, ALLEGRO_PLAYMODE_ONCE);
					al_set_sample_instance_position(hit_sound, 0);
					al_play_sample_instance(hit_sound);
					switch (l[j]->getweaponID())
					{
					case LAZER:
						l[j]->set_damage(1);
						f[i]->set_hit(true);
						hit.set_frame(0);
						f[i]->set_y(f[i]->get_y() - 25);
						f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
						break;

					case ICET:
						l[j]->set_damage(1);
						f[i]->set_coord_ID(l[j]->effect());
						f[i]->set_duration(150);
						f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
						break;

					case INFERRED:
						l[j]->set_damage(2);
						f[i]->set_coord_ID(l[j]->effect());
						f[i]->set_duration(75);
						f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
						break;

					case ZIGGONET:
						l[j]->set_damage(3);
						f[i]->set_coord_ID(l[j]->effect());
						f[i]->set_duration(100);
						f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
						break;

					case HAYCH:
						for (int i = 0; i < f.size(); i++)
						{
							if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) <= winx && f[i]->get_x() >= 0 &&
								f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) <= winy && f[i]->get_y() >= 0))
							{
								l[j]->set_damage(3);
								f[i]->set_hit(true);
								f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
								f[i]->set_coord_ID(l[j]->effect());
							}
						}
						break;

					case HAYCHBA:
						for (int i = 0; i < f.size(); i++)
						{
							if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) <= winx && f[i]->get_x() >= 0 &&
								f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) <= winy && f[i]->get_y() >= 0))
							{
								l[j]->set_damage(4);
								f[i]->set_hit(true);
								f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
								f[i]->set_coord_ID(l[j]->effect());
							}
						}
						break;

					case SONICWAVE:
						for (int i = 0; i < f.size(); i++)
						{
							if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) <= winx && f[i]->get_x() >= 0 &&
								f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) <= winy && f[i]->get_y() >= 0))
							{
								f[i]->set_duration(300);
								l[j]->set_damage(5);
								f[i]->set_hit(true);
								f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
								f[i]->set_coord_ID(l[j]->effect());
							}
						}
						break;
					}

					if (f[i]->get_y() < 0)
					{
						f[i]->set_y(0);
					}

					//enemy_dies(font, NULL, s, score, t, )
					//std::cout << "Enemy Health " << i << " :" << f[i]->get_health() << std::endl;


					l.erase(l.begin() + j);

				}
			}
		}
	}
}

void collision::enemy_dies( ALLEGRO_FONT *font, Animate &d, Status &s, int &numkills, int &score, Tools_manager & tm, std::vector<Ammo*>& a,
	std::vector<Tools*>& t, std::vector<enemies*>& f, bool weaponunlock[7], ALLEGRO_SAMPLE_INSTANCE * instance)
{
	for (int i = 0; i < f.size(); i++)
	{
		if (i > f.size())
		{
			break;
		}

		if (f[i]->get_health() <= 0)
		{

			//std::cout << numkills << std::endl;

			f[i]->update_destroy_animation();
			f[i]->set_coord_ID(10);

			al_set_sample_instance_position(instance, 0);
			al_play_sample_instance(instance);
			al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

			if (f[i]->get_destroy_frame() >= 20)
			{
				tm.set_tool_ID(rand() % 51);
				//tm.set_tool_ID(11);
				f[i]->init();
				f[i]->set_hit(false);

				if (tm.get_tool_ID() < 12)
				{
					int randomammo = ((2 * (rand() % 6)) + 5);
					//std::cout << "AMMO: " << (2 * (rand() % 6) + 5) << std::endl;
					if (weaponunlock[ICET] && randomammo == ICE)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), ICE));

					}
					
					else if (weaponunlock[INFERRED] && randomammo == FIRE)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), FIRE));

					}

					else if (weaponunlock[ZIGGONET] && randomammo == ZIG)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), ZIG));

					}

					else if (weaponunlock[HAYCH] && randomammo == H)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), H));

					}

					else if (weaponunlock[HAYCHBA] && randomammo == HBAR)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), HBAR));

					}

					else if (weaponunlock[SONICWAVE] && randomammo == WAVE)
					{
						a.push_back(new Ammo(f[i]->get_x(), f[i]->get_y(), WAVE));

					}
				}

				else if (tm.get_tool_ID() > 25)
				{
						t.push_back(new Tools(f[i]->get_x(), f[i]->get_y(), rand() % 2));
				}

				


				score = score + f[i]->get_score();

				f.erase(f.begin() + i);
				s.setscore(score, font);
				numkills++;
			}
			
		}

	}
}

void collision::enemy_gets_damaged(Enemy_Manager EN, std::vector<Tools*>& t, std::vector<enemies*>& f, Status & s, ALLEGRO_FONT * font)
{
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < stunned_enemy.size(); j++)
		{

			if (f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) < f[stunned_enemy[j]]->get_x() && f[i]->get_x() < f[stunned_enemy[j]]->get_x() + 50 
				&& f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) < f[stunned_enemy[j]]->get_y() && f[i]->get_y() < f[stunned_enemy[j]]->get_y())
			{
				num_of_kill += 1;
				set_num_of_kills(num_of_kill);
				t.push_back(new Tools(f[i]->get_x(), f[i]->get_y(), rand() % 20));

				

				f.erase(f.begin() + stunned_enemy[j]);
				f.erase(f.begin() + i);

			
				break;
			}
		}
	}
}

void collision::boss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector <boss*> &b, std::vector <Boss_weapon*> &bw, std::vector <Weapon*> &f, 
	ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_SAMPLE_INSTANCE *instance2, bool &bossdefeated)
{

	for (int i = 0; i < b.size(); i++)
	{
		for (int l = 0; l < bw.size(); l++)
		{
			if ((b[i]->get_x() < bw[l]->get_x() + EN.boss_weapon_w(bw[l]->get_kinds_of_weapon()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > bw[l]->get_y() &&
				b[i]->get_y() < bw[l]->get_y() + EN.boss_weapon_h(bw[l]->get_kinds_of_weapon()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > bw[l]->get_x()) && bw[l]->isreflected())
			{				
				if (b[i]->get_health() > 0 && bw[l]->get_kinds_of_weapon() == BALL)
				{
					b[i]->set_frame(0);
					b[i]->set_y(b[i]->get_y() - 50);
					b[i]->set_health(b[i]->get_health() - 1);
					
					bw.erase(bw.begin() + l);
					
					al_set_sample_instance_position(instance, 0);
					EN.sethit(true);
					b[i]->set_vel(b[i]->get_vel() + 1);
					b[i]->set_action(rand() % 4);
					
					al_set_sample_instance_gain(instance, 1.5);
					al_play_sample_instance(instance);
				}	
			}
		}

		

		for (int j = 0; j < f.size(); j++)
		{
			if (b.size() <= 0)
			{
				break;
			}

			switch (b[i]->get_boss())
			{
			case SPARTAK:
				if ((b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx()))
				{
					if (f[j]->getweaponID() == LAZER)
					{
						al_set_sample_instance_position(instance2, 0);

						al_set_sample_instance_gain(instance2, 1);
						al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance2);
						f.erase(f.begin() + j);
					}

					else if (f[j]->getweaponID() == HAYCH)
					{
						if (b[i]->get_health() > 0)
						{
							bw.clear();
							b[i]->set_frame(0);
							b[i]->set_y(b[i]->get_y() - 50);
							b[i]->set_health(b[i]->get_health() - 1);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_action(rand() % 4);
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							f.erase(f.begin() + j);
						}
					}
					
					else if (f[j]->getweaponID() == HAYCHBA)
					{
						if (b[i]->get_health() > 0)
						{
							b[i]->set_frame(0);
							b[i]->set_y(b[i]->get_y() - 50);
							b[i]->set_health(b[i]->get_health() - 2);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_action(rand() % 4);
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							f.erase(f.begin() + j);
						}
					}
				}
				break;

			case MARTIANB:
				if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx())
				{

					if (f[j]->getweaponID() == LAZER)
					{
						if (b[i]->get_coordID() == UP || b[i]->get_coordID() == DOWN)
						{
							b[i]->set_health(b[i]->get_health() - 1);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_frame(0);
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							
							
							f.erase(f.begin() + j);
							

						}

						else
						{
							al_set_sample_instance_position(instance2, 0);

							al_set_sample_instance_gain(instance2, 1);
							al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(instance2);
							
							f.erase(f.begin() + j);
							

						}
					}

					else if (f[j]->getweaponID() == HAYCH)
					{
						if (b[i]->get_health() > 0)
						{
							b[i]->set_frame(0);
							b[i]->set_y(b[i]->get_y() - 50);
							b[i]->set_health(b[i]->get_health() - 1);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_action(rand() % 4);
							if (b[i]->get_vel() > 3)
							{
								b[i]->set_vel(3);
							}
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							f.erase(f.begin() + j);

						}

						
					}

					else if (f[j]->getweaponID() == HAYCHBA)
					{
						if (b[i]->get_health() > 0)
						{
							b[i]->set_frame(0);
							b[i]->set_y(b[i]->get_y() - 50);
							b[i]->set_health(b[i]->get_health() - 2);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_action(rand() % 4);
							if (b[i]->get_vel() > 3)
							{
								b[i]->set_vel(3);
							}
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							f.erase(f.begin() + j);
						}
					}


				}
				break;

			case KAMETKHAN:
				if ((b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx()))
				{
					if (f[j]->getweaponID() == LAZER)
					{
						al_set_sample_instance_position(instance2, 0);

						al_set_sample_instance_gain(instance2, 1);
						al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance2);
						f.erase(f.begin() + j);
					}

					else if (f[j]->getweaponID() == HAYCHBA)
					{
						if (b[i]->get_health() > 0)
						{
							b[i]->set_frame(0);
							b[i]->set_y(b[i]->get_y() - 50);
							b[i]->set_health(b[i]->get_health() - 1);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							b[i]->set_action(rand() % 4);
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);
							f.erase(f.begin() + j);
						}
					}
				}
				break;

			case XORGANA:
				if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx())
				{

					b[i]->set_health(b[i]->get_health() - 1);
					f.erase(f.begin() + j);
					al_set_sample_instance_position(instance, 0);
					EN.sethit(true);
					b[i]->set_frame(0);
					al_set_sample_instance_gain(instance, 1.5);
					al_play_sample_instance(instance);

					b[i]->set_vel(b[i]->get_vel() + 1);
				}
				break;
			}
		}

		for (int k = 0; k < f.size(); k++)
		{
			if (b.size() == 0)
			{
				break;
			}

			if (b[i]->get_boss() == KAMETKHAN)
			{

				if ((b[i]->get_y() < f[k]->gety() + W.geth(f[k]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[k]->gety() &&
					b[i]->get_x() < f[k]->getx() + W.getw(f[k]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[k]->getx()) && 
					f[k]->getweaponID() == ICET)
				{

					b[i]->set_health(b[i]->get_health() - 1);
					f.erase(f.begin() + k);
					al_set_sample_instance_position(instance, 0);
					EN.sethit(true);
					b[i]->set_frame(0);
					al_set_sample_instance_gain(instance, 1.5);
					al_play_sample_instance(instance);

					if (b[i]->get_health() % 2 == 0)
					{
						b[i]->set_vel(b[i]->get_vel() + 1);
						if (b[i]->get_vel() > 3)
						{
							b[i]->set_vel(3);
						}
					}

				}

				
				break;
			}


		}

		if (b[i]->get_health() <= 0)
		{

			bossdefeated = true;
			EN.set_death(true);
			EN.sethit(false);

			if (b[i]->get_frame() > 205)
			{
				b.erase(b.begin() + i);
				EN.set_death(false);
			}


		}
	}
}

void collision::Ball_gets_redirected(Enemy_Manager &EN, weaponManager W, std::vector <Boss_weapon*> &bw, std::vector <Weapon*> &f,
	ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{
	for (int i = 0; i < bw.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			
			
			if (bw[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && bw[i]->get_y() + EN.boss_weapon_h(bw[i]->get_kinds_of_weapon()) > f[j]->gety() &&
				bw[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && bw[i]->get_x() + EN.boss_weapon_w(bw[i]->get_kinds_of_weapon()) > f[j]->getx())
			{
				if (bw[i]->get_kinds_of_weapon() == BALL)
				{
					al_set_sample_instance_position(instance, 0);
					al_set_sample_instance_gain(instance, 1);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(instance);

					bw[i]->set_reflect(true);
					bw[i]->set_coord_ID(UP);
					f.erase(f.begin() + j);
					break;
				}
				
			}

		
			


		}

	}
}

void collision::Ball_gets_destroyed(Enemy_Manager &EN, weaponManager W, Tools_manager & tm, std::vector <Boss_weapon*> &bw, std::vector <Weapon*> &f,
	std::vector <Ammo*> &a, ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{
	for (int i = 0; i < bw.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			if (f.size() > 0 && bw.size() > 0)
			{
				if (bw[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && bw[i]->get_y() + EN.boss_weapon_h(bw[i]->get_kinds_of_weapon()) > f[j]->gety() &&
					bw[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && bw[i]->get_x() + EN.boss_weapon_w(bw[i]->get_kinds_of_weapon()) > f[j]->getx())
				{
					if (bw[i]->get_kinds_of_weapon() == MOLTEN)
					{
						tm.set_tool_ID(rand() % 7);

						if (tm.get_tool_ID() <= 5)
						{
							a.push_back(new Ammo(bw[i]->get_x(), bw[i]->get_y(), ICE));
						}

						f.erase(f.begin() + j);
						bw.erase(bw.begin() + i);
					}

				}
			}
		}
	}
}

void collision::Boss_weapon_immune_to_weapon(Enemy_Manager &EN, Stages s, std::vector <enemies*> e, weaponManager W,
	std::vector <Enemy_Lazer*> &lazer, std::vector <Weapon*> &f, std::vector <Turrets *> turrets, std::vector <Boss_weapon*> &bw,
	ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{

	for (int i = 0; i < bw.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			if (f.size() > 0 && bw.size() > 0)
			{
				if (bw[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && bw[i]->get_y() + EN.boss_weapon_h(bw[i]->get_kinds_of_weapon()) > f[j]->gety() &&
					bw[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && bw[i]->get_x() + EN.boss_weapon_w(bw[i]->get_kinds_of_weapon()) > f[j]->getx())
				{
					if (bw[i]->get_kinds_of_weapon() == MOLTEN || bw[i]->get_kinds_of_weapon() == BALL)
					{
						al_set_sample_instance_position(instance, 0);
						al_set_sample_instance_gain(instance, 1);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance);
						f.erase(f.begin() + j);
					}
				}

				
			}
		}
	}
	

	for (int n = 0; n < e.size(); n++)
	{
		for (int i = 0; i < e[n]->get_weaponsize(); i++)
		{
			for (int j = 0; j < f.size(); j++)
			{
				if (e[n]->get_weapony(i) < f[j]->gety() + W.geth(f[j]->getweaponID()) && e[n]->get_weapony(i) + EN.get_Eweapon_h(e[n]->get_name_ID()) > f[j]->gety() &&
					e[n]->get_weaponx(i) < f[j]->getx() + W.getw(f[j]->getweaponID()) && e[n]->get_weaponx(i) + EN.get_Eweapon_w(e[n]->get_name_ID()) > f[j]->getx())
				{
					if (f[j]->getweaponID() == LAZER)
					{
						al_set_sample_instance_position(instance, 0);
						al_set_sample_instance_gain(instance, 1);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance);

						e[n]->killweapon(i);
						f.erase(f.begin() + j);
					}


					else
					{
						al_set_sample_instance_position(instance, 0);
						al_set_sample_instance_gain(instance, 1);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance);

						e[n]->killweapon(i);
					}

					break;
				}

			}
		}
	}

}

void collision::Boss_weapon_immune_to_weapon(Enemy_Manager & EN, weaponManager W, std::vector<enemies*> e, std::vector<Weapon*>& f,
	ALLEGRO_SAMPLE_INSTANCE * instance, bool & bossdefeated)
{
	for (int n = 0; n < e.size(); n++)
	{
		for (int i = 0; i < e[n]->get_weaponsize(); i++)
		{
			for (int j = 0; j < f.size(); j++)
			{
				if (e[n]->get_weapony(i) < f[j]->gety() + W.geth(f[j]->getweaponID()) && e[n]->get_weapony(i) + EN.get_Eweapon_h(e[n]->get_name_ID()) > f[j]->gety() &&
					e[n]->get_weaponx(i) < f[j]->getx() + W.getw(f[j]->getweaponID()) && e[n]->get_weaponx(i) + EN.get_Eweapon_w(e[n]->get_name_ID()) > f[j]->getx())
				{
					if (f[j]->getweaponID() == LAZER)
					{
						al_set_sample_instance_position(instance, 0);
						al_set_sample_instance_gain(instance, 1);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance);

						e[n]->killweapon(i);
						f.erase(f.begin() + j);
					}


					else
					{
						al_set_sample_instance_position(instance, 0);
						al_set_sample_instance_gain(instance, 1);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(instance);

						e[n]->killweapon(i);
					}

					break;
				}

			}
		}
	}
}

void collision::miniboss_gets_damaged(Enemy_Manager &EN, Stages s, weaponManager W, std::vector <mini_boss*> &mb, std::vector <Turrets *> &turrets, 
	std::vector <Weapon*> &f, ALLEGRO_SAMPLE_INSTANCE * hit, ALLEGRO_SAMPLE_INSTANCE *die, bool &bossdefeated)
{
	
	for (int i = 0; i < turrets.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			if ((turrets[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && turrets[i]->get_y() + EN.get_turret_h(s.get_stage()) > f[j]->gety() &&
				turrets[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && turrets[i]->get_x() + EN.get_turret_w(s.get_stage()) > f[j]->getx()) && f[j]->getweaponID() == LAZER)
			{
				//std::cout << turrets[i]->get_health() << std::endl;
				if (turrets[i]->get_health() > 0)
				{
					al_play_sample_instance(hit);
					turrets[i]->decrement_health();
					turrets[i]->set_hit(true);
					f.erase(f.begin() + j);

				}

				else
				{
					al_play_sample_instance(die);
					turrets.erase(turrets.begin() + i);
					if (i == 0)
					{
						mb.erase(mb.begin() + 0);
					}

					if (i == 1)
					{
						mb.erase(mb.begin() + 1);
					}
				}

				break;
			}
		}
	}
}

void collision::player_gets_damaged(Enemy_Manager &EN, std::vector <mini_boss*> &mb, std::vector <boss*> &b, std::vector <enemies*> &f, std::vector <player*> &p, 
	Status s, ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, Animate &hit, int &health)
{
	// If player collides with enemies
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (f[i]->get_health() > 0)
			{
				if (p[j]->get_y() < f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) && p[j]->get_y() + p[j]->get_h() > f[i]->get_y() &&
					p[j]->get_x() < f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) && p[j]->get_x() + p[j]->get_w() > f[i]->get_x())
				{
					if (s.gethealth() > 0)
					{
						health = health - f[i]->get_damage();
						p[j]->set_y(p[j]->get_y() + 25);

						if (p[j]->get_y() + p[j]->get_h() > 400)
						{
							p[j]->set_y(400 - p[j]->get_h());
						}

						s.sethealth(health, font);
						p[j]->ship_hit(true);
						hit.set_frame(0);

						if (f[i]->get_name_ID() != SATUSPHERE || f[i]->get_name_ID() != JUPIBALL)
						{
							f[i]->ability(p[j], e);
						}

						if (f[i]->get_name_ID() == KAMEKOSET)
						{
							f[i]->set_health(0);
						}

						al_set_sample_instance_position(instance, 0);
						al_play_sample_instance(instance);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
					}
				}

				else if (p[j]->get_y() < f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) + 50 && p[j]->get_y() + p[j]->get_h() > f[i]->get_y() - 50 &&
					p[j]->get_x() < f[i]->get_x() + 50 + EN.get_w(f[i]->get_name_ID()) && p[j]->get_x() + p[j]->get_w() > f[i]->get_x() - 50)
				{
					if (f[i]->get_name_ID() == SATUSPHERE || f[i]->get_name_ID() == JUPIBALL)
					{
						f[i]->gravity(p[j]);
						p[j]->set_keys(p[j]->get_coords_ID(), false);

						if (p[j]->get_y() + p[j]->get_h() > 400)
						{
							p[j]->set_y(400 - p[j]->get_h());
						}
					}
				}

				else
				{
					p[j]->set_vel(5);
				}
			}
		}
	}

	// If Player collides with the boss
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) && p[j]->get_y() + p[j]->get_h() > b[i]->get_y() &&
				p[j]->get_x() < b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) && p[j]->get_x() + p[j]->get_w() > b[i]->get_x())
			{
				if (s.gethealth() > 0)
				{

					

					switch (b[i]->get_boss())
					{
					case SPARTAK:
						health = health - 20;
						break;
					case MARTIANB:
						health = health - 20;
						break;
					case KAMETKHAN:
						health = health - 30;
						break;
					case XORGANA:
						health = health - 40;
						break;
					}


					p[j]->ship_hit(true);
					hit.set_frame(0);
					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

					if (p[j]->get_y() + p[j]->get_h() > 400)
					{
						p[j]->set_y(400 - p[j]->get_h());
					}

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}
		}

	}

	for (int i = 0; i < mb.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < mb[i]->get_y() + EN.get_E_h())
			{
				if (s.gethealth() > 0)
				{
					health = health - 10;
					if (p[j]->get_y() + p[j]->get_h() > 400)
					{
						p[j]->set_y(400 - p[j]->get_h());
					}

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);
					p[j]->ship_hit(true);
					hit.set_frame(0);

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}


		}

	}
	
}

void collision::player_gets_damaged(Enemy_Manager & EN, std::vector<enemies*>& foes, std::vector<Enemy_Lazer*>& lazer, std::vector<player*>& p, 
	Status s, ALLEGRO_SAMPLE_INSTANCE * instance, ALLEGRO_FONT * font, ALLEGRO_EVENT e, Animate & hit, int & health)
{
	for (int n = 0; n < foes.size(); n++)
	{
		for (int i = 0; i < foes[n]->get_weaponsize(); i++)
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (foes[n]->get_weapony(i) < p[j]->get_y() + p[j]->get_h() && foes[n]->get_weapony(i) + EN.get_Eweapon_h(foes[n]->get_name_ID()) > p[j]->get_y() &&
					foes[n]->get_weaponx(i) < p[j]->get_x() + p[j]->get_w() && foes[n]->get_weaponx(i) + EN.get_Eweapon_w(foes[n]->get_name_ID()) > p[j]->get_x())
				{
					if (s.gethealth() > 0)
					{

						

						p[j]->set_y(p[j]->get_y() + 50);
						
						s.sethealth(health, font);
						p[j]->ship_hit(true);
						hit.set_frame(0);
						foes[n]->weapon_ability(p[0]);
						foes[n]->killweapon(i);
						health = health - foes[n]->get_damage();

						if (p[j]->get_y() + p[j]->get_h() > 400)
						{
							p[j]->set_y(400 - p[j]->get_h());
						}

						al_set_sample_instance_position(instance, 0);
						al_play_sample_instance(instance);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

					}

				}
			}
		}
	}
}

void collision::check_position(Enemy_Manager E, std::vector<enemies*>& f)
{
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			if (j != i && f[i]->get_x() + E.get_w(f[i]->get_name_ID()) < f[j]->get_x())
			{
				f[i]->set_y(f[i]->get_y() - E.get_w(f[i]->get_name_ID()));
			}
		}
	}
}

void collision::player_gets_damaged(Enemy_Manager &EN, Stages stage, std::vector <enemies*> &foes, std::vector <Enemy_Lazer*> &lazer, 
	std::vector <Turrets *> turrets, std::vector <player*> &p, std::vector <Boss_weapon*> &bw, Status s,
	ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, Animate &hit, int &health)
{
	for (int i = 0; i < bw.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < bw[i]->get_y() + EN.boss_weapon_h(bw[i]->get_kinds_of_weapon()) && p[j]->get_y() + p[j]->get_h() > bw[i]->get_y() &&
				p[j]->get_x() < bw[i]->get_x() + EN.boss_weapon_w(bw[i]->get_kinds_of_weapon()) && p[j]->get_x() + p[j]->get_w() > bw[i]->get_x())
			{
				if (s.gethealth() > 0)
				{
					switch (bw[i]->get_kinds_of_weapon())
					{
					case BALL:
						health = health - 15;
						break;
					case DIAMONDS:
						health = health - 10;
						break;
					case EGG:
						health = health - 25;
						break;
					case TURBULENCE:
						health = health - 15;
						break;
					case B_LAZER:
						health = health - 10;
						break;
					case MOLTEN:
						health = health - 35;
						break;
					case KAMET:
						health = health - 35;
						break;
					case V:
						health = health - 25;
						break;
					case SINGTW:
						health = health - 40;
						break;
					}

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);
					p[j]->ship_hit(true);
					hit.set_frame(0);
					bw.erase(bw.begin() + i);

					if (p[j]->get_y() + p[j]->get_h() > 400)
					{
						p[j]->set_y(400 - p[j]->get_h());
					}

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
				}

			}

			
			else if (p[j]->get_x() < (bw[i]->get_x() + EN.get_boss_w(KAMETKHAN) / 2) + (bw[i]->get_r()) &&
				p[j]->get_y() < (bw[i]->get_y() + EN.get_boss_h(KAMETKHAN) / 2) + (bw[i]->get_r()) &&
				p[j]->get_x() + p[j]->get_w() > (bw[i]->get_x()) - (bw[i]->get_r()) &&
				p[j]->get_y() + p[j]->get_h() > (bw[i]->get_y()) - (bw[i]->get_r()))
			{
				if (bw[i]->get_kinds_of_weapon() == HEAT)
				{
					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);
					p[j]->ship_hit(true);
					hit.set_frame(0);

					bw.erase(bw.begin() + i);
					health = health - 15;

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
				}
			}
				
		}
	}

	for (int n = 0; n < foes.size(); n++)
	{
		for (int i = 0; i < foes[n]->get_weaponsize(); i++)
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (foes[n]->get_weapony(i) < p[j]->get_y() + p[j]->get_h() && foes[n]->get_weapony(i) + EN.get_Eweapon_h(foes[n]->get_name_ID()) > p[j]->get_y() &&
					foes[n]->get_weaponx(i) < p[j]->get_x() + p[j]->get_w() && foes[n]->get_weaponx(i) + EN.get_Eweapon_w(foes[n]->get_name_ID()) > p[j]->get_x())
				{
					if (s.gethealth() > 0)
					{

						p[j]->set_y(p[j]->get_y() + 50);
						s.sethealth(health, font);
						p[j]->ship_hit(true);
						hit.set_frame(0);
						foes[n]->weapon_ability(p[0]);
						foes[n]->killweapon(i);
						health = health - foes[n]->get_damage();

						if (p[j]->get_y() + p[j]->get_h() > 400)
						{
							p[j]->set_y(400 - p[j]->get_h());
						}

						al_set_sample_instance_position(instance, 0);
						al_play_sample_instance(instance);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

					}

				}
			}
		}
	}

	for (int n = 0; n < turrets.size(); n++)
	{
		for (int i = 0; i < turrets[n]->weapon_size(); i++)
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (turrets[n]->get_weapony(i) < p[j]->get_y() + p[j]->get_h() && turrets[n]->get_weapony(i) + EN.get_turretweapon_h(stage.get_stage()) > p[j]->get_y() &&
					turrets[n]->get_weaponx(i) < p[j]->get_x() + p[j]->get_w() && turrets[n]->get_weaponx(i) + EN.get_turretweapon_w(stage.get_stage()) > p[j]->get_x())
				{
					if (s.gethealth() > 0)
					{

						p[j]->set_y(p[j]->get_y() + 50);
						if (p[j]->get_y() + p[j]->get_h() > 400)
						{
							p[j]->set_y(400 - p[j]->get_h());
						}

						s.sethealth(health, font);
						p[j]->ship_hit(true);
						hit.set_frame(0);

						turrets[n]->killweapon(i);
						health = health - 10;

						al_set_sample_instance_position(instance, 0);
						al_play_sample_instance(instance);
						al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

					}

				}
			}
		}
	}
}

void collision::player_gets_tool(std::vector <player*> &p, Enemy_Manager EN, std::vector <enemies*> &fo,
	std::vector <Tools*> &t, std::vector <Ammo*> &a, Tools_manager tm, Status s, Stages &stage, ALLEGRO_SAMPLE_INSTANCE *instance[3], 
	ALLEGRO_FONT *f, int &health, int (& ammo)[7], bool &killonce)
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_x() + p[j]->get_w() > t[i]->get_x() && p[j]->get_x() < t[i]->get_x() + tm.get_tools_w(t[i]->get_tool_ID()) && 
				p[j]->get_y() + p[j]->get_h() > t[i]->get_y() && p[j]->get_y() < t[i]->get_y() + tm.get_tools_h(t[i]->get_tool_ID()))
			{
				switch (t[i]->get_tool_ID())
				{
				case HEALTH:
					al_set_sample_instance_position(instance[0], 0);
					al_set_sample_instance_playmode(instance[0], ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(instance[0]);

					health += 10;
					s.sethealth(health, f);
					break;

				case DISFIG:
					al_set_sample_instance_position(instance[2], 0);
					al_set_sample_instance_playmode(instance[2], ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(instance[2]);

					killonce = true;
					stage.set_disfig(true);

					break;
				}

				t.erase(t.begin() + i);

			}
		}
	}
	

	//std::cout << "AMMO: " << a.size() << std::endl;

	for (int k = 0; k < a.size(); k++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_x() + p[j]->get_w() > a[k]->get_x() && p[j]->get_x() < a[k]->get_x() + tm.get_ammo_w(a[k]->get_ammo_ID()) && 
				p[j]->get_y() + p[j]->get_h() > a[k]->get_y() && p[j]->get_y() < a[k]->get_y() + tm.get_ammo_h(a[k]->get_ammo_ID()))
			{
			
				al_set_sample_instance_position(instance[1], 0);
				al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(instance[1]);
				
				
				switch (a[k]->get_ammo_ID())
				{
				case ICE:
					ammo[ICET] ++;
					break;

				case FIRE:
					ammo[INFERRED] ++;
					break;

				case ZIG:
					ammo[ZIGGONET] ++;
					break;

				case H:
					ammo[HAYCH] ++;
					break;

				case HBAR:
					ammo[HAYCHBA] ++;
					break;

				case WAVE:
					ammo[SONICWAVE] ++;
					break;
				}

				a.erase(a.begin() + k);
			}
		}
	}
}

void collision::destroy_foes_inside(Enemy_Manager EN, std::vector<enemies*>& f)
{
	for (int i = 0; i < f.size(); i++)
	{
		//std::cout << i << std::endl;
		if (f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) <= winx && f[i]->get_x() >= 0 &&
			f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) <= winy && f[i]->get_y() >= 0)
		{
			f[i]->set_health(0);
		}

		
	}

	
}

int collision::get_num_of_kills()
{
	return this->num_of_kill;
}

void collision::set_num_of_kills(int kill)
{
	this->num_of_kill = kill;
}