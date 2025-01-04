#include "Student.h"
#include "CourseManager.h"
#include "Logger.h"
#include "NotificationSystem.h"
#include "Utility.h"
#include <iostream>
#include <algorithm>
using namespace std;

Student::Student(string uname,string pwd) : User(uname, pwd) {
    role = "student";
}

bool Student::enrollInCourse(shared_ptr<Course> course) {
    if (enrolledCourses.size() >= MAX_COURSES) {
        cout << "Cannot enroll in more than " << MAX_COURSES << " courses!" << endl;
        return false;
    }

    if (course->enrollStudent(username)) {
        enrolledCourses.push_back(course);
        Logger::getInstance()->log(username + " enrolled in " + course->getCourseName());
        NotificationSystem::notifyAll(username + " enrolled in " + course->getCourseName());
        return true;
    }
    return false;
}

bool Student::dropCourse(std::shared_ptr<Course> course) {
    auto it = find(enrolledCourses.begin(), enrolledCourses.end(), course);
    if (it != enrolledCourses.end()) {
        course->dropStudent(username);
        enrolledCourses.erase(it);
        Logger::getInstance()->log(username + " dropped " + course->getCourseName());
        NotificationSystem::notifyAll(username + " dropped " + course->getCourseName());
        return true;
    }
    return false;
}

void Student::viewEnrolledCourses() {
    cout << "\nEnrolled Courses:" << std::endl;
    if (enrolledCourses.empty()) {
        std::cout << "No courses enrolled." << std::endl;
        return;
    }

    for (size_t i = 0; i < enrolledCourses.size(); i++) {
        cout << i + 1 << ". " << enrolledCourses[i]->getCourseName()
                  << " (Code: " << enrolledCourses[i]->getCourseCode() << ")"
                  << " - Instructor: " << enrolledCourses[i]->getAdminUsername() << endl;
    }
}

void Student::takeExam(std::shared_ptr<Course> course) {
    auto exams = course->getExams();
    vector<shared_ptr<Exam>> activeExams;

    for (const auto& exam : exams) {
        if (exam->getIsActive()) {
            activeExams.push_back(exam);
        }
    }

    if (activeExams.empty()) {
        cout << "No active exams available." << endl;
        return;
    }

    std::cout << "\nActive Exams:" << std::endl;
    for (size_t i = 0; i < activeExams.size(); i++) {
        cout << (i + 1) << ". " << activeExams[i]->getTitle() << endl;
    }

    cout << "Choose exam to take (0 to cancel): ";
    int choice = Utility::getValidatedInput(0, activeExams.size());

    if (choice == 0) return;

    if (activeExams[choice - 1]->takeExam(username)) {
        Logger::getInstance()->log("Student " + username + " completed exam: " + activeExams[choice - 1]->getTitle());
    }
}

void Student::viewExamResults(std::shared_ptr<Course> course) {
    auto exams = course->getExams();
    if (exams.empty()) {
        cout << "No exams available." << endl;
        return;
    }

    cout << "\nExam Results:" << endl;
    for (const auto& exam : exams) {
        auto scores = exam->getScores();
        auto it = scores.find(username);
        if (it != scores.end()) {
            cout << exam->getTitle() << ": " << it->second << "%" << endl;
        }
    }
}

void Student::submitAssignment(std::shared_ptr<Course> course) {
    auto assignments = course->getAssignments();
    if (assignments.empty()) {
        cout << "No assignments available." << endl;
        return;
    }

    cout << "\nAvailable Assignments:" <<endl;
    for (size_t i = 0; i < assignments.size(); i++) {
        cout << (i + 1) << ". ";
        assignments[i]->displayDetails();
    }

    int choice = Utility::getValidatedInput(1, assignments.size());

    string submission;
    cout << "Enter your submission: ";
    getline(cin, submission);

    assignments[choice - 1]->submit(username, submission);
}

void Student::viewCourseContent(std::shared_ptr<Course> course) {
    auto contents = course->getContents();
    if (contents.empty()) {
        cout << "No content available for this course." << endl;
        return;
    }

    cout << "\nCourse Contents for " << course->getCourseName() << ":" << endl;
    for (const auto& content : contents) {
        cout << "\nTitle: " << content->getTitle() << endl;
        cout << "Type: " << content->getType() << endl;
        cout << "Upload Date: " << content->getUploadDate();
        cout << "Content: " << content->getContent() << endl;
        cout << "------------------------" << endl;
    }
}

void Student::viewGrades(std::shared_ptr<Course> course) {
    auto grades = course->getStudentGrades(username);
    if (grades.empty()) {
        cout << "No grades available for this course." << endl;
        return;
    }

    cout << "\nGrades for " << course->getCourseName() << ":" << endl;
    for (const auto& grade : grades) {
        cout << grade.getItemType() << ": " << grade.getItemName() << endl;
        cout << "Score: " << grade.getScore() << endl;
        cout << "------------------------" << endl;
    }
}

void Student::displayMenu() {
    while (true) {
        cout << "\nStudent Menu:" <<endl;
        cout << "1. View Enrolled Courses" << endl;
        cout << "2. Enroll in Course" << endl;
        cout << "3. Drop Course" << endl;
        cout << "4. Take Exam" << endl;
        cout << "5. Submit Assignment" << endl;
        cout << "6. View Course Content" << endl;
        cout << "7. View Grades" <<endl;
        cout << "8. View Exam Results" << endl;
        cout << "9. Logout" << endl;

        int choice = Utility::getValidatedInput(1, 9);

        switch (choice) {
            case 1:
                viewEnrolledCourses();
                break;
            case 2: {
                auto availableCourses = CourseManager::getAvailableCourses();
                cout << "\nAvailable Courses:" << endl;
                for(size_t i = 0; i < availableCourses.size(); i++) {
                   cout << i + 1 << ". " << availableCourses[i]->getCourseName()
                              << " (Code: " << availableCourses[i]->getCourseCode() << ")" << endl;
                }
                if(!availableCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, availableCourses.size());
                    enrollInCourse(availableCourses[courseChoice - 1]);
                }
                break;
            }
            case 3: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    dropCourse(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 4: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    takeExam(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 5: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    submitAssignment(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 6: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    viewCourseContent(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 7: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    viewGrades(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 8: {
                viewEnrolledCourses();
                if(!enrolledCourses.empty()) {
                    int courseChoice = Utility::getValidatedInput(1, enrolledCourses.size());
                    viewExamResults(enrolledCourses[courseChoice - 1]);
                }
                break;
            }
            case 9:
                return;
            default:
                cout << "Invalid choice!" <<endl;
        }
    }
}
