// Main
// By Rifdhan Nazeer
// Contains the main functions of the program


#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <GL/glut.h>

#include "parser_map.h"
#include "Intersection.h"
#include "StreetSegment.h"


// Map data containers
extern std::unordered_map<unsigned, Intersection> intersections;
extern std::unordered_map<unsigned, StreetSegment> streetSegments;

// Main function
// By Rifdhan Nazeer
int main(int argc, char **argv);

// Initializes the graphics and output window
// By Rifdhan Nazeer
void initializeGraphics(int argc, char **argv);

// Main parsing function
// By Rifdhan Nazeer
void parseAllData();

// Main screen update function (OpenGL callback)
// By Rifdhan Nazeer
void drawScreen();

#endif // MAIN_H
