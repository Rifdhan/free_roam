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
    
    // Invalid
    pair<string, string> myPair = parseKeyValPair("<myKey=myValue>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseKeyValPair("<     anotherKey  =    \"string <> Value\" >");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<123=\" HI\"\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<<Snail=\" Bob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<Snail= \" Bob\" 8>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<Snail= \" Bob\">>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseKeyValPair("<Snail=\" Bob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<Sna$il=\" B_ob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl << endl;
    
    // Invalid
    myPair = parseKeyValPair("<Sna$il=>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<=\"\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseKeyValPair("<HI \"There\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    return 0;
}
