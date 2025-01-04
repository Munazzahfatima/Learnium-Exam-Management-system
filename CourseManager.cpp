#include "CourseManager.h"
using namespace std;

vector<shared_ptr<Course>> CourseManager::allCourses;

void CourseManager::addCourse(shared_ptr<Course> course) {
    allCourses.push_back(course);
}

vector<shared_ptr<Course>> CourseManager::getAvailableCourses() {
    return allCourses;
}

shared_ptr<Course> CourseManager::findCourseByCode(const string& code) {
    for (auto& course : allCourses) {
        if (course->getCourseCode() == code) {
            return course;
        }
    }
    return nullptr;
}
