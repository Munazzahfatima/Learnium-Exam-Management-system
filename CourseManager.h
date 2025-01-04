#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include <vector>
#include <memory>
#include "Course.h"
using namespace std;
class CourseManager {
private:
    static vector<shared_ptr<Course>> allCourses;

public:
    static void addCourse(shared_ptr<Course> course);
    static vector<shared_ptr<Course>> getAvailableCourses();
    static shared_ptr<Course> findCourseByCode(const std::string& code);
};

#endif
