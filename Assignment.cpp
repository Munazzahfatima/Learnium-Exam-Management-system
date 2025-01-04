#include "Assignment.h"
#include <iostream>
using namespace std;

Assignment::Assignment(string t, string desc, string due)
    : title(t), description(desc), dueDate(due) {}

void Assignment::submit(const string& username, const string& submission) {
    submissions[username] = submission;
    Logger::getInstance()->log("Assignment submitted by: " + username);
    NotificationSystem::notifyAll(username + " has submitted assignment: " + title);
}

void Assignment::displayDetails() const {
    cout << "\nAssignment: " << title << endl;
    cout << "Description: " << description <<endl;
    cout << "Due Date: " << dueDate << endl;
}

string Assignment::getTitle() const { return title; }

void Assignment::viewSubmissions() const {
    cout << "\nSubmissions for " << title << ":" << endl;
    for (const auto& submission : submissions) {
        cout << "Student: " << submission.first << endl;
        cout << "Submission: " << submission.second << endl;
        cout << "------------------------" << endl;
    }
}
