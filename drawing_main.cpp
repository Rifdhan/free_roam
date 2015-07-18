// Drawing - Main
// By Rifdhan Nazeer and David Cheung
// Contains functions to draw major game objects


#include "drawing_main.h"


using namespace std;


// Draws the map
// By Rifdhan Nazeer and David Cheung
void drawMap()
{
    // Iterate through all street segments
    for(auto iter = streetSegments.begin(); iter != streetSegments.end(); iter++)
    {
        // Draw the current street segment
        //worldDrawRectCorners(const PointC& bottomLeft, const PointC& topRight, const bool& filled, const ColourRgb& colour);
        iter->second.draw();
    }
    
    // Iterate through all intersections
    for(auto iter = intersections.begin(); iter != intersections.end(); iter++)
    {
        // Draw the current intersection
        iter->second.draw();
    }
}

void drawPed()
{
    Pedestrian newPed = pedestrians["Joe"];
    newPed.setPos(PointC(50,50));
    newPed.draw();


}
