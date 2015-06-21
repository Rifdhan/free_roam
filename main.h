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

#include "parser_map.h"
#include "Intersection.h"
#include "StreetSegment.h"


// Map data containers
extern std::unordered_map<unsigned, Intersection> intersections;
extern std::unordered_map<unsigned, StreetSegment> streetSegments;

// Main function
// By Rifdhan Nazeer
int main(int argc, char **argv);

// Main parsing function
// By Rifdhan Nazeer
void parseAllData();


#endif // MAIN_H
