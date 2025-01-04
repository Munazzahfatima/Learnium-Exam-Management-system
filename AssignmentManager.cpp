#include "AssignmentManager.h"
#include "Assignment.h"
#include "Logger.h"
#include <iostream>
using namespace std;

// Implementation of AssignmentManager methods
void AssignmentManager::createAssignment(const string& courseCode, shared_ptr<Assignment> assignment) {
    assignments[courseCode] = assignment;
}

void AssignmentManager::gradeAssignment(const string& courseCode, const string& studentUsername,
                                         const string& assignmentTitle, double score) {
    Grade grade(studentUsername, courseCode, "Assignment", assignmentTitle, score);
    grades[courseCode].push_back(grade);
    Logger::getInstance()->log("Graded assignment " + assignmentTitle + " for student " + studentUsername);
}

vector<Grade> AssignmentManager::getStudentGrades(const string& studentUsername, const string& courseCode) {
   vector<Grade> studentGrades;
    
        for (const auto& grade : grades[courseCode]) {
            if (grade.getStudentUsername() == studentUsername) {
                studentGrades.push_back(grade);
            }
        }
    
    return studentGrades;
}
