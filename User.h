#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "INotifiable.h"
#include "FileOperationException.h"
#include "LoginException.h"
#include "Logger.h"
using namespace std;

class User : public INotifiable {
protected:
    string username;
    string password;
    string role;
    std::vector<std::string> notifications;
    static const int MAX_COURSES = 5;

public:
    User(std::string uname, std::string pwd);
    void notify(const std::string& message) override;
    virtual ~User();
    virtual bool login(std::string uname, std::string pwd);
    virtual void displayMenu() = 0;
    string getUsername() const;
    string getRole() const;
    virtual void saveToFile();
};

#endif
