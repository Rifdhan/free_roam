// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include "primitives.h"

// Parses the given line and returns a key-value pair
// By David Cheung
std::pair<std::string, std::string> parseKeyValPair(std::string line);
