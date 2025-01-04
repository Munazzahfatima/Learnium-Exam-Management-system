#include "Exam.h"
#include "Logger.h"
#include "NotificationSystem.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Exam::Exam(string t, int limit) : title(t), timeLimit(limit), isActive(false) {}

void Exam::addQuestion(shared_ptr<Question> question) {
    questions.push_back(question);
}

void Exam::startExam() {
    isActive = true;
    timer = make_unique<ExamTimer>(timeLimit);
}

void Exam::endExam() {
    isActive = false;
    timer.reset();
}

bool Exam::takeExam(const string& studentUsername) {
    if (!isActive || questions.empty()) {
        cout << "Exam is not available." << endl;
        return false;
    }

    startExam();
    double score = 0;
    int totalQuestions = questions.size();

    cout << "\nExam: " << title << std::endl;
    cout << "Time limit: " << timeLimit << " minutes" << endl;

    for (size_t i = 0; i < questions.size(); i++) {
        if (timer->isTimeUp()) {
            cout << "\nTime's up! Exam ended." << endl;
            break;
        }

        cout << "\nTime remaining: " << timer->getRemainingTime() / 60
                  << " minutes " << timer->getRemainingTime() % 60 << " seconds" << endl;

        cout << "\nQuestion " << (i + 1) << "/" << totalQuestions << ":" << endl;
        questions[i]->display();

        int answer = Utility::getValidatedInput(1, 4);
        if (questions[i]->checkAnswer(answer)) {
            score++;
        }
    }

    double finalScore = (score / totalQuestions) * 100;
    studentScores[studentUsername] = finalScore;
    scoreManager.addScore(finalScore);
    endExam();

    return true;
}

string Exam::getTitle() const { return title; }

bool Exam::getIsActive() const { return isActive; }

const map<string, double>& Exam::getScores() const { return studentScores; }
