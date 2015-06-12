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
    
    string::const_iterator keyBegin = line.begin();                 // Iterator to the first char of the key
    string::const_iterator keyEnd;                                  // Iterator to the last char of the key
    string::const_iterator valueBegin;                              // Iterator to the first char of the value
    string::const_iterator valueEnd;                                // Iterator to the last char of the value
    string::const_iterator toEnd;                                   // Iterator to the last char of the string
    string::const_iterator separator = find(keyBegin, keyEnd, '='); // Iterator to the location of the separator (=)
	unsigned eCount = 0;											// Counter for the number of 'e' for exponents
    bool flag = 0;
    
    if(separator == line.end()) // Determine if the separator '=' exists within the string
    {
        error("No separator (=) found in key-value pair \"" + line + "\"");
        return pair<string, int>("", 0);
    }
    else if(separator == line.begin() || separator == line.end() - 1) // Determine if there is room for a key and value between the separator
    {
        error("No key or value found in key-value pair \"" + line + "\"");
        return pair<string, int>("", 0);
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
            return pair<string, int>("", 0);
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
            return pair<string, int>("", 0);
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
            return pair<string, int>("", 0);    
        }
    }
        
    valueBegin = keyEnd;  
    
    // Find first digit of value
    while(true)
    {
        if(*valueBegin == '=' || *valueBegin == ' ' || *valueBegin == '\t') // Check for whitespace or separator
        {
            valueBegin++;
        }
        else if(isdigit(*valueBegin) || *valueBegin == '-' || *valueBegin == '+') // Check for numbers
        {
            valueBegin++;
            break;
        }
        else // Invalid digit found 
        {
            error("The initial value is not a number for key-value pair \"" + line + "\"");
            return pair<string, int>("", 0); 
        }
    }
    
    valueEnd = valueBegin;
    
    // Find last digit of value
    while(valueEnd != line.end())
    {
        if(isdigit(*valueEnd) || (*valueEnd == 'e' && eCount == 0) || flag == true) // Digits of the value
        {
            
			
			if(eCount == 1 && flag == true)
			{
			    if(isdigit(*valueEnd) || *valueEnd == '-' || *valueEnd == '+') // Valid character after exponent
			    {
			        flag = false;
			    } 
			    else 
			    {
			        break;
			    }
			}
			
			if(*valueEnd == 'e') // Check for exponent
            {
			    eCount = 1;
			    flag = true;			    
			}
			 
			valueEnd++;
        }
        else // End of value
        {
            break;
        }
    }
    
    if(*(valueEnd - 1) == 'e' || *(valueEnd - 1) == '-' || *(valueEnd - 1) == '+') // Check for number entered as last character
    {
        error("Invalid character entered after the exponent in key-value pair \"" + line + "\"");
        return pair<string, int>("", 0);  
    }
    
    toEnd = valueEnd;
    
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
            return pair<string, int>("", 0);
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
            return pair<string, int>("", 0);
        }
    }
    
    double numericValue = stod(string(valueBegin - 1, valueEnd)); // String value converted to a double
    
       // Check if the value is an integer
       if(fmod(numericValue,1.0) == 0.0){
            // Construct and return the key-value pair
            return pair<string, int>(string(keyBegin, keyEnd), (int)numericValue); 
       } 
       else // Not an integer 
       {
            error("Value is not an integer in key-value pair \"" + line + "\"");
            return pair<string, int>("", 0);
       }   
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
    
    
    
    string::const_iterator keyBegin = line.begin();                 // Iterator to the first char of the key
    string::const_iterator keyEnd;                                  // Iterator to the last char of the key
    string::const_iterator valueBegin;                              // Iterator to the first char of the value
    string::const_iterator valueEnd;                                // Iterator to the last char of the value
    string::const_iterator toEnd;                                   // Iterator to the last char of the string
    string::const_iterator separator = find(keyBegin, keyEnd, '='); // Iterator to the location of the separator (=)
	unsigned eCount = 0;											// Counter for the number of exponents 'e'
	unsigned dCount = 0;                                            // Counter for the number of decimals '.'
    bool flag = false;                                              // Flag to indicate whether an exponent 'e' was already parsed in the value.
    
    if(separator == line.end()) // Determine if the separator '=' exists within the string
    {
        error("No separator (=) found in key-value pair \"" + line + "\"");
        return pair<string, double>("", 0.0);
    }
    else if(separator == line.begin() || separator == line.end() - 1) // Determine if there is room for a key and value between the separator
    {
        error("No key or value found in key-value pair \"" + line + "\"");
        return pair<string, double>("", 0.0);
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
            return pair<string, double>("", 0.0);
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
            return pair<string, double>("", 0.0);
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
            return pair<string, double>("", 0.0);   
        }
    }
        
    valueBegin = keyEnd;  
    
    // Find first digit of value
    while(true)
    {
        if(*valueBegin == '=' || *valueBegin == ' ' || *valueBegin == '\t') // Check for whitespace or separator
        {
            valueBegin++;
        }
        else if(isdigit(*valueBegin) || *valueBegin == '-' || *valueBegin == '+' || *valueBegin == '.') // Check for numbers or sign
        {
            valueBegin++;
            break;
        }
        else // Invalid digit found 
        {
            error("The initial value is not a number for key-value pair \"" + line + "\"");
            return pair<string, double>("", 0.0);
        }
    }
    
    valueEnd = valueBegin;
    
    // Find last digit of value
    while(valueEnd != line.end())
    {
        if(isdigit(*valueEnd) || (*valueEnd == 'e' && eCount == 0) || (*valueEnd == '.' && dCount == 0) || flag == true) // Digits of the value
        {
            
			
			if(eCount == 1 && flag == true)
			{
			    if(isdigit(*valueEnd) || *valueEnd == '-' || *valueEnd == '+') // Valid character after exponent
			    {
			        flag = false;
			    } 
			    else // Invalid character for value
			    {
			        break;
			    }
			}
			
			if(*valueEnd == '.') // Check for exponent
			{
			    dCount = 1;
			}
			
			if(*valueEnd == 'e') // Check for exponent
            {
			    eCount = 1;
			    flag = true;			    
			}
			 
			valueEnd++;
        }
        else // End of value
        {
            break;
        }
    }
    
    if(*(valueEnd - 1) == 'e' || *(valueEnd - 1) == '-' || *(valueEnd - 1) == '+') // Check for number entered as last character
    {
        error("Invalid character entered after the exponent in key-value pair \"" + line + "\"");
        return pair<string, double>("", 0.0); 
    }
    
    toEnd = valueEnd;
    
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
            return pair<string, double>("", 0.0);
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
            return pair<string, double>("", 0.0);
        }
    }
    
    // Construct and return the key-value pair
    return pair<string, double>(string(keyBegin, keyEnd), stod(string(valueBegin - 1, valueEnd))); 
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
 
 
    string::const_iterator keyBegin = line.begin();                 // Iterator to the first char of the key
    string::const_iterator keyEnd;                                  // Iterator to the last char of the key
    string::const_iterator valueBegin;                              // Iterator to the first char of the value
    string::const_iterator toEnd;                                   // Iterator to the last char of the string
    string::const_iterator separator = find(keyBegin, keyEnd, '='); // Iterator to the location of the separator (=)
    bool result = false;                                            // Resulting boolean for the value
    
    if(separator == line.end()) // Determine if the separator '=' exists within the string
    {
        error("No separator (=) found in key-value pair \"" + line + "\"");
        return pair<string, bool>("", false);
    }
    else if(separator == line.begin() || separator == line.end() - 1) // Determine if there is room for a key and value between the separator
    {
        error("No key or value found in key-value pair \"" + line + "\"");
        return pair<string, bool>("", false);
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
            return pair<string, bool>("", false);
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
            return pair<string, bool>("", false);
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
            return pair<string, bool>("", false);    
        }
    }
        
    valueBegin = keyEnd;  
    
    // Find first digit of value
    while(true)
    {
        if(*valueBegin == '=' || *valueBegin == ' ' || *valueBegin == '\t') // Check for whitespace or separator
        {
            valueBegin++;
        }
        else if(toupper(*valueBegin) == 'T' || toupper(*valueBegin) == 'F') // Check for boolean
        {
            string tempStr = string(valueBegin, valueBegin + 5); // Temporary string for true/false range

            if (toupper(*valueBegin) == 'T') // Value is true
            {
                result = true;
            }
            else // Value is false
            {
                result = false;
            }
            
            if(tempStr.substr(0, 4) == "TRUE" || tempStr.substr(0, 4) == "true" 
                    || tempStr.substr(0, 4) == "True") // Different variation of true
            {

                valueBegin += 3; // End of value
                
            } 
            else if (tempStr.substr(0, 5) == "FALSE" || tempStr.substr(0, 5) == "False" 
                    || tempStr.substr(0, 5) == "false") // Different variation of false;
            {
                valueBegin += 4; // End of value
                              
            }
            
            valueBegin++;
            break;
        }
        else // Invalid character found 
        {
            error("The initial value is not a recognized boolean for key-value pair \"" + line + "\"");
            return pair<string, bool>("", false);
        }
    }  
     
    toEnd = valueBegin;   
    
    // Check for invalid characters after value
    while(toEnd != line.end())
    {
        if(*toEnd == ' ' || *toEnd == '\t') // Whitespace
        {
            toEnd++;
        }
        else if(*toEnd == '>') // Closing bracket
        {
            toEnd++;
            break;
        }
        else // Invalid character
        {
            error("Invalid character after value in key-value pair \"" + line + "\"");
            return pair<string, bool>("", false);
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
            return pair<string, bool>("", false);
        }
    }
       
    // Construct and return the key-value pair
    return pair<string, bool>(string(keyBegin, keyEnd), result);   
}
