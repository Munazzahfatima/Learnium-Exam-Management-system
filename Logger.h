#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Logger {
private:
    static Logger* instance;
    ofstream logFile;
    Logger();
public:
    static Logger* getInstance();
    void log(const string& message);
    ~Logger();
};

#endif
