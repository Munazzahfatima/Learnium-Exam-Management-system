#ifndef FILEOPERATIONEXCEPTION_H
#define FILEOPERATIONEXCEPTION_H

#include <exception>
#include <string>
using namespace std;
class FileOperationException : public exception {
private:
    string message;

public:
    explicit FileOperationException(const string& msg); 
    const char* what() const noexcept override;  
};

#endif
