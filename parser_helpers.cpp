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
    string::const_iterator keyEnd = line.end() - 1;                 // Iterator to the last char of the key
    string::const_iterator valueBegin;                              // Iterator to the first char of the value
    string::const_iterator valueEnd;                                // Iterator to the last char of the value
    string::const_iterator toEnd;                                   // Iterator to the last char of the string
    string::const_iterator separator = find(keyBegin, keyEnd, '='); // Iterator to the location of the separator '='
    int quotation = 0;                                              // The number of quotations " that were found
    
    
    // Check if the string is enclosed in "< >"
    if (separator == keyEnd)    // Determine if the separator '=' exists within the string
    {
        error("There is no seperator");
        return pair<string, string>("","");
    }
    else if (*keyBegin != '<' || *keyEnd != '>')    // Determine if the string is enclosed in <>
    {
        error("Input not enclosed in < >");
        return pair<string, string>("","");
    }
    else if (separator == keyBegin + 1 || separator == keyEnd - 1)  // Determine if there is room for a key and value between the separator
    {
        error("There is no key or value");
        return pair<string, string>("","");
    }
      
    keyBegin++; // Advance past the initial '<'
    
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
            error("Invalid character was entered before the key");
            return pair<string, string>("","");
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
        else // Invalid character found.
        {
            error("Invalid character was entered in the key");
            return pair<string, string>("","");    
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
            quotation++;
            valueBegin++;
            break;
        }
        else // Initial quotation for string not found 
        {
            error("String not enclosed in \"\"");
            return pair<string, string>("",""); 
        }
    }
    
    valueEnd = valueBegin;
    
    // Find last letter of value
    while(valueEnd != line.end())
    {
        if(*valueEnd == '"') // Check for end of string
        {
            quotation++;
            valueEnd++;
            break;
        }
        else // Characters of the value
        {
            valueEnd++;
        }
    }
    
    toEnd = valueEnd;
    
    // Check if there are invalid characters after the value until the closing bracket.
    while(toEnd != line.end() - 1)
    {
        // Invalid character found
        if(*toEnd != ' ' && *toEnd != '\t')
        {
            error("Invalid character entered after the value");
            return pair<string, string>("","");
        }
        else // Valid character
        {
            toEnd++;
        }
    }
    
    // Check if the string is enclosed in two quotations ""
    if(quotation != 2)
    {    
        error("String not enclosed in \"\" properly");
        return pair<string, string>("","");
    }
       
    // Construct and return the key-value pair
    return pair<string, string>(string(keyBegin, keyEnd), string(valueBegin, valueEnd));  
}
