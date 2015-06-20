// Vehicle
// By Rifdhan Nazeer
// Base class for vehicles (non-instantiable)


#include "Vehicle.h"


using namespace std;


// Constructors/destructors

Vehicle::Vehicle(const VehicleType::VehicleType& newType, const string& newName, const double& newMass)
{
    // Initialize provided data
    type = newType;
    name = newName;
    mass = newMass;
}

Vehicle::~Vehicle()
{
    // Nothing to do
}

// General

VehicleType::VehicleType Vehicle::getVehicleType()
{
    return type;
}

string Vehicle::getName()
{
    return name;
}

// Physics

double Vehicle::getMass()
{
    return mass;
}
