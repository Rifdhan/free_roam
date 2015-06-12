// Main
// By Rifdhan Nazeer
// Contains the main function


#include <iostream>
#include <string>
#include <utility>
#include <stdio.h>
#include "parser_helpers.h"


using namespace std;


// Main function
int main(int argc, char **argv)
{
    // Do nothing for now
    
    // Testing parseKeyValPair
    
    // Parsing Strings  
    // Test Cases 
    
    cout << "------------------------Parsing Strings------------------------" << endl;
    {
    // Invalid
    pair<string, string> myPair = parseStringKeyValPair("<myKey=myValue>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseStringKeyValPair("<     anotherKey  =    \"string <> Value\" >");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<123=\" HI\"\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<<Snail=\" Bob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Snail= \" Bob\" 8>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Snail= \" Bob\">>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseStringKeyValPair("<Snail=\" Bob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Sna$il=\" B_ob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Sna$il=>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<=\"\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<HI \"There\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseStringKeyValPair("   \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair(" ' \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("  \t < key=\"Value\">\t> \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }   

    cout << endl << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 



 
    // Test Cases
    // Parse Integers 
    
    cout << "------------------------Parsing Integers------------------------" << endl;
    {
    // Valid
     pair<string, int> myPair = parseIntKeyValPair("  \t < key= 1337> \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseIntKeyValPair("  \t < key= 13v37> \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid 
    myPair = parseIntKeyValPair("   \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= +999>\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= -999 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl; 
    
     // Invalid
    myPair = parseIntKeyValPair("   \t < key= -99+9>\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;   
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= 10e2 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid  
    myPair = parseIntKeyValPair("   \t < key= 10ee2 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= 10e-1 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseIntKeyValPair("   \t < key= 10e >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseIntKeyValPair("   \t < key= 10e-3 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }

    cout << endl << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
 
 
    // Test Cases
    // Parsing Doubles
    
    cout << "------------------------Parsing Doubles------------------------" << endl;   
    {
    // Valid
    pair<string, double> myPair = parseDoubleKeyValPair("   \t < key= 10e-3 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;   
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < key= 10.10 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < key= .10 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < key= 10. >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < key= 1.8e-1 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < key= 1.8e2 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseDoubleKeyValPair("   \t < key= 10f >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }
 
    cout << endl << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    
    // Parsing Boolean
    // Test Cases
    cout << "------------------------Parsing Boolean------------------------" << endl;
    {
    // Valid
    pair<string, bool> myPair = parseBoolKeyValPair("   \t < key= T >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;  
    
    // Invalid
    myPair = parseBoolKeyValPair("   \t < key = hi >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseBoolKeyValPair("   \t < key = T$ >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseBoolKeyValPair("   \t < key = F >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
  
    // Valid
    myPair = parseBoolKeyValPair("   \t < key = f >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseBoolKeyValPair("   \t < key = false >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseBoolKeyValPair("   \t < key = True >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseBoolKeyValPair("   \t < key = true >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // InValid
    myPair = parseBoolKeyValPair("   \t < key = truee >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }
       
    return 0;
}
