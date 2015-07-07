// Pedestrian
// By David Cheung
// Base class for pedestrians

#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <string>
#include "primitives.h"

class Pedestrian
{
protected:
	// General
	std::string name;
	double health;
	double damage;	

	// Physics
	double mass;
	PointC position;
	PointC velocity;


public:
	// Constructors/destructors
	Pedestrian();
	
	Pedestrian(const std::string& newName, const double& newHp, const double& newDmg, const double& newMass);

	virtual ~Pedestrian();
	
	
	// General

	void setHealth(const double& newHp);

	void setDamage(const double& newDmg);

	std::string getName();

	double getHealth();

	double getDamage();


	// Physics

	double getMass();

	PointC getVelocity();

	void setVelocity(const PointC& newVelocity);


	// drawing pedestrian
	void draw();
};


#endif // PEDESTRIAN_H
