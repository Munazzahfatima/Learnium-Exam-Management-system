#include "FileOperationException.h"
using namespace std;

FileOperationException::FileOperationException(const string& msg) : message(msg) {}

const char* FileOperationException::what() const noexcept {
    return message.c_str();
}
