#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <memory>
#include "QuestionState.h"

class Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    int correctAnswer;
    std::unique_ptr<QuestionState> state;
    bool isAnswered;

public:
    Question(std::string text, std::vector<std::string> opts, int correct);
    void setState(std::unique_ptr<QuestionState> newState);
    void display() const;
    bool checkAnswer(int answer);
    bool getIsAnswered() const;
    std::string getQuestionText() const;
};

#endif
