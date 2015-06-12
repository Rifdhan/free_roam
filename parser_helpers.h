// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include <iostream>
#include <string>
#include <utility>
#include <algorithm>  
#include "primitives.h"


// Parses the given line and returns a key-value pair of type <key, string>
// By David Cheung
std::pair<std::string, std::string> parseStringKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, int>
// By David Cheung
std::pair<std::string, int> parseIntKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, double>
// By David Cheung
std::pair<std::string, double> parseDoubleKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, bool>
// By David Cheung
std::pair<std::string, bool> parseBoolKeyValPair(std::string line);
