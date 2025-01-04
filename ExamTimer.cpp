#include "ExamTimer.h"
#include <ctime>
#include <algorithm>
using namespace std;

ExamTimer::ExamTimer(int duration) : durationMinutes(duration) {
    startTime = time(nullptr);
}

bool ExamTimer::isTimeUp() const {
    time_t currentTime = time(nullptr);
    return difftime(currentTime, startTime) >= durationMinutes * 60;
}

int ExamTimer::getRemainingTime() const {
    time_t currentTime = time(nullptr);
    int elapsedSeconds = static_cast<int>(difftime(currentTime, startTime));
    int remainingSeconds = (durationMinutes * 60) - elapsedSeconds;
    return max(0, remainingSeconds);
}
