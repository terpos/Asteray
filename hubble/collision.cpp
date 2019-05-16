#include "collision.h"



collision::collision()
{
	num_of_kill = 0;
	declare = false;
	//foeswap = new enemies();
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
		int x = p[i]->get_x();
		int y = p[i]->get_y();

		if (x > winx - 50)
		{
			p[i]->set_x(p[i]->get_x() - p[i]->get_vel());
		}

		if (x < 0)
		{
			p[i]->set_x(p[i]->get_x() + p[i]->get_vel());
		}

		if (y < 0)
		{
			p[i]->set_y(p[i]->get_y() + p[i]->get_vel());
		}

		if (y > winy - 150)
		{
			p[i]->set_y(p[i]->get_y() - p[i]->get_vel());
		}
	}

	
}

void collision::Enemy_boundary_collision(std::vector <enemies*> &foe, int destroy_or_rebound)
{
	for (int i = 0; i < foe.size(); i++)
	{
		
		if (destroy_or_rebound == REBOUND)
		{
			if (foe[i]->get_x() + 50 > winx)
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

			if (foe[i]->get_y() > winy - 200)
			{
				cid = UP;
				foe[i]->set_coord_ID(cid);
				break;
			}
		}

		if (destroy_or_rebound == DESTROY)
		{
			if (foe[i]->get_x() + 50 > winx || foe[i]->get_x() < 0 || foe[i]->get_y() < 0 || foe[i]->get_y() > winy - 200)
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
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = RIGHT;
				foe[i]->set_coordID(cid);
				break;
			}

			if (foe[i]->get_y() < 0)
			{
				cid = DOWN;
				foe[i]->set_coordID(cid);
				break;
			}

			if (foe[i]->get_y() > winy - EN.get_boss_h(foe[i]->get_boss()) - 100)
			{
				cid = UP;
				foe[i]->set_coordID(cid);
				break;
			}
		}

		else
		{
			if (foe[i]->get_x() + EN.get_boss_w(foe[i]->get_boss()) > winx)
			{
				cid = LEFT;
				foe[i]->set_coordID(cid);
				break;
			}

			if (foe[i]->get_x() < 0)
			{
				cid = RIGHT;
				foe[i]->set_coordID(cid);
				break;
			}
		}
	}
}

void collision::enemy_gets_damaged(Enemy_Manager EN, weaponManager W, Tools_manager & tm, std::vector<Ammo*>& a,
	std::vector<Tools*>& t, std::vector<enemies*>& f, std::vector<Weapon*>& l, 
	Status & s, ALLEGRO_SAMPLE_INSTANCE * instance, ALLEGRO_FONT * font, int & score)
{
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < l.size(); j++)
		{
			if (f[i]->get_x() < l[j]->getx() + W.getw(l[j]->getweaponID()) && f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) > l[j]->getx() &&
				f[i]->get_y() < l[j]->gety() + W.geth(l[j]->getweaponID()) && f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) > l[j]->gety())
			{
				//f[i]->setlife(false);
				


				switch (l[j]->getweaponID())
				{
				case LAZER:
					l[j]->set_damage(1);
					f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
					break;
				case ICET:
					l[j]->set_damage(1);
					f[i]->set_coord_ID(l[j]->effect());
					f[i]->set_duration(150);
					f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
					break;
				case INFERRED:
					l[j]->set_damage(1);
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
						if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) < winx && f[i]->get_x() > 0 &&
							f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) < winy && f[i]->get_y() > 0))
						{
							l[j]->set_damage(2);
							f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
							f[i]->set_coord_ID(l[j]->effect());
						}
					}
					break;
				case HAYCHBA:
					for (int i = 0; i < f.size(); i++)
					{
						if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) < winx && f[i]->get_x() > 0 &&
							f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) < winy && f[i]->get_y() > 0))
						{
							l[j]->set_damage(4);
							f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
							f[i]->set_coord_ID(l[j]->effect());
						}
					}
					break;
				case SONICWAVE:
					for (int i = 0; i < f.size(); i++)
					{
						if ((f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) < winx && f[i]->get_x() > 0 &&
							f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) < winy && f[i]->get_y() > 0))
						{
							l[j]->set_damage(5);
							f[i]->set_health(f[i]->get_health() - l[j]->get_damage());
							f[i]->set_coord_ID(l[j]->effect());
						}
					}
					break;
				}

				

				//std::cout << "Enemy Health " << i << " :" << f[i]->get_health() << std::endl;

				delete l[j];
				l.erase(l.begin() + j);

			}
		}
	}
}

