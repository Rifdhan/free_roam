// StreetSegment
// By Rifdhan Nazeer and David Cheung
// Contains information about a single street segment


#include "StreetSegment.h"


using namespace std;


// Constructors/destructors

StreetSegment::StreetSegment()
{
    id = INVALID_ID;
}
   
StreetSegment::StreetSegment(const unsigned& newId)
{
    id = newId;
}
 
StreetSegment::~StreetSegment()
{
    // Do nothing
}

// Intersection connections

void StreetSegment::setStartIntersectionId(const unsigned& newStartIntersectionId, const PointC& newStartIntersectionPosition)
{
    startIntersectionId = newStartIntersectionId;
    startIntersectionPosition = newStartIntersectionPosition;
}

void StreetSegment::setEndIntersectionId(const unsigned& newEndIntersectionId, const PointC& newEndIntersectionPosition)
{
    endIntersectionId = newEndIntersectionId;
    endIntersectionPosition = newEndIntersectionPosition;
}

unsigned StreetSegment::getStartIntersectionId()
{
    return startIntersectionId;
}

PointC StreetSegment::getStartIntersectionPosition()
{
    return startIntersectionPosition;
}

unsigned StreetSegment::getEndIntersectionId()
{
    return endIntersectionId;
}

PointC StreetSegment::getEndIntersectionPosition()
{
    return endIntersectionPosition;
}

// Drawing
// By David Cheung
// Two lane road, one lane in each direction, yellow divider line between the lanes, sidewalk on either side
// Should only need to use rectangle drawing functions (see graphics.h)
void StreetSegment::draw()
{   
    // Draw vertical street segment
    if(startIntersectionPosition.x == endIntersectionPosition.x)
    {  
        if(startIntersectionPosition.y < endIntersectionPosition.y) // bottom to top direction
        {
            // Road
            // Stop drawing before 3 meters before intersection
            // Width of each lane 3.5 meters 
            worldDrawRectCorners(PointC(startIntersectionPosition.x - ROAD_WIDTH, startIntersectionPosition.y + DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x + ROAD_WIDTH, endIntersectionPosition.y - DIST_FROM_INTERSECT), true, ROAD_COLOUR);
            
            // Left sidewalk width: 1.5 meters
            worldDrawRectCorners(PointC(startIntersectionPosition.x - ROAD_WIDTH, startIntersectionPosition.y + DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x - ROAD_WIDTH - SIDEWALK_WIDTH, endIntersectionPosition.y - DIST_FROM_INTERSECT), true, SIDEWALK_COLOUR);
            // Right sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + ROAD_WIDTH, startIntersectionPosition.y + DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x + ROAD_WIDTH + SIDEWALK_WIDTH, endIntersectionPosition.y - DIST_FROM_INTERSECT), true, SIDEWALK_COLOUR);          
            
            // Draw lane dividers 0.1 meters width, 0.4 meters height    
            for(int i = startIntersectionPosition.y + LANE_DIVIDER_FROM_INTERSECT + 1; i < endIntersectionPosition.y - LANE_DIVIDER_FROM_INTERSECT; i++)
            {
                worldDrawRectCorners(PointC(startIntersectionPosition.x - LANE_DIVIDER_WIDTH, i), 
                    PointC(endIntersectionPosition.x + LANE_DIVIDER_WIDTH, i + LANE_DIVIDER_HEIGHT), true, LANE_COLOUR);    
            }    
                
        }
        else // opposite direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x - ROAD_WIDTH, startIntersectionPosition.y - DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x + ROAD_WIDTH, endIntersectionPosition.y + DIST_FROM_INTERSECT), true, ROAD_COLOUR);

            // Left sidewalk width: 1.5 meters
            worldDrawRectCorners(PointC(startIntersectionPosition.x - ROAD_WIDTH, startIntersectionPosition.y - DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x - ROAD_WIDTH - SIDEWALK_WIDTH, endIntersectionPosition.y + DIST_FROM_INTERSECT), 
                true, SIDEWALK_COLOUR);
                
            // Right sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + ROAD_WIDTH, startIntersectionPosition.y - DIST_FROM_INTERSECT), 
                PointC(endIntersectionPosition.x + ROAD_WIDTH + SIDEWALK_WIDTH, endIntersectionPosition.y + DIST_FROM_INTERSECT), 
                true, SIDEWALK_COLOUR);                
            
            // Draw lane dividers 0.1 meters width, 0.4 meters height    
            for(int i = startIntersectionPosition.y - LANE_DIVIDER_FROM_INTERSECT - 1; i > endIntersectionPosition.y + LANE_DIVIDER_FROM_INTERSECT; i--)
            {
                worldDrawRectCorners(PointC(startIntersectionPosition.x + LANE_DIVIDER_WIDTH, i), 
                    PointC(endIntersectionPosition.x - LANE_DIVIDER_WIDTH, i + LANE_DIVIDER_HEIGHT), true, LANE_COLOUR);    
            }     
        }
    }
    else if(startIntersectionPosition.y == endIntersectionPosition.y) // Draw horizontal street segment
    {
        if(startIntersectionPosition.x < endIntersectionPosition.x) // left-to-right direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x + DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH), 
                PointC(endIntersectionPosition.x - DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH), true, ROAD_COLOUR);
            
            // Top sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH + SIDEWALK_WIDTH), 
                PointC(endIntersectionPosition.x - DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH), true, SIDEWALK_COLOUR);
            
            // Bottom sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH - SIDEWALK_WIDTH), 
                PointC(endIntersectionPosition.x - DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH), true, SIDEWALK_COLOUR);        
                
            for(int j = startIntersectionPosition.x + LANE_DIVIDER_FROM_INTERSECT + 1; j < endIntersectionPosition.x - LANE_DIVIDER_FROM_INTERSECT; j++)
            {
                worldDrawRectCorners(PointC(j, startIntersectionPosition.y - LANE_DIVIDER_WIDTH), 
                    PointC(j + LANE_DIVIDER_HEIGHT, endIntersectionPosition.y + LANE_DIVIDER_WIDTH), true, LANE_COLOUR); 
            }    
        }
        else // opposite direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x - DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH), 
                PointC(endIntersectionPosition.x + DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH), true, ROAD_COLOUR);
            
            // Top sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x - DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH + SIDEWALK_WIDTH), 
                PointC(endIntersectionPosition.x + DIST_FROM_INTERSECT, endIntersectionPosition.y + ROAD_WIDTH), true, SIDEWALK_COLOUR);
            
            // Bottom sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x - DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH - SIDEWALK_WIDTH), 
                PointC(endIntersectionPosition.x + DIST_FROM_INTERSECT, startIntersectionPosition.y - ROAD_WIDTH), true, SIDEWALK_COLOUR);
                
            for(int i = startIntersectionPosition.x - LANE_DIVIDER_FROM_INTERSECT - 1; i > endIntersectionPosition.x + LANE_DIVIDER_FROM_INTERSECT; i--)
            {
                worldDrawRectCorners(PointC(i, startIntersectionPosition.y - LANE_DIVIDER_WIDTH), 
                    PointC(i + LANE_DIVIDER_HEIGHT, endIntersectionPosition.y + LANE_DIVIDER_WIDTH), true, LANE_COLOUR); 
            }                            
        } 
    }
    
}
