// Main
// By Rifdhan Nazeer and David Cheung
// Contains the main functions of the program


#include "main.h"


using namespace std;


// Map data containers
unordered_map<unsigned, Intersection> intersections;
unordered_map<unsigned, StreetSegment> streetSegments;
unordered_map<string, Vehicle> vehicles;
Player player;

// Initializes the graphics and output window
// By Rifdhan Nazeer
void initializeGraphics(int argc, char **argv)
{
    // Initialize OpenGL
    glutInit(&argc, argv);
    //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // Double buffering, RGB colours
    
    // Create an output window
    glutCreateWindow("Free Roam");
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(50, 50); // Position of top-left corner
    
    // Setup callback functions
    glutDisplayFunc(drawScreen);

    glutReshapeFunc(windowResize);
    glutKeyboardFunc(handleKeyboard);
}


// Screen update function
// By David Cheung
void updateScreen()
{
    glutPostRedisplay();
}


// Main parsing function
// By Rifdhan Nazeer
void parseAllData()
{
    // Parse map data first
    parseMapData();
}

// Main function
// By Rifdhan Nazeer
int main(int argc, char **argv)
{ 
    // Initialize graphics
    initializeGraphics(argc, argv);
    
    // Parse data
    parseAllData();
    
    glutIdleFunc(updateScreen);
    
    // Enter OpenGL event loop
    glutMainLoop();
}

// Main screen update function (OpenGL callback)
// By Rifdhan Nazeer
void drawScreen()
{
    // Erase previous drawings
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    // Draw the map
    drawMap();
    
    // Draw the player
    player.draw();
    
    // Swap the buffers to display the current frame on screen
    glFlush();
    //glutSwapBuffers();
}

// Window resize handler (OpenGL callback)
// By Rifdhan Nazeer
void windowResize(int newWidth, int newHeight)
{
    glViewport(0,0,newWidth,newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0f,(GLfloat)newWidth/(GLfloat)newHeight,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Function to handle keyboard events
// By Rifdhan Nazeer and David Cheung
void handleKeyboard(unsigned char keyPressed, int mouseX, int mouseY)
{
    // Handle key pressed
    switch(keyPressed)
    {
        case 27: // ESC - exit
            performExit();
            break;
        case 97: // Player - Left 'a'
	        player.move(LEFT);
	        break;
        case 100: // Player - Right 'd'
	        player.move(RIGHT);
	        break;
        case 115: // Player - Down 's'
	        player.move(DOWN);
	        break;
        case 119: // Player - Up 'w'
	        player.move(UP);
	        break;            
    }
}

// Handles ending the program
// By Rifdhan Nazeer
void performExit()
{
    // Exit
    exit(0);
}
