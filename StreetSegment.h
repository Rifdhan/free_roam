// StreetSegment
// By Rifdhan Nazeer and David Cheung
// Contains information about a single street segment


#ifndef STREET_SEGMENT_H
#define	STREET_SEGMENT_H


#include "primitives.h"
#include "graphics.h"

// Draw street segment constants
#define ROAD_WIDTH 3.5
#define SIDEWALK_WIDTH 1.6
#define DIST_FROM_INTERSECT 3.5
#define LANE_DIVIDER_HEIGHT 0.4
#define LANE_DIVIDER_WIDTH 0.3 // Half of lane divider width
#define LANE_DIVIDER_FROM_INTERSECT 4 // Distance lane divider is from intersection
#define LANE_COLOUR ColourRgb(1.0, 1.0, 1.0)
#define SIDEWALK_COLOUR ColourRgb(0.80, 0.80, 0.80)
#define ROAD_COLOUR ColourRgb(0.2, 0.2, 0.2)


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
