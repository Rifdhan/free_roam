// Parser - Vehicles
// By David Cheung
// Performs all data parsing for vehicles


#ifndef PARSER_VEHICLE_H
#define PARSER_VEHICLE_H


#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#include <iostream>
#include "primitives.h"
#include "main.h"
#include "parser_helpers.h"
#include "Vehicle.h"

// Main parsing function
void parseAllVehicles();

// Helper function for parsing
void parseVehicle(std::ifstream& vehicleFile);

#endif // PARSER_VEHICLE_H
