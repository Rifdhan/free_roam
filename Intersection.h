// Intersection
// By Rifdhan Nazeer and David Cheung
// Contains information about a single intersection


#ifndef INTERSECTION_H
#define	INTERSECTION_H


#include "primitives.h"
#include "graphics.h"

#define SIDEWALK_WIDTH 1.6
#define INTERSECTION_WIDTH 7.0
#define HALF_INTERSECTION 3.5
#define CROSSWALK_BORDER 0.3
#define CROSSWALK_WIDTH 1.6
#define CROSSWALK_LINES_WIDTH 0.3 

class Intersection
{
private:
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
    
    // Drawing
    void draw();
};


#endif // INTERSECTION_H
