#include "Course.h"
#include "Logger.h"
#include "NotificationSystem.h"
#include <iostream>
#include <algorithm>
#include "AssignmentManager.h"
using namespace std;

// Constructor: Already defined
Course::Course(std::string name, std::string admin)
    : courseName(name), adminUsername(admin) {
    courseCode = generateCourseCode();
}

// Method to enroll a student: Already defined
bool Course::enrollStudent(const std::string& username) {
    if (enrolledStudents.size() >= MAX_STUDENTS) {
        return false;
    }
    if (std::find(enrolledStudents.begin(), enrolledStudents.end(), username) != enrolledStudents.end()) {
        return false;
    }
    enrolledStudents.push_back(username);
    return true;
}

// Method to drop a student: Already defined
bool Course::dropStudent(const std::string& username) {
    auto it = std::find(enrolledStudents.begin(), enrolledStudents.end(), username);
    if (it != enrolledStudents.end()) {
        enrolledStudents.erase(it);
        return true;
    }
    return false;
}

// Method to add content: Already defined
void Course::addContent(std::shared_ptr<CourseContent> content) {
    courseContents.push_back(content);
    NotificationSystem::notifyAll("New content added to " + courseName + ": " + content->getTitle());
}

// Method to generate a course code: Already defined
std::string Course::generateCourseCode() {
    std::string code = "CS";
    for (int i = 0; i < 3; i++) {
        code += std::to_string(rand() % 10);
    }
    return code;
}

void Course::addQuestionToExam(const string& examTitle, const string& questionText, 
                          const vector<string>& options, int correctAnswer) {
        for (auto& exam : exams) {
            if (exam->getTitle() == examTitle) {
                auto question = make_shared<Question>(questionText, options, correctAnswer);
                exam->addQuestion(question);
                break;
            }
        }
    }


void Course::activateExam(const string& examTitle) {
    for (auto& exam : exams) {
            if (exam->getTitle() == examTitle) {
                exam->startExam();
                NotificationSystem::notifyAll("Exam activated: " + examTitle);
                break;
            }
        }
    }

void Course::createAssignment(const string& title, const string& description, const string& dueDate) {
    auto assignment = make_shared<Assignment>(title, description, dueDate);
        assignments.push_back(assignment);
        assignmentManager.createAssignment(courseCode, assignment);
        NotificationSystem::notifyAll("New assignment created for " + courseName + ": " + title);
 
}

void Course::createExam(const string& title, int timeLimit) {
    auto exam = make_shared<Exam>(title, timeLimit);
    exams.push_back(exam);
    NotificationSystem::notifyAll("New exam created for " + courseName + ": " + title);
}

void Course::gradeAssignment(const string& studentUsername, const string& assignmentTitle, double score) {
        assignmentManager.gradeAssignment(courseCode, studentUsername, assignmentTitle, score);
}

vector<Grade> Course::getStudentGrades(const string& studentUsername) {
        return assignmentManager.getStudentGrades(studentUsername, courseCode);
}


std::string Course::getCourseName() const {
    return courseName;  // Return the name of the course
}

std::string Course::getCourseCode() const {
    return courseCode;  // Return the course code
}

string Course::getAdminUsername() const {
    return adminUsername;  // Return the admin username
}

const vector<string>& Course::getEnrolledStudents() const {
    return enrolledStudents;  // Return the list of enrolled students
}

vector<shared_ptr<CourseContent>> Course::getContents() const {
    return courseContents;  // Return the list of course contents
}

vector<shared_ptr<Assignment>> Course::getAssignments() const {
    return assignments;  // Return the list of assignments
}

vector<shared_ptr<Exam>> Course::getExams() const {
    return exams;  // Return the list of exams
}