void collision::enemy_dies(Tools_manager & tm, std::vector<Ammo*>& a, std::vector<Tools*>& t, std::vector<enemies*>& f, ALLEGRO_SAMPLE_INSTANCE * instance)
{
	for (int i = 0; i < f.size(); i++)
	{

		if (f[i]->get_coord_ID() == FROZEN || f[i]->get_coord_ID() == BURNED || f[i]->get_coord_ID() == STUNNED)
		{
			if (f[i]->get_health() <= 0)
			{
				this->num_of_kill += 1;
				set_num_of_kills(num_of_kill);

				tm.set_tool_ID(rand() % 30);

				al_set_sample_instance_position(instance, 0);
				al_play_sample_instance(instance);
				al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				if (tm.get_tool_ID() <= 15)
				{
					a.push_back(new Ammo());
					a[a.size() - 1]->set_ammo_ID(rand() % 20);
					a[a.size() - 1]->set_x(f[i]->get_x());
					a[a.size() - 1]->set_y(f[i]->get_y());
				}

				else
				{
					t.push_back(new Tools());
					t[t.size() - 1]->set_tool_ID(rand() % 4);
					t[t.size() - 1]->set_x(f[i]->get_x());
					t[t.size() - 1]->set_y(f[i]->get_y());
				}

				delete f[i];
				f.erase(f.begin() + i);				
			}
		}

		else
		{
			if (f[i]->get_health() <= 0)
			{
				this->num_of_kill += 1;
				set_num_of_kills(num_of_kill);

				tm.set_tool_ID(rand() % 30);

				al_set_sample_instance_position(instance, 0);
				al_play_sample_instance(instance);
				al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				if (tm.get_tool_ID() >= 12)
				{
					a.push_back(new Ammo());
					a[a.size() - 1]->set_ammo_ID(rand() % 20);
					a[a.size() - 1]->set_x(f[i]->get_x());
					a[a.size() - 1]->set_y(f[i]->get_y());
				}

				else
				{
					t.push_back(new Tools());
					t[t.size() - 1]->set_tool_ID(rand() % 4);
					t[t.size() - 1]->set_x(f[i]->get_x());
					t[t.size() - 1]->set_y(f[i]->get_y());
				}

				delete f[i];
				f.erase(f.begin() + i);
				break;
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
				t.push_back(new Tools());

				t[t.size() - 1]->set_tool_ID(rand() % 4);
				t[t.size() - 1]->set_x(f[i]->get_x());
				t[t.size() - 1]->set_y(f[i]->get_y());

				f.erase(f.begin() + stunned_enemy[j]);
				f.erase(f.begin() + i);

			
				break;
			}
		}
	}
}

void collision::boss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector <boss*> &b, std::vector <Spartak_ball*> &ball, std::vector <Weapon*> &f, 
	ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_SAMPLE_INSTANCE *instance2, bool &bossdefeated)
{

	for (int i = 0; i < b.size(); i++)
	{
		for (int l = 0; l < ball.size(); l++)
		{
			if ((b[i]->get_x() < ball[l]->get_x() + EN.get_ball_w() && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > ball[l]->get_y() &&
				b[i]->get_y() < ball[l]->get_y() + EN.get_ball_h() && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > ball[l]->get_x()) && ball[l]->isreflected())
			{
				//std::cout << "HIT" << std::endl;
				if (b[i]->get_health() == 0)
				{
					ball.erase(ball.begin() + l);
					b.erase(b.begin() + i);
					bossdefeated = true;
					EN.sethit(true);

					break;
				}

				else
				{
					b[i]->set_frame(0);
					b[i]->set_y(b[i]->get_y() - 50);
					b[i]->set_health(b[i]->get_health() - 1);
					ball.erase(ball.begin() + l);
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
					break;
				}


				//bossdefeated = true;
				break;
			}
		}

		for (int j = 0; j < f.size(); j++)
		{
			if (b.size() == 0)
			{
				break;
			}

			switch (b[i]->get_boss())
			{
			case SPARTAK:
				if ((b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx()) && f[j]->getweaponID() == LAZER)
				{
					al_set_sample_instance_position(instance2, 0);

					al_set_sample_instance_gain(instance2, 1);
					al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(instance2);
					f.erase(f.begin() + j);

				}
				break;

			case MARTIANB:
				if ((b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx()) && f[j]->getweaponID() == LAZER)
				{

					if (b[i]->get_health() == 0)
					{
						b.erase(b.begin() + i);
						f.erase(f.begin() + j);
						bossdefeated = true;
					}

					else
					{
						if (b[i]->get_coordID() == UP || b[i]->get_coordID() == DOWN)
						{
							b[i]->set_health(b[i]->get_health() - 1);
							f.erase(f.begin() + j);
							al_set_sample_instance_position(instance, 0);
							EN.sethit(true);
							b[i]->set_vel(b[i]->get_vel() + 1);
							if (b[i]->get_vel() > 3)
							{
								b[i]->set_vel(3);
							}
							b[i]->set_frame(0);
							al_set_sample_instance_gain(instance, 1.5);
							al_play_sample_instance(instance);

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
					break;
				}
				break;

			case KAMETKHAN:
				if ((b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx()) && f[j]->getweaponID() == LAZER)
				{
					al_set_sample_instance_position(instance2, 0);
					al_set_sample_instance_gain(instance2, 1);
					al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(instance2);
					f.erase(f.begin() + j);
					break;
				}
				break;

			case XORGANA:
				if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_boss_h(b[i]->get_boss()) > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[j]->getx())
				{
					if (b[i]->get_health() == 0)
					{
						b.erase(b.begin() + i);
						f.erase(f.begin() + j);

						bossdefeated = true;
					}

					else
					{
							b[i]->set_health(b[i]->get_health() - 1);
							f.erase(f.begin() + j);
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
					b[i]->get_x() < f[k]->getx() + W.getw(f[k]->getweaponID()) && b[i]->get_x() + EN.get_boss_w(b[i]->get_boss()) > f[k]->getx()) && f[k]->getweaponID()==ICET)
				{
					if (b[i]->get_health() == 0)
					{
						b.erase(b.begin() + i);
						f.erase(f.begin() + k);
						bossdefeated = true;
					}

					else
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

				break;
			}


		}
	}
}

void collision::Ball_gets_redirected(Enemy_Manager &EN, weaponManager W, std::vector <Spartak_ball*> &b, std::vector <Weapon*> &f,
	ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			
			if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_ball_h() > f[j]->gety() &&
					b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_ball_w() > f[j]->getx())
			{
				al_set_sample_instance_position(instance, 0);
				al_set_sample_instance_gain(instance, 1);
				al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(instance);

				b[i]->set_reflect(true);
				b[i]->set_coord_ID(UP);
				f.erase(f.begin() + j);
				break;
			}
			


		}

	}
}

