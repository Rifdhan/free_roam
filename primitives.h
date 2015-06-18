// Primitives
// By Rifdhan Nazeer
// Defines several basic data structures and helper functions


#include <cmath>
#include <string>
#include <iostream>
#include "globals.h"


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
    PointC(double newX = 0.0, double newY = 0.0);
    
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
    PointP(double newRadius = 0.0, double newAngleDeg = 0.0);
    
    // Equals operator
    PointP& operator=(const PointP& rhs);
    
    // Calculates the Cartesian x value
    double computeX();
    
    // Calculates the Cartesian y value
    double computeY();
    
    // Conversion into a Cartesian point object
    PointC convertToCartesian();
};


// ==================================================
// Helper Functions
// ==================================================

// Wrapper for sin taking an angle in degrees
double sind(double angleDeg);

// Wrapper for cos taking an angle in degrees
double cosd(double angleDeg);

// Registers an error in the system, and prints an error message to logs
void error(std::string message);
