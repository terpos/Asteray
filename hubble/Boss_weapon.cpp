#include "Boss_weapon.h"


//initial variable assignment
Boss_weapon::Boss_weapon(int x, int y, int vel, int cid)
{
}


Boss_weapon::~Boss_weapon()
{
}

//returns x coordiate
int Boss_weapon::get_x()
{
	return 0;
}

//returns y coordinate
int Boss_weapon::get_y()
{
	return 0;
}

//returns radius of the circle
int Boss_weapon::get_r()
{
	return 0;
}

//returns speed
int Boss_weapon::get_vel()
{
	return 0;
}

//returns direction
int Boss_weapon::get_coord_ID()
{
	return 0;
}

//returns whether the weapon is shot or not
bool Boss_weapon::isshot()
{
	return false;
}

//returns weapon type
int Boss_weapon::get_kinds_of_weapon()
{
	return 0;
}

//returns whether the weapon is reflected or not
bool Boss_weapon::isreflected()
{
	return false;
}

//sets x coordinate
void Boss_weapon::set_x(int x)
{
}

//sets y coordinate
void Boss_weapon::set_y(int y)
{
}

//sets speed
void Boss_weapon::set_vel(int vel)
{
}

//sets direction
void Boss_weapon::set_coord_ID(int cid)
{
}

//sets the ability to shoot
void Boss_weapon::set_shot(bool isshot)
{
}

//sets the ability to be reflective when shot
void Boss_weapon::set_reflect(bool isreflected)
{
}

//the radius increase
void Boss_weapon::grow_heat(int x, int y)
{
}

//updates the ball being shot
void Boss_weapon::shootball()
{
}

//updates reflection
void Boss_weapon::reflect()
{
}
