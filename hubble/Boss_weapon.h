/*
This class is a polymorphic class that uses virtual function.
All classes that inherit this class use the same function(s).
*/

#pragma once
class Boss_weapon
{
public:
	//initial variable decleration
	Boss_weapon(int x, int y, int vel, int cid);

	~Boss_weapon();

	//returns x coordiate
	virtual int get_x();

	//returns y coordinate
	virtual int get_y();

	//returns radius of the circle
	//[classes that uses this function: heat wave]
	virtual int get_r();

	//returns speed
	virtual int get_vel();

	//returns direction
	virtual int get_coord_ID();

	//returns whether the weapon is shot or not
	virtual bool isshot();

	//returns weapon type
	virtual int get_kinds_of_weapon();

	//returns whether the weapon is reflected or not
	virtual bool isreflected();

	//sets x coordinate
	virtual void set_x(int x);

	//sets y coordinate
	virtual void set_y(int y);

	//sets speed
	virtual void set_vel(int vel);

	//sets direction
	virtual void set_coord_ID(int cid);

	//sets the ability to shoot
	virtual void set_shot(bool isshot);

	//sets the ability to be reflective when shot
	//[classes that uses this function: spartak ball]
	virtual void set_reflect(bool isreflected);

	//the radius increase
	//[classes that uses this function: heat wave]
	virtual void grow_heat(int x, int y);

	//updates the ball being shot
	virtual void shootball();

	//updates reflection
	//[classes that uses this function: spartak ball]
	virtual void reflect();


private:
	//int variables
	int x, y, vel, cid;

	//boolean variables 
	bool reflected, shot;
};

