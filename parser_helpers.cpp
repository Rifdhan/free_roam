// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include "parser_helpers.h"


using namespace std;


// Parses the given line and returns a key-value pair
// By David Cheung
pair<string, string> parseStringKeyValPair(string line)
{
    string::const_iterator keyBegin = line.begin();                 // Iterator to the first char of the key
    string::const_iterator keyEnd;                                  // Iterator to the last char of the key
    string::const_iterator valueBegin;                              // Iterator to the first char of the value
    string::const_iterator valueEnd;                                // Iterator to the last char of the value
    string::const_iterator toEnd;                                   // Iterator to the last char of the string
    string::const_iterator separator = find(keyBegin, keyEnd, '='); // Iterator to the location of the separator (=)
    unsigned nQuotations = 0;                                       // The number of quotations (") that were found
    
    // Check if the string is enclosed in "< >"
    if(separator == line.end()) // Determine if the separator '=' exists within the string
    {
        error("No separator (=) found in key-value pair \"" + line + "\"");
        return pair<string, string>("", "");
    }
    else if(separator == line.begin() || separator == line.end() - 1) // Determine if there is room for a key and value between the separator
    {
        error("No key or value found in key-value pair \"" + line + "\"");
        return pair<string, string>("", "");
    }
    
    // Find the first angle bracket '<'
    while(true)
    {
        if(*keyBegin == ' ' || *keyBegin == '\t') // Check for whitespace
        {
            keyBegin++;
        }
        else if(*keyBegin == '<') // Angle bracket found
        {
            keyBegin++;
            break;
        }
        else // Invalid character found
        {
            error("Invalid character before key-value pair \"" + line + "\"");
            return pair<string, string>("", "");
        }
    }
    
    // Find first letter of key
    while(true)
    {        
        if(*keyBegin == ' ' || *keyBegin == '\t') // Check for whitespace
        {
            keyBegin++;
        }
        else if(isalnum(*keyBegin)) // Key found
        {
            break;
        }
        else // Invalid character found
        {
            error("Invalid character before key in key-value pair \"" + line + "\"");
            return pair<string, string>("", "");
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
        else if(isalnum(*keyEnd)) // Characters of the key
        {
            keyEnd++;
        } 
        else // Invalid character found
        {
            error("Invalid character in the key in key-value pair \"" + line + "\"");
            return pair<string, string>("", "");    
        }
    }
        
    valueBegin = keyEnd;  
    
    // Find first letter of value
    while(true)
    {
        if(*valueBegin == '=' || *valueBegin == ' ' || *valueBegin == '\t') // Check for whitespace or separator
        {
            valueBegin++;
        }
        else if(*valueBegin == '"') // Check for quotes (means value is a string)
        {
            nQuotations++;
            valueBegin++;
            break;
        }
        else // Initial quotation for string not found 
        {
            error("String value not enclosed in quotes (\") in key-value pair \"" + line + "\"");
            return pair<string, string>("", ""); 
        }
    }
    
    valueEnd = valueBegin;
    
    // Find last letter of value
    while(valueEnd != line.end())
    {
        if(*valueEnd == '"') // Check for end of string
        {
            nQuotations++;
            break;
        }
        else // Characters of the value
        {
            valueEnd++;
        }
    }
    
    toEnd = valueEnd + 1;
    
    // Check for invalid characters after value
    while(toEnd != line.end())
    {
        if(*toEnd == ' ' || *toEnd == '\t') // Whitespace
        {
            toEnd++;
        }
        else if(*toEnd == '>')
        {
            toEnd++;
            break;
        }
        else // Invalid character
        {
            error("Invalid character after value in key-value pair \"" + line + "\"");
            return pair<string, string>("", "");
        }
    }
    
    // Check for invalid characters after key-value pair
    while(toEnd != line.end())
    {
        if(*toEnd == ' ' || *toEnd == '\t') // Whitespace
        {
            toEnd++;
        }
        else // Invalid character
        {
            error("Invalid character after key-value pair \"" + line + "\"");
            return pair<string, string>("", "");
        }
    }
    
    // Check if the string is enclosed in two quotations ""
    if(nQuotations != 2)
    {    
        error("String value contains too few or too many quotations (\") in key-value pair \"" + line + "\"");
        return pair<string, string>("", "");
    }
       
    // Construct and return the key-value pair
    return pair<string, string>(string(keyBegin, keyEnd), string(valueBegin, valueEnd));  
}

// Parses the given line and returns a key-value pair of type <key, int>
// By David Cheung
std::pair<std::string, int> parseIntKeyValPair(std::string line)
{
    // Valid ints:
    // 123   -> 123
    // 0123  -> 123
    // -12   -> -12
    // +12   -> 12
    // 10e4  -> 100000
    // 10e-1 -> 1
    
    // Invalid:
    // 123.0
    // 123.
    // +-12
    // 8e-2
    // 4 e2
    // 4e 2
    // 4 e 2
    
    // Dummy return
    return pair<string, int>("", 0);
}

// Parses the given line and returns a key-value pair of type <key, double>
// By David Cheung
std::pair<std::string, double> parseDoubleKeyValPair(std::string line)
{
    // Valid doubles:
    // 12.3   -> 12.3
    // .021   -> 0.021
    // 1.0000 -> 1.0
    // 12.    -> 12.0
    // 15     -> 15.0
    // 12e2   -> 1200.0
    // 11.4e1 -> 114.0
    // 1.8e-1 -> 0.18
    
    // Invalid:
    // 1.4 e2
    // 1.4e 2
    // 1.4 e 2
    // 11.4f
    
    // Dummy return
    return pair<string, double>("", 0.0);
}

// Parses the given line and returns a key-value pair of type <key, bool>
// By David Cheung
std::pair<std::string, bool> parseBoolKeyValPair(std::string line)
{
    // Valid bools:
    // true
    // t
    // T
    // false
    // f
    // F
    
    // Invalid:
    // anything else
    
    // Dummy return
    return pair<string, bool>("", false);
}
