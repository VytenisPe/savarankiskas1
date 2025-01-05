#include "performance_utils.h"
#include <iostream>

void Timer::startTimer() {
    start = steady_clock::now();
}

double Timer::stopTimer(const string& operation) {
    auto end = steady_clock::now();
    double elapsed = duration_cast<milliseconds>(end - start).count() / 1000.0;
    cout << operation << " took " << elapsed << " seconds.\n";
    return elapsed;
}
