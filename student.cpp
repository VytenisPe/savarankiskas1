#include "student.h"
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

Student::Student() : exam(0), finalGradeAvg(0.0), finalGradeMed(0.0) {}

Student::Student(const string& first, const string& last, const vector<int>& hw, int ex)
    : firstName(first), lastName(last), homework(hw), exam(ex) {
    calculateFinalGrade();
    calculateFinalGradeWithMed();
}

const string& Student::getFirstName() const {
    return firstName;
}

const string& Student::getLastName() const {
    return lastName;
}

double Student::getFinalGradeAvg() const {
    return finalGradeAvg;
}

double Student::getFinalGradeMed() const {
    return finalGradeMed;
}

void Student::calculateFinalGrade() {
    double average = accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    finalGradeAvg = 0.4 * average + 0.6 * exam;
}

void Student::calculateFinalGradeWithMed() {
    vector<int> temp = homework;
    sort(temp.begin(), temp.end());
    double median = (temp.size() % 2 == 0)
        ? (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0
        : temp[temp.size() / 2];
    finalGradeMed = 0.4 * median + 0.6 * exam;
}

ostream& operator<<(ostream& out, const Student& student) {
    out << setw(15) << left << student.lastName
        << setw(15) << student.firstName
        << setw(20) << fixed << setprecision(2) << student.finalGradeAvg
        << setw(20) << student.finalGradeMed;
    return out;
}
