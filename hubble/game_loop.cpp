#include "game_loop.h"


game_loop::game_loop()
{
	key = 0;
	health = 100;
	lvl = 1;
	sc = 0;
	pauseCounter = 0;
	num_of_enemies = 0;
	stagenumber = EARTH;
	weaponsel = 0;
	frame = 0;
	textframe = 0;
	num_of_weapon = 0;
	backgroundvol = 1.5;
	options = -1;
	scorecounter = 500;
	//s.set_y(0);
	increment = 0;
	num_of_kills = 0;
	//disfig_index = 0;
	miniboss_battle = false;
	advance = false;
	

	unlockweapon[ICET] = false;
	unlockweapon[INFERRED] = false;
	unlockweapon[ZIGGONET] = false;
	unlockweapon[HAYCH] = false;
	unlockweapon[HAYCHBA] = false;
	unlockweapon[SONICWAVE] = false;

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

	enemy_health[BLOBBY] = 8; // DEFAULT:8
	enemy_health[ASTERIX] = 10; // DEFAULT:10
	enemy_health[EPOLICE] = 3; // DEFAULT:3
	enemy_health[JUPIBALL] = 8; // DEFAULT:8
	enemy_health[KAMEKOSET] = 1; // DEFAULT:1
	enemy_health[MPOLICE] = 6; // DEFAULT:6
	enemy_health[SATUSPHERE] = 15; // DEFAULT:15
	enemy_health[SPACESHIP] = 2; // DEFAULT:2
	enemy_health[SPYDER] = 3; // DEFAULT:3
	enemy_health[VOLCANON] = 5; // DEFAULT:5
	enemy_health[WYRM] = 12; // DEFAULT:12
	enemy_health[XYBTOFY] = 2; // DEFAULT:2

	//spaceship = player();

	draw = false;
	battle = false;
	bossdefeated = false;
	gameover = false;
	startanimating = false;
	minibossdefeated = false;
	mouse = false;
	disfig = false;

	credit.set_frame(0);
	player_damaged.set_frame(0);
	enemy_damaged.set_frame(0);
	adestroy.set_frame(0);

	status = NULL;

}

game_loop::~game_loop()
{

}

void game_loop::replay()
{

	al_stop_sample_instance(Earth);
	al_stop_sample_instance(Earth_Factory);
	al_stop_sample_instance(Mars);
	al_stop_sample_instance(Mars_Nest);
	al_stop_sample_instance(Astroid);
	al_stop_sample_instance(Boss);
	al_stop_sample_instance(Saturn);
	al_stop_sample_instance(Final_Boss);

	foes.clear();
	b.clear();
	foes_scroll1.clear();
	foes_scroll2.clear();
	foes_scroll3.clear();
	foes_scroll4.clear();
	foes_scroll5.clear();
	mb.clear();
	spaceship.push_back(new player());
	t.clear();
	t2.clear();
	t3.clear();
	t4.clear();
	t5.clear();
	t6.clear();
	am.clear();
	am2.clear();
	am3.clear();
	am4.clear();
	am5.clear();
	am6.clear();
	elazer.clear();
	ball.clear();
	mball.clear();
	v.clear();
	ds.clear();
	EB.clear();
	ST.clear();
	LB.clear();
	K.clear();
	hw.clear();
	st.clear();
	w.clear();
	bw.clear();
	turrets.clear();
	

	for (int i = 0; i < spaceship.size(); i++)
	{
		spaceship[i]->load();
		spaceship[i]->set_coords(winx / 2, winy - 150);

	}
	

	key = 0;
	health = 100;
	lvl = 1;
	sc = 0;
	pauseCounter = 0;
	num_of_enemies = 0;
	

	ammo[ICET] = 10;
	ammo[INFERRED] = 8;
	ammo[ZIGGONET] = 10;
	ammo[HAYCH] = 5;
	ammo[HAYCHBA] = 3;
	ammo[SONICWAVE] = 5;

	stat.sethealth(health, status);
	stat.setlvl(lvl, status);
	s.set_stage(stagenumber);
	s.set_y(s.get_h());

	draw = false;
	battle = false;
	bossdefeated = false;
	gameover = false;
	startanimating = false;

}

void game_loop::init()
{
	key = 0;
	health = 100;
	lvl = 1;
	sc = 0;
	pauseCounter = 0;
	num_of_enemies = 0;
	stagenumber = EARTH;
	weaponsel = 0;
	frame = 0;
	textframe = 0;
	num_of_weapon = 0;
	backgroundvol = 1.5;
	options = -1;
	scorecounter = 500;
	//s.set_y(0);
	increment = 0;
	num_of_kills = 0;
	//disfig_index = 0;
	miniboss_battle = false;
	advance = false;


	unlockweapon[ICET] = false;
	unlockweapon[INFERRED] = false;
	unlockweapon[ZIGGONET] = false;
	unlockweapon[HAYCH] = false;
	unlockweapon[HAYCHBA] = false;
	unlockweapon[SONICWAVE] = false;

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

	enemy_health[BLOBBY] = 8; // DEFAULT:8
	enemy_health[ASTERIX] = 10; // DEFAULT:10
	enemy_health[EPOLICE] = 3; // DEFAULT:3
	enemy_health[JUPIBALL] = 8; // DEFAULT:8
	enemy_health[KAMEKOSET] = 1; // DEFAULT:1
	enemy_health[MPOLICE] = 6; // DEFAULT:6
	enemy_health[SATUSPHERE] = 15; // DEFAULT:15
	enemy_health[SPACESHIP] = 2; // DEFAULT:2
	enemy_health[SPYDER] = 3; // DEFAULT:3
	enemy_health[VOLCANON] = 5; // DEFAULT:5
	enemy_health[WYRM] = 12; // DEFAULT:12
	enemy_health[XYBTOFY] = 2; // DEFAULT:2

	//spaceship = player();

	draw = false;
	battle = false;
	bossdefeated = false;
	gameover = false;
	startanimating = false;
	minibossdefeated = false;
	mouse = false;
	disfig = false;

	credit.set_frame(0);
	player_damaged.set_frame(0);
	enemy_damaged.set_frame(0);
	adestroy.set_frame(0);

	status = NULL;
	s.set_stage(stagenumber);


}

