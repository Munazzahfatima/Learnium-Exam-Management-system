#ifndef LOGINEXCEPTION_H
#define LOGINEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class LoginException : public exception {
public:
    const char* what() const noexcept override;
};

#endif
