#include "Weapon.h"

// Initialize base weapon
WeaponBase::WeaponBase()
{
	damage = 8;
	velocity = 0;
	delay = 1;
}

WeaponBase::~WeaponBase()
{
	// Do nothing
}

void WeaponBase::draw()
{
	return;
}

void WeaponBase::drawBullet()
{
	return;
}

Pistol::Pistol()
{
		damage = 25;
		velocity = 20;
		delay = 1.5;
}

Pistol::~Pistol()
{
	// Do nothing
}

void Pistol::draw()
{

}

void Pistol::drawBullet()
{

}

MachineGun::MachineGun()
{
		damage = 25;
		velocity = 20;
		delay = 0.5;
}

MachineGun::~MachineGun()
{
	// Do nothing
}

void MachineGun::draw()
{

}

void MachineGun::drawBullet()
{

}

