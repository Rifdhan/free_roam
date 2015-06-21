// StreetSegment
// By Rifdhan Nazeer
// Contains information about a single street segment


#include "StreetSegment.h"


using namespace std;


// Constructors/destructors

StreetSegment::StreetSegment(const unsigned& newId)
{
    id = newId;
}

StreetSegment::~StreetSegment()
{
    // Nothing to do
}

// Intersection connections

void StreetSegment::setStartIntersectionId(const unsigned& newStartIntersectionId)
{
    startIntersectionId = newStartIntersectionId;
}

void StreetSegment::setEndIntersectionId(const unsigned& newEndIntersectionId)
{
    endIntersectionId = newEndIntersectionId;
}

unsigned StreetSegment::getStartIntersectionId()
{
    return startIntersectionId;
}

unsigned StreetSegment::getEndIntersectionId()
{
    return endIntersectionId;
}
