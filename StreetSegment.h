// StreetSegment
// By Rifdhan Nazeer
// Contains information about a single street segment


#ifndef STREET_SEGMENT_H
#define	STREET_SEGMENT_H


#include "primitives.h"


class StreetSegment
{
private:
    // General
    unsigned id;
    
    // Connected intersections
    unsigned startIntersectionId;
    PointC startIntersectionPosition;
    unsigned endIntersectionId;
    PointC endIntersectionPosition;
    
public:
    // Constructors/destructors
    StreetSegment();
    StreetSegment(const unsigned& newId);
    ~StreetSegment();
    
    // Intersection connections
    void setStartIntersectionId(const unsigned& newStartIntersectionId, const PointC& newStartIntersectionPosition);
    void setEndIntersectionId(const unsigned& newEndIntersectionId, const PointC& newEndIntersectionPosition);
    unsigned getStartIntersectionId();
    PointC getStartIntersectionPosition();
    unsigned getEndIntersectionId();
    PointC getEndIntersectionPosition();
    
    // Drawing
    void draw();
};


#endif // STREET_SEGMENT_H
