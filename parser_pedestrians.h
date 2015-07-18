// Parser - Pedestrian
// By David Cheung
// Performs all data parsing for Pedestrians


#ifndef PARSER_PEDESTRIAN_H
#define PARSER_PEDESTRIAN_H


#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#include <iostream>
#include "primitives.h"
#include "main.h"
#include "parser_helpers.h"
#include "Pedestrian.h"

// Main parsing function
void parseAllPed();

// Helper function for parsing
void parsePed(std::ifstream& pedFile);

#endif // PARSER_PEDESTRIAN_H
