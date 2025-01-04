#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

class Utility {
public:
    // Validates input within a specific range
    static int getValidatedInput(int min, int max);
    
    // Reads a line from standard input with optional prompt
    static string getLine(const string& prompt);
};

#endif
