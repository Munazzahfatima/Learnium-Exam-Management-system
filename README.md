# Learnium Exam Management System (LEMS)

This project is a comprehensive Learning Management System (LMS) implemented in C++. It features user registration, login functionality, course and assignment management, exam handling, notifications, and a robust grading system. It demonstrates various Object-Oriented Programming (OOP) principles, including inheritance, polymorphism, the singleton pattern, and the observer pattern.

## Features

### General
- **User Management**: Register and login as either an admin or a student.
- **Role-Based Access**: Admins and students have distinct functionality.

### For Admins
- Create and manage courses.
- Add course content (lectures, resources, materials).
- Create and manage assignments and exams.
- Grade assignments and view exam results.
- Send notifications to students.

### For Students
- Enroll in and drop courses.
- View course content and grades.
- Take exams and submit assignments.
- View notifications about courses.

### Technical Features
- **Design Patterns**: Singleton (Logger), Observer (Notification System), and State (Question State).
- **Error Handling**: Custom exceptions for file operations and login errors.
- **Persistence**: Data storage for users, scores, and logs.
- **Template Usage**: Generic score management.
- **Time Management**: Exam timer to track exam durations.

## Prerequisites

- C++17 or above
- Standard libraries: `<iostream>`, `<string>`, `<vector>`, `<ctime>`, `<fstream>`, `<map>`, `<memory>`, `<algorithm>`, `<sstream>`

## How to Run

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-name>
   ```
2. Compile the project using a C++ compiler:
   ```bash
   g++ projectoop.cpp -o LMS -std=c++17
   ```
3. Run the compiled program:
   ```bash
   ./LMS
   ```

## Usage

### Main Menu
1. **Register**: Create a new user (admin or student).
2. **Login**: Log in with your credentials to access role-specific features.
3. **Exit**: Exit the application.

### Admin Menu
- Add new courses and manage them.
- Create exams and assignments with customizable settings.
- View and grade student submissions.
- Manage course content and activate/deactivate exams.

### Student Menu
- View enrolled courses and their content.
- Submit assignments and take exams.
- View grades and exam results.
- Manage course enrollments.

## Project Structure

The program is organized into the following classes:
- **Core**: `User`, `Admin`, `Student`
- **Course Management**: `Course`, `CourseManager`, `CourseContent`
- **Exam Handling**: `Exam`, `ExamTimer`, `Question`
- **Assignment Management**: `Assignment`, `AssignmentManager`
- **Utility**: `Logger`, `AuthManager`, `NotificationSystem`

## Future Enhancements
- Add a graphical user interface (GUI).
- Integrate with a database for better scalability.
- Expand grading criteria and analytics.

## License
This project is licensed under the MIT License.

