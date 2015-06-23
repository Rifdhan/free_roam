// Drawing - Main
// By Rifdhan Nazeer
// Contains functions to draw major game objects


#include "drawing_main.h"


using namespace std;


// Draws the map
// By Rifdhan Nazeer
void drawMap()
{
    // Iterate through all intersections
    for(auto iter = intersections.begin(); iter != intersections.end(); iter++)
    {
        // Draw the current intersection
        worldDrawCircle(iter->second.getPosition(), 10.0, true, ColourRgb(0.5, 0.5, 0.5));
    }
    
    // Iterate through all street segments
    for(auto iter = streetSegments.begin(); iter != streetSegments.end(); iter++)
    {
        // Draw the current street segment
        //worldDrawRectCorners(const PointC& bottomLeft, const PointC& topRight, const bool& filled, const ColourRgb& colour);
    }
}
