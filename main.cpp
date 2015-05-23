// Main
// By Rifdhan Nazeer
// Contains the main function


#include <iostream>
#include <string>
#include <utility>

#include "parser_helpers.h"


using namespace std;


// Main function
int main(int argc, char **argv)
{
    // Do nothing for now
    
    // Testing parseKeyValPair
    pair<string, string> myPair = parseKeyValPair("<myKey=myValue");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    myPair = parseKeyValPair("<anotherKey=\"stringValue\"");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    myPair = parseKeyValPair("<123=456>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    return 0;
}
