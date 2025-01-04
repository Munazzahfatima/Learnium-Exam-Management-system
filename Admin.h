#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include <memory>
#include "Course.h"
using namespace std;

class Admin : public User {
private:
    vector<shared_ptr<Course>> teachingCourses;
public:
    Admin(string uname, string pwd);
    bool addCourse(const string& courseName);
    void viewTeachingCourses();
    void createExam(shared_ptr<Course> course);
    void createAssignment(shared_ptr<Course> course);
    void createCourseContent(shared_ptr<Course> course);
    void gradeAssignment(shared_ptr<Course> course);
    void manageExams(shared_ptr<Course> course);
    void displayMenu() override;
};

#endif
