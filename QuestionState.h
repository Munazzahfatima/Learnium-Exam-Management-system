#ifndef QUESTIONSTATE_H
#define QUESTIONSTATE_H

class Question;

class QuestionState {
public:
    virtual void handle(Question* question) = 0;
    virtual ~QuestionState() = default;
};

class UnansweredState : public QuestionState {
public:
    void handle(Question* question) override;
};

class AnsweredState : public QuestionState {
public:
    void handle(Question* question) override;
};

#endif
