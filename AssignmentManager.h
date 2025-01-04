#ifndef ASSIGNMENTMANAGER_H
#define ASSIGNMENTMANAGER_H

#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Assignment.h"
#include "Grade.h"
using namespace std;

class AssignmentManager {
private:
    std::map<string, shared_ptr<Assignment>> assignments;
    std::map<string, vector<Grade>> grades;
public:
    void createAssignment(const string& courseCode, shared_ptr<Assignment> assignment);
    void gradeAssignment(const string& courseCode, const string& studentUsername, 
                         const string& assignmentTitle, double score);
    std::vector<Grade> getStudentGrades(const string& studentUsername, const string& courseCode);
};

#endif
