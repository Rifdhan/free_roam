// Intersection
// By Rifdhan Nazeer
// Contains information about a single intersection


#include "Intersection.h"


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