void game_loop::load_stuff()
{
	s.load_stages();
	
	T.load();
	T2.load();
	T3.load();
	T4.load();
	T5.load();
	T6.load();


	spaceship.push_back(new player());
	status = al_load_ttf_font("bahnschrift.ttf", 15, NULL);
	pause = al_load_ttf_font("bahnschrift.ttf", 30, NULL);
	pause_options = al_load_ttf_font("bahnschrift.ttf", 20, NULL);


	frozen = al_load_bitmap("Frozen.png");

	stat.sethealth(health, status);
	al_reserve_samples(21);
	
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
	eh = al_load_sample("Enemy_hit.ogg");
	scm = al_load_sample("Stage_completed.ogg");

	health_pickup = al_load_sample("Health_pickup.ogg");
	ammo_pickup = al_load_sample("ammo_pickup.ogg");
	destroy_all = al_load_sample("destroy_all.ogg");

	Destroy = al_load_sample("destroy.ogg");

	Hit = al_load_sample("Player_hit.ogg");
	PO = al_load_sample("Pause_transistion_on.ogg");
	POF = al_load_sample("Pause_transistion_off.ogg");

	Game_over = al_load_sample("Game_over.ogg");
	Bossdes = al_load_sample("boss_destroyed.ogg");

	Reflect = al_load_sample("214048__taira-komori__reflection.ogg");
	Ballreflect = al_load_sample("49673__ejfortin__energy-short-sword-2.ogg");
	Bosshit = al_load_sample("404786__owlstorm__retro-video-game-sfx-reflect.ogg");

	cre = al_load_sample("credit.ogg");
	cntdwn = al_load_sample("countdown.ogg");
	
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
	Boss_destroyed = al_create_sample_instance(Bossdes);

	pickup[0] = al_create_sample_instance(health_pickup);
	pickup[1] = al_create_sample_instance(ammo_pickup);
	pickup[2] = al_create_sample_instance(destroy_all);

	Pause_On = al_create_sample_instance(PO);
	Pause_Off = al_create_sample_instance(POF);

	destroy = al_create_sample_instance(Destroy);

	hit = al_create_sample_instance(Hit);

	game_over = al_create_sample_instance(Game_over);

	reflect = al_create_sample_instance(Reflect);
	ballreflect = al_create_sample_instance(Ballreflect);
	bosshit = al_create_sample_instance(Bosshit);
	enemy_hit = al_create_sample_instance(eh);
	Stage_Completed = al_create_sample_instance(scm);
	Credit = al_create_sample_instance(cre);
	Countdown = al_create_sample_instance(cntdwn);

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
	al_attach_sample_instance_to_mixer(Pause_On, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Pause_Off, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(enemy_hit, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Stage_Completed, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Boss_destroyed, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Credit, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(Countdown, al_get_default_mixer());

	al_set_sample_instance_playmode(Earth, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Earth_Factory, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Mars, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Mars_Nest, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Astroid, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Saturn, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Boss, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Final_Boss, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(Stage_Completed, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(Credit, ALLEGRO_PLAYMODE_ONCE);


	for (int i = 0; i < 3; i++)
	{
		al_set_sample_instance_gain(pickup[i], 2);
	}

	al_set_sample_instance_gain(destroy, 2);
	al_set_sample_instance_gain(hit, 2);
	al_set_sample_instance_gain(Pause_On, 2);
	al_set_sample_instance_gain(Pause_Off, 2);
	al_set_sample_instance_gain(Stage_Completed, 2);
	al_set_sample_instance_gain(Boss_destroyed, 2);
	al_set_sample_instance_gain(Credit, 2);
	al_set_sample_instance_gain(Countdown, 2);

	al_set_sample_instance_position(Stage_Completed, 1);
	al_set_sample_instance_position(Credit, 0);


	burned_red = al_load_bitmap("burned_red.png");
	burned_yellow = al_load_bitmap("burned_yellow.png");
	
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->load();
		spaceship[j]->set_coords(winx / 2, winy - 150);
		spaceship[j]->ship_hit(false);
	}

	s.set_stage(this->stagenumber);

	shipWeapon.load_weapon_img();
	
	al_set_sample_instance_gain(enemy_hit, 2);

	E.load_enemy_img();
	E2.load_enemy_img();
	E3.load_enemy_img();
	E4.load_enemy_img();
	E5.load_enemy_img();
	E6.load_enemy_img();
}

void game_loop::loop(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q, bool &loop)
{
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->set_movement(true);
	}

	s.set_y(s.get_h());

	while (!done)
	{
		if (E.get_num_of_enemy(foes) == 0 && battle)
		{
			battle = false;
			s.scroll_down();
			lvl++;
		}

		if (mb.size() == 0 && miniboss_battle)
		{
			minibossdefeated = true;
			
			al_stop_sample_instance(Earth);
			al_set_sample_instance_position(Earth, 0);

			forward(spaceship[0]);
		}

		if (spaceship.size() > 0)
		{
			if (spaceship[0]->get_y() < 0 && minibossdefeated)
			{
				advance = false;
				al_stop_sample_instance(Earth);
				al_set_sample_instance_position(Earth, 0);
				spaceship[0]->set_keys(UP, false);
				spaceship[0]->set_vel(5);
				spaceship[0]->set_coords(winx / 2, winy - 150);
				s.set_y(s.get_y() + 500);
				s.scroll_down();
				minibossdefeated = false;
				miniboss_battle = false;
				lvl++;
				stat.setlvl(lvl, status);
			}

		}

		if (bossdefeated && boss_battle && b.size() == 0)
		{
			al_stop_samples();

			if (s.get_y() == 0)
			{
				t.clear();
				am.clear();
				elazer.clear();
				ball.clear();
				mball.clear();
				v.clear();
				ds.clear();
				EB.clear();
				ST.clear();
				LB.clear();
				K.clear();
				hw.clear();
				st.clear();
				w.clear();

				if (stagenumber != SATURN)
				{
					pauseCounter = 4;
				}

				else
				{
					boss_battle = false;
					pauseCounter = 5;
					//std::cout << "Pause Counter: " << pauseCounter << std::endl;
				}
			}
			
			else
			{
				s.scroll_down();
				lvl++;
				boss_battle = false;
			}
		}

		Event_listenter(ev, q);
		update(ev, q);
	}

	al_stop_sample_instance(Earth);
	al_stop_sample_instance(Earth_Factory);
	al_stop_sample_instance(Mars);
	al_stop_sample_instance(Mars_Nest);
	al_stop_sample_instance(Astroid);
	al_stop_sample_instance(Boss);
	al_stop_sample_instance(Saturn);
	al_stop_sample_instance(Final_Boss);

}

void game_loop::stage_advance(player *&p)
{
	if (p->get_x() < winx / 2)
	{
		p->set_x(p->get_x() + p->get_vel());
	}

	if (p->get_x() > winx / 2)
	{
		p->set_x(p->get_x() - p->get_vel());
	}

	if (p->get_y() < winy -150)
	{
		p->set_y(p->get_y() + p->get_vel());
	}

	if (p->get_y() > winy - 150)
	{
		p->set_y(p->get_y() - p->get_vel());
	}
}

void game_loop::forward(player *&p)
{

	if (spaceship[0]->get_x() == winx / 2 && spaceship[0]->get_y() == winy - 150)
	{
		al_stop_sample_instance(Earth);
		advance = true;
		
	}

	else
	{
		al_stop_sample_instance(Earth);
		al_set_sample_instance_position(Earth, 0);
		stage_advance(p);
	}

	if (advance)
	{
		p->set_vel(10);
		p->set_y(p->get_y() - p->get_vel());
		p->set_keys(UP, true);
		p->set_keys(DOWN, false);
		p->set_keys(LEFT, false);
		p->set_keys(RIGHT, false);
		battle = false;
	}
}

void game_loop::Event_listenter(ALLEGRO_EVENT &ev, ALLEGRO_EVENT_QUEUE *q)
{
	al_wait_for_event(q, &ev);

	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		destroy_stuff();
		exit(EXIT_SUCCESS);
	}
		
	if (ev.type == ALLEGRO_EVENT_DISPLAY_SWITCH_OUT)
	{
		if (pauseCounter != 5)
		{
			pauseCounter = 1;
		}
	}

	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		mouse = false;
		if (pauseCounter == 1 && spaceship.size() > 0)
		{
			for (int j = 0; j < spaceship.size(); j++)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					destroy_stuff();
					exit(EXIT_SUCCESS);
					break;

				case ALLEGRO_KEY_P:
					pauseCounter = 0;
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					break;

				case ALLEGRO_KEY_R:

					if (spaceship.size() != 0)
					{
						spaceship[j]->destroy();
						spaceship.erase(spaceship.begin());
					}

					replay();
					
					break;

				case ALLEGRO_KEY_DOWN:
					options = (options + 1) % 5;
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					break;


				case ALLEGRO_KEY_UP:
					options = (options - 1) % 5;
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					if (options < 0)
					{
						options = 4;
					}
					break;

				case ALLEGRO_KEY_ENTER:
					switch (options)
					{
					case 0:
						pauseCounter = 0;
						al_set_sample_instance_position(Pause_On, 0);
						al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(Pause_On);
						break;

					case 1:
						if (spaceship.size() != 0)
						{
							spaceship.erase(spaceship.begin());
						}
						al_set_sample_instance_position(Pause_On, 0);
						al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(Pause_On);
						replay();
						
						break;

					case 2:
						pauseCounter = 3;
						al_set_sample_instance_position(Pause_On, 0);
						al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(Pause_On);
						break;

					case 3:
						done = true;
						break;

					case 4:
						destroy_stuff();
						exit(EXIT_SUCCESS);
						break;
					}
					break;

				}
			}
		}

		else if (pauseCounter == 4 && spaceship.size() > 0)
		{
			for (int j = 0; j < spaceship.size(); j++)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					destroy_stuff();
					exit(EXIT_SUCCESS);
					break;

				case ALLEGRO_KEY_ENTER:

					if (scorecounter <= 0)
					{
						lvl = 1;
						al_set_sample_instance_position(Stage_Completed, 0);
						al_set_sample_instance_position(Pause_On, 0);
						al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
						al_play_sample_instance(Pause_On);
						player_damaged.set_frame(0);
						spaceship[j]->ship_hit(false);
						spaceship[j]->set_coords(winx / 2, winy - 150);
						pauseCounter = 0;
						scorecounter = 500;
						increment = 1;
						health = 100;
						boss_battle = false;
						stagenumber++;
						stat.sethealth(health, status);
						stat.setlvl(lvl, status);
						s.set_stage(stagenumber);
						s.set_y(s.get_h());
						
					}
					break;
				}
			}
		}

		else if (spaceship.size() <= 0 && pauseCounter != 5)
		{
			switch (ev.keyboard.keycode)
			{

			case ALLEGRO_KEY_ESCAPE:
				destroy_stuff();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_R:
				replay();
				//stage(ev, q);
				break;

			case ALLEGRO_KEY_DOWN:
				options = (options + 1) % 2;
				break;
			case ALLEGRO_KEY_UP:
				options = abs((options - 1) % 2);
				break;

			case ALLEGRO_KEY_ENTER:
				switch (options)
				{
				case 0:
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					replay();
					//stage(ev, q, loop);
					break;

				case 1:
					destroy_stuff();
					exit(EXIT_SUCCESS);
				}
				break;
			}
		}

		else if (pauseCounter == 0 && spaceship.size() > 0)
		{
			for (int j = 0; j < spaceship.size(); j++)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_ESCAPE:
					destroy_stuff();
					exit(EXIT_SUCCESS);
					break;

				case ALLEGRO_KEY_P:
					pauseCounter = 1;
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					break;

				case ALLEGRO_KEY_S:
					weaponsel++;
					if (num_of_weapon > 0)
					{
						weaponsel = weaponsel % num_of_weapon;

					}					
					
					if (weaponsel > num_of_weapon + 1)
					{
						weaponsel = 1;
					}
					break;

				case ALLEGRO_KEY_A:
					weaponsel--;
					if (num_of_weapon > 0)
					{
						weaponsel = weaponsel % num_of_weapon;

					}
					
					if (weaponsel < 0)
					{
						weaponsel = num_of_weapon - 1;
					}
					break;

				case ALLEGRO_KEY_Z:
					if (spaceship[j]->get_ability_to_shoot())
					{
						shipWeapon.load_ammo(w, LAZER, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 3);
						al_set_sample_instance_position(lsr, 0);
						al_play_sample_instance(lsr);
						al_set_sample_instance_playmode(lsr, ALLEGRO_PLAYMODE_ONCE);

					}
					break;

				case ALLEGRO_KEY_X:
					if (spaceship[j]->get_ability_to_shoot())
					{
						switch (weaponsel)
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
								shipWeapon.load_ammo(w, HAYCHBA, spaceship[j]->get_x() + 20, spaceship[j]->get_y(), 5);
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
					}
					break;

				}
			}
		}

		else if (pauseCounter == 3 && spaceship.size() > 0)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				destroy_stuff();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_SPACE:
				pauseCounter = 1;
				al_set_sample_instance_position(Pause_On, 0);
				al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(Pause_On);
				break;
			}
		}

		else if (pauseCounter == 5)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				destroy_stuff();
				exit(EXIT_SUCCESS);
				break;

			case ALLEGRO_KEY_ENTER:
				if (credit.get_frame() >= 700)
				{
					destroy_stuff();
					exit(EXIT_SUCCESS);
				}
				break;


			}
		}
	}

	else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		mouse = true;

		

		if (spaceship.size() > 0)
		{
			if (pauseCounter == 1)
			{

				if (ev.mouse.x >= 190 && ev.mouse.x <= 190 + al_get_text_width(pause_options, "CONTINUE [P]") &&
					ev.mouse.y >= 230 && ev.mouse.y <= 230 + al_get_font_line_height(pause_options))
				{
					options = 0;
				}

				else if (ev.mouse.x >= 190 && ev.mouse.x <= 190 + al_get_text_width(pause_options, "REPLAY [R]") &&
					ev.mouse.y >= 260 && ev.mouse.y <= 260 + al_get_font_line_height(pause_options))
				{
					options = 1;
				}

				else if (ev.mouse.x >= 190 && ev.mouse.x <= 190 + al_get_text_width(pause_options, "HOW TO PLAY") &&
					ev.mouse.y >= 290 && ev.mouse.y <= 290 + al_get_font_line_height(pause_options))
				{
					options = 2;
				}

				else if (ev.mouse.x >= 160 && ev.mouse.x <= 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") &&
					ev.mouse.y >= 320 && ev.mouse.y <= 320 + al_get_font_line_height(pause_options))
				{
					options = 3;
				}

				else if (ev.mouse.x >= 190 && ev.mouse.x <= 190 + al_get_text_width(pause_options, "QUIT [ESC]") &&
					ev.mouse.y >= 350 && ev.mouse.y <= 350 + al_get_font_line_height(pause_options))
				{
					options = 4;
				}

				else
				{
					options = -1;
				}
			}

			else if (pauseCounter == 3)
			{

				if (ev.mouse.x >= 170 && ev.mouse.x <= 180 + al_get_text_width(status, "BACK TO MAIN MENU") &&
					ev.mouse.y >= 500 - 2 * al_get_font_line_height(status) && ev.mouse.y <= 500)
				{
					options = 0;
				}

				else
				{
					options = -1;
				}
			}

			else if (pauseCounter == 4)
			{

				if (ev.mouse.x >= 200 && ev.mouse.x <= 220 + al_get_text_width(pause_options, "CONTINUE") &&
					ev.mouse.y >= 500 - 2 * al_get_font_line_height(pause_options) && ev.mouse.y <= 500)
				{
					options = 0;
				}

				else
				{
					options = -1;
				}
			}

			
		}

		else if (pauseCounter == 5)
		{

			if (ev.mouse.x >= 200 && ev.mouse.x <= 220 + al_get_text_width(status, "(ENTER)") &&
				ev.mouse.y >= 250 && ev.mouse.y <= 270 + 2 * al_get_font_line_height(status))
			{
				options = 0;
			}

			else
			{
				options = -1;
			}
		}

		else if (spaceship.size() <= 0 && pauseCounter != 5)
		{
			if (ev.mouse.x >= 190 && ev.mouse.x <= 200 + al_get_text_width(status, "PLAY AGAIN") &&
				ev.mouse.y >= 230 && ev.mouse.y <= 230 + al_get_font_line_height(status))
			{
				options = 0;
			}

			else if (ev.mouse.x >= 190 && ev.mouse.x <= 200 + al_get_text_width(status, "PLAY AGAIN") &&
				ev.mouse.y >= 260 && ev.mouse.y <= 260 + al_get_font_line_height(status))
			{
				options = 1;
			}

			else
			{
				options = -1;
			}
		}

	}
	
	else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (ev.mouse.button == 1)
		{

			if (spaceship.size() > 0)
			{
				if (pauseCounter == 0)
				{
					pauseCounter = 1;
				}

				else if (pauseCounter == 1)
				{

					for (int j = 0; j < spaceship.size(); j++)
					{
						switch (options)
						{

						case 0:
							pauseCounter = 0;
							options = -1;
							al_set_sample_instance_position(Pause_On, 0);
							al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(Pause_On);
							break;

						case 1:
							if (spaceship.size() != 0)
							{
								spaceship.erase(spaceship.begin());
							}
							options = -1;
							al_set_sample_instance_position(Pause_On, 0);
							al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(Pause_On);
							replay();
							break;

						case 2:
							pauseCounter = 3;
							options = -1;
							al_set_sample_instance_position(Pause_On, 0);
							al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(Pause_On);
							break;

						case 3:
							done = true;
							break;

						case 4:
							al_set_sample_instance_position(Pause_On, 0);
							options = -1;
							al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(Pause_On);
							destroy_stuff();
							exit(EXIT_SUCCESS);
							break;

						}
					}

				}

				else if (pauseCounter == 3)
				{

					for (int j = 0; j < spaceship.size(); j++)
					{
						switch (options)
						{

						case 0:
							pauseCounter = 1;
							options = -1;
							al_set_sample_instance_position(Pause_On, 0);
							al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
							al_play_sample_instance(Pause_On);
							break;

						}
					}

				}

				else if (pauseCounter == 4)
				{

					for (int j = 0; j < spaceship.size(); j++)
					{
						switch (options)
						{

						case 0:

							if (scorecounter <= 0)
							{
								lvl = 1;
								al_set_sample_instance_position(Stage_Completed, 0);
								al_set_sample_instance_position(Pause_On, 0);
								al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
								al_play_sample_instance(Pause_On);
								player_damaged.set_frame(0);
								spaceship[j]->ship_hit(false);
								spaceship[j]->set_coords(winx / 2, winy - 150);
								pauseCounter = 0;
								scorecounter = 500;
								increment = 1;
								health = 100;
								boss_battle = false;
								stagenumber++;
								stat.sethealth(health, status);
								stat.setlvl(lvl, status);
								s.set_stage(stagenumber);
								s.set_y(s.get_h());
							}

							break;

						}
					}

				}	
			}

			else if (pauseCounter == 5)
			{
				switch (options)
				{

				case 0:
					destroy_stuff();
					exit(EXIT_SUCCESS);
					break;
				}
			}

			else if (spaceship.size() <= 0 && pauseCounter != 5)
			{
				switch (options)
				{

				case 0:
					if (spaceship.size() != 0)
					{
						spaceship.erase(spaceship.begin());
					}
					options = -1;
					al_set_sample_instance_position(Pause_On, 0);
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					replay();
					break;

				case 1:
					al_set_sample_instance_position(Pause_On, 0);
					options = -1;
					al_set_sample_instance_playmode(Pause_On, ALLEGRO_PLAYMODE_ONCE);
					al_play_sample_instance(Pause_On);
					destroy_stuff();
					exit(EXIT_SUCCESS);
					break;
				}
			}
		}

	}

	for (int j = 0; j < spaceship.size(); j++)
	{
		if (!minibossdefeated)
		{
			spaceship[j]->control(ev);
		}
	}

}

