// Vehicle
// By Rifdhan Nazeer
// Base class for vehicles (non-instantiable)


#ifndef VEHICLE_H
#define	VEHICLE_H


#include <string>

#include "primitives.h"


// Types of vehicles
namespace VehicleType
{
    enum VehicleType {car_poor, car_average, car_luxury, car_super};
}


class Vehicle
{
protected:
    // General
    VehicleType::VehicleType type;
    std::string name;
    
    // Physics
    double mass;
    PointC position;
    PointC velocity;
    
public:
    // Constructors/destructors
    Vehicle();
    
    Vehicle(const VehicleType::VehicleType& newType, const std::string& newName, const double& newMass);
    
    virtual ~Vehicle();
    
    // General
    VehicleType::VehicleType getVehicleType();
    std::string getName();
    
    // Physics
    double getMass();
    
    // Drawing
    //virtual void draw() = 0;
    
};


#endif // VEHICLE_H
