#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "Question.h"
#include "ScoreManager.h"
#include "ExamTimer.h"

class Exam {
private:
    std::string title;
    std::vector<std::shared_ptr<Question>> questions;
    int timeLimit;
    ScoreManager<double> scoreManager;
    bool isActive;
    std::map<std::string, double> studentScores;
    std::unique_ptr<ExamTimer> timer;

public:
    Exam(std::string t, int limit);
    void addQuestion(std::shared_ptr<Question> question);
    void startExam();
    void endExam();
    bool takeExam(const std::string& studentUsername);
    std::string getTitle() const;
    bool getIsActive() const;
    const std::map<std::string, double>& getScores() const;
};

#endif
