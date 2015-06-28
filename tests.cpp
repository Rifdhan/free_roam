// Tests
// By Rifdhan Nazeer and David Cheung
// Contains many testing and experimental functions


#include "tests.h"


using namespace std;


// Tests various parsing function
// By David Cheung
void testParsing()
{
    // Testing parseKeyValPair
    
    // Parsing Strings  
    // Test Cases 
    
    cout << "------------------------Parsing Strings------------------------" << endl;
    { 
    // Valid
    pair<string, string>  myPair = parseStringKeyValPair("<     anotherKey  =    \"string <> Value\" >");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseStringKeyValPair("<Snail=\" Bob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseStringKeyValPair("   \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
     // Valid
    myPair = parseStringKeyValPair("   \t < _key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
     // Valid
    myPair = parseStringKeyValPair("   \t < k_ey=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    cout << "--------------------------------------------------------------------------" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<myKey=myValue>");
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
        
    // Invalid
    myPair = parseStringKeyValPair("<=\"\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<HI \"There\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair(" ' \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("  \t < key=\"Value\">\t> \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Sna$il=\" B_ob\">");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseStringKeyValPair("<Sna$il=>");
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
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= +999>\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= -999 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl; 
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= 10e2 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < key= 10e-1 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Valid
    myPair = parseIntKeyValPair("   \t < _ke_y= 10e-1 >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
        
     // Invalid
    myPair = parseIntKeyValPair("   \t < key= -99+9>\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;   
        
    // Invalid
    myPair = parseIntKeyValPair("  \t < key= 13v37> \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid 
    myPair = parseIntKeyValPair("   \t < key=\"Value\">\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid  
    myPair = parseIntKeyValPair("   \t < key= 10ee2 >\t \t ");
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
    
    // Valid
    myPair = parseDoubleKeyValPair("   \t < _ke_y_= 1.8e2 >\t \t ");
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
    
    // Valid
    myPair = parseBoolKeyValPair("   \t < _k_ey_ = true >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    // Invalid
    myPair = parseBoolKeyValPair("   \t < key = truee >\t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    
    //Invalid
    myPair = parseBoolKeyValPair("   \t < key = true \t \t ");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }
       
       
    // Header, Footer and White Space
    // Test Cases
    cout << "------------------------Parsing Header/Footer------------------------" << endl;
    {
    // Valid
    bool result = isWhitespace("   \t    \n   \r    \t   \t \t ");
    cout << "Status: " << result << endl;  
    
    // Valid
    result = isHeader("< car >", "car");
    cout << "Status: " << result << endl;  
    
    // Valid
    result = isFooter("< / car >", "car");
    cout << "Status: " << result << endl;
    // Valid
    result = isFooter("< / car >", "car");
    cout << "Status: " << result << endl;
    
    // Valid
    result = isFooter("</ car >", "car");
    cout << "Status: " << result << endl;
    
    // Valid
    result = isFooter("< /car    >", "car");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isFooter("< / cars >", "car");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isFooter("< / car >", "cars");
    cout << "Status: " << result << endl;   
    
    // Invalid
    result = isHeader("<  car >", "bob");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isHeader("< ca r >", "car");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isFooter("< / car ", "car");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isHeader(" car >", "car");
    cout << "Status: " << result << endl;
    
    // Invalid
    result = isWhitespace("  s \t    \n   \r    \t   \t \t ");
    cout << "Status: " << result << endl; 
    }
    
 
    // Header, Footer and White Space
    // Test Cases
    cout << "------------------------Parsing Unsigned------------------------" << endl;
    {
    // Valid
    pair<string, unsigned> myPair = parseUnsignedKeyValPair("<test= 123 >");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl; 
    
    // Valid
    myPair = parseUnsignedKeyValPair("<_te_st_ = 123 >");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl; 
    
    // Invalid
    myPair = parseUnsignedKeyValPair("<test = -123>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;        
    
    // Invalid
    myPair = parseUnsignedKeyValPair("<test = 1.23>");
    cout << "first: \"" << myPair.first << "\", second: \"" << myPair.second << "\"" << endl;
    }
}