void game_loop::update(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *q)
{
	if (stat.gethealth() <= 0)
	{
		for (int i = 0; i < spaceship.size(); i++)
		{

			if (spaceship.size() > 0)
			{
				spaceship[i]->destroy();

				al_stop_samples();
				spaceship.erase(spaceship.begin());
				al_set_sample_instance_position(game_over, 0);
				al_set_sample_instance_playmode(game_over, ALLEGRO_PLAYMODE_ONCE);
				al_play_sample_instance(game_over);
				//std::cout << "Ship Size: " << spaceship.size() << std::endl;
			}
		}
	}
	
	if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 0 && spaceship.size() > 0)
	{
		for (int i = 0; i < 6; i++)
		{
			if (ammo[i] < 0)
			{
				ammo[i] = 0;
			}
		}

		for (int j = 0; j < spaceship.size(); j++)
		{
			spaceship[j]->update();
			spaceship[j]->countdown_duration();
			spaceship[j]->poisoned(stat, health, status);
		
			if (player_damaged.get_frame() >= 100)
			{
				player_damaged.set_frame(0);
				spaceship[j]->ship_hit(false);
			}

			else
			{
				player_damaged.increment_frame();
			}
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
							E2.spawn_enemy(foes_scroll1, enemy_health, DOWN, 2, 5, XYBTOFY);
							col2.check_position(E2, foes_scroll1);
						}

						if (s.get_y() == -2600)
						{
							E3.spawn_enemy(foes_scroll2, enemy_health, DOWN, 2, 5, KAMEKOSET);
							col3.check_position(E3, foes_scroll2);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth, backgroundvol);
						al_set_sample_instance_speed(Earth, 1);
						al_play_sample_instance(Earth);
					}

					else if ((s.get_y() < -1562 || s.get_y() > -1562) && stat.getlvl() == 2)
					{
						if (s.get_y() == -2300)
						{
							E3.spawn_enemy(foes_scroll3, enemy_health, DOWN, 2, 5, KAMEKOSET);
							col2.check_position(E4, foes_scroll3);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Earth, backgroundvol);
						al_set_sample_instance_speed(Earth, 1);
						al_play_sample_instance(Earth);
					}

					else if ((s.get_y() < -800 || s.get_y() > -800) && stat.getlvl() == 3)
					{
						if (s.get_y() == -1000)
						{
							E4.spawn_enemy(foes_scroll4, enemy_health, DOWN, 2, 5, EPOLICE);
							col2.check_position(E5, foes_scroll4);
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
							E5.spawn_enemy(foes_scroll5, enemy_health, DOWN, 2, 5, EPOLICE);
							col2.check_position(E6, foes_scroll5);
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
						if (s.get_y() == -2800)
						{
							E2.spawn_enemy(foes_scroll1, enemy_health, DOWN, 2, 5, BLOBBY);
							col2.check_position(E2, foes_scroll1);
						}

						if (s.get_y() == -2600)
						{
							E3.spawn_enemy(foes_scroll2, enemy_health, DOWN, 2, 5, MPOLICE);
							col3.check_position(E3, foes_scroll2);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Mars, backgroundvol);
						al_set_sample_instance_speed(Mars, 1);
						al_play_sample_instance(Mars);
					}

					else if ((s.get_y() < -1600 || s.get_y() > -1600) && stat.getlvl() == 2)
					{
						if (s.get_y() == -2300)
						{
							E3.spawn_enemy(foes_scroll3, enemy_health, DOWN, 2, 5, WYRM);
							col2.check_position(E4, foes_scroll3);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Mars, backgroundvol);
						al_set_sample_instance_speed(Mars, 1);
						al_play_sample_instance(Mars);
					}

					else if ((s.get_y() < -800 || s.get_y() > -800) && stat.getlvl() == 3)
					{
						if (s.get_y() == -1000)
						{
							E4.spawn_enemy(foes_scroll4, enemy_health, DOWN, 2, 10, WYRM);
							col2.check_position(E5, foes_scroll4);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Mars_Nest, backgroundvol);
						al_set_sample_instance_speed(Mars_Nest, 1);
						al_play_sample_instance(Mars_Nest);
					}

					else if ((s.get_y() < 0 || s.get_y() > 0) && stat.getlvl() == 4)
					{
						if (s.get_y() == -600)
						{
							E5.spawn_enemy(foes_scroll5, enemy_health, DOWN, 2, 5, MPOLICE);
							col2.check_position(E6, foes_scroll5);
						}

						s.scroll_down();
						al_set_sample_instance_gain(Mars_Nest, backgroundvol);
						al_set_sample_instance_speed(Mars_Nest, 1);
						al_play_sample_instance(Mars_Nest);
					}
				}
			}

		}

		else if (stagenumber == AST)
		{
			if (stat.getlvl() == 1)
			{
				if (s.get_y() == -2800 && !battle)
				{
					battle = true;
					s.stop_moving();

					E.spawn_enemy(foes, enemy_health, DOWN, 5, BLOBBY);
				}

				if (s.get_y() < -2800 || s.get_y() > -2800)
				{
					s.scroll_down();
				}

			}

			else if (stat.getlvl() == 2)
			{

				if (s.get_y() == -2400 && !boss_battle)
				{
					boss_battle = true;
					s.stop_moving();
					E.spawn_boss(b, SPARTAK);
				}

				if (s.get_y() < -2400 || s.get_y() > -2400)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 3)
			{
				if (s.get_y() == -2000 && !battle)
				{
					battle = true;
					s.stop_moving();

					E.spawn_enemy(foes, enemy_health, DOWN, 5, SPYDER);
				}

				if (s.get_y() < -2000 || s.get_y() > -2000)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 4)
			{
				if (s.get_y() == -1600 && !battle)
				{
					battle = true;
					E.spawn_enemy(foes, enemy_health, DOWN, 6, ASTERIX);
					s.stop_moving();
				}

				if (s.get_y() < -1600 || s.get_y() > -1600)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 5)
			{
				if (s.get_y() == -1200 && !battle)
				{
					battle = true;
					E.spawn_enemy(foes, enemy_health, DOWN, 4, JUPIBALL);
					s.stop_moving();
				}

				if (s.get_y() < -1200 || s.get_y() > -1200)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 6)
			{
				if (s.get_y() == -800 && !boss_battle)
				{
					boss_battle = true;
					E.spawn_boss(b, MARTIANB);
					s.stop_moving();
				}

				if (s.get_y() < -800 || s.get_y() > -800)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 7)
			{
				if (s.get_y() == -400 && !battle)
				{
					battle = true;
					E.spawn_enemy(foes, enemy_health, DOWN, 4, JUPIBALL);
					s.stop_moving();
				}

				if (s.get_y() < -400 || s.get_y() > -400)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 8)
			{

				if (s.get_y() == 0 && !boss_battle)
				{
					boss_battle = true;
					E.spawn_boss(b, KAMETKHAN);
					s.stop_moving();
				}

				if (s.get_y() < 0 || s.get_y() > 0)
				{
					s.scroll_down();
				}
			}
		}

		else if (stagenumber == SATURN)
		{
			if (stat.getlvl() == 1)
			{
				if (s.get_y() == -800 && !battle)
				{
					battle = true;
					s.stop_moving();
					E.spawn_enemy(foes, enemy_health, DOWN, 1, SATUSPHERE);// 5
				}

				if (s.get_y() < -800 || s.get_y() > -800)
				{
					s.scroll_down();
				}
			}

			else if (stat.getlvl() == 2)
			{
				if (s.get_y() == -400 && !battle)
				{
					battle = true;
					s.stop_moving();
					E.spawn_enemy(foes, enemy_health, DOWN, 1, SATUSPHERE);// 8
				}

				if (s.get_y() < -400 || s.get_y() > -400)
				{
					s.scroll_down();
				}

			
			}

			else if (stat.getlvl() == 3)
			{
				if (s.get_y() == 0 && !boss_battle)
				{
					al_stop_sample_instance(Saturn);
					boss_battle = true;
					s.stop_moving();

					E.spawn_boss(b, XORGANA);
				}

				if (s.get_y() < 0 || s.get_y() > 0)
				{
					s.scroll_down();
				}

			}
		}
		
		if (s.get_y() == -2400 && !battle && lvl == 1)
		{
			battle = true;
			s.stop_moving();

			if (stagenumber == EARTH)
			{
				E.spawn_enemy(foes, enemy_health, DOWN, 5, EPOLICE);
				col2.check_position(E, foes);
			}

			else if (stagenumber == MARS)
			{
			
				E.spawn_enemy(foes, enemy_health, 50, 110, 10, 0, VOLCANON);
				E.spawn_enemy(foes, enemy_health, 250, 150, 10, 0, VOLCANON);
				E.spawn_enemy(foes, enemy_health, 350, 50, 10, 0, VOLCANON);
				E.spawn_enemy(foes, enemy_health, 350, 250, 10, 0, VOLCANON);
				E.spawn_enemy(foes, enemy_health, 50, 300, 10, 0, VOLCANON);
				//E.spawn_enemy(foes, enemy_health, DOWN, 1, 5, BLOBBY);
				col2.check_position(E, foes);
			}

		}

		else if (s.get_y() == -1562 && !miniboss_battle && lvl == 2 && !minibossdefeated)
		{
			if (stagenumber == EARTH)
			{
				miniboss_battle = true;
				s.stop_moving();
				E.spawn_minboss(mb, turrets, s, 0);
			}
		}

		else if (s.get_y() == -1600 && !miniboss_battle && lvl == 2 && !minibossdefeated)
		{
			if (stagenumber == MARS)
			{
				miniboss_battle = true;
				s.stop_moving();
				E.spawn_minboss(mb, turrets, s, 1);
			}
		}
		
		else if (s.get_y() == -800 && !battle && lvl == 3)
		{
			battle = true;
			s.stop_moving();

			if (stagenumber == EARTH)
			{
				E.spawn_enemy(foes, enemy_health, DOWN, 5, SPACESHIP);
				col2.check_position(E, foes);
			}

			else if (stagenumber == MARS)
			{
				E.spawn_enemy(foes, enemy_health, DOWN, 5, SPYDER);
				col2.check_position(E, foes);
			}
		}

		else if (s.get_y() == 0 && !boss_battle && lvl == 4)
		{

			boss_battle = true;
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

		shipWeapon.update(w);
		shipWeapon.destroy_ammo(w);

		col.win_collsion(spaceship);
		col.Enemy_boundary_collision(E, foes, REBOUND);
		col2.Enemy_boundary_collision(E2, foes_scroll1, REBOUND);
		col3.Enemy_boundary_collision(E3, foes_scroll2, DESTROY);
		col4.Enemy_boundary_collision(E4, foes_scroll3, DESTROY);
		col5.Enemy_boundary_collision(E5, foes_scroll4, DESTROY);
		col6.Enemy_boundary_collision(E6, foes_scroll5, DESTROY);

		
		col.Boss_boundary_collision(E, b);

		col.boss_gets_damaged(E, shipWeapon, b, bw, w, bosshit, reflect, bossdefeated);
		col.miniboss_gets_damaged(E, s, shipWeapon, mb, turrets, w, bosshit, Boss_destroyed, bossdefeated);
		
		col.enemy_gets_damaged(E, shipWeapon, T, am, t, foes, w, stat, destroy, enemy_hit, status, enemy_damaged, sc);
		col2.enemy_gets_damaged(E2, shipWeapon, T2, am2, t2, foes_scroll1, w, stat, destroy, enemy_hit, status, enemy_while_scroll_damaged, sc);
		col3.enemy_gets_damaged(E3, shipWeapon, T3, am3, t3, foes_scroll2, w, stat, destroy, enemy_hit, status, enemy_while_scroll_damaged, sc);
		col4.enemy_gets_damaged(E4, shipWeapon, T4, am4, t4, foes_scroll3, w, stat, destroy, enemy_hit, status, enemy_while_scroll_damaged, sc);
		col5.enemy_gets_damaged(E5, shipWeapon, T5, am5, t5, foes_scroll4, w, stat, destroy, enemy_hit, status, enemy_while_scroll_damaged, sc);
		col6.enemy_gets_damaged(E6, shipWeapon, T6, am6, t6, foes_scroll5, w, stat, destroy, enemy_hit, status, enemy_while_scroll_damaged, sc);


		col.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T, am, t, foes, unlockweapon, destroy);
		col2.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T2, am2, t2, foes_scroll1, unlockweapon, destroy);
		col3.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T3, am3, t3, foes_scroll2, unlockweapon, destroy);
		col4.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T4, am4, t4, foes_scroll3, unlockweapon, destroy);
		col5.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T5, am5, t5, foes_scroll4, unlockweapon, destroy);
		col6.enemy_dies(status, adestroy, stat, num_of_enemies, sc, T6, am6, t6, foes_scroll5, unlockweapon, destroy);


		E.update(foes, b, mb, elazer, turrets, bw, ani, s, enemy_damaged);
		E2.update(foes_scroll1, enemy_while_scroll_damaged);
		E3.update(foes_scroll2, enemy_while_scroll_damaged);
		E4.update(foes_scroll3, enemy_while_scroll_damaged);
		E5.update(foes_scroll4, enemy_while_scroll_damaged);
		E6.update(foes_scroll5, enemy_while_scroll_damaged);

		T.update(am, t);
		T2.update(am2, t2);
		T3.update(am3, t3);
		T4.update(am4, t4);
		T5.update(am5, t5);
		T6.update(am6, t6);

		col.player_gets_tool(spaceship, E, foes, t, am, T, stat, s, pickup, status, health, ammo, disfig);
		col2.player_gets_tool(spaceship, E2, foes_scroll1, t2, am2, T, stat, s, pickup, status, health, ammo, disfig);
		col3.player_gets_tool(spaceship, E3, foes_scroll2, t3, am3, T, stat, s, pickup, status, health, ammo, disfig);
		col4.player_gets_tool(spaceship, E4, foes_scroll3, t4, am4, T, stat, s, pickup, status, health, ammo, disfig);
		col5.player_gets_tool(spaceship, E5, foes_scroll4, t5, am5, T, stat, s, pickup, status, health, ammo, disfig);
		col6.player_gets_tool(spaceship, E6, foes_scroll5, t6, am6, T, stat, s, pickup, status, health, ammo, disfig);
		s.update_animation();

		if (!spaceship[0]->ishit())
		{
			col.player_gets_damaged(E, mb, b, foes, spaceship, stat, hit, status, ev, player_damaged, health);
			
			col.player_gets_damaged(E, s, foes, elazer, turrets, spaceship, bw, stat, hit, status, ev, player_damaged, health);
			col2.player_gets_damaged(E, foes_scroll1, elazer, spaceship, stat, hit, status, ev, player_damaged, health);
			col2.player_gets_damaged(E, foes_scroll2, elazer, spaceship, stat, hit, status, ev, player_damaged, health);
			col2.player_gets_damaged(E, foes_scroll3, elazer, spaceship, stat, hit, status, ev, player_damaged, health);
			col2.player_gets_damaged(E, foes_scroll4, elazer, spaceship, stat, hit, status, ev, player_damaged, health);
			col2.player_gets_damaged(E, foes_scroll5, elazer, spaceship, stat, hit, status, ev, player_damaged, health);

			col2.player_gets_damaged(E2, mb, b, foes_scroll1, spaceship, stat, hit, status, ev, player_damaged, health);
			col3.player_gets_damaged(E3, mb, b, foes_scroll2, spaceship, stat, hit, status, ev, player_damaged, health);
			col4.player_gets_damaged(E4, mb, b, foes_scroll3, spaceship, stat, hit, status, ev, player_damaged, health);
			col5.player_gets_damaged(E5, mb, b, foes_scroll4, spaceship, stat, hit, status, ev, player_damaged, health);
			col6.player_gets_damaged(E6, mb, b, foes_scroll5, spaceship, stat, hit, status, ev, player_damaged, health);


		}
		
		if (disfig)
		{
			col.destroy_foes_inside(E, foes);
			col2.destroy_foes_inside(E2, foes_scroll1);
			col3.destroy_foes_inside(E3, foes_scroll2);
			col4.destroy_foes_inside(E4, foes_scroll3);
			col5.destroy_foes_inside(E5, foes_scroll4);
			col6.destroy_foes_inside(E6, foes_scroll5);

			disfig = false;
		}

		col.Ball_gets_redirected(E, shipWeapon, bw, w, ballreflect, bossdefeated);
		col.Ball_gets_destroyed(E, shipWeapon, T, bw, w, am, reflect, bossdefeated);
		col.Boss_weapon_immune_to_weapon(E, s, foes, shipWeapon, elazer, w, turrets, bw, reflect, bossdefeated);

		col2.Boss_weapon_immune_to_weapon(E, shipWeapon, foes_scroll1, w, reflect, bossdefeated);
		col3.Boss_weapon_immune_to_weapon(E, shipWeapon, foes_scroll2, w, reflect, bossdefeated);
		col4.Boss_weapon_immune_to_weapon(E, shipWeapon, foes_scroll3, w, reflect, bossdefeated);
		col5.Boss_weapon_immune_to_weapon(E, shipWeapon, foes_scroll4, w, reflect, bossdefeated);
		col6.Boss_weapon_immune_to_weapon(E, shipWeapon, foes_scroll5, w, reflect, bossdefeated);

		
		draw = true;
		render();

	}

	else if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 1 && spaceship.size() > 0)
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

	else if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 3 && spaceship.size() > 0)
	{
		draw = true;
		render();
	}

	else if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 4 && spaceship.size() > 0)
	{


		w.clear();

		//std::cout << al_get_sample_instance_position(Stage_Completed) << std::endl;
		
		if (al_get_sample_instance_position(Stage_Completed) == 0 && scorecounter > 0)
		{
			al_stop_sample_instance(Stage_Completed);
			increment = 1;
		}

		else if (al_get_sample_instance_position(Stage_Completed) > 0)
		{
			al_play_sample_instance(Stage_Completed);

		}

		if (scorecounter < 0)
		{
			increment = 0;
		}

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

	else if (ev.type == ALLEGRO_EVENT_TIMER && pauseCounter == 5)
	{
		w.clear();
		spaceship.clear();
		foes.clear();
		b.clear();
		foes_scroll1.clear();
		foes_scroll2.clear();
		foes_scroll3.clear();
		foes_scroll4.clear();
		foes_scroll5.clear();
		mb.clear();
		t.clear();
		t2.clear();
		t3.clear();
		t4.clear();
		t5.clear();
		t6.clear();
		am.clear();
		am2.clear();
		am3.clear();
		am4.clear();
		am5.clear();
		am6.clear();
		elazer.clear();
		ball.clear();
		mball.clear();
		v.clear();
		ds.clear();
		EB.clear();
		ST.clear();
		LB.clear();
		K.clear();
		hw.clear();
		st.clear();
		credit.increment_frame();

		al_stop_sample_instance(Earth);
		al_stop_sample_instance(Earth_Factory);
		al_stop_sample_instance(Mars);
		al_stop_sample_instance(Mars_Nest);
		al_stop_sample_instance(Astroid);
		al_stop_sample_instance(Boss);
		al_stop_sample_instance(Saturn);
		al_stop_sample_instance(Final_Boss);
		//std::cout << credit.get_frame() << std::endl;

		draw = true;
		render();
	}

	else if (ev.type == ALLEGRO_EVENT_TIMER && spaceship.size() <= 0 && pauseCounter!= 5)
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
	
	if (draw && pauseCounter == 0 && spaceship.size() > 0)
	{
		if (b.size() == 0 && spaceship.size() > 0)
		{
			if (minibossdefeated)
			{
				al_stop_sample_instance(Earth);
				al_stop_sample_instance(Earth_Factory);
				al_stop_sample_instance(Mars);
				al_stop_sample_instance(Mars_Nest);
				al_stop_sample_instance(Astroid);
				al_stop_sample_instance(Boss);
				al_stop_sample_instance(Saturn);
				al_stop_sample_instance(Final_Boss);
			}

			switch (s.get_stage())
			{
			case EARTH:
				s.earth();
				if ((lvl == 1 || lvl == 2) && !minibossdefeated)
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
				if ((lvl == 1 || lvl == 2) && !minibossdefeated)
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
		
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i]->get_health() <= 0)
			{
				al_stop_sample_instance(Mars_Nest);
				al_stop_sample_instance(Mars);
				al_stop_sample_instance(Earth);
				al_stop_sample_instance(Earth_Factory);
				al_stop_sample_instance(Astroid);
				al_stop_sample_instance(Saturn);
				al_stop_sample_instance(Boss);
				al_stop_sample_instance(Final_Boss);

			}
		}
		


		E.renderenemy(foes, enemy_damaged);
		E.renderenemy(foes_scroll1, enemy_while_scroll_damaged);
		E.renderenemy(foes_scroll2, enemy_while_scroll_damaged);
		E.renderenemy(foes_scroll3, enemy_while_scroll_damaged);
		E.renderenemy(foes_scroll4, enemy_while_scroll_damaged);
		E.renderenemy(foes_scroll5, enemy_while_scroll_damaged);
		
		E.renderboss(b, elazer, bw, ani, Boss_destroyed, frame);
		E.renderminiboss(mb, turrets, s, ani);

		
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
		
		for (int i = 0; i < foes_scroll1.size(); i++)
		{
			if (foes_scroll1[i]->get_duration() > 0)
			{
				switch (foes_scroll1[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll1[i]->get_name_ID()), E.get_h(foes_scroll1[i]->get_name_ID()), foes_scroll1[i]->get_x(), foes_scroll1[i]->get_y(), E.get_w(foes_scroll1[i]->get_name_ID()), E.get_h(foes_scroll1[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll1[i]->get_x(), foes_scroll1[i]->get_y(), foes_scroll1[i]->get_duration(), 15, 0, 7);
					break;
				}
			}
			
		}

		for (int i = 0; i < foes_scroll2.size(); i++)
		{
			if (foes_scroll2[i]->get_duration() > 0)
			{
				switch (foes_scroll2[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll2[i]->get_name_ID()), 
						E.get_h(foes_scroll2[i]->get_name_ID()), foes_scroll2[i]->get_x(), 
						foes_scroll2[i]->get_y(), E.get_w(foes_scroll2[i]->get_name_ID()), E.get_h(foes_scroll2[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll2[i]->get_x(), foes_scroll2[i]->get_y(), foes_scroll2[i]->get_duration(), 15, 0, 7);
					break;
				}
			}

		}

		for (int i = 0; i < foes_scroll3.size(); i++)
		{
			if (foes_scroll3[i]->get_duration() > 0)
			{
				switch (foes_scroll3[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll3[i]->get_name_ID()), E.get_h(foes_scroll3[i]->get_name_ID()), 
						foes_scroll3[i]->get_x(), foes_scroll3[i]->get_y(), E.get_w(foes_scroll3[i]->get_name_ID()), E.get_h(foes_scroll3[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll3[i]->get_x(), foes_scroll3[i]->get_y(), foes_scroll3[i]->get_duration(), 15, 0, 7);
					break;
				}
			}

		}

		for (int i = 0; i < foes_scroll4.size(); i++)
		{
			if (foes_scroll4[i]->get_duration() > 0)
			{
				switch (foes_scroll4[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll4[i]->get_name_ID()), E.get_h(foes_scroll4[i]->get_name_ID()),
						foes_scroll4[i]->get_x(), foes_scroll4[i]->get_y(), E.get_w(foes_scroll4[i]->get_name_ID()), E.get_h(foes_scroll4[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll4[i]->get_x(), foes_scroll4[i]->get_y(), foes_scroll4[i]->get_duration(), 15, 0, 7);
					break;
				}
			}

		}

		for (int i = 0; i < foes_scroll5.size(); i++)
		{
			if (foes_scroll5[i]->get_duration() > 0)
			{
				switch (foes_scroll5[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll5[i]->get_name_ID()), E.get_h(foes_scroll5[i]->get_name_ID()),
						foes_scroll5[i]->get_x(), foes_scroll5[i]->get_y(), E.get_w(foes_scroll5[i]->get_name_ID()), E.get_h(foes_scroll5[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll5[i]->get_x(), foes_scroll5[i]->get_y(), foes_scroll5[i]->get_duration(), 15, 0, 7);
					break;
				}
			}

		}
		
		for (int i = 0; i < foes_scroll6.size(); i++)
		{
			if (foes_scroll6[i]->get_duration() > 0)
			{
				switch (foes_scroll6[i]->get_coord_ID())
				{
				case FROZEN:
					//al_draw_bitmap(frozen, foes[i]->get_x(), foes[i]->get_y(), NULL);
					al_draw_scaled_bitmap(frozen, 0, 0, E.get_w(foes_scroll6[i]->get_name_ID()), E.get_h(foes_scroll6[i]->get_name_ID()),
						foes_scroll6[i]->get_x(), foes_scroll6[i]->get_y(), E.get_w(foes_scroll6[i]->get_name_ID()), E.get_h(foes_scroll6[i]->get_name_ID()), NULL);
					break;

				case BURNED:
					ani.two_frames_custom(burned_red, burned_yellow, foes_scroll6[i]->get_x(), foes_scroll6[i]->get_y(), foes_scroll6[i]->get_duration(), 15, 0, 7);
					break;
				}
			}

		}

		
		
		for (int i = 0; i < am.size(); i++)
		{
			T.draw(am[i]->get_ammo_ID(), unlockweapon, am[i]->get_x(), am[i]->get_y());
		}
		
		for (int i = 0; i < am2.size(); i++)
		{
			T2.draw(am2[i]->get_ammo_ID(), unlockweapon, am2[i]->get_x(), am2[i]->get_y());
		}

		for (int i = 0; i < am3.size(); i++)
		{
			T3.draw(am3[i]->get_ammo_ID(), unlockweapon, am3[i]->get_x(), am3[i]->get_y());
		}

		for (int i = 0; i < am4.size(); i++)
		{
			T4.draw(am4[i]->get_ammo_ID(), unlockweapon, am4[i]->get_x(), am4[i]->get_y());
		}

		for (int i = 0; i < am5.size(); i++)
		{
			T5.draw(am5[i]->get_ammo_ID(), unlockweapon, am5[i]->get_x(), am5[i]->get_y());
		}

		for (int i = 0; i < am6.size(); i++)
		{
			T6.draw(am6[i]->get_ammo_ID(), unlockweapon, am6[i]->get_x(), am6[i]->get_y());
		}


		for (int i = 0; i < t.size(); i++)
		{
			T.draw(t[i]->get_tool_ID(), t[i]->get_x(), t[i]->get_y());
		}

		for (int i = 0; i < t2.size(); i++)
		{

			T2.draw(t2[i]->get_tool_ID(), t2[i]->get_x(), t2[i]->get_y());
		}

		for (int i = 0; i < t3.size(); i++)
		{

			T3.draw(t3[i]->get_tool_ID(), t3[i]->get_x(), t3[i]->get_y());
		}
		
		for (int i = 0; i < t4.size(); i++)
		{

			T4.draw(t4[i]->get_tool_ID(), t4[i]->get_x(), t4[i]->get_y());
		}

		for (int i = 0; i < t5.size(); i++)
		{
			T5.draw(t5[i]->get_tool_ID(), t5[i]->get_x(), t5[i]->get_y());
		}

		for (int i = 0; i < t6.size(); i++)
		{
			T6.draw(t6[i]->get_tool_ID(), t6[i]->get_x(), t6[i]->get_y());
		}
		
		
		
		stat.Status_box(0, winy - 100, winx, winy);
		stat.sethealth(health, status);
		stat.set_health_bar(211, 440, 311, 455);
		stat.setlvl(lvl, status);
		stat.setscore(sc, status);

		for (int j = 0; j < spaceship.size(); j++)
		{
			spaceship[j]->render(stat, status, player_damaged);
		}

		if (num_of_enemies == 2)
		{

			stat.setnotification("YOU GOT NEW WEAPON: ICET", status, 160, 400, textframe);
			unlockweapon[ICET] = true;
			num_of_weapon = 1;

		}

		if (num_of_enemies == 4)
		{

			stat.setnotification("YOU GOT NEW WEAPON: INFERRED", status, 160, 400, textframe);
			unlockweapon[INFERRED] = true;
			num_of_weapon = 2;

		}

		if (num_of_enemies == 8)
		{

			stat.setnotification("YOU GOT NEW WEAPON: ZIGGONET", status, 160, 400, textframe);
			unlockweapon[ZIGGONET] = true;
			num_of_weapon = 3;

		}

		if (num_of_enemies == 24)
		{

			stat.setnotification("YOU GOT NEW WEAPON: HAYCH", status, 160, 400, textframe);
			unlockweapon[HAYCH] = true;
			num_of_weapon = 4;

		}

		if (num_of_enemies == 48)
		{

			stat.setnotification("YOU GOT NEW WEAPON: HAYCHBA", status, 160, 400, textframe);
			unlockweapon[HAYCHBA] = true;
			num_of_weapon = 5;

		}

		if (num_of_enemies == 60)
		{

			stat.setnotification("YOU GOT NEW WEAPON: SONIC WAVE", status, 160, 400, textframe);
			unlockweapon[SONICWAVE] = true;
			num_of_weapon = 6;

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

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		draw = false;
	}
	
	else if (draw && pauseCounter == 1 && spaceship.size() > 0)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		stat.setnotification("PAUSE", pause, 200, 150, al_map_rgb(0,255,0));
		
		stat.setnotification("CONTINUE [P]", pause_options, 190, 230, al_map_rgb(255, 255, 255));
		stat.setnotification("REPLAY [R]", pause_options, 195, 260, al_map_rgb(255, 255, 255));
		stat.setnotification("HOW TO PLAY", pause_options, 190, 290, al_map_rgb(255, 255, 255));
		stat.setnotification("BACK TO MAIN MENU", pause_options, 160, 320, al_map_rgb(255, 255, 255));
		stat.setnotification("QUIT [ESC]", pause_options, 200, 350, al_map_rgb(255, 255, 255));
		

		if (mouse)
		{
			switch (options)
			{
			case 0:
				al_draw_filled_rectangle(160 - 5, 230, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 230 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 230, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 230 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("CONTINUE [P]", pause_options, 190, 230, al_map_rgb(255, 0, 0));
				break;

			case 1:
				al_draw_filled_rectangle(160 - 5, 260, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 260 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 260, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 260 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("REPLAY [R]", pause_options, 195, 260, al_map_rgb(255, 0, 0));
				break;

			case 2:
				al_draw_filled_rectangle(160 - 5, 290, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 290 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 290, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 290 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("HOW TO PLAY", pause_options, 190, 290, al_map_rgb(255, 0, 0));
				break;

			case 3:
				al_draw_filled_rectangle(160 - 5, 320, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 320 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 320, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 320 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("BACK TO MAIN MENU", pause_options, 160, 320, al_map_rgb(255, 0, 0));
				break;

			case 4:
				al_draw_filled_rectangle(160 - 5, 350, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 350 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(160 - 5, 350, 160 + al_get_text_width(pause_options, "BACK TO MAIN MENU") + 5, 350 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("QUIT [ESC]", pause_options, 200, 350, al_map_rgb(255, 0, 0));
				break;
			}
		}

		else
		{
			switch (options)
			{
			case 0:
				stat.setnotification("CONTINUE [P]", pause_options, 190, 230, al_map_rgb(255, 0, 0));
				break;

			case 1:
				stat.setnotification("REPLAY [R]", pause_options, 195, 260, al_map_rgb(255, 0, 0));
				break;

			case 2:
				stat.setnotification("HOW TO PLAY", pause_options, 190, 290, al_map_rgb(255, 0, 0));
				break;

			case 3:
				stat.setnotification("BACK TO MAIN MENU", pause_options, 160, 320, al_map_rgb(255, 0, 0));
				break;

			case 4:
				stat.setnotification("QUIT [ESC]", pause_options, 200, 350, al_map_rgb(255, 0, 0));
				break;


			}
		}

		al_flip_display();
	}

	else if (draw && spaceship.size() <= 0 && pauseCounter != 5)
	{
		al_clear_to_color(al_map_rgb(200, 0, 0));

		stat.setnotification("GAME OVER", pause, 170, 150, al_map_rgb(0, 0, 0));
		
		
		stat.setnotification("PLAY AGAIN", pause_options, 190, 230, al_map_rgb(0, 0, 0));
		stat.setnotification("QUIT [ESC]", pause_options, 200, 260, al_map_rgb(0, 0, 0));
		if (mouse)
		{
			switch (options)
			{
			case 0:
				al_draw_filled_rectangle(190 - 5, 230, 190 + al_get_text_width(pause_options, "CONTINUE [P]") + 10, 230 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(190 - 5, 230, 190 + al_get_text_width(pause_options, "CONTINUE [P]") + 10, 230 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("PLAY AGAIN", pause_options, 190, 230, al_map_rgb(0, 0, 255));
				break;

			case 1:
				al_draw_filled_rectangle(190 - 5, 260, 190 + al_get_text_width(pause_options, "CONTINUE [P]") + 10, 260 + al_get_font_line_height(pause_options), al_map_rgb(255, 255, 0));
				al_draw_rectangle(190 - 5, 260, 190 + al_get_text_width(pause_options, "CONTINUE [P]") + 10, 260 + al_get_font_line_height(pause_options), al_map_rgb(255, 55, 0), 1);
				stat.setnotification("QUIT [ESC]", pause_options, 200, 260, al_map_rgb(0, 0, 255));
				break;
			}
		}

		else
		{
			switch (options)
			{
			case 0:
				stat.setnotification("PLAY AGAIN", pause_options, 190, 230, al_map_rgb(0, 0, 255));
				break;

			case 1:
				stat.setnotification("QUIT [ESC]", pause_options, 200, 260, al_map_rgb(0, 0, 255));
				break;
			}
		}
		
		
		al_flip_display();
	}

	else if (draw && pauseCounter == 3 && spaceship.size() > 0)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		stat.setnotification("HOW TO PLAY", pause, 150, 0, al_map_rgb(200, 0, 100));

		stat.setnotification("PRESS (ESC) IF YOU WANT TO QUIT", pause_options, 0, 100, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (P) IF YOU WANT TO CONTINUE OR PAUSE", pause_options, 0, 130, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (R) TO RESET THE GAME (ONLY IN PAUSE MENU)", pause_options, 0, 160, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (DIRECTIONAL KEY) TO MOVE THE PLAYER", pause_options, 0, 190, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (Z) TO SHOOT LAZERS", pause_options, 0, 220, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (X) TO SHOOT SPECIAL WEAPONS", pause_options, 0, 250, al_map_rgb(50, 255, 255));
		stat.setnotification("PRESS (A) or (S) TO SWITCH SPECIAL WEAPONS", pause_options, 0, 280, al_map_rgb(50, 255, 255));

		al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0));
		stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255));
		stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(255, 255, 255));

		if (mouse && options == 0)
		{
			al_draw_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(100, 0, 0), 1);
			al_draw_filled_rectangle(170, 500 - 2 * al_get_font_line_height(status), 180 + al_get_text_width(status, "BACK TO MAIN MENU"), 500, al_map_rgb(255, 255, 0));
			stat.setnotification("BACK TO MAIN MENU", status, 175, 500 - 2 * al_get_font_line_height(status), al_map_rgb(155, 0, 0));
			stat.setnotification("[SPACEBAR]", status, 200, 500 - al_get_font_line_height(status), al_map_rgb(155, 0, 0));
		}

		al_flip_display();

	}

	else if (draw && pauseCounter == 4 && spaceship.size() > 0)
	{
		al_clear_to_color(al_map_rgb(100, 200, 0));

		stat.setnotification("Stage Completed", pause, 150, 0, al_map_rgb(50, 100, 50));
		
		if (increment == 1)
		{
			al_set_sample_instance_position(Countdown, 0);
			al_play_sample_instance(Countdown);
		}


		scorecounter -= increment;
		stat.setscore(scorecounter, pause_options, "STAGE SCORE: ", 150, 100);

		sc+=increment;
		if (scorecounter <= 0)
		{
			if (s.get_stage() == EARTH)
			{
				stat.setnotification("Now the ship will go on to Mars to destroy more resources", status, 50, 300, al_map_rgb(70, 50, 70));
			}

			else if (s.get_stage() == MARS)
			{
				stat.setnotification("Martian B told who and where the leader is.", status, 50, 300, al_map_rgb(70, 50, 70));
				stat.setnotification("He goes by the name Xorgana and lives in Saturn's Ring.", status, 50, 320, al_map_rgb(70, 50, 70));
				stat.setnotification("ONWARDS THRU THE ASTROID BELT!!!", status, 50, 340, al_map_rgb(70, 50, 70));
			}

			else if (s.get_stage() == AST)
			{
				stat.setnotification("This is it! Xorgana is wating at Saturn's ring...", status, 50, 300, al_map_rgb(70, 50, 70));
			}

			increment = 0;


			if (mouse && options == 0)
			{
				al_draw_rectangle(200, winy - 2 * al_get_font_line_height(pause_options), 220 + al_get_text_width(pause_options, "CONTINUE"), 500, al_map_rgb(100, 0, 0), 1);
				al_draw_filled_rectangle(200, winy - 2 * al_get_font_line_height(pause_options), 220 + al_get_text_width(pause_options, "CONTINUE"), 500, al_map_rgb(0, 150, 255));
				stat.setnotification("CONTINUE", pause_options, 210, winy - 2 * al_get_font_line_height(pause_options), al_map_rgb(200, 0, 200));
				stat.setnotification("(ENTER)", pause_options, 220, winy - al_get_font_line_height(pause_options), al_map_rgb(200, 0, 200));
			}

			else
			{
				al_draw_rectangle(200, winy - 2 * al_get_font_line_height(pause_options), 220 + al_get_text_width(pause_options, "CONTINUE"), 500, al_map_rgb(100, 0, 0), 1);
				al_draw_filled_rectangle(200, winy - 2 * al_get_font_line_height(pause_options), 220 + al_get_text_width(pause_options, "CONTINUE"), 500, al_map_rgb(0, 255, 255));
				stat.setnotification("CONTINUE", pause_options, 210, winy - 2 * al_get_font_line_height(pause_options), al_map_rgb(200, 0, 100));
				stat.setnotification("(ENTER)", pause_options, 220, winy - al_get_font_line_height(pause_options), al_map_rgb(200, 0, 100));
			}
		

		}

		stat.setscore(sc, pause_options, 150, 150);


	

		al_flip_display();

	}

	else if (draw && pauseCounter == 5)
	{

		

		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (credit.get_frame() >= 0 && credit.get_frame() < 100)
		{
			stat.setnotification("Director", pause_options, 205, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("GEORGE EBEID", pause_options, 180, 230, al_map_rgb(255, 255, 255));
		}
		
		else if(credit.get_frame() >= 100 && credit.get_frame() < 200)
		{
			stat.setnotification("Producer", pause_options, 205, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("GEORGE EBEID", pause_options, 180, 230, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 200 && credit.get_frame() < 300)
		{
			stat.setnotification("Artwork", pause_options, 205, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("GEORGE EBEID", pause_options, 180, 230, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 300 && credit.get_frame() < 400)
		{
			stat.setnotification("Background Music", pause_options, 165, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("GEORGE EBEID", pause_options, 180, 230, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 400 && credit.get_frame() < 500)
		{
			stat.setnotification("Special Effects and Background Music", pause_options, 100, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("GEORGE EBEID", pause_options, 180, 230, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 500 && credit.get_frame() < 600)
		{
			stat.setnotification("Special Thanks To", pause_options, 175, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("Visual Studio 2017 Experess", pause_options, 130, 230, al_map_rgb(255, 255, 255));
			stat.setnotification("LMMS", pause_options, 220, 260, al_map_rgb(255, 255, 255));
			stat.setnotification("Krita", pause_options, 225, 290, al_map_rgb(255, 255, 255));
			stat.setnotification("Inkscape", pause_options, 210, 320, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 600 && credit.get_frame() < 700)
		{
			stat.setnotification("Special Thanks To", pause_options, 175, 200, al_map_rgb(255, 255, 255));
			stat.setnotification("Allegro 5", pause_options, 200, 230, al_map_rgb(255, 255, 255));
			stat.setnotification("Freesounds.com (for sound effects)", pause_options, 100, 260, al_map_rgb(255, 255, 255));
		}

		else if (credit.get_frame() >= 700)
		{
			stat.setnotification("THE END", pause_options, 200, 200, al_map_rgb(255, 255, 255));


			

			if (mouse && options == 0)
			{
				al_draw_rectangle(200, 250, 220 + al_get_text_width(status, "(ENTER)"), 270 + 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255), 1);
				al_draw_filled_rectangle(200, 250, 220 + al_get_text_width(status, "(ENTER)"), 270 + 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255));
				stat.setnotification("QUIT", status, 220, 260, al_map_rgb(0, 0, 0));
				stat.setnotification("(ENTER)", status, 210, 280, al_map_rgb(0, 0, 0));
			}

			else
			{
				al_draw_rectangle(200, 250, 220 + al_get_text_width(status, "(ENTER)"), 270 + 2 * al_get_font_line_height(status), al_map_rgb(255, 255, 255), 1);
				//al_draw_filled_rectangle(200, winy - 2 * al_get_font_line_height(status), 220 + al_get_text_width(status, "CONTINUE"), 500, al_map_rgb(0, 255, 255));
				stat.setnotification("QUIT", status, 220, 260, al_map_rgb(255, 255, 255));
				stat.setnotification("(ENTER)", status, 210, 280, al_map_rgb(255, 255, 255));
			}


		}

		if (credit.get_frame() < 710)
		{
			al_play_sample_instance(Credit);
		}

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
	al_destroy_sample(PO);
	al_destroy_sample(POF);
	al_destroy_sample(eh);
	al_destroy_sample(scm);
	al_destroy_sample(Bossdes);
	al_destroy_sample(cre);
	al_destroy_sample(cntdwn);

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

	al_destroy_sample_instance(Pause_On);
	al_destroy_sample_instance(Pause_Off);

	al_destroy_sample_instance(game_over);
	al_destroy_sample_instance(enemy_hit);
	al_destroy_sample_instance(Stage_Completed);
	al_destroy_sample_instance(Boss_destroyed);
	al_destroy_sample_instance(Credit);
	al_destroy_sample_instance(Countdown);

	s.destroy_stages();

	E.destroy_enemy_img();
	E2.destroy_enemy_img();
	E3.destroy_enemy_img();
	E4.destroy_enemy_img();
	E5.destroy_enemy_img();
	E6.destroy_enemy_img();
	
	T.destroy();
	T2.destroy();
	T3.destroy();
	T4.destroy();
	T5.destroy();
	T6.destroy();
	
	for (int j = 0; j < spaceship.size(); j++)
	{
		spaceship[j]->destroy();
	}

	shipWeapon.destroy_weapon_img();
	al_destroy_font(status);
	al_destroy_font(pause);
	al_destroy_font(pause_options);

}

