// StreetSegment
// By Rifdhan Nazeer
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

void draw()
{
    // Two lane road, one lane in each direction, yellow divider line between the lanes, sidewalk on either side
    // Should only need to use rectangle drawing functions (see graphics.h)
}
