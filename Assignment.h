#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <map>
#include <memory>
#include "Logger.h"
#include "NotificationSystem.h"

class Assignment {
private:
    std::string title;
    std::string description;
    std::string dueDate;
    std::map<std::string, std::string> submissions;

public:
    Assignment(std::string t, std::string desc, std::string due);
    void submit(const std::string& username, const std::string& submission);
    void displayDetails() const;
    std::string getTitle() const;
    void viewSubmissions() const;
};

#endif
