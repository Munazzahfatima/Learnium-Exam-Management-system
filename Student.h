#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>
#include <memory>
#include "Course.h"
using namespace std;
class Student : public User {
private:
    vector<shared_ptr<Course>> enrolledCourses;
public:
    Student(string uname, string pwd);
    bool enrollInCourse(shared_ptr<Course> course);
    bool dropCourse(shared_ptr<Course> course);
    void viewEnrolledCourses();
    void takeExam(shared_ptr<Course> course);
    void viewExamResults(shared_ptr<Course> course);
    void submitAssignment(shared_ptr<Course> course);
    void viewCourseContent(shared_ptr<Course> course);
    void viewGrades(shared_ptr<Course> course);
    void displayMenu() override;
};

#endif
