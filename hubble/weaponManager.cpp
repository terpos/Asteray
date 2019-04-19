#include "weaponManager.h"



weaponManager::weaponManager()
{
}


weaponManager::~weaponManager()
{
}

void weaponManager::load_weapon_img()
{
	shiplaser[BLUE] = al_load_bitmap("lazer_blue.png");
	shiplaser[YELLOW] = al_load_bitmap("lazer_yellow.png");
	shiplaser[RED] = al_load_bitmap("lazer_red.png");

	inferred[0] = al_load_bitmap("redfire.png");
	inferred[1] = al_load_bitmap("bluefire.png");

	icet[0] = al_load_bitmap("Icazor.png");
	icet[1] = al_load_bitmap("Icazor2.png");

	haych[0] = al_load_bitmap("haychblack.png");
	haych[1] = al_load_bitmap("haychwhite.png");

	haychba[0] = al_load_bitmap("haychbablack.png");
	haychba[1] = al_load_bitmap("haychbawhite.png");

	ziggonet = al_load_bitmap("zigonnet.png");
	sonic_wave = al_load_bitmap("Sonic_Wave.png");

	font = al_load_ttf_font("Pixellari.ttf", 12, NULL);

	//al_reserve_samples(1);
}

void weaponManager::select_keys(int keys, int p_or_s)
{
	if (p_or_s == PRIME)
	{
		if (keys == ALLEGRO_KEY_Z)
		{
			std::cout << "Z" << std::endl;
		}
	}

	else if (p_or_s == SECONDARY)
	{
		if (keys == ALLEGRO_KEY_X)
		{
			std::cout << "X" << std::endl;
		}
	}
}

void weaponManager::setweaponID(int id)
{
	this->id = id;
}

int weaponManager::getweaponID()
{
	return this->id;
}

void weaponManager::printout()
{
	std::cout << "hello world" << std::endl;
}

void weaponManager::load_ammo(std::vector <lazer*> &laser, int x, int y, int lim)
{
	if (laser.size() < lim)
	{
		laser.push_back(new lazer(x, y));
	}
	
	if (laser.size() > 2)
	{
		laser.erase(laser.begin() + 3, laser.end());
	}
}

void weaponManager::load_ammo(std::vector <Icet*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Icet(x, y));
	}

	if (ice.size() > lim-1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::load_ammo(std::vector <Inferred*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Inferred(x, y));
	}

	if (ice.size() > lim - 1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::load_ammo(std::vector <Ziggonet*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Ziggonet(x, y));
	}

	if (ice.size() > lim - 1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::load_ammo(std::vector <Haych*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Haych(x, y));
	}

	if (ice.size() > lim - 1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::load_ammo(std::vector <Haychba*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Haychba(x, y));
	}

	if (ice.size() > lim - 1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::load_ammo(std::vector <Sonic_Wave*> &ice, int x, int y, int lim)
{
	if (ice.size() < lim)
	{
		ice.push_back(new Sonic_Wave(x, y));
	}

	if (ice.size() > lim - 1)
	{
		ice.erase(ice.begin() + 3, ice.end());
	}
}

void weaponManager::update(std::vector <lazer*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Icet*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Inferred*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Ziggonet*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Haych*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Haychba*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::update(std::vector <Sonic_Wave*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->shoot(true);
	}
}

void weaponManager::renderweapon(std::vector <lazer*> &laser, Status s)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(shiplaser[BLUE], shiplaser[YELLOW], shiplaser[RED]);
		//laser[i]->draw(icet[BLUE], icet[YELLOW], shiplaser[RED]);
		
	}
	s.prime_Weapon_box(shiplaser[BLUE], font);
}

void weaponManager::renderweapon(std::vector <Icet*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(icet[0], icet[1]);
	}
	s.secondary_Weapon_box(icet[0], font, ammo);
	
}

void weaponManager::renderweapon(std::vector <Inferred*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(inferred[0], inferred[1]);
	}
	s.secondary_Weapon_box(inferred[0], font, ammo);

}

void weaponManager::renderweapon(std::vector <Ziggonet*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(ziggonet, ziggonet);
	}
	s.secondary_Weapon_box(ziggonet, font, ammo);

}

void weaponManager::renderweapon(std::vector <Haych*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(haych[0], haych[1]);
	}
	s.secondary_Weapon_box(haych[0], font, ammo);
}

void weaponManager::renderweapon(std::vector <Haychba*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(haychba[0], haychba[1]);
	}
	s.secondary_Weapon_box(haychba[0], font, ammo);
}

void weaponManager::renderweapon(std::vector <Sonic_Wave*> &laser, Status s, int ammo)
{
	for (int i = 0; i < laser.size(); i++)
	{
		laser[i]->draw(sonic_wave, sonic_wave);
	}
	s.secondary_Weapon_box(sonic_wave, font, ammo);
}


void weaponManager::destroy_ammo(std::vector <lazer*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->getweapony() < 0)
		{
			laser.erase(laser.begin() + i);
		}
		
		
	}
}

void weaponManager::destroy_ammo(std::vector <Icet*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}


	}
}

void weaponManager::destroy_ammo(std::vector <Inferred*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}


	}
}

void weaponManager::destroy_ammo(std::vector <Ziggonet*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}


	}
}

void weaponManager::destroy_ammo(std::vector <Haych*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}


	}
}

void weaponManager::destroy_ammo(std::vector <Haychba*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}
	}
}

void weaponManager::destroy_ammo(std::vector <Sonic_Wave*> &laser)
{
	for (int i = 0; i < laser.size(); i++)
	{
		if (laser[i]->gety() < 0)
		{
			laser.erase(laser.begin() + i);
		}
	}
	

}

void weaponManager::destroy_weapon_img()
{
	for (int i = 0; i < 3; i++)	
	{al_destroy_bitmap(shiplaser[i]);}	

	al_destroy_bitmap(inferred[0]);
	al_destroy_bitmap(inferred[1]);
	al_destroy_bitmap(icet[0]);
	al_destroy_bitmap(icet[1]);
	al_destroy_bitmap(haych[0]);
	al_destroy_bitmap(haych[1]);
	al_destroy_bitmap(haychba[0]);
	al_destroy_bitmap(haychba[1]);
	al_destroy_bitmap(ziggonet);
	al_destroy_bitmap(sonic_wave);

}