#ifndef EXAMTIMER_H
#define EXAMTIMER_H

#include <ctime>

class ExamTimer {
private:
    time_t startTime;
    int durationMinutes;

public:
    ExamTimer(int duration);
    bool isTimeUp() const;
    int getRemainingTime() const;
};

#endif
