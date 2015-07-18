// Graphics
// By Rifdhan Nazeer
// Contains the graphics functions of the program


#include "graphics.h"


using namespace std;


// Global scaling factor
double scale = 0.009;



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
        glVertex2f(bottomLeft.x * scale, bottomLeft.y * scale);
        glVertex2f(  topRight.x * scale, bottomLeft.y * scale);
        glVertex2f(  topRight.x * scale,   topRight.y * scale);
        glVertex2f(bottomLeft.x * scale,   topRight.y * scale);
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
        glVertex2f(scale * (center.x - widthHeight.x / 2.0), scale * (center.y - widthHeight.y / 2.0));
        glVertex2f(scale * (center.x + widthHeight.x / 2.0), scale * (center.y - widthHeight.y / 2.0));
        glVertex2f(scale * (center.x + widthHeight.x / 2.0), scale * (center.y + widthHeight.y / 2.0));
        glVertex2f(scale * (center.x - widthHeight.x / 2.0), scale * (center.y + widthHeight.y / 2.0));
    glEnd();
}

// Draws a circle
void worldDrawCircle(const PointC& center, const double& radius, const bool& filled, const ColourRgb& colour)
{
    // Check fill requirement
    handleFilling(filled);
    
    // Generate the circle
    glBegin(GL_LINE_STRIP);
        for(unsigned degrees = 0; degrees < 360; degrees++)
        {
            glVertex2f((center.x + cos(DEG_TO_RAD * degrees) * radius) * scale, (center.y + sin(DEG_TO_RAD * degrees) * radius) * scale);
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
