// Parser - Map
// By Rifdhan Nazeer
// Performs all data parsing for the map


#include "parser_map.h"


using namespace std;


// Parses all map data
// By Rifdhan Nazeer
void parseMapData()
{
    // Open the map file
    ifstream mapFile("./data/map.xml", ifstream::in);
    
    // Stores the current line
    string line;
    
    // Loop through all lines of map file
    while(getline(mapFile, line))
    {
        // Check if the current line is blank
        if(isWhitespace(line)) continue;
        
        // This line must be a header, determine the header type
        if(isHeader(line, "intersection"))
        {
            parseIntersection(mapFile);
        }
        else if(isHeader(line, "road"))
        {
            parseStreetSegment(mapFile);
        }
        else
        {
            Log::warning("Unrecognized entry in map file: '" + line + "'");
        }
    }
}

// Parses a single intersection
// By Rifdhan Nazeer
void parseIntersection(ifstream& mapFile)
{
    // Parse the data about this intersection
    string line;
    
    getline(mapFile, line);
    pair<string, unsigned> id = parseUnsignedKeyValPair(line);
    
    getline(mapFile, line);
    pair<string, double> positionX = parseDoubleKeyValPair(line);
    
    getline(mapFile, line);
    pair<string, double> positionY = parseDoubleKeyValPair(line);
    
    // Create a new Intersection object
    Intersection newIntersection(id.second, PointC(positionX.second, positionY.second));
    
    // Add it to the list of intersections
    intersections[id.second] = newIntersection;
}

// Parses a single street segment
// By David Cheung
void parseStreetSegment(ifstream& mapFile)
{
    // Parse the data about this street segment
    string line;
    
    getline(mapFile, line);
    pair<string, unsigned> id = parseUnsignedKeyValPair(line);
    
    getline(mapFile, line);
    pair<string, unsigned> startIntersection = parseUnsignedKeyValPair(line);
    
    getline(mapFile, line);
    pair<string, unsigned> endIntersection = parseUnsignedKeyValPair(line);
    
    // Create a new StreetSegment object
    StreetSegment newStreetSegment(id.second);
    
    // Set starting intersection ID and position
    newStreetSegment.setStartIntersectionId(startIntersection.second, intersections.at(startIntersection.second).getPosition());
    
    // Set ending intersection ID and position
    newStreetSegment.setEndIntersectionId(endIntersection.second, intersections.at(endIntersection.second).getPosition());
    
    // Add it to the list of street segments
    streetSegments[id.second] = newStreetSegment;
}
