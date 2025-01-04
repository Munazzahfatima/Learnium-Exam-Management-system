#include "QuestionState.h"
#include "Question.h"
#include <iostream>
using namespace std;

void UnansweredState::handle(Question* question) {
    if (!question->getIsAnswered()) {
        cout << "Question is ready to be answered." << endl;
    }
}

void AnsweredState::handle(Question* question) {
    if (question->getIsAnswered()) {
        cout << "Question has been answered." << endl;
    }
}
