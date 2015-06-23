// Intersection
// By Rifdhan Nazeer
// Contains information about a single intersection


#ifndef INTERSECTION_H
#define	INTERSECTION_H


#include "primitives.h"


class Intersection
{
protected:
    // General
    unsigned id;
    PointC position;
    
    // Connected streets
    unsigned nConnectedStreetSegments;
    unsigned rightStreetSegmentId;
    unsigned topStreetSegmentId;
    unsigned leftStreetSegmentId;
    unsigned bottomStreetSegmentId;
    
public:
    // Constructors/destructors
    Intersection();
    Intersection(const unsigned& newId, const PointC& newPosition);
    Intersection(const Intersection& original);
    ~Intersection();
    
    // General
    unsigned getId();
    PointC getPosition();
    
    // Street connections
    void setRightStreetSegmentId(const unsigned& newRightStreetSegmentId);
    void setTopStreetSegmentId(const unsigned& newTopStreetSegmentId);
    void setLeftStreetSegmentId(const unsigned& newLeftStreetSegmentId);
    void setBottomStreetSegmentId(const unsigned& newBottomStreetSegmentId);
    unsigned getRightStreetSegmentId();
    unsigned getTopStreetSegmentId();
    unsigned getLeftStreetSegmentId();
    unsigned getBottomStreetSegmentId();
};


#endif // INTERSECTION_H
