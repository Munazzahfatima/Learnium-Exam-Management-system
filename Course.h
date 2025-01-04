#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <memory>
#include "CourseContent.h"
#include "Assignment.h"
#include "Grade.h"
#include "Exam.h"
#include "AssignmentManager.h"
using namespace std;
class Course {
private:
    string courseCode;
    string courseName;
    string adminUsername;
    vector<string> enrolledStudents;
    vector<shared_ptr<CourseContent>> courseContents;
    vector<shared_ptr<Assignment>> assignments;
    AssignmentManager assignmentManager;
    vector<shared_ptr<Exam>> exams;
    static const int MAX_STUDENTS = 30;
public:
    Course(string name,string admin);
    bool enrollStudent(const string& username);
    bool dropStudent(const string& username);
    void addContent(shared_ptr<CourseContent> content);
    void createExam(const string& title, int timeLimit);
    void addQuestionToExam(const string& examTitle, const string& questionText, 
                            const vector<string>& options, int correctAnswer);
    void activateExam(const string& examTitle);
    void createAssignment(const string& title, const string& description, const string& dueDate);
    void gradeAssignment(const string& studentUsername, const string& assignmentTitle, double score);
    string generateCourseCode();
    vector<Grade> getStudentGrades(const string& studentUsername);
    string getCourseCode() const;
    string getCourseName() const;
    string getAdminUsername() const;
    const vector<string>& getEnrolledStudents() const;
    vector<shared_ptr<CourseContent>> getContents() const;
    vector<shared_ptr<Assignment>> getAssignments() const;
    vector<shared_ptr<Exam>> getExams() const;
};

#endif
