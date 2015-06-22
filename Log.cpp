// Log
// By Rifdhan Nazeer
// Facilitates easy log entries of various types


#include "Log.h"


using namespace std;


unsigned Log::nErrors = 0;
unsigned Log::nWarnings = 0;
unsigned Log::nInfos = 0;


// Logs an error
void Log::error(string message)
{
    nErrors++;
    cout << "Error (" + to_string(nErrors) + "): " << message << endl;
}

// Logs a warning
void Log::warning(string message)
{
    nWarnings++;
    cout << "Warning (" + to_string(nWarnings) + "): " << message << endl;
}

// Logs an informational message
void Log::info(string message)
{
    nInfos++;
    cout << "Info (" + to_string(nInfos) + "): " << message << endl;
}

// Returns how many errors have occurred
unsigned Log::getNErrors()
{
    return nErrors;
}
