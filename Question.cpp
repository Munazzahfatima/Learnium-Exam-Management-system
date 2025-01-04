#include "Question.h"
#include <iostream>
using namespace std;

Question::Question(string text,vector<string> opts, int correct)
    : questionText(text), options(opts), correctAnswer(correct), isAnswered(false) {
    state = make_unique<UnansweredState>();
}

void Question::setState(unique_ptr<QuestionState> newState) {
    state =move(newState);
}

void Question::display() const {
    cout << questionText << endl;
    for (size_t i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

bool Question::checkAnswer(int answer) {
    if (answer < 1 || answer > static_cast<int>(options.size())) {
        cout << "Invalid answer! Please choose a valid option." << endl;
        return false;
    }
    isAnswered = true;
    setState(make_unique<AnsweredState>());
    return answer == correctAnswer;
}

bool Question::getIsAnswered() const { return isAnswered; }

string Question::getQuestionText() const { return questionText; }
