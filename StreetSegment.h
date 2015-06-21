// StreetSegment
// By Rifdhan Nazeer
// Contains information about a single street segment


#ifndef STREET_SEGMENT_H
#define	STREET_SEGMENT_H


#include "primitives.h"


class StreetSegment
{
protected:
    // General
    unsigned id;
    
    // Connected intersections
    unsigned startIntersectionId;
    unsigned endIntersectionId;
    
public:
    // Constructors/destructors
    StreetSegment(const unsigned& newId);
    ~StreetSegment();
    
    // Intersection connections
    void setStartIntersectionId(const unsigned& newStartIntersectionId);
    void setEndIntersectionId(const unsigned& newEndIntersectionId);
    unsigned getStartIntersectionId();
    unsigned getEndIntersectionId();
};


#endif // STREET_SEGMENT_H
