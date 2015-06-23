// Parser - Map
// By Rifdhan Nazeer
// Performs all data parsing for the map


#ifndef PARSER_MAP_H
#define PARSER_MAP_H


#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#include "primitives.h"
#include "main.h"
#include "parser_helpers.h"
#include "Intersection.h"
#include "StreetSegment.h"


// Parses all map data
// By Rifdhan Nazeer
void parseMapData();

// Parses a single intersection
// By Rifdhan Nazeer
void parseIntersection(std::ifstream& mapFile);

// Parses a single street segment
// By Rifdhan Nazeer
void parseStreetSegment(std::ifstream& mapFile);


#endif // PARSER_MAP_H
