// Main
// By Rifdhan Nazeer
// Contains the main functions of the program


#include "main.h"


using namespace std;


// Map data containers
unordered_map<unsigned, Intersection> intersections;
unordered_map<unsigned, StreetSegment> streetSegments;


// Main function
// By Rifdhan Nazeer
int main(int argc, char **argv)
{
    // Initialize graphics
    initializeGraphics(argc, argv);
    
    // Parse data
    parseAllData();
    
    // Enter OpenGL event loop
    glutMainLoop();
    
    return 0;
}

// Initializes the graphics and output window
// By Rifdhan Nazeer
void initializeGraphics(int argc, char **argv)
{
    // Initialize OpenGL
    glutInit(&argc, argv);
    
    // Create an output window
    glutCreateWindow("Free Roam");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50); // Position of top-left corner
    
    // Setup callback functions
    glutDisplayFunc(drawScreen);
}

// Main parsing function
// By Rifdhan Nazeer
void parseAllData()
{
    // Parse map data first
    parseMapData();
}

// Main screen update function (OpenGL callback)
// By Rifdhan Nazeer
void drawScreen()
{
    
}