void collision::Ball_gets_destroyed(Enemy_Manager &EN, weaponManager W, Tools_manager & tm, std::vector <Molten_shot*> &b, std::vector <Weapon*> &f,
	std::vector <Ammo*> &a, ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{

			if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_ball_h() > f[j]->gety() &&
				b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_ball_w() > f[j]->getx())
			{
				tm.set_tool_ID(rand() % 21);

				if (tm.get_tool_ID() <= 5)
				{
					a.push_back(new Ammo());
					a[a.size() - 1]->set_ammo_ID(ICE);
					a[a.size() - 1]->set_x(b[i]->get_x());
					a[a.size() - 1]->set_y(b[i]->get_y());
					
					
				}
			
				f.erase(f.begin() + j);
				b.erase(b.begin() + i);

				//f[j]->setweapony(f[j]->getweapony() + 1);
				break;
			}



		}
		
	}

	
}

void collision::Ball_gets_destroyed(Enemy_Manager &EN, weaponManager W, std::vector <v_beam*> &b, std::vector <Weapon*> &f, ALLEGRO_SAMPLE_INSTANCE *instance, bool &bossdefeated)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{

			if (b[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && b[i]->get_y() + EN.get_ball_h() > f[j]->gety() &&
				b[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && b[i]->get_x() + EN.get_ball_w() > f[j]->getx())
			{
				al_set_sample_instance_position(instance, 0);
				al_set_sample_instance_gain(instance, 1);
				al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(instance);
				f.erase(f.begin() + j);

				//f[j]->setweapony(f[j]->getweapony() + 1);
				break;
			}

		}

	}
}

void collision::miniboss_gets_damaged(Enemy_Manager &EN, weaponManager W, std::vector <mini_boss*> &mb, std::vector <Weapon*> &f, bool &bossdefeated)
{
	for (int i = 0; i < mb.size(); i++)
	{
		for (int j = 0; j < f.size(); j++)
		{
			if ((mb[i]->get_y() < f[j]->gety() + W.geth(f[j]->getweaponID()) && mb[i]->get_y() + EN.get_E_h() > f[j]->gety() &&
				mb[i]->get_x() < f[j]->getx() + W.getw(f[j]->getweaponID()) && mb[i]->get_x() + EN.get_E_w() > f[j]->getx()) && f[j]->getweaponID() == LAZER)
			{
				//::cout << "You Win" << std::endl;
				mb.erase(mb.begin()+i);
				//bossdefeated = true;
				break;
			}
		}

	}
}

void collision::player_gets_damaged(Enemy_Manager &EN, std::vector <mini_boss*> &mb, std::vector <boss*> &b, std::vector <enemies*> &f, std::vector <player*> &p, Status s,
	ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, int &health)
{
	// If player collides with enemies
	for (int i = 0; i < f.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < f[i]->get_y() + EN.get_h(f[i]->get_name_ID()) && p[j]->get_y() + p[j]->get_h() > f[i]->get_y() && 
				p[j]->get_x() < f[i]->get_x() + EN.get_w(f[i]->get_name_ID()) && p[j]->get_x() + p[j]->get_w() > f[i]->get_x())
			{
				if (s.gethealth() > 0)
				{
					health = health - f[i]->get_damage();
					p[j]->set_y(p[j]->get_y() + 25);
					s.sethealth(health, font);

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

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

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

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

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}


		}

	}
	
}

