// Pedestrian
// By David Cheung
// Base class for pedestrians

#include "Pedestrian.h"

using namespace std;


// Constructors/destructors
Pedestrian::Pedestrian()
{

}


	
Pedestrian::Pedestrian(const std::string& newName, const double& newHp, const double& newDmg, const double& newMass)
{
	name = newName;
	health = newHp;
	damage = newDmg;
	mass = newMass;
}

Pedestrian::~Pedestrian()
{
    // Do nothing
}


// General	

void Pedestrian::setHealth(const double& newHp)
{
	health = newHp;
}

void Pedestrian::setDamage(const double& newDmg)
{
	damage = newDmg;
}

std::string Pedestrian::getName()
{
	return name;
}

double Pedestrian::getHealth()
{
	return health;
}

double Pedestrian::getDamage()
{
	return damage;
}


// Physics

double Pedestrian::getMass()
{
	return mass;
}

PointC Pedestrian::getVelocity()
{
	return velocity;
}

void Pedestrian::setVelocity(const PointC& newVelocity)
{
	velocity = newVelocity;
}

// drawing pedestrian
void Pedestrian::draw()
{

}
