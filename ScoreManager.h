#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <vector>
#include <string>

template<typename T>
class ScoreManager {
private:
    std::vector<T> scores;

public:
    void addScore(T score);
    T getAverage() const;
    void saveToFile(const std::string& filename) const; 
};

#endif
