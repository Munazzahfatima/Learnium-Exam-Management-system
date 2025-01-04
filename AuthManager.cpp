#include "AuthManager.h"
#include "UserFactory.h"
#include "FileOperationException.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

void AuthManager::registerUser(const string& role, const string& username, const string& password) {
    if (users.find(username) != users.end()) {
        throw runtime_error("Username already exists");
    }
    
    auto user = UserFactory::createUser(role, username, password);
    user->saveToFile();
    users[username] = move(user);
    Logger::getInstance()->log("New user registered: " + username);
}

User* AuthManager::login(const string& username, const string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second->login(username, password)) {
        return it->second.get();
    }
    throw LoginException();
}

void AuthManager::loadUsers() {
    try {
        ifstream file("users.txt");
        if (!file.is_open()) {
            throw FileOperationException("Unable to open users file");
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string role, username, password;
            getline(ss, role, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            
            if (!username.empty() && !password.empty()) {
                registerUser(role, username, password);
            }
        }
        file.close();
    } catch (const exception& e) {
        Logger::getInstance()->log("Error loading users: " + string(e.what()));
    }
}
