#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <ctime>
using namespace std;
class Grade {
private:
    string studentUsername;
    string courseCode;
    string itemType; // "exam", "assignment"
    string itemName;
    double score;
    time_t gradedDate;
public:
    Grade(const string& student, const string& course, const string& type,
          const string& name, double score);
    double getScore() const;
    string getStudentUsername() const;
    string getCourseCode() const;
    string getItemType() const;
    string getItemName() const;
};

#endif
