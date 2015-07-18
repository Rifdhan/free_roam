// Parser - Pedestrian
// By David Cheung
// Performs all data parsing for pedestrians


#include "parser_pedestrians.h"


using namespace std;


// Main parsing function
void parseAllPed()
{

    // Open the map file
    ifstream pedFile("./data/pedestrian.xml", ifstream::in);
    
    // Stores the current line
    string line;
    
    // Loop through all lines of pedestrian file
    while(getline(pedFile, line))
    {
        // Check if the current line is blank
        if(isWhitespace(line)) continue;

        // This line must be a header, determine the header type
        if(isHeader(line, "pedestrian"))
        {   
            
            parsePed(pedFile);
            while(getline(pedFile,line))
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
            isFooter(line, "pedestrian");
        }
        else
        {
            Log::warning("Unrecognized entry in vehicle file: '" + line + "'");
        }
    }
    pedFile.close();
}    



void parsePed(ifstream& pedFile)
{
    // Parse the data about this pedestrian
    string line;
    
    getline(pedFile, line);
    pair<string, string> type = parseStringKeyValPair(line);
    
    getline(pedFile, line);
    pair<string, string> name = parseStringKeyValPair(line);
    
    getline(pedFile, line);
    pair<string, double> health = parseDoubleKeyValPair(line);
    
    getline(pedFile, line);
    pair<string, double> damage = parseDoubleKeyValPair(line);
    
    getline(pedFile, line);
    pair<string, double> mass = parseDoubleKeyValPair(line);
    
    
    // Create a new pedestrian object
    Pedestrian newPedestrian(name.second, type.second, health.second, damage.second, mass.second);
    
    // Add it to the list of pedestrians
    pedestrians[name.second] = newPedestrian;
}
