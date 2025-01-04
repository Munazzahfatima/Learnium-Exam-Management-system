#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <map>
#include <memory>
#include <string>
#include "User.h"
#include "LoginException.h"

class AuthManager {
private:
    std::map<std::string, std::unique_ptr<User>> users;

public:
    void registerUser(const std::string& role, const std::string& username, const std::string& password);
    User* login(const std::string& username, const std::string& password);
    void loadUsers();
};

#endif
