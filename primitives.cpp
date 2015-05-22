// Primitives
// By Rifdhan Nazeer
// Defines several basic data structures and primitives


#include "primitives.h"


// A point in Cartesian coordinates
struct PointC
{
    double x, y;
    
    // Constructor
    PointC(double newX, double newY)
    {
        x = newX;
        y = newY;
    }
    
    // Equals operator
    PointC& operator=(const PointC& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        
        return *this;
    }
    
    // Calculates the magnitude
    double computeMagnitude()
    {
        return sqrt(x * x + y * y);
    }
    
    // Calculates the angle in degrees
    double computeAngleDeg()
    {
        return (atan2(y, x) * RAD_TO_DEG);
    }
    
    // Conversion into a polar point object
    PointP convertToPolar()
    {
        double radius = computeMagnitude();
        double angleDeg = computeAngleDeg();
        
        return PointP(radius, angleDeg);
    }
}

// A point in polar coordinates
struct PointP
{
    double radius, angleDeg;
    
    // Constructor
    PointP(double newRadius, double newAngleDeg)
    {
        radius = newRadius;
        angleDeg = newAngleDeg;
    }
    
    // Equals operator
    PointP& operator=(const PointP& rhs)
    {
        radius = rhs.radius;
        angleDeg = rhs.angleDeg;
        
        return *this;
    }
    
    // Calculates the Cartesian x value
    double computeX()
    {
        return (radius * cosd(angleDeg));
    }
    
    // Calculates the Cartesian y value
    double computeY()
    {
        return (radius * sind(angleDeg));
    }
    
    // Conversion into a Cartesian point object
    PointC convertToCartesian()
    {
        double x = computeX();
        double y = computeY();
        
        return PointC(x, y);
    }
}


// Wrapper for sin taking an angle in degrees
double sind(double angleDeg)
{
    return sin(angleDeg * DEG_TO_RAD);
}

// Wrapper for cos taking an angle in degrees
double cosd(double angleDeg)
{
    return cos(angleDeg * DEG_TO_RAD);
}
