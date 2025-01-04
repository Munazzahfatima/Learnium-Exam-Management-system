#include "Logger.h"
#include <ctime>
using namespace std;

Logger* Logger::instance = nullptr;

Logger::Logger() {
    logFile.open("system.log", ios::app);
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const std::string& message) {
    time_t now = time(0);
    string timestamp = ctime(&now);
    timestamp = timestamp.substr(0, timestamp.length() - 1); // Remove newline
    logFile << timestamp << ": " << message << endl;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
