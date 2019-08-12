#pragma once
class Boss_weapon
{
public:
	Boss_weapon(int x, int y, int vel, int cid);
	~Boss_weapon();



	virtual int get_x();
	virtual int get_y();
	virtual int get_r();
	virtual int get_vel();
	virtual int get_coord_ID();
	virtual bool isshot();
	virtual int get_kinds_of_weapon();
	virtual bool isreflected();


	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_coord_ID(int cid);
	virtual void set_shot(bool isshot);
	virtual void set_reflect(bool isreflected);

	virtual void grow_heat(int x, int y);


	virtual void shootball();
	virtual void reflect();


private:
	int x, y, vel, cid;
	bool reflected, shot;
};

