// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include "parser_helpers.h"


using namespace std;


// Parses the given line and returns a key-value pair
// By David Cheung
pair<string, string> parseKeyValPair(string line)
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
