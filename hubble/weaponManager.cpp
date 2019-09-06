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

int weaponManager::getweaponID()
{
	return HAYCH;
}

int weaponManager::geth(int ID)
{
	switch (ID)
	{
	case LAZER:
		return al_get_bitmap_height(shiplaser[BLUE]);
		break;
	case ICET:
		return al_get_bitmap_height(icet[0]);
		break;
	case INFERRED:
		return al_get_bitmap_height(inferred[0]);
		break;
	case ZIGGONET:
		return al_get_bitmap_height(ziggonet);
		break;
	case HAYCH:
		return al_get_bitmap_height(haych[0]);
		break;
	case HAYCHBA:
		return al_get_bitmap_height(haychba[0]);
		break;
	case SONICWAVE:
		return al_get_bitmap_height(sonic_wave);
		break;
	}
	return NULL;
}

int weaponManager::getw(int ID)
{
	switch (ID)
	{
	case LAZER:
		return al_get_bitmap_width(shiplaser[BLUE]);
		break;
	case ICET:
		return al_get_bitmap_width(icet[0]);
		break;
	case INFERRED:
		return al_get_bitmap_width(inferred[0]);
		break;
	case ZIGGONET:
		return al_get_bitmap_width(ziggonet);
		break;
	case HAYCH:
		return al_get_bitmap_width(haych[0]);
		break;
	case HAYCHBA:
		return al_get_bitmap_width(haychba[0]);
		break;
	case SONICWAVE:
		return al_get_bitmap_width(sonic_wave);
		break;
	}
	return NULL;
}

void weaponManager::printout()
{
	std::cout << "hello world" << std::endl;
}

void weaponManager::load_ammo(std::vector<Weapon*>& w, int ID, int x, int y, int lim)
{
	switch (ID)
	{
	case LAZER:
		w.push_back(new lazer(x, y));
		break;
	case ICET:
		w.push_back(new Icet(x, y));
		break;
	case INFERRED:
		w.push_back(new Inferred(x, y));
		break;
	case ZIGGONET:
		w.push_back(new Ziggonet(x, y));
		break;
	case HAYCH:
		w.push_back(new Haych(x, y));
		break;
	case HAYCHBA:
		w.push_back(new Haychba(x, y));
		break;
	case SONICWAVE:
		w.push_back(new Sonic_Wave(x, y));
		break;
	}
	
}

void weaponManager::update(std::vector<Weapon*>& w)
{
	for (int i = 0; i < w.size(); i++)
	{
		w[i]->shoot(true);
	}
}

void weaponManager::renderweapon(std::vector<Weapon*>& w, int ID, Status s, int ammo)
{

	for (int i = 0; i < w.size(); i++)
	{
		switch (w[i]->getweaponID())
		{
		case LAZER:
			w[i]->draw(shiplaser[BLUE], shiplaser[YELLOW], shiplaser[RED]);
			break;
		case ICET:
			w[i]->draw(icet[0], icet[1]);
			break;
		case INFERRED:
			w[i]->draw(inferred[0], inferred[1]);
			break;
		case ZIGGONET:
			w[i]->draw(ziggonet, ziggonet);
			break;
		case HAYCH:
			w[i]->draw(haych[0], haych[1]);
			break;
		case HAYCHBA:
			w[i]->draw(haychba[0], haychba[1]);
			break;
		case SONICWAVE:
			w[i]->draw(sonic_wave, sonic_wave);
			break;
		}
	}

	
}

void weaponManager::renderweaponinbox(int ID, Status s, int ammo[7])
{
	switch (ID)
	{
	case LAZER:
		s.prime_Weapon_box(shiplaser[BLUE], font);
		break;
	case ICET:
		s.secondary_Weapon_box(icet[0], font, ammo[ICET]);
		break;
	case INFERRED:
		s.secondary_Weapon_box(inferred[0], font, ammo[INFERRED]);
		break;
	case ZIGGONET:
		s.secondary_Weapon_box(ziggonet, font, ammo[ZIGGONET]);
		break;
	case HAYCH:
		s.secondary_Weapon_box(haych[0], font, ammo[HAYCH]);
		break;
	case HAYCHBA:
		s.secondary_Weapon_box(haychba[0], font, ammo[HAYCHBA]);
		break;
	case SONICWAVE:
		s.secondary_Weapon_box(sonic_wave, font, ammo[SONICWAVE]);
		break;
	default:
		s.empty_Weapon_box(font, ammo[0]);
		break;
	}
}

void weaponManager::destroy_ammo(std::vector<Weapon*>& w)
{
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i]->gety() < 0)
		{
			w.erase(w.begin() + i);
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