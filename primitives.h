// Primitives
// By Rifdhan Nazeer
// Defines several basic data structures and helper functions


#ifndef PRIMITIVES_H
#define PRIMITIVES_H


#include <cmath>
#include <string>


// Unit conversion constants
#define DEG_TO_RAD 0.0174532925199432957692369076848861271344287188854172 // Factor to convert degrees to radians
#define RAD_TO_DEG 57.295779513082320876798154814105170332405472466564321 // Factor to convert radians to degrees


// Other constants
#define INVALID_ID (unsigned) (-1)


// Forward declarations
struct PointC;
struct PointP;


// ==================================================
// Primitive Types
// ==================================================

// A point in Cartesian coordinates
struct PointC
{
    double x, y;
    
    // Constructor
    PointC(const double& newX = 0.0, const double& newY = 0.0);
    
    // Equals operator
    PointC& operator=(const PointC& rhs);
    
    // Calculates the magnitude
    double computeMagnitude();
    
    // Calculates the angle in degrees
    double computeAngleDeg();
    
    // Conversion into a polar point object
    PointP convertToPolar();
};

// A point in polar coordinates
struct PointP
{
    double radius, angleDeg;
    
    // Constructor
    PointP(const double& newRadius = 0.0, const double& newAngleDeg = 0.0);
    
    // Equals operator
    PointP& operator=(const PointP& rhs);
    
    // Calculates the Cartesian x value
    double computeX();
    
    // Calculates the Cartesian y value
    double computeY();
    
    // Conversion into a Cartesian point object
    PointC convertToCartesian();
};

// A colour in RGB (all values between 0.0 and 1.0)
struct ColourRgb
{
    double red, green, blue;
    
    // Constructor
    ColourRgb(const double& newRed = 0.0, const double& newGreen = 0.0, const double& newBlue = 0.0);
    
    // Finds the average brightness
    double getBrightness();
};


// ==================================================
// Helper Functions
// ==================================================

// Wrapper for sin taking an angle in degrees
double sind(const double& angleDeg);

// Wrapper for cos taking an angle in degrees
double cosd(const double& angleDeg);


#endif // PRIMITIVES_H
