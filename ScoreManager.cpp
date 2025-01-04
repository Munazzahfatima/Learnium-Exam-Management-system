#include "ScoreManager.h"
#include <fstream>
#include <stdexcept>
#include <numeric>
#include "FileOperationException.h"
using namespace std;

// Template method definitions
template<typename T>
void ScoreManager<T>::addScore(T score) {
    scores.push_back(score);
}

template<typename T>
T ScoreManager<T>::getAverage() const {
    if (scores.empty()) return 0;
    T sum = accumulate(scores.begin(), scores.end(), T(0));
    return sum / scores.size();
}

template<typename T>
void ScoreManager<T>::saveToFile(const string& filename) const {
    try {
        ofstream file(filename);
        if (!file.is_open()) {
            throw FileOperationException("Unable to open score file: " + filename);
        }
        for (const T& score : scores) {
            file << score << endl;
        }
        file.close();
    } catch (const exception& e) {
        throw FileOperationException(e.what());
    }
}

// Explicit template instantiation for common types
template class ScoreManager<int>;
template class ScoreManager<double>;
