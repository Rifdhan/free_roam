// Graphics
// By Rifdhan Nazeer
// Contains the graphics functions of the program


#include "graphics.h"


using namespace std;


// World drawing functions

// Draws a rectangle using corners
void worldDrawRectCorners(const PointC& bottomLeft, const PointC& topRight, const bool& filled, const ColourRgb& colour)
{
    // Check fill requirement
    handleFilling(filled);
    
    // Drawing a quadrilateral
    glBegin(GL_QUADS);
        // Set colour
        glColor3f(colour.red, colour.green, colour.blue);
        
        // Draw four vertices
        glVertex2f(bottomLeft.x, bottomLeft.y);
        glVertex2f(  topRight.x, bottomLeft.y);
        glVertex2f(  topRight.x,   topRight.y);
        glVertex2f(bottomLeft.x,   topRight.y);
    glEnd();
}

// Draws a rectangle using center and width, height
void worldDrawRectCentered(const PointC& center, const PointC& widthHeight, const bool& filled, const ColourRgb& colour)
{
    // Check fill requirement
    handleFilling(filled);
    
    // Drawing a quadrilateral
    glBegin(GL_QUADS);
        // Set colour
        glColor3f(colour.red, colour.green, colour.blue);
        
        // Draw four vertices
        glVertex2f(center.x - widthHeight.x / 2.0, center.y - widthHeight.y / 2.0);
        glVertex2f(center.x + widthHeight.x / 2.0, center.y - widthHeight.y / 2.0);
        glVertex2f(center.x + widthHeight.x / 2.0, center.y + widthHeight.y / 2.0);
        glVertex2f(center.x - widthHeight.x / 2.0, center.y + widthHeight.y / 2.0);
    glEnd();
}

// Draws a circle
void worldDrawCircle(const PointC& center, const double& radius, const bool& filled, const ColourRgb& colour)
{
    // Check fill requirement
    handleFilling(filled);
    
    // Generate the circle
    glBegin(GL_LINE_LOOP);
        for(unsigned degrees = 0; degrees < 360; degrees++)
        {
            glVertex2f(cos(DEG_TO_RAD * degrees) * radius, sin(DEG_TO_RAD * degrees) * radius);
        }
    glEnd();
}


// Miscellaneous helper functions

// Turns on or off shape filling
void handleFilling(const bool& filled)
{
    // Check fill requirement
    if(filled)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
}
