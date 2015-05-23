// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include "parser_helpers.h"


using namespace std;


// Parses the given line and returns a key-value pair
// By David Cheung
pair<string, string> parseKeyValPair(string line)
{
    string::const_iterator keyBegin = line.begin(); // Iterator to the first char of the key
    string::const_iterator keyEnd;                  // Iterator to the last char of the key
    string::const_iterator valueBegin;              // Iterator to the first char of the value
    string::const_iterator valueEnd;                // Iterator to the last char of the value
    bool valueIsString = false; // Whether or not the value is a string (and encapsulated in quotes (""))
    
    // Find first letter of key
    while(true)
    {
        if(*keyBegin == ' ' || *keyBegin == '\t' || *keyBegin == '<') // Check for whitespace or '<'
        {
            keyBegin++;
        }
        else // Key found
        {
            break;
        }
    }
    
    keyEnd = keyBegin;
    
    // Find last letter of key
    while(true)
    {
        if(*keyEnd == ' ' || *keyEnd == '\t' || *keyEnd == '=') // Check for whitespace or '='
        {
            break;
        }
        else // Characters of the key
        {
            keyEnd++;
        }
    }
    
    valueBegin = keyEnd;
    
    // Find first letter of value
    while(true)
    {
        if(*valueBegin == '=' || *valueBegin == ' ' || *valueBegin == '\t') // Check for whitespace
        {
            valueBegin++;
        }
        else if(*valueBegin == '"') // Check for quotes (means value is a string)
        {
            valueIsString = true;
            valueBegin++;
        }
        else // Value found
        {
            break;
        }
    }
    
    valueEnd = valueBegin;
    
    // Find last letter of value
    while(valueEnd != line.end())
    {
        if(*valueEnd == ' ' || *valueEnd == '\t' || *valueEnd == '>') // Check for whitespace or '>'
        {
            break;
        }
        else if(valueIsString && *valueEnd == '"') // Check for end of string
        {
            break;
        }
        else // Characters of the value
        {
            valueEnd++;
        }
    }
    
    // Construct and return the key-value pair
    return pair<string, string>(string(keyBegin, keyEnd), string(valueBegin, valueEnd));
}
