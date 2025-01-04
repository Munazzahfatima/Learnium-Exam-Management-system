#include "NotificationSystem.h"
#include <algorithm>
using namespace std;

vector<INotifiable*> NotificationSystem::observers;

void NotificationSystem::addObserver(INotifiable* observer) {
    observers.push_back(observer);
}

void NotificationSystem::removeObserver(INotifiable* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void NotificationSystem::notifyAll(const string& message) {
    for (auto observer : observers) {
        observer->notify(message);
    }
}