void collision::player_gets_damaged(Enemy_Manager &EN, std::vector <Spartak_ball*> &b, std::vector<Molten_shot*>& mball, std::vector<v_beam*>& v, std::vector <player*> &p, Status s,
	ALLEGRO_SAMPLE_INSTANCE *instance, ALLEGRO_FONT *font, ALLEGRO_EVENT e, int &health)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < b[i]->get_y() + EN.get_ball_h() && p[j]->get_y() + p[j]->get_h() > b[i]->get_y() &&
				p[j]->get_x() < b[i]->get_x() + EN.get_ball_w() && p[j]->get_x() + p[j]->get_w() > b[i]->get_x())
			{
				if (s.gethealth() > 0)
				{

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

					b.erase(b.begin() + i);
					health = health - 15;

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}
		}



	}

	for (int i = 0; i < mball.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < mball[i]->get_y() + EN.get_ball_h() && p[j]->get_y() + p[j]->get_h() > mball[i]->get_y() &&
				p[j]->get_x() < mball[i]->get_x() + EN.get_ball_w() && p[j]->get_x() + p[j]->get_w() > mball[i]->get_x())
			{
				if (s.gethealth() > 0)
				{

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

					mball.erase(mball.begin() + i);
					health = health - 25;

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}
		}
	}

	for (int n = 0; n < v.size(); n++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_y() < v[n]->get_y() + EN.get_ball_h() && p[j]->get_y() + p[j]->get_h() > v[n]->get_y() &&
				p[j]->get_x() < v[n]->get_x() + EN.get_ball_w() && p[j]->get_x() + p[j]->get_w() > v[n]->get_x())
			{
				if (s.gethealth() > 0)
				{

					p[j]->set_y(p[j]->get_y() + 50);
					s.sethealth(health, font);

					v.erase(v.begin() + n);
					health = health - 35;

					al_set_sample_instance_position(instance, 0);
					al_play_sample_instance(instance);
					al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);

				}

			}
		}
	}
}


void collision::player_gets_tool(std::vector <player*> &p, Enemy_Manager EN, std::vector <enemies*> &fo,
	std::vector <Tools*> &t, std::vector <Ammo*> &a, Status s, ALLEGRO_SAMPLE_INSTANCE *instance[3], ALLEGRO_FONT *f, int &health, int (& ammo)[6])
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_x() + 50 > t[i]->get_x() && p[j]->get_x() < t[i]->get_x() + 25 && p[j]->get_y() + 50 > t[i]->get_y() && p[j]->get_y() < t[i]->get_y() + 25)
			{
				switch (t[i]->get_tool_ID())
				{
				case HEALTH:
					al_set_sample_instance_position(instance[0], 0);
					al_play_sample_instance(instance[0]);
					al_set_sample_instance_playmode(instance[0], ALLEGRO_PLAYMODE_ONCE);

					health += 10;
					s.sethealth(health, f);
					t.erase(t.begin() + i);
					break;

				case DISFIG:
					al_set_sample_instance_position(instance[2], 0);
					al_play_sample_instance(instance[2]);
					al_set_sample_instance_playmode(instance[2], ALLEGRO_PLAYMODE_ONCE);
					EN.clear_enemy(fo);
					t.erase(t.begin() + i);
					break;
				}
			}
		}

		
	}
		
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j]->get_x() + 50 > a[i]->get_x() && p[j]->get_x() < a[i]->get_x() + 25 && p[j]->get_y() + 50 > a[i]->get_y() && p[j]->get_y() < a[i]->get_y() + 25)
			{
				switch (a[i]->get_ammo_ID())
				{
				case ICE:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[ICET] ++;
					a.erase(a.begin() + i);
					break;

				case FIRE:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[INFERRED] ++;
					a.erase(a.begin() + i);
					break;

				case ZIG:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[ZIGGONET] ++;
					a.erase(a.begin() + i);
					break;

				case H:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[HAYCH] ++;
					a.erase(a.begin() + i);
					break;

				case HBAR:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[HAYCHBA] ++;
					a.erase(a.begin() + i);
					break;

				case WAVE:
					al_set_sample_instance_position(instance[1], 0);
					al_play_sample_instance(instance[1]);
					al_set_sample_instance_playmode(instance[1], ALLEGRO_PLAYMODE_ONCE);

					ammo[SONICWAVE] ++;
					a.erase(a.begin() + i);
					break;
				}
			}
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
