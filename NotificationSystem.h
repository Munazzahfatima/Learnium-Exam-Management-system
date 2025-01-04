#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include <vector>
#include <string>
#include "INotifiable.h"
using namespace std;

class NotificationSystem {
private:
    static vector<INotifiable*> observers;
public:
    static void addObserver(INotifiable* observer);
    static void removeObserver(INotifiable* observer);
    static void notifyAll(const string& message);
};

#endif
