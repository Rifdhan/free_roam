// Intersection
// By Rifdhan Nazeer and David Cheung
// Contains information about a single intersection


#include "Intersection.h"
#include "climits"

using namespace std;


// Constructors/destructors

Intersection::Intersection()
{
    id = INVALID_ID;
}

Intersection::Intersection(const unsigned& newId, const PointC& newPosition)
{
    id = newId;
    position = newPosition;
    nConnectedStreetSegments = 0;
    rightStreetSegmentId = INT_MAX;
    topStreetSegmentId = INT_MAX;
    leftStreetSegmentId = INT_MAX;
    bottomStreetSegmentId = INT_MAX;
}

Intersection::Intersection(const Intersection& original)
{
    id = original.id;
    position = original.position;
    nConnectedStreetSegments = original.nConnectedStreetSegments;
    rightStreetSegmentId = original.rightStreetSegmentId;
    topStreetSegmentId = original.topStreetSegmentId;
    leftStreetSegmentId = original.leftStreetSegmentId;
    bottomStreetSegmentId = original.bottomStreetSegmentId;
}

Intersection::~Intersection()
{
    // Nothing to do
}

// General

unsigned Intersection::getId()
{
    return id;
}

PointC Intersection::getPosition()
{
    return position;
}

// Add a street connection

void Intersection::setRightStreetSegmentId(const unsigned& newRightStreetSegmentId)
{
    rightStreetSegmentId = newRightStreetSegmentId;
    nConnectedStreetSegments++;
}

void Intersection::setTopStreetSegmentId(const unsigned& newTopStreetSegmentId)
{
    topStreetSegmentId = newTopStreetSegmentId;
    nConnectedStreetSegments++;
}

void Intersection::setLeftStreetSegmentId(const unsigned& newLeftStreetSegmentId)
{
    leftStreetSegmentId = newLeftStreetSegmentId;
    nConnectedStreetSegments++;
}

void Intersection::setBottomStreetSegmentId(const unsigned& newBottomStreetSegmentId)
{
    bottomStreetSegmentId = newBottomStreetSegmentId;
    nConnectedStreetSegments++;
}

unsigned Intersection::getRightStreetSegmentId()
{
    return rightStreetSegmentId;
}

unsigned Intersection::getTopStreetSegmentId()
{
    return topStreetSegmentId;
}

unsigned Intersection::getLeftStreetSegmentId()
{
    return leftStreetSegmentId;
}

unsigned Intersection::getBottomStreetSegmentId()
{
    return bottomStreetSegmentId;
}

// Draw
// By David Cheung
// Draws the intersection connecting the street segments.
void Intersection::draw()
{
        worldDrawRectCentered(position, PointC(INTERSECTION_WIDTH, INTERSECTION_WIDTH), true, ColourRgb(0.2, 0.2, 0.2));
        
        // Draw left sidewalk for intersection
        if (leftStreetSegmentId == INT_MAX)
        {
           worldDrawRectCorners(PointC(position.x - HALF_INTERSECTION - SIDEWALK_WIDTH, position.y - HALF_INTERSECTION - SIDEWALK_WIDTH), 
                PointC(position.x - HALF_INTERSECTION, position.y + HALF_INTERSECTION + SIDEWALK_WIDTH), true, ColourRgb(0.80, 0.80, 0.80));            
        }
        
        // Draw right sidewalk for intersection
        if (rightStreetSegmentId == INT_MAX)
        {
           worldDrawRectCorners(PointC(position.x + HALF_INTERSECTION + SIDEWALK_WIDTH, position.y - HALF_INTERSECTION - SIDEWALK_WIDTH), 
                PointC(position.x + HALF_INTERSECTION, position.y + HALF_INTERSECTION + SIDEWALK_WIDTH), true, ColourRgb(0.80, 0.80, 0.80));                      
        }
        
        // Draw top sidewalk for intersection
        if (topStreetSegmentId == INT_MAX)
        {
           worldDrawRectCorners(PointC(position.x - HALF_INTERSECTION, position.y + HALF_INTERSECTION), 
                PointC(position.x + HALF_INTERSECTION, position.y + HALF_INTERSECTION + SIDEWALK_WIDTH), true, ColourRgb(0.80, 0.80, 0.80));                      
        }
        
        // Draw bottom sidewalk for intersection
        if (bottomStreetSegmentId == INT_MAX)
        {
           worldDrawRectCorners(PointC(position.x - HALF_INTERSECTION, position.y - HALF_INTERSECTION - SIDEWALK_WIDTH), 
                PointC(position.x + HALF_INTERSECTION, position.y - HALF_INTERSECTION), true, ColourRgb(0.80, 0.80, 0.80));                      
        }
        
}
