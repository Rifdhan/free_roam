// Parser - Map
// By Rifdhan Nazeer and David Cheung
// Performs all data parsing for the map


#include "parser_map.h"


using namespace std;


// Parses all map data
// By Rifdhan Nazeer and David Cheung
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
            while(getline(mapFile,line))
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
            isFooter(line, "intersection");
        }
        else if(isHeader(line, "road"))
        {
            parseStreetSegment(mapFile);
            while(getline(mapFile,line))
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
            isFooter(line, "road");
        }
        else
        {
            Log::warning("Unrecognized entry in map file: '" + line + "'");
        }
    }
    mapFile.close();
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
    
    const PointC start = intersections.at(startIntersection.second).getPosition();
    const PointC end = intersections.at(endIntersection.second).getPosition();
    
    // Set starting intersection ID and position
    newStreetSegment.setStartIntersectionId(startIntersection.second, start);
    
    // Set ending intersection ID and position
    newStreetSegment.setEndIntersectionId(endIntersection.second, end);
    
    // Update intersection with the connected street segment (top, bottom, left, right)
    if (start.x == end.x) // Vertical separation between intersections
    {
        if (start.y < end.y)
        {
            intersections.at(startIntersection.second).setTopStreetSegmentId(id.second);
            intersections.at(endIntersection.second).setBottomStreetSegmentId(id.second);   
        }
        else
        {
            intersections.at(endIntersection.second).setTopStreetSegmentId(id.second);
            intersections.at(startIntersection.second).setBottomStreetSegmentId(id.second);        
        }
    }
    else // Horizontal separation between intersections
    {
        if (start.x < end.x)
        {
            intersections.at(startIntersection.second).setRightStreetSegmentId(id.second);
            intersections.at(endIntersection.second).setLeftStreetSegmentId(id.second);   
        }
        else
        {
            intersections.at(endIntersection.second).setRightStreetSegmentId(id.second);
            intersections.at(startIntersection.second).setLeftStreetSegmentId(id.second);        
        }    
    }   
    
    // Add it to the list of street segments
    streetSegments[id.second] = newStreetSegment;
}
