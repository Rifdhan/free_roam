// Primitives
// By Rifdhan Nazeer
// Defines several basic data structures and functions


#include "primitives.h"


using namespace std;


// ==================================================
// Primitive Types
// ==================================================

// A point in Cartesian coordinates

// Constructor
PointC::PointC(double newX, double newY)
{
    x = newX;
    y = newY;
}

// Equals operator
PointC& PointC::operator=(const PointC& rhs)
{
    x = rhs.x;
    y = rhs.y;
    
    return *this;
}

// Calculates the magnitude
double PointC::computeMagnitude()
{
    return sqrt(x * x + y * y);
}

// Calculates the angle in degrees
double PointC::computeAngleDeg()
{
    return (atan2(y, x) * RAD_TO_DEG);
}

// Conversion into a polar point object
PointP PointC::convertToPolar()
{
    double radius = computeMagnitude();
    double angleDeg = computeAngleDeg();
    
    return PointP(radius, angleDeg);
}

// A point in polar coordinates

// Constructor
PointP::PointP(double newRadius, double newAngleDeg)
{
    radius = newRadius;
    angleDeg = newAngleDeg;
}

// Equals operator
PointP& PointP::operator=(const PointP& rhs)
{
    radius = rhs.radius;
    angleDeg = rhs.angleDeg;
    
    return *this;
}

// Calculates the Cartesian x value
double PointP::computeX()
{
    return (radius * cosd(angleDeg));
}

// Calculates the Cartesian y value
double PointP::computeY()
{
    return (radius * sind(angleDeg));
}

// Conversion into a Cartesian point object
PointC PointP::convertToCartesian()
{
    double x = computeX();
    double y = computeY();
    
    return PointC(x, y);
}


// ==================================================
// Helper Functions
// ==================================================

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

// Registers an error in the system, and prints an error message to logs
void error(string message)
{
    // Register an error
    errorOccurred = true;
    
    // Print message to terminal
    cout << "Error: " << message << endl;
}
