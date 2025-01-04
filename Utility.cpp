#include "Utility.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Function to validate input within a given range
int Utility::getValidatedInput(int min, int max) {
    int choice;
    string input;
    bool valid = false;

    do {
        cout << "Enter choice (" << min << "-" << max << "): ";
        getline(cin, input);
        
        if (input.empty()) {
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            choice = stoi(input);
            if (choice >= min && choice <= max) {
                valid = true;
            } else {
                cout << "Invalid choice. Please enter a number between " << min << " and " << max << "." << endl;
            }
        } catch (const exception&) {
            cout << "Invalid input. Please enter a valid number." << endl;
        }

    } while (!valid);

    return choice;
}

// Function to read a line from standard input
string Utility::getLine(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}
