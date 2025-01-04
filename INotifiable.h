#ifndef INOTIFIABLE_H
#define INOTIFIABLE_H

#include <string>
using namespace std;
class INotifiable {
public:
    virtual void notify(const string& message) = 0;
    virtual ~INotifiable() = default;
};

#endif
