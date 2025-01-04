#include "Grade.h"
#include <ctime>
using namespace std;

Grade::Grade(const string& student, const string& course, const string& type,
             const string& name, double score)
    : studentUsername(student), courseCode(course), itemType(type), itemName(name), score(score) {}


double Grade::getScore() const { return score; }
string Grade::getStudentUsername() const { return studentUsername; }
string Grade::getCourseCode() const { return courseCode; }
string Grade::getItemType() const { return itemType; }
string Grade::getItemName() const { return itemName; }
