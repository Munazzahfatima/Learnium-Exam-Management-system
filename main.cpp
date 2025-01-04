#include <iostream>
#include <algorithm>  
#include "AuthManager.h"
#include "Logger.h"
#include "NotificationSystem.h"
#include "Utility.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    AuthManager authManager;

    try {
        authManager.loadUsers();
        Logger::getInstance()->log("System started - Users loaded successfully");
    } catch (const exception& e) {
        cout << "Error loading users: " << e.what() <<endl;
        Logger::getInstance()->log("System startup error: " + string(e.what()));
    }

    while (true) {
        cout << "\n=== Learnium: The Smart Learning Solution ===" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "================================" << endl;

        int choice = Utility::getValidatedInput(1, 3);

        try {
            switch (choice) {
                case 1: {
                    string username, password, role;
                    cout << "\n=== User Registration ===" << endl;
                    cout << "Enter username: ";
                    getline(cin, username);
                    cout << "Enter password: ";
                    getline(cin, password);
                    do {
                        cout << "Enter role (Admin/Student): ";
                        getline(cin, role);
                        transform(role.begin(), role.end(), role.begin(), ::tolower);
                        role[0] = toupper(role[0]);
                    } while (role != "Admin" && role != "Student");

                    authManager.registerUser(role, username, password);
                    cout << "\nRegistration successful!" << endl;
                    Logger::getInstance()->log("New user registered: " + username + " as " + role);
                    break;
                }
                case 2: {
                    string username, password;
                    cout << "\n=== User Login ===" << endl;
                    cout << "Enter username: ";
                    getline(cin, username);
                    cout << "Enter password: ";
                    getline(cin, password);

                    User* user = authManager.login(username, password);
                    cout << "\nLogin successful! Welcome, " << user->getUsername() 
                              << " (" << user->getRole() << ")" << endl;

                    Logger::getInstance()->log("User logged in: " + username);
                    user->displayMenu();
                    Logger::getInstance()->log("User logged out: " + username);
                    break;
                }
                case 3: {
                    cout << "\nThank you for using the Learning Management System!" << endl;
                    Logger::getInstance()->log("System shutdown - normal exit");
                    return 0;
                }
                default:
                    cout << "\nInvalid choice! Please select 1-3." << endl;
            }
        } catch (const LoginException& e) {
            cout << "\nLogin Error: " << e.what() << endl;
        } catch (const FileOperationException& e) {
            cout << "\nFile Error: " << e.what() << endl;
        } catch (const exception& e) {
            cout << "\nError: " << e.what() << endl;
        }
    }

    return 0;
}
