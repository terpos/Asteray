#include "game_loop.h"


game_loop::game_loop()
{
	key = 0;
	health = 100;
	lvl = 3;
	sc = 0;
	pauseCounter = 0;
	num_of_enemies = 0;
	stagenumber = -1;
	weaponsel = 0;
	frame = 0;
	textframe = 0;
	num_of_weapon = 1;
	backgroundvol = 1.5;

	unlockweapon[ICET] = false;
	unlockweapon[INFERRED] = false;
	unlockweapon[ZIGGONET] = false;
	unlockweapon[HAYCH] = false;
	unlockweapon[HAYCHBA] = false;

	ammo[ICET] = 10;
	ammo[INFERRED] = 8;
	ammo[ZIGGONET] = 10;
	ammo[HAYCH] = 5;
	ammo[HAYCHBA] = 3;
	ammo[SONICWAVE] = 5;

	maxammo[ICET] = 10;
	maxammo[INFERRED] = 8;
	maxammo[ZIGGONET] = 10;
	maxammo[HAYCH] = 5;
	maxammo[HAYCHBA] = 3;
	maxammo[SONICWAVE] = 5;

	enemy_health[BLOBBY] = 1; // DEFAULT:8
	enemy_health[ASTERIX] = 1; // DEFAULT:10
	enemy_health[EPOLICE] = 1; // DEFAULT:3
	enemy_health[JUPIBALL] = 1; // DEFAULT:8
	enemy_health[KAMEKOSET] = 1; // DEFAULT:1
	enemy_health[MPOLICE] = 1; // DEFAULT:6
	enemy_health[SATUSPHERE] = 1; // DEFAULT:20
	enemy_health[SPACESHIP] = 1; // DEFAULT:2
	enemy_health[SPYDER] = 1; // DEFAULT:3
	enemy_health[VOLCANON] = 1; // DEFAULT:5
	enemy_health[WYRM] = 1; // DEFAULT:12
	enemy_health[XYBTOFY] = 1; // DEFAULT:1

	//spaceship = player();

	update = true;
	draw = false;
	battle = false;
	bossdefeated = false;
	gameover = false;

	status = NULL;
}

game_loop::~game_loop()
{

}

