// Parser - Helpers
// By Rifdhan Nazeer and David Cheung
// Several useful helper functions for parsing XML data


#include "parser_helpers.h"


using namespace std;


// Parses the given line and returns a key-value pair
// By David Cheung
pair parseKeyValPair(string line)
{
        typedef string::const_iterator iter;
        iter b = s.begin();
        iter e = s.end();
        int valueStart, valueEnd = 0;
        int seperator = 0;        
        int keyStart, keyEnd = 0;
        int flag = 0;
        
        while (1)
        {
        
                // Attempting to find first letter of key.
        
                if (b == '<' || b == ' '){
                        b++;
                } else {
                // key found
                        keyStart = b;
                        break;
                }
        }
        
        
       
        
        while (1)
        {
                // Find end of key
                if (b == '=' || b == ' '){
                        keyEnd = b - 1;
                        break;
                } else {
                        b++;
                }
        }
        
        while (1)
        {
                // find beginning of value
                if (b == '=' || b == ' ') b++;
                break;
        
        }
        
                // determine whether the value is in quotations
                if (b == '"'){
                        valueStart = b + 1;
                        flag = 1;
                } else {
                        valueStart = b;
                }
        
        // find end of value
        while(b != e)
        {
                // find closing quotation (type 1)
                if (flag == 1){
                        if (b == '"'){
                                valueEnd = b - 1;
                                break;
                        } else {
                                b++;
                        }
                // no surrounding quotations so find first space or closing bracket.                      
                } else {
                        if (b == ">" || b == ' '){
                                value_end = b - 1;
                                break;
                        } else {
                                b++;
                        } 
                }
        }
        return make_pair(line.substr(keyStart, keyEnd), 
                        line.substr(valueStart, valueEnd));        
               
                        
              
}
