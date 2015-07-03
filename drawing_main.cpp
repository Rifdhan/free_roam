// Drawing - Main
// By Rifdhan Nazeer and David Cheung
// Contains functions to draw major game objects


#include "drawing_main.h"


using namespace std;


// Draws the map
// By Rifdhan Nazeer and David Cheung
void drawMap()
{
    // Iterate through all intersections
    for(auto iter = intersections.begin(); iter != intersections.end(); iter++)
    {
        // Draw the current intersection
        worldDrawCircle(iter->second.getPosition(), 5.0, false, ColourRgb(0.5, 0.5, 0.5));
        //worldDrawRectCentered(iter->second.getPosition(), PointC(9.0, 9.0), true, ColourRgb(0.5, 0.5, 0.5));
    }
    
    // Iterate through all street segments
    for(auto iter = streetSegments.begin(); iter != streetSegments.end(); iter++)
    {
        // Draw the current street segment
        //worldDrawRectCorners(const PointC& bottomLeft, const PointC& topRight, const bool& filled, const ColourRgb& colour);
        iter->second.draw();
        //worldDrawRectCorners(iter->second.getStartIntersectionPosition(), iter->second.getEndIntersectionPosition(), false, ColourRgb(0.5,0.2,0.2));
    }
}