void game_loop::load_stuff()
{
	s.load_stages();
	T.load();
	spaceship.push_back(new player());
	status = al_load_ttf_font("bahnschrift.ttf", 15, NULL);

	frozen = al_load_bitmap("Frozen.png");

	stat.sethealth(health, status);
	al_reserve_samples(19);
	update = true;
	
	earth = al_load_sample("Earth.ogg");
	earth_factory = al_load_sample("Earth_Factory.ogg");
	boss = al_load_sample("Boss_music.ogg");
	mars = al_load_sample("mars.ogg");
	mars_nest = al_load_sample("Martian_nest.ogg");
	astroid = al_load_sample("Asteroid_Belt.ogg");
	saturn = al_load_sample("Saturn.ogg");
	final_boss = al_load_sample("final_boss.ogg");
	
	ls = al_load_sample("laser_shot.ogg");
	ic = al_load_sample("Ice-beam.ogg");
	fi = al_load_sample("fire-shot.ogg");
	li = al_load_sample("lightning-shot.ogg");
	ha = al_load_sample("haych.ogg");
	so = al_load_sample("wave_shot.ogg");

	health_pickup = al_load_sample("Health_pickup.ogg");
	ammo_pickup = al_load_sample("ammo_pickup.ogg");
	destroy_all = al_load_sample("destroy_all.ogg");

	Destroy = al_load_sample("destroy.ogg");

	Hit = al_load_sample("Player_hit.ogg");

	Game_over = al_load_sample("Game_over.ogg");

	Reflect = al_load_sample("214048__taira-komori__reflection.ogg");
	Ballreflect = al_load_sample("49673__ejfortin__energy-short-sword-2.ogg");
	Bosshit = al_load_sample("404786__owlstorm__retro-video-game-sfx-reflect.ogg");
	
	Earth = al_create_sample_instance(earth);
	Earth_Factory = al_create_sample_instance(earth_factory);
	Mars = al_create_sample_instance(mars);
	Mars_Nest = al_create_sample_instance(mars_nest);
	Astroid = al_create_sample_instance(astroid);
	Boss = al_create_sample_instance(boss);
	Saturn = al_create_sample_instance(saturn);
	Final_Boss = al_create_sample_instance(final_boss);

	lsr = al_create_sample_instance(ls);
	ice = al_create_sample_instance(ic);
	fire = al_create_sample_instance(fi);
	lit = al_create_sample_instance(li);
	haa = al_create_sample_instance(ha);
	wavey = al_create_sample_instance(so);

	pickup[0] = al_create_sample_instance(health_pickup);
	pickup[1] = al_create_sample_instance(ammo_pickup);
	pickup[2] = al_create_sample_instance(destroy_all);

	destroy = al_create_sample_instance(Destroy);

	hit = al_create_sample_instance(Hit);

	game_over = al_create_sample_instance(Game_over);

	reflect = al_create_sample_instance(Reflect);
	ballreflect = al_create_sample_instance(Ballreflect);
	bosshit = al_create_sample_instance(Bosshit);

	al_attach_sample_instance_to_mixer(Earth, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Earth_Factory, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Mars, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Mars_Nest, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Astroid, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Boss, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Saturn, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Final_Boss, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(lsr, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(ice, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(fire, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(lit, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(haa, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(wavey, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(pickup[0], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(pickup[1], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(pickup[2], al_get_default_mixer());
	al_attach_sample_instance_to_mixer(destroy, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(hit, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(game_over, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(reflect, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(ballreflect, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(bosshit, al_get_default_mixer());

	al_set_sample_instance_playmode(Earth, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Earth_Factory, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Mars, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Mars_Nest, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Astroid, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Saturn, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Boss, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Final_Boss, ALLEGRO_PLAYMODE_LOOP);
	
	for (int i = 0; i < 3; i++)
	{
		al_set_sample_instance_gain(pickup[i], 2);
	}

	al_set_sample_instance_gain(destroy, 2);
	al_set_sample_instance_gain(hit, 2);
	s.set_y(0);
	burned_red = al_load_bitmap("burned_red.png");
	burned_yellow = al_load_bitmap("burned_yellow.png");
	
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->load();
		spaceship[j]->set_coords(winx / 2, winy - 150);
	}

	shipWeapon.load_weapon_img();
	
	E.load_enemy_img();
	E2.load_enemy_img();
}

void game_loop::loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q)
{
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->set_enable(true);
	}

	while (!done)
	{
		//Event_listenter(ev, q);
		//update_loop(ev, q);
		stage(ev, q);
	}
}

void game_loop::stage(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q)
{
GAMEOVER:

	while (gameover)
	{
		update = false;

		al_stop_samples();

		update_loop(ev, q);
	}


CHANGESTAGE:
	
	stagenumber++;
	s.set_stage(stagenumber);

	while (s.get_stage() == EARTH)
	{
	LEVELUP:

		lvl++;
		stat.setlvl(lvl, status);

		while (stat.getlvl() == 1)
		{

			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP;
			}
			

			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		while (stat.getlvl() == 2)
		{
			if (mb.size() == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				al_stop_sample_instance(Earth);
				al_set_sample_instance_position(Earth, 0);
				goto LEVELUP;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}
		
		while (stat.getlvl() == 3)
		{
			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP;
			}
			
			Event_listenter(ev, q);

			update_loop(ev, q);
		
		}

		while (stat.getlvl() == 4)
		{
			if (bossdefeated && battle && b.size() == 0)
			{
				al_stop_samples();
				battle = false;
				s.scroll_down();
				lvl = 0;
				stat.setlvl(lvl, status);
				goto CHANGESTAGE;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);

		}
	}
	al_stop_sample_instance(Boss);
	while (s.get_stage() == MARS)
	{
		s.set_y(-2800);
		update = true;
		battle = false;
	LEVELUP2:

		lvl++;
		stat.setlvl(lvl, status);


		while (stat.getlvl() == 1)
		{

			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP2;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 2)
		{
			if (mb.size() == 0 && battle)
			{
				al_stop_sample_instance(Mars);
				battle = false;
				s.scroll_down();
				goto LEVELUP2;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		while (stat.getlvl() == 3)
		{
			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP2;
			}
			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		while (stat.getlvl() == 4)
		{
			if (bossdefeated && battle && b.size() == 0)
			{
				al_stop_samples();
				//delete b;
				battle = false;
				s.scroll_down();
				lvl = 0;
				stat.setlvl(lvl, status);
				goto CHANGESTAGE;
			}
			Event_listenter(ev, q);

			update_loop(ev, q);
		}
	}
	al_stop_sample_instance(Boss);
	while (s.get_stage() == AST)
	{
		//b->set_boss(-1);
		s.set_y(-2800);
		update = true;
		battle = false;

	LEVELUP3:

		lvl++;
		stat.setlvl(lvl, status);

		while (stat.getlvl() == 1)
		{


			if (s.get_y() == -2800 && !battle && lvl == 1)
			{
				battle = true;
				s.stop_moving();

				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, BLOBBY);
			}

			if (s.get_y() < -2800 || s.get_y() > -2800)
			{
				s.scroll_down();
			}


			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 2)
		{
			
			if (s.get_y() == -2400 && !battle && lvl == 2)
			{
				battle = true;
				s.stop_moving();
				E.spawn_boss(b, SPARTAK);
			}

			if (s.get_y() < -2400 || s.get_y() > -2400)
			{
				s.scroll_down();
			}

			if (b.size() == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}
			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 3)
		{
			if (s.get_y() == -2000 && !battle && lvl == 3)
			{
				battle = true;
				s.stop_moving();

				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, SPYDER);
			}

			if (s.get_y() < -2000 || s.get_y() > -2000)
			{
				s.scroll_down();
			}

			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 4)
		{
			if (s.get_y() == -1600 && !battle && lvl == 4)
			{
				battle = true;
				E.spawn_enemy(foes, enemy_health, rand() % 4, 6, ASTERIX);
				s.stop_moving();
			}

			if (s.get_y() < -1600 || s.get_y() > -1600)
			{
				s.scroll_down();
			}

			if (battle && foes.size() == 0)
			{
				//delete b;
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 5)
		{
			if (s.get_y() == -1200 && !battle && lvl == 5)
			{
				battle = true;
				E.spawn_enemy(foes, enemy_health, rand() % 4, 4, JUPIBALL);
				s.stop_moving();
			}

			if (s.get_y() < -1200 || s.get_y() > -1200)
			{
				s.scroll_down();
			}

			if (battle && foes.size() == 0)
			{
				//bossdefeated = false;
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 6)
		{
			if (s.get_y() == -800 && !battle && lvl == 6)
			{
				battle = true;
				E.spawn_boss(b, MARTIANB);
				s.stop_moving();
			}

			if (s.get_y() < -800 || s.get_y() > -800)
			{
				s.scroll_down();
			}

			if (battle && b.size() == 0)
			{
				//bossdefeated = false;
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 7)
		{
			if (s.get_y() == -400 && !battle && lvl == 7)
			{
				battle = true;
				E.spawn_enemy(foes, enemy_health, rand() % 4, 4, JUPIBALL);
				s.stop_moving();
			}

			if (s.get_y() < -400 || s.get_y() > -400)
			{
				s.scroll_down();
			}

			if (battle && E.get_num_of_enemy(foes) == 0)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP3;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
			
		}

		while (stat.getlvl() == 8)
		{

			if (s.get_y() == 0 && !battle && lvl == 8)
			{
				battle = true;
				E.spawn_boss(b, KAMETKHAN);
				s.stop_moving();
			}

			if ((s.get_y() < 0 || s.get_y() > 0) && b.size() == 0)
			{
				s.scroll_down();
				
			}

			if (battle && b.size() == 0)
			{
				//delete b;
				battle = false;
				s.scroll_down();
				lvl = 0;
				stat.setlvl(lvl, status);
				goto CHANGESTAGE;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}
	}
	al_stop_sample_instance(Boss);
	while (s.get_stage() == SATURN)
	{
		s.set_y(-800);
		update = true;
		battle = false;

LEVELUP4:

		lvl++;
		stat.setlvl(lvl, status);


		while (stat.getlvl() == 1)
		{
			if (s.get_y() == -800 && !battle && lvl == 1)
			{
				battle = true;
				s.stop_moving();
				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, SATUSPHERE);
			}

			if (s.get_y() < -800 || s.get_y() > -800)
			{
				s.scroll_down();
			}

			if (E.get_num_of_enemy(foes) == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP4;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		while (stat.getlvl() == 2)
		{
			if (s.get_y() == -400 && !battle && lvl == 2)
			{
				battle = true;
				s.stop_moving();
				E.spawn_enemy(foes, enemy_health, rand() % 4, 10, SATUSPHERE);
			}

			if (s.get_y() < -400 || s.get_y() > -400)
			{
				s.scroll_down();
			}

			if (foes.size() == 0 && battle)
			{
				battle = false;
				s.scroll_down();
				goto LEVELUP4;
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		while (stat.getlvl() == 3)
		{
			if (s.get_y() == 0 && !battle && lvl == 3)
			{
				al_stop_sample_instance(Saturn);
				battle = true;
				s.stop_moving();
			
				E.spawn_boss(b, XORGANA);
			}

			if ((s.get_y() < 0 || s.get_y() > 0) && b.size() == 0)
			{
				s.scroll_down();
			}

			if (b.size() == 0 && battle)
			{
				battle = false;
				destroy_stuff();
				exit(EXIT_SUCCESS);
				
			}

			Event_listenter(ev, q);

			update_loop(ev, q);
		}

		
	}
}

void game_loop::Event_listenter(ALLEGRO_EVENT &ev, ALLEGRO_EVENT_QUEUE *q)
{
	al_wait_for_event(q, &ev);

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				destroy_stuff();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_ENTER:
				pauseCounter = (pauseCounter + 1) % 2;
				break;
			}
	}


	if (ev.type == ALLEGRO_EVENT_KEY_DOWN && pauseCounter == 0)
	{

		for (int j = 0; j < spaceship.size(); j++)
		{
			switch (ev.keyboard.keycode)
			{
		

			case ALLEGRO_KEY_A:
				weaponsel++;
				weaponsel = weaponsel % num_of_weapon;
				if (weaponsel > num_of_weapon + 1)
				{
					weaponsel = 1;
				}
				//std::cout << weaponsel << std::endl;
				break;

			case ALLEGRO_KEY_S:
				weaponsel--;
				weaponsel = weaponsel % num_of_weapon;
				if (weaponsel < 0)
				{
					weaponsel = num_of_weapon - 1;
				}
				//std::cout << weaponsel << std::endl;
				break;

			case ALLEGRO_KEY_Z:
				shipWeapon.load_ammo(w, LAZER, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 3);
				al_set_sample_instance_position(lsr, 0);
				al_play_sample_instance(lsr);
				al_set_sample_instance_playmode(lsr, ALLEGRO_PLAYMODE_ONCE);
				break;

			case ALLEGRO_KEY_X:
				switch (weaponsel % num_of_weapon)
				{

				case ICET:
					if (unlockweapon[ICET] && ammo[ICET] > 0)
					{
						al_set_sample_instance_position(ice, 0);
						al_play_sample_instance(ice);
						al_set_sample_instance_playmode(ice, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, ICET, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[ICET]--;
					}

					break;

				case INFERRED:
					if (unlockweapon[INFERRED] && ammo[INFERRED] > 0)
					{
						al_set_sample_instance_position(fire, 0);
						al_play_sample_instance(fire);
						al_set_sample_instance_playmode(fire, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, INFERRED, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[INFERRED]--;
					}
					break;

				case ZIGGONET:
					if (unlockweapon[ZIGGONET] && ammo[ZIGGONET] > 0)
					{
						al_set_sample_instance_position(lit, 0);
						al_play_sample_instance(lit);
						al_set_sample_instance_playmode(lit, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, ZIGGONET, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[ZIGGONET]--;
					}
					break;

				case HAYCH:
					if (unlockweapon[HAYCH] && ammo[HAYCH] > 0)
					{
						al_set_sample_instance_position(haa, 0);
						al_play_sample_instance(haa);
						al_set_sample_instance_playmode(haa, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, HAYCH, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[HAYCH]--;
					}
					break;

				case HAYCHBA:
					if (unlockweapon[HAYCHBA] && ammo[HAYCHBA] > 0)
					{
						al_set_sample_instance_position(haa, 0);
						al_play_sample_instance(haa);
						al_set_sample_instance_playmode(haa, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, HAYCH, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[HAYCHBA]--;
					}
					break;

				case SONICWAVE:
					if (unlockweapon[SONICWAVE] && ammo[SONICWAVE] > 0)
					{
						al_set_sample_instance_position(wavey, 0);
						al_play_sample_instance(wavey);
						al_set_sample_instance_playmode(wavey, ALLEGRO_PLAYMODE_ONCE);
						shipWeapon.load_ammo(w, SONICWAVE, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
						ammo[SONICWAVE]--;
					}
					break;
				}

				break;
			}
		}
	}
	
	

	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->control(ev);
	}
}

void game_loop::update_loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q)
{

	if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 0)
	{

		for (int i = 0; i < 6; i++)
		{
			if (ammo[i] < 0)
			{
				ammo[i] = 0;
			}
		}
		
		if (stat.gethealth() <= 0)
		{
			if (spaceship.size() > 0)
			{
				al_stop_samples();
				spaceship.erase(spaceship.begin());
				al_set_sample_instance_position(game_over, 0);
				al_set_sample_instance_playmode(game_over, ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(game_over);
			}
		}

		for (int j = 0; j < spaceship.size(); j++)
		{
			spaceship[j]->update();
		}
		
		if (stagenumber == EARTH)
		{
			if (!battle)
			{
				if (spaceship.size() > 0)
				{

					if ((s.get_y() < -2400 || s.get_y() > -2400) && stat.getlvl() == 1)
					{
						if (s.get_y() == -2800)
						{
							E2.spawn_enemy(foes_while_scroll, enemy_health, rand()%4, 5, 5, SPACESHIP);
						}

						if (s.get_y() == -2600)
						{
							E2.spawn_enemy(foes_while_scroll, enemy_health, rand() % 4, 5, 5, KAMEKOSET);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth, backgroundvol);
						al_set_sample_instance_speed(Earth, 1);
						al_play_sample_instance(Earth);
					}

					else if ((s.get_y() < -1600 || s.get_y() > -1600) && stat.getlvl() == 2)
					{
						if (s.get_y() == -2300)
						{
							E2.spawn_enemy(foes_while_scroll, enemy_health, rand() % 4, 5, 5, KAMEKOSET);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth, backgroundvol);
						al_set_sample_instance_speed(Earth, 1);
						al_play_sample_instance(Earth);
					}

					else if ((s.get_y() < -800 || s.get_y() > -800) && stat.getlvl() == 3)
					{
						if (s.get_y() == -1400)
						{
							E2.spawn_enemy(foes_while_scroll, enemy_health, rand() % 4, 5, 5, EPOLICE);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth_Factory, backgroundvol);
						al_set_sample_instance_speed(Earth_Factory, 1);
						al_play_sample_instance(Earth_Factory);
					}

					else if ((s.get_y() < 0 || s.get_y() > 0) && stat.getlvl() == 4)
					{
						if (s.get_y() == -600)
						{
							E2.spawn_enemy(foes_while_scroll, enemy_health, rand() % 4, 5, 5, EPOLICE);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth_Factory, backgroundvol);
						al_set_sample_instance_speed(Earth_Factory, 1);
						al_play_sample_instance(Earth_Factory);
					}
				}
			}
			
		}

		else if (stagenumber == MARS)
		{
			if (!battle)
			{
				if (spaceship.size() > 0)
				{

					if ((s.get_y() < -2400 || s.get_y() > -2400) && stat.getlvl() == 1)
					{
						s.scroll_down();
					}

					else if ((s.get_y() < -1600 || s.get_y() > -1600) && stat.getlvl() == 2)
					{
						s.scroll_down();
					}

					else if ((s.get_y() < -800 || s.get_y() > -800) && stat.getlvl() == 3)
					{
						s.scroll_down();
					}

					else if ((s.get_y() < 0 || s.get_y() > 0) && stat.getlvl() == 4)
					{
						s.scroll_down();
					}
				}
			}

		}

		if (s.get_y() == -2400 && !battle && lvl == 1 )
		{
			battle = true;
			s.stop_moving();
			
			if (stagenumber == EARTH)
			{
				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, EPOLICE);
			}

			else if (stagenumber == MARS)
			{
				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, BLOBBY);
			}

		}

		else if (s.get_y() == -1600 && !battle && lvl == 2)
		{
			battle = true;
			s.stop_moving();

			if (stagenumber == EARTH)
			{
				E.spawn_minboss(mb, 0);
			}

			else if (stagenumber == MARS)
			{
				E.spawn_minboss(mb, 1);
			}
		}

		else if (s.get_y() == -800 && !battle && lvl == 3)
		{
			battle = true;
			s.stop_moving();

			if (stagenumber == EARTH)
			{
				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, XYBTOFY);
			}

			else if (stagenumber == MARS)
			{
				E.spawn_enemy(foes, enemy_health, rand() % 4, 5, SPYDER);
			}
		}

		else if (s.get_y() == 0 && !battle && lvl == 4)
		{
			
			battle = true;
			s.stop_moving();

			if (stagenumber == EARTH)
			{
				E.spawn_boss(b, SPARTAK);
			}

			else if (stagenumber == MARS)
			{
				E.spawn_boss(b, MARTIANB);
			}
		}

		col.win_collsion(spaceship);
		col.Enemy_boundary_collision(foes, REBOUND);
		col2.Enemy_boundary_collision(foes_while_scroll, REBOUND);

		col.Boss_boundary_collision(E, b);

		col.boss_gets_damaged(E, shipWeapon, b, ball, w, bosshit, reflect, bossdefeated);
		col.miniboss_gets_damaged(E, shipWeapon, mb, w, bossdefeated);

		col.enemy_gets_damaged(E, shipWeapon, T, am, t, foes, w, stat, destroy, status, sc);
		col2.enemy_gets_damaged(E2, shipWeapon, T, am, t, foes_while_scroll, w, stat, destroy, status, sc);

		E.update(foes, b, mb, ball, ds, EB, ST, LB, K, hw, st, sl, mball, v, ani);
		E2.update(foes_while_scroll);


		col.enemy_dies(T, am, t, foes, destroy);
		col2.enemy_dies(T, am, t, foes_while_scroll, destroy);

	
		col.player_gets_tool(spaceship, E, foes, t, am, stat, pickup, status, health, ammo);
		col2.player_gets_tool(spaceship, E2, foes_while_scroll, t, am, stat, pickup, status, health, ammo);


		col.player_gets_damaged(E, mb, b, foes, spaceship, stat, hit, status, ev, health);
		col.player_gets_damaged(E, ball, mball, v, spaceship, stat, hit, status, ev, health);

		col2.player_gets_damaged(E2, mb, b, foes_while_scroll, spaceship, stat, hit, status, ev, health);


		col.Ball_gets_redirected(E, shipWeapon, ball, w, ballreflect, bossdefeated);
		col.Ball_gets_destroyed(E, shipWeapon, T, mball, w, am, reflect, bossdefeated);
		col.Ball_gets_destroyed(E, shipWeapon, v, w, reflect, bossdefeated);
		
		shipWeapon.update(w);
		shipWeapon.destroy_ammo(w);
		
		draw = true;
		render();

	}

	else if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 1)
	{

		al_stop_sample_instance(Earth);
		al_stop_sample_instance(Earth_Factory);
		al_stop_sample_instance(Mars);
		al_stop_sample_instance(Mars_Nest);
		al_stop_sample_instance(Astroid);
		al_stop_sample_instance(Boss);
		al_stop_sample_instance(Saturn);
		al_stop_sample_instance(Final_Boss);

		draw = true;
		render();
	}
}

void game_loop::render()
{
	if (draw && pauseCounter == 0)
	{
		if (b.size() == 0 && spaceship.size() > 0)
		{
			switch (s.get_stage())
			{
			case EARTH:
				s.earth();
				if (lvl == 1 || lvl == 2)
				{
					al_set_sample_instance_gain(Earth, backgroundvol);
					al_set_sample_instance_speed(Earth, 1);
					al_play_sample_instance(Earth);
				}

				else if (lvl == 3 || lvl == 4)
				{
					al_stop_sample_instance(Earth);
					al_set_sample_instance_gain(Earth_Factory, backgroundvol);
					al_set_sample_instance_speed(Earth_Factory, 1);
					al_play_sample_instance(Earth_Factory);
				}
				break;

			case MARS:
				s.mars();
				if (lvl == 1 || lvl == 2)
				{
					al_stop_sample_instance(Earth_Factory);

					al_set_sample_instance_gain(Mars, backgroundvol);
					al_set_sample_instance_speed(Mars, 1);
					al_play_sample_instance(Mars);
				}

				else if (lvl == 3 || lvl == 4)
				{
					al_set_sample_instance_gain(Mars_Nest, backgroundvol);
					al_set_sample_instance_speed(Mars_Nest, 1);
					al_play_sample_instance(Mars_Nest);
				}
				break;

			case AST:
				al_stop_sample_instance(Boss);
				al_stop_sample_instance(Mars_Nest);
				al_set_sample_instance_gain(Astroid, backgroundvol);
				al_set_sample_instance_speed(Astroid, 1);
				al_play_sample_instance(Astroid);
				s.astroid_belt();
				break;

			case SATURN:
				al_set_sample_instance_gain(Saturn, backgroundvol);
				al_set_sample_instance_speed(Saturn, 1);
				al_play_sample_instance(Saturn);
				s.saturn();
				break;
			}
		}
		
		else if (b.size() > 0 && spaceship.size() > 0)
		{

			switch (s.get_stage())
			{
			case EARTH:
				s.earth();
				break;

			case MARS:
				s.mars();
				break;

			case AST:
				s.astroid_belt();
				break;

			case SATURN:
				s.saturn();
				break;
			}

			if (s.get_stage() == SATURN)
			{
				al_stop_sample_instance(Saturn);
				al_set_sample_instance_gain(Final_Boss, backgroundvol);
				al_set_sample_instance_speed(Final_Boss, 1);
				al_play_sample_instance(Final_Boss);
			}

			else
			{
				al_stop_sample_instance(Mars_Nest);
				al_stop_sample_instance(Mars);
				al_stop_sample_instance(Earth);
				al_stop_sample_instance(Earth_Factory);
				al_stop_sample_instance(Astroid);
				al_set_sample_instance_gain(Boss, backgroundvol);
				al_set_sample_instance_speed(Boss, 1);
				al_play_sample_instance(Boss);
			}
		}
	
		E.renderenemy(foes);
		E.renderenemy(foes_while_scroll);
		E.renderboss(b, ball, ds, EB, ST, LB, K, hw, st, sl, mball, v, ani, frame);
		E.renderminiboss(mb, ani);

		stat.Status_box(0, winy - 100, winx, winy);
		stat.sethealth(health, status);	
		stat.set_health_bar(211, 440, 311, 455);
		stat.setlvl(lvl, status);
		stat.setscore(sc, status);
		

		if (spaceship.size() <= 0)
		{
			stat.setnotification("GAME OVER", status, 200, 400, textframe);
		}

		

		switch (s.get_stage())
		{
		case EARTH:
			s.display_stage("EARTH", status);
			break;
		case MARS:
			s.display_stage("MARS", status);
			break;
		case AST:
			s.display_stage("ASTEROID BELT", status);
			break;
		case SATURN:
			s.display_stage("SATURN", status);
			break;
		}

		for (int j = 0; j < spaceship.size(); j++)
		{
			spaceship[j]->render();
		}
		

		for (int k = 0; k < w.size(); k++)
		{
			shipWeapon.renderweapon(w, w[k]->getweaponID(), stat, ammo[w[k]->getweaponID()]);

		}

		shipWeapon.renderweaponinbox(LAZER, stat, NULL);
		
		switch (weaponsel)
		{
		case ICET:
			shipWeapon.renderweaponinbox(ICET, stat, ammo[ICET]);
			break;

		case INFERRED:
			shipWeapon.renderweaponinbox(INFERRED, stat, ammo[INFERRED]);
			break;

		case ZIGGONET:
			shipWeapon.renderweaponinbox(ZIGGONET, stat, ammo[ZIGGONET]);
			break;

		case HAYCH:
			shipWeapon.renderweaponinbox(HAYCH, stat, ammo[HAYCH]);
			break;

		case HAYCHBA:
			shipWeapon.renderweaponinbox(HAYCHBA, stat, ammo[HAYCHBA]);
			break;

		case SONICWAVE:
			shipWeapon.renderweaponinbox(SONICWAVE, stat, ammo[SONICWAVE]);
			break;

		}
		
		

		for (int i = 0; i < foes.size(); i++)
		{
			if (foes[i]->get_duration() > 0)
			{
				switch (foes[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes[i]->get_name_ID()), E.get_h(foes[i]->get_name_ID()), foes[i]->get_x(), foes[i]->get_y(), E.get_w(foes[i]->get_name_ID()), E.get_h(foes[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes[i]->get_x(), foes[i]->get_y(), foes[i]->get_duration(), 15, 0, 7);
					break;
				}
			}
		}
		
		for (int i = 0; i < foes_while_scroll.size(); i++)
		{
			if (foes_while_scroll[i]->get_duration() > 0)
			{
				switch (foes_while_scroll[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_while_scroll[i]->get_name_ID()), E.get_h(foes_while_scroll[i]->get_name_ID()), foes_while_scroll[i]->get_x(), foes_while_scroll[i]->get_y(), E.get_w(foes_while_scroll[i]->get_name_ID()), E.get_h(foes_while_scroll[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_while_scroll[i]->get_x(), foes_while_scroll[i]->get_y(), foes_while_scroll[i]->get_duration(), 15, 0, 7);
					break;
				}
			}
		}

		
		for (int i = 0; i < am.size(); i++)
		{
			T.draw(am[i]->get_ammo_ID(), unlockweapon, am[i]->get_x(), am[i]->get_y());
		}
		

		for (int i = 0; i < t.size(); i++)
		{
			T.draw(t[i]->get_tool_ID(), t[i]->get_x(), t[i]->get_y());
		}
		


		if (col.get_num_of_kills() == 2 )
		{
			if (textframe < 200)
			{
				textframe++;
				stat.setnotification("YOU GOT NEW WEAPON: ICET", status, 160, 400, textframe);
				unlockweapon[ICET] = true;
				num_of_weapon = 1;
			}
		}

		if (col.get_num_of_kills() == 3)
		{
			if (textframe > 0)
			{
				textframe--;
				stat.setnotification("YOU GOT NEW WEAPON: INFERRED", status, 160, 400, textframe);
				unlockweapon[INFERRED] = true;
				num_of_weapon = 2;
			}
		}

		if (col.get_num_of_kills() == 4)
		{
			if (textframe < 200)
			{
				textframe++;
				stat.setnotification("YOU GOT NEW WEAPON: ZIGGONET", status, 160, 400, textframe);
				unlockweapon[ZIGGONET] = true;
				num_of_weapon = 3;
			}
		}

		if (col.get_num_of_kills() == 5)
		{
			if (textframe > 0)
			{
				textframe--;
				stat.setnotification("YOU GOT NEW WEAPON: HAYCH", status, 160, 400, textframe);
				unlockweapon[HAYCH] = true;
				num_of_weapon = 4;
			}
		}

		if (col.get_num_of_kills() == 6)
		{
			if (textframe < 100)
			{
				textframe++;
				stat.setnotification("YOU GOT NEW WEAPON: HAYCHBA", status, 160, 400, textframe);
				unlockweapon[HAYCHBA] = true;
				num_of_weapon = 5;
			}
		}

		if (col.get_num_of_kills() == 7)
		{
			if (textframe > 0)
			{
				textframe--;
				stat.setnotification("YOU GOT NEW WEAPON: SONIC WAVE", status, 160, 400, textframe);
				unlockweapon[SONICWAVE] = true;
				num_of_weapon = 6;
			}
		}
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		draw = false;
	}
	
	if (draw && pauseCounter == 1)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		stat.setnotification("PAUSE", status, 235, 205, al_map_rgb(0,255,0));
		stat.setnotification("[PRESS (ESC) IF YOU WANT TO QUIT]", status, 140, 225, al_map_rgb(255, 255, 255));
		stat.setnotification("[PRESS (ENTER) IF YOU WANT TO CONTINUE]", status, 125, 245, al_map_rgb(255, 255, 255));
		stat.setnotification("[PRESS (DIR KEY) TO MOVE THE PLAYER]", status, 130, 280, al_map_rgb(0, 200, 255));
		stat.setnotification("[PRESS (Z) TO SHOOT LAZERS]", status, 160, 300, al_map_rgb(0, 200, 255));
		stat.setnotification("[PRESS (X) TO SHOOT SPECIAL WEAPONS]", status, 125, 320, al_map_rgb(0, 200, 255));

		al_flip_display();
	}
}

void game_loop::destroy_stuff()
{
	al_destroy_bitmap(frozen);

	al_destroy_sample(earth);
	al_destroy_sample(earth_factory);
	al_destroy_sample(boss);
	al_destroy_sample(mars);
	al_destroy_sample(mars_nest);
	al_destroy_sample(astroid);
	al_destroy_sample(saturn);
	al_destroy_sample(final_boss);

	al_destroy_sample(ls);

	al_destroy_sample(health_pickup);
	al_destroy_sample(ammo_pickup);
	al_destroy_sample(destroy_all);

	al_destroy_sample(Destroy);

	al_destroy_sample(Hit);
	al_destroy_sample(Reflect);
	al_destroy_sample(Ballreflect);
	al_destroy_sample(Bosshit);

	al_destroy_sample(Game_over);

	al_destroy_sample_instance(Earth);
	al_destroy_sample_instance(Earth_Factory);
	al_destroy_sample_instance(Mars);
	al_destroy_sample_instance(Mars_Nest);
	al_destroy_sample_instance(Astroid);
	al_destroy_sample_instance(Boss);
	al_destroy_sample_instance(Saturn);
	al_destroy_sample_instance(Final_Boss);

	al_destroy_sample_instance(lsr);
	al_destroy_sample_instance(ice);
	al_destroy_sample_instance(fire);
	al_destroy_sample_instance(lit);
	al_destroy_sample_instance(haa);
	al_destroy_sample_instance(wavey);
	
	al_destroy_sample_instance(pickup[0]);
	al_destroy_sample_instance(pickup[1]);
	al_destroy_sample_instance(pickup[2]);

	al_destroy_sample_instance(destroy);

	al_destroy_sample_instance(hit);
	al_destroy_sample_instance(reflect);
	al_destroy_sample_instance(ballreflect);
	al_destroy_sample_instance(bosshit);

	al_destroy_sample_instance(game_over);

	s.destroy_stages();
	E.destroy_enemy_img();
	E2.destroy_enemy_img();
	T.destroy();
	
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->destroy();
	}

	shipWeapon.destroy_weapon_img();
	al_destroy_font(status);

}

