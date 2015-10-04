class WeaponBase
{
protected:
	int damage;
	int velocity;
	double delay;
	int startX;
	int startY;
	int targetX;
	int targetY;
	
public:
	// Constructor/Destructor
	WeaponBase();
	~WeaponBase();
	
	// Base draw weapon function
	virtual void draw();
	
	// Base draw bullet function
	virtual void drawBullet();
};

class Pistol : public WeaponBase
{
	Pistol();
	~Pistol();
	
	void draw();
	void drawBullet();
};

class MachineGun : public WeaponBase
{
	MachineGun();
	~MachineGun();
	
	void draw();
	void drawBullet();
};
