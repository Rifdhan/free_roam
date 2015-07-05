// Parser - Vehicles
// By David Cheung
// Performs all data parsing for vehicles


#include "parser_vehicles.h"


using namespace std;


// Main parsing function
void parseAllVehicles()
{
    // Open the map file
    ifstream vehicleFile("./data/vehicles.xml", ifstream::in);
    
    // Stores the current line
    string line;
    
    // Loop through all lines of vehicle file
    while(getline(vehicleFile, line))
    {
        // Check if the current line is blank
        if(isWhitespace(line)) continue;
        
        // This line must be a header, determine the header type
        if(isHeader(line, "vehicle"))
        {
            //parseVehicle(vehicleFile);
            while(getline(vehicleFile,line))
            {
                if(isWhitespace(line)) 
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            isFooter(line, "vehicle");
        }
        else
        {
            Log::warning("Unrecognized entry in vehicle file: '" + line + "'");
        }
    }
    vehicleFile.close();
}    



void parseVehicle(ifstream& vehicleFile)
{
    // Parse the data about this vehicle
    string line;
    
    getline(vehicleFile, line);
    pair<string, string> type = parseStringKeyValPair(line);
    
    getline(vehicleFile, line);
    pair<string, string> name = parseStringKeyValPair(line);
    
    getline(vehicleFile, line);
    pair<string, double> width = parseDoubleKeyValPair(line);
    
    getline(vehicleFile, line);
    pair<string, double> height = parseDoubleKeyValPair(line);
    
    getline(vehicleFile, line);
    pair<string, double> mass = parseDoubleKeyValPair(line);
    
    VehicleType::VehicleType typeName;
    
    // Check for enum type
    if(type.second == "car_poor")
    {
        typeName = VehicleType::car_poor;
    }
    else if(type.second == "car_average")
    {
        typeName = VehicleType::car_average;    
    }
    else if(type.second == "car_luxury")
    {
       typeName = VehicleType::car_luxury; 
    }
    else if(type.second == "car_super")
    {
        typeName = VehicleType::car_super;
    }
    else
    {
        Log::warning("Unrecognized vehicle type in vehicle file: '" + type.second + "'");
    }
    
    // Create a new Intersection object
    Vehicle newVehicle(typeName, name.second, mass.second);
    
    // Add it to the list of vehicles
    vehicles[name.second] = newVehicle;
}
