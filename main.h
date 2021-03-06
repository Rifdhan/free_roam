// Main
// By Rifdhan Nazeer and David Cheung
// Contains the main functions of the program


#ifndef MAIN_H
#define MAIN_H

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3


#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <GL/glut.h>
#include <unistd.h>

#include "Pedestrian.h"
#include "parser_map.h"
#include "drawing_main.h"
#include "Intersection.h"
#include "StreetSegment.h"
#include "Vehicle.h"
#include "Player.h"
#include "parser_vehicles.h"
#include "parser_pedestrians.h"

class Pedestrian;

// Map data containers
extern std::unordered_map<unsigned, Intersection> intersections;
extern std::unordered_map<unsigned, StreetSegment> streetSegments;
extern std::unordered_map<std::string, Vehicle> vehicles;
extern std::unordered_map<std::string, Pedestrian> pedestrians;
extern Player player;

// Initializes the graphics and output window
// By Rifdhan Nazeer
void initializeGraphics(int argc, char **argv);

// Updates screen
// By David Cheung
void updateScreen();

// Draw all components of the game
void drawAll();

// Main parsing function
// By Rifdhan Nazeer
void parseAllData();

// Main function
// By Rifdhan Nazeer and David Cheung
int main(int argc, char **argv);

// Main screen update function (OpenGL callback)
// By Rifdhan Nazeer
void drawScreen();

// Window resize handler (OpenGL callback)
// By Rifdhan Nazeer
void windowResize(int newWidth, int newHeight);

// Function to handle keyboard events (OpenGL callback)
// By Rifdhan Nazeer and David
void handleKeyboard(unsigned char keyPressed, int mouseX, int mouseY);

// Function to handle mouse events
// By David Cheung
void handleMouse(int button, int state, int mouseX, int mouseY);

// Function to handle mouse passive movement
// By David Cheung
void mouseMovement(int mouseX, int mouseY);

// Handles ending the program
// By Rifdhan Nazeer
void performExit();




#endif // MAIN_H
