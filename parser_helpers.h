// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include <iostream>
#include <string>
#include <utility>
#include <algorithm>  

#include "Log.h"


// Parses the given line and determines if it is whitespace
// By David Cheung
bool isWhitespace(std::string line);

// Parses the given line and determines if it is a header of type <header>
// By David Cheung
bool isHeader(std::string line, std::string header);

// Parses the given line and determines if it is a footer of type </footer>
// By David Cheung
bool isFooter(std::string line, std::string footer);

// Parses the given line and returns a key-value pair of type <key, string>
// By David Cheung
std::pair<std::string, std::string> parseStringKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, int>
// By David Cheung
std::pair<std::string, int> parseIntKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, unsigned>
// By David Cheung
std::pair<std::string, unsigned> parseUnsignedKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, double>
// By David Cheung
std::pair<std::string, double> parseDoubleKeyValPair(std::string line);

// Parses the given line and returns a key-value pair of type <key, bool>
// By David Cheung
std::pair<std::string, bool> parseBoolKeyValPair(std::string line);
