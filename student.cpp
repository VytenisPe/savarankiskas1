#include "student.h"
#include <numeric>
#include <iomanip>

Student::Student() : exam(0), finalGrade(0.0) {}

Student::Student(const string& first, const string& last, const vector<int>& hw, int ex)
    : firstName(first), lastName(last), homework(hw), exam(ex) {
    finalGrade = calculateFinalGrade();
}

double Student::calculateFinalGrade() {
    double average = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    return 0.4 * average + 0.6 * exam;
}

const string& Student::getFirstName() const {
    return firstName;
}

const string& Student::getLastName() const {
    return lastName;
}

double Student::getFinalGrade() const {
    return finalGrade;
}

ostream& operator<<(ostream& out, const Student& student) {
    out << setw(15) << left << student.lastName
        << setw(15) << student.firstName
        << setw(10) << fixed << setprecision(2) << student.finalGrade;
    return out;
}
