// Log
// By Rifdhan Nazeer
// Facilitates easy log entries of various types


#ifndef LOG_H
#define LOG_H


#include <iostream>
#include <string>


class Log
{
private:
    // Counters
    static unsigned nErrors;
    static unsigned nWarnings;
    static unsigned nInfos;
    
    // Constructors/destructors
    Log() {};
    Log(const Log& original) {};
    //Log& operator=(const Log& rhs) {};
    
public:
    // Logs an error
    static void error(std::string message);
    
    // Logs a warning
    static void warning(std::string message);
    
    // Logs an informational message
    static void info(std::string message);
    
    // Returns how many errors have occurred
    static unsigned getNErrors();
};


#endif // LOG_H
