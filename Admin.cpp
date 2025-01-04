#include "Admin.h"
#include "Logger.h"
#include "CourseManager.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Admin::Admin(string uname, string pwd) : User(uname, pwd) {
    role = "admin";
}

bool Admin::addCourse(const string& courseName) {
    if(teachingCourses.size() >= MAX_COURSES) {
        cout << "Cannot teach more than " << MAX_COURSES << " courses!" << std::endl;
        return false;
    }

    auto course = make_shared<Course>(courseName, username);
    teachingCourses.push_back(course);
    CourseManager::addCourse(course);
    Logger::getInstance()->log("New course added: " + courseName);
    NotificationSystem::notifyAll("New course added: " + courseName);
    return true;
}

void Admin::viewTeachingCourses() {
    cout << "\nTeaching Courses:" << endl;
    if(teachingCourses.empty()) {
        cout << "No courses assigned." << endl;
        return;
    }

    for(size_t i = 0; i < teachingCourses.size(); i++) {
        cout << i + 1 << ". " << teachingCourses[i]->getCourseName()
                  << " (Code: " << teachingCourses[i]->getCourseCode() << ")" << endl;
        cout << "   Enrolled Students: " << teachingCourses[i]->getEnrolledStudents().size() << endl;
    }
}

void Admin::createExam(shared_ptr<Course> course) {
    string title;
    int timeLimit;

    cout << "Enter exam title: ";
    getline(cin, title);
    cout << "Enter time limit (in minutes): ";
    timeLimit = Utility::getValidatedInput(1, 180);

    course->createExam(title, timeLimit);

    int numQuestions;
    cout << "Enter number of questions: ";
    numQuestions = Utility::getValidatedInput(1, 50);

    for (int i = 0; i < numQuestions; i++) {
        string questionText;
        vector<string> options(4);

        cout << "\nEnter question " << (i + 1) << ": ";
        getline(cin, questionText);

        for (int j = 0; j < 4; j++) {
            cout << "Enter option " << (j + 1) << ": ";
            getline(cin, options[j]);
        }

        cout << "Enter correct answer (1-4): ";
        int correctAnswer = Utility::getValidatedInput(1, 4);

        course->addQuestionToExam(title, questionText, options, correctAnswer);
    }

    Logger::getInstance()->log("Exam created for " + course->getCourseName());
}

void Admin::createAssignment(shared_ptr<Course> course) {
    string title, description, dueDate;

    cout << "Enter assignment title: ";
    getline(cin, title);
    cout << "Enter assignment description: ";
    getline(cin, description);
    cout << "Enter due date: ";
    getline(cin, dueDate);

    course->createAssignment(title, description, dueDate);
    Logger::getInstance()->log("Assignment created for " + course->getCourseName());
}

void Admin::createCourseContent(shared_ptr<Course> course) {
    string title, content, type;
    cout << "Enter content title: ";
    getline(cin, title);
    cout << "Enter content type (lecture/resource/material): ";
    getline(cin, type);
    cout << "Enter content: ";
    getline(cin, content);

    auto courseContent = make_shared<CourseContent>(title, content, type);
    course->addContent(courseContent);
    Logger::getInstance()->log("Course content added to " + course->getCourseName());
}

void Admin::gradeAssignment(shared_ptr<Course> course) {
    auto assignments = course->getAssignments();
    if (assignments.empty()) {
        cout << "No assignments available." << endl;
        return;
    }

    cout << "\nAvailable Assignments:" << endl;
    for (const auto& assignment : assignments) {
        assignment->displayDetails();
    }

    cout << "Enter assignment title to grade: ";
    string title;
    getline(cin, title);

    auto students = course->getEnrolledStudents();
    for (const auto& student : students) {
        cout << "Enter grade for student " << student << " (0-100): ";
        double grade = Utility::getValidatedInput(0, 100);
        course->gradeAssignment(student, title, grade);
    }
}

void Admin::manageExams(shared_ptr<Course> course) {
    auto exams = course->getExams();
    if (exams.empty()) {
        cout << "No exams available." << endl;
        return;
    }

    cout << "\nAvailable Exams:" << endl;
    for (size_t i = 0; i < exams.size(); i++) {
        cout << (i + 1) << ". " << exams[i]->getTitle()
                  << (exams[i]->getIsActive() ? " (Active)" : " (Inactive)") << endl;
    }

    cout << "\n1. Activate Exam" << endl;
    cout << "2. View Results" << endl;
    cout << "3. Back" << endl;

    int choice = Utility::getValidatedInput(1, 3);

    if (choice == 1) {
        cout << "Enter exam number to activate: ";
        int examChoice = Utility::getValidatedInput(1, exams.size());
        course->activateExam(exams[examChoice - 1]->getTitle());
    } else if (choice == 2) {
        cout << "Enter exam number to view results: ";
        int examChoice = Utility::getValidatedInput(1, exams.size());
        auto scores = exams[examChoice - 1]->getScores();

        cout << "\nExam Results:" << endl;
        for (const auto& score : scores) {
            cout << "Student: " << score.first << ", Score: " << score.second << "%" << endl;
        }
    }
}

void Admin::displayMenu() {
    while (true) {
        cout << "\nAdmin Menu:" << endl;
        cout << "1. Add New Course" << endl;
        cout << "2. View Teaching Courses" << endl;
        cout << "3. Create Exam" << endl;
        cout << "4. Create Assignment" << endl;
        cout << "5. Create Course Content" << endl;
        cout << "6. Grade Assignments" << endl;
        cout << "7. Manage Exams" << endl;
        cout << "8. Logout" << endl;

        int choice = Utility::getValidatedInput(1, 8);

        switch (choice) {
            case 1: {
                string courseName;
                cout << "Enter course name: ";
                getline(cin, courseName);
                if(courseName.empty()) {
                    cout << "Course name cannot be empty!" << std::endl;
                    break;
                }
                addCourse(courseName);
                break;
            }
            case 2:
                viewTeachingCourses();
                break;
            case 3: {
                viewTeachingCourses();
                if(!teachingCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, teachingCourses.size());
                    createExam(teachingCourses[courseChoice - 1]);
                }
                break;
            }
            case 4: {
                viewTeachingCourses();
                if(!teachingCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, teachingCourses.size());
                    createAssignment(teachingCourses[courseChoice - 1]);
                }
                break;
            }
            case 5: {
                viewTeachingCourses();
                if(!teachingCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, teachingCourses.size());
                    createCourseContent(teachingCourses[courseChoice - 1]);
                }
                break;
            }
            case 6: {
                viewTeachingCourses();
                if(!teachingCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, teachingCourses.size());
                    gradeAssignment(teachingCourses[courseChoice - 1]);
                }
                break;
            }
            case 7: {
                viewTeachingCourses();
                if(!teachingCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, teachingCourses.size());
                    manageExams(teachingCourses[courseChoice - 1]);
                }
                break;
            }
            case 8:
                return;
            default:
                cout << "Invalid choice!" <<endl;
        }
    }
}
