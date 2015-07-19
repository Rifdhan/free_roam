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
	currentCheckPoint = 0;
	follow = false;
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

void Pedestrian::setFollow(bool status)
{
	follow = status;
}

void Pedestrian::addCheckPoint(int id)
{
    checkPoints.push_back(id);
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

bool Pedestrian::isAlive()
{
    return (health > 0) ? true : false;
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


// Drawing pedestrian
// By David Cheung
void Pedestrian::draw()
{
    if(!isAlive())
    {
        return;
    }
    
    //std::cout << type << std::endl;
    if(type == "normal")
    {
        // Character initially positioned facing up
        // Draw Head
        worldDrawCircle(PointC(position.x, position.y), 2.0, false, ColourRgb(0.0, 1.0, 0.0));
    
        // Draw Eyes
        worldDrawCircle(PointC(position.x - 1.0, position.y + 0.3), 0.3, false, ColourRgb(0.0, 1.0, 0.0));
        worldDrawCircle(PointC(position.x + 1.0, position.y + 0.3), 0.3, false, ColourRgb(0.0, 1.0, 0.0));
   
        // Hands
        worldDrawCircle(PointC(position.x + 2.5, position.y + 0.5), 0.5, false, ColourRgb(0.0, 1.0, 0.0));
        worldDrawCircle(PointC(position.x - 2.5, position.y + 0.5), 0.5, false, ColourRgb(0.0, 1.0, 0.0));
    }
    else if(type == "thug")
    {
        // Character initially positioned facing up
        // Draw Head
        worldDrawCircle(PointC(position.x, position.y), 2.0, false, ColourRgb(1.0, 0.0, 0.1));
    
        // Draw Eyes
        worldDrawRectCentered(PointC(position.x - 1.0, position.y + 0.3), PointC(0.8, 0.5), true, ColourRgb(1.0, 0.0, 0.1));
        worldDrawRectCentered(PointC(position.x + 1.0, position.y + 0.3), PointC(0.8,0.5), true, ColourRgb(1.0, 0.0, 0.1));
   
        // Hands
        worldDrawCircle(PointC(position.x + 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));
        worldDrawCircle(PointC(position.x - 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));    
    }
    else if(type == "police")
    {
        // Character initially positioned facing up
        // Draw Head
        worldDrawCircle(PointC(position.x, position.y), 2.0, false, ColourRgb(1.0, 0.0, 0.1));
    
        // Draw Eyes
        worldDrawRectCentered(PointC(position.x - 1.0, position.y + 0.3), PointC(1.0, 0.6), true, ColourRgb(1.0, 0.0, 0.0));
        worldDrawRectCentered(PointC(position.x + 1.0, position.y + 0.3), PointC(1.0, 0.6), true, ColourRgb(0.0, 0.0, 1.0));
   
        // Hands
        worldDrawCircle(PointC(position.x + 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));
        worldDrawCircle(PointC(position.x - 2.5, position.y + 0.5), 0.5, false, ColourRgb(0, 0.9, 0.1));    
    }
}


// Moving to checkpoints
// By David Cheung
void Pedestrian::moveToPt()
{ 
            PointC coord;
            
            if(follow == false)
            {              
                    // No checkpoints
                if(checkPoints.size() == 0)
                {
                    return;
                }
    
                // Reached last checkpoint
                if(currentCheckPoint == checkPoints.size())
                {
                    currentCheckPoint = 0;
                }
                 coord = intersections[checkPoints[currentCheckPoint]].getPosition();
            }
            else
            {
                coord = player.getPosition();
                coord.x += 1;
                coord.y += 1;
            }
            
            if(position.x < coord.x)
            {
                position.x += 0.1;
               
            }
            
            if(position.y < coord.y)
            {
                position.y += 0.1;
            }
            
            if(position.x > coord.x)
            {
                position.x -= 0.1;    
            }
                      
            if(position.y > coord.y)
            {
                position.y -= 0.1;
            }
            
            // Checkpoint reached, proceed to next checkpoint
            if(abs(position.x - coord.x) < 0.2 && abs(position.y - coord.y) < 0.2 && follow == false)
            {
                currentCheckPoint++;
            }
}
