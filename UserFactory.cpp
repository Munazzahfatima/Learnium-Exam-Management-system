#include "UserFactory.h"
#include "Admin.h"
#include "Student.h"
#include <memory>
using namespace std;

unique_ptr<User> UserFactory::createUser(const string& role, const string& username, const string& password) {
    if (role == "Admin") {
        return make_unique<Admin>(username, password);
    } else if (role == "Student") {
        return make_unique<Student>(username, password);
    }
    throw runtime_error("Invalid user role");
}
