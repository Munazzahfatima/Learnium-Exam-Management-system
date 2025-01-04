#include "LoginException.h"

const char* LoginException::what() const noexcept {
    return "Invalid login credentials!";
}
