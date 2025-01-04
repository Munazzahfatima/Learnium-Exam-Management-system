#include "CourseContent.h"
#include <iostream>
using namespace std;

CourseContent::CourseContent(const string& t, const string& ty, const string& c)
    : title(t), type(ty), content(c) {
    uploadDate = time(nullptr);  // Initialize with the current time, or use another logic
}

string CourseContent::getTitle() const {
    return title;  // Return the title of the course content
}

string CourseContent::getType() const {
    return type;  // Return the type of content (e.g., video, document, etc.)
}

string CourseContent::getContent() const {
    return content;  // Return the content itself (could be a link, text, or file)
}

string CourseContent::getUploadDate() const {
    
    char buffer[80];
    struct tm* timeInfo = localtime(&uploadDate);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return string(buffer);
}
