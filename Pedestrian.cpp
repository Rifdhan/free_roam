// Pedestrian
// By David Cheung
// Base class for pedestrians

#include "Pedestrian.h"

using namespace std;


// Constructors/destructors
Pedestrian::Pedestrian()
{

}


	
Pedestrian::Pedestrian(const std::string& newName, const std::string& newType, const double& newHp, const double& newDmg, const double& newMass)
{
	name = newName;
	health = newHp;
	damage = newDmg;
	mass = newMass;
	type = newType;
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

PointC Pedestrian::getPos()
{
    return position;
}

void Pedestrian::setPos(PointC newPos)
{
     position = newPos;
}

// drawing pedestrian
void Pedestrian::draw()
{
    //std::cout << type << std::endl;
    if(type == "normal")
    {
        // Character initially positioned facing up
        // Draw Head
        worldDrawCircle(PointC(position.x, position.y), 2.0, false, ColourRgb(1.0, 0.0, 0.1));
    
        // Draw Eyes
        worldDrawCircle(PointC(position.x - 1.0, position.y + 0.3), 0.3, false, ColourRgb(0, 0.9, 0.1));
        worldDrawCircle(PointC(position.x + 1.0, position.y + 0.3), 0.3, false, ColourRgb(0, 0.9, 0.1));
   
        // Hands
        worldDrawCircle(PointC(position.x + 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));
        worldDrawCircle(PointC(position.x - 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));
    }
}
