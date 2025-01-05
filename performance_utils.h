#ifndef PERFORMANCE_UTILS_H
#define PERFORMANCE_UTILS_H

#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

class Timer {
private:
    steady_clock::time_point start;

public:
    void startTimer();
    double stopTimer(const string& operation);
};

#endif // PERFORMANCE_UTILS_H
