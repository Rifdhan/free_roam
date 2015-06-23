// Graphics
// By Rifdhan Nazeer
// Contains the graphics functions of the program


#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <GL/glut.h>

#include "primitives.h"


// World drawing functions

// Draws a rectangle using corners
void worldDrawRectCorners(const PointC& bottomLeft, const PointC& topRight, const bool& filled, const ColourRgb& colour);

// Draws a rectangle using center and width, height
void worldDrawRectCentered(const PointC& center, const PointC& widthHeight, const bool& filled, const ColourRgb& colour);

// Draws a circle
void worldDrawCircle(const PointC& center, const double& radius, const bool& filled, const ColourRgb& colour);


// Miscellaneous helper functions

// Turns on or off shape filling
void handleFilling(const bool& filled);


#endif // GRAPHICS_H
