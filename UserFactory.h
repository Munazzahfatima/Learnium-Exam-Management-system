#ifndef USERFACTORY_H
#define USERFACTORY_H

#include <memory>
#include <string>
#include "User.h"
#include "Student.h"
#include "Admin.h"
#include <stdexcept>
using namespace std;
class UserFactory {
public:
    // Factory method to create a User object (Admin or Student)
    static unique_ptr<User> createUser(const string& role, const string& username, const string& password);
};

#endif
