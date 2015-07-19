// Pedestrian
// By David Cheung
// Base class for pedestrians

#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <string>
#include "primitives.h"
#include "graphics.h"
#include <iostream>
#include <vector>
#include "main.h"
#include "drawing_main.h"
#include <cmath> 

class Pedestrian
{
protected:
	// General
	std::string name;
	std::string type;
	double health;
	double damage;	
    std::vector<int> checkPoints;
    unsigned currentCheckPoint;
    bool follow;
    
	// Physics
	double mass;
	PointC position;
	PointC velocity;


public:
	// Constructors/destructors
	Pedestrian();
	
	Pedestrian(const std::string& newName, const std::string& newType, const double& newHp, const double& newDmg, const double& newMass);

	virtual ~Pedestrian();
	
	
	// General

	void setHealth(const double& newHp);

	void setDamage(const double& newDmg);
	
	void setFollow(bool status);
	
	void addCheckPoint(int id);

	std::string getName();

	double getHealth();

	double getDamage();

    bool isAlive();



	// Physics
    
	double getMass();

	PointC getVelocity();

	void setVelocity(const PointC& newVelocity);
	
	PointC getPos();

    void setPos(PointC newPos);

	// Drawing pedestrian
	void draw();
	
	// Moving pedestrian
	void moveToPt();	
};


#endif // PEDESTRIAN_H
