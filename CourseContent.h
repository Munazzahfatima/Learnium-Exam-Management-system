#ifndef COURSECONTENT_H
#define COURSECONTENT_H

#include <string>
#include <ctime>
#include <memory>
using namespace std;

class CourseContent {
private:
    string title;
    string type;
    string content;
    time_t uploadDate;  
public:
    CourseContent(const string& t, const string& ty, const string& c);
    
    string getTitle() const;
    string getType() const;
    string getContent() const;
    string getUploadDate() const;  
};

#endif
