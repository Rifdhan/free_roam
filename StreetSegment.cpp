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
// Two lane road, one lane in each direction, yellow divider line between the lanes, sidewalk on either side
// Should only need to use rectangle drawing functions (see graphics.h)
// By David Cheung
void StreetSegment::draw()
{
    const double roadWidth = 3.5;
    const double sidewalkWidth = 1.5;
    const double distFromIntersect = 3.5;
    const double laneDividerHeight = 0.4;
    const double laneDividerWidth = 0.3; // Half of lane divider width
    const double laneDividerFromIntersect = 4; // Distance lane divider is from intersection
    const ColourRgb laneColour = ColourRgb(1.0, 1.0, 1.0);
    const ColourRgb sidewalkColour = ColourRgb(0.80, 0.80, 0.80);
    const ColourRgb roadColour = ColourRgb(0.2, 0.2, 0.2);
    
    // Draw vertical street segment
    if(startIntersectionPosition.x == endIntersectionPosition.x)
    {  
        if(startIntersectionPosition.y < endIntersectionPosition.y) // bottom to top direction
        {
            // Road
            // Stop drawing before 3 meters before intersection
            // Width of each lane 3.5 meters 
            worldDrawRectCorners(PointC(startIntersectionPosition.x - roadWidth, startIntersectionPosition.y + distFromIntersect), 
                PointC(endIntersectionPosition.x + roadWidth, endIntersectionPosition.y - distFromIntersect), true, roadColour);
            
            // Left sidewalk width: 1.5 meters
            worldDrawRectCorners(PointC(startIntersectionPosition.x - roadWidth, startIntersectionPosition.y + distFromIntersect), 
                PointC(endIntersectionPosition.x - roadWidth - sidewalkWidth, endIntersectionPosition.y - distFromIntersect), true, sidewalkColour);
            // Right sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + roadWidth, startIntersectionPosition.y + distFromIntersect), 
                PointC(endIntersectionPosition.x + roadWidth + sidewalkWidth, endIntersectionPosition.y - distFromIntersect), true, sidewalkColour);          
            
            // Draw lane dividers 0.1 meters width, 0.4 meters height    
            for(int i = startIntersectionPosition.y + laneDividerFromIntersect; i < endIntersectionPosition.y - laneDividerFromIntersect; i++)
            {
                worldDrawRectCorners(PointC(startIntersectionPosition.x - laneDividerWidth, i), 
                    PointC(endIntersectionPosition.x + laneDividerWidth, i + laneDividerHeight), true, laneColour);    
            }    
                
        }
        else // opposite direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x - roadWidth, startIntersectionPosition.y - distFromIntersect), 
                PointC(endIntersectionPosition.x + roadWidth, endIntersectionPosition.y + distFromIntersect), true, roadColour);

            // Left sidewalk width: 1.5 meters
            worldDrawRectCorners(PointC(startIntersectionPosition.x - roadWidth, startIntersectionPosition.y - distFromIntersect), 
                PointC(endIntersectionPosition.x - roadWidth - sidewalkWidth, endIntersectionPosition.y + distFromIntersect), 
                true, sidewalkColour);
                
            // Right sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + roadWidth, startIntersectionPosition.y - distFromIntersect), 
                PointC(endIntersectionPosition.x + roadWidth + sidewalkWidth, endIntersectionPosition.y + distFromIntersect), 
                true, sidewalkColour);                
            
            // Draw lane dividers 0.1 meters width, 0.4 meters height    
            for(int i = startIntersectionPosition.y - laneDividerFromIntersect; i > endIntersectionPosition.y + laneDividerFromIntersect; i--)
            {
                worldDrawRectCorners(PointC(startIntersectionPosition.x + laneDividerWidth, i), 
                    PointC(endIntersectionPosition.x - laneDividerWidth, i + laneDividerHeight), true, laneColour);    
            }     
        }
    }
    else if(startIntersectionPosition.y == endIntersectionPosition.y) // Draw horizontal street segment
    {
        if(startIntersectionPosition.x < endIntersectionPosition.x) // left-to-right direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x + distFromIntersect, startIntersectionPosition.y - roadWidth), 
                PointC(endIntersectionPosition.x - distFromIntersect, endIntersectionPosition.y + roadWidth), true, roadColour);
            
            // Top sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + distFromIntersect, endIntersectionPosition.y + roadWidth + sidewalkWidth), 
                PointC(endIntersectionPosition.x - distFromIntersect, endIntersectionPosition.y + roadWidth), true, sidewalkColour);
            
            // Bottom sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x + distFromIntersect, startIntersectionPosition.y - roadWidth - sidewalkWidth), 
                PointC(endIntersectionPosition.x - distFromIntersect, startIntersectionPosition.y - roadWidth), true, sidewalkColour);        
                
            for(int j = startIntersectionPosition.x + laneDividerFromIntersect; j < endIntersectionPosition.x - laneDividerFromIntersect; j++)
            {
                worldDrawRectCorners(PointC(j, startIntersectionPosition.y - laneDividerWidth), 
                    PointC(j + laneDividerHeight, endIntersectionPosition.y + laneDividerWidth), true, laneColour); 
            }    
        }
        else // opposite direction
        {
            worldDrawRectCorners(PointC(startIntersectionPosition.x - distFromIntersect, startIntersectionPosition.y - roadWidth), 
                PointC(endIntersectionPosition.x + distFromIntersect, endIntersectionPosition.y + roadWidth), true, roadColour);
            
            // Top sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x - distFromIntersect, endIntersectionPosition.y + roadWidth + sidewalkWidth), 
                PointC(endIntersectionPosition.x + distFromIntersect, endIntersectionPosition.y + roadWidth), true, sidewalkColour);
            
            // Bottom sidewalk
            worldDrawRectCorners(PointC(startIntersectionPosition.x - distFromIntersect, startIntersectionPosition.y - roadWidth - sidewalkWidth), 
                PointC(endIntersectionPosition.x + distFromIntersect, startIntersectionPosition.y - roadWidth), true, sidewalkColour);
                
            for(int i = startIntersectionPosition.x - laneDividerFromIntersect; i > endIntersectionPosition.x + laneDividerFromIntersect; i--)
            {
                worldDrawRectCorners(PointC(i, startIntersectionPosition.y - laneDividerWidth), 
                    PointC(i + laneDividerHeight, endIntersectionPosition.y + laneDividerWidth), true, laneColour); 
            }                            
        } 
    }
    
}
