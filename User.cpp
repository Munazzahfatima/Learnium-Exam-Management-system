#include "User.h"
#include "Logger.h"
#include "NotificationSystem.h"
#include "LoginException.h"
#include "FileOperationException.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

User::User(string uname, string pwd)  {
    
    username = uname;
    password = pwd;
    NotificationSystem::addObserver(this);
}

void User::notify(const string& message) {
    notifications.push_back(message);
    cout << "Notification for " << username << ": " << message << endl;
}

User::~User() {
    NotificationSystem::removeObserver(this);
}

bool User::login(string uname, string pwd) {
    if (username != uname || password != pwd) {
        Logger::getInstance()->log("Failed login attempt for user: " + uname);
        throw LoginException();
    }
    Logger::getInstance()->log("Successful login for user: " + uname);
    return true;
}

void User::saveToFile() {
    try {
        ofstream file("users.txt", ios::app);
        if (!file.is_open()) {
            throw FileOperationException("Unable to open users file");
        }
        file << role << "," << username << "," << password << endl;
        file.close();
    } catch (const exception& e) {
        throw FileOperationException(e.what());
    }
}

string User::getUsername() const { return username; }

string User::getRole() const { return role; }
