#include "student.h"
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <sstream>

using namespace std;

// Default constructor
Student::Student() : exam(0), finalGrade(0.0) {}

// Constructor with parameters
Student::Student(const string& first, const string& last, const vector<int>& hw, int ex)
    : firstName(first), lastName(last), homework(hw), exam(ex) {
    calculateFinalGrade();
}

// Copy constructor
Student::Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName), homework(other.homework),
    exam(other.exam), finalGrade(other.finalGrade) {}

// Assignment operator
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    return *this;
}

// Destructor
Student::~Student() {}

// Calculate final grade (average method)
void Student::calculateFinalGrade() {
    if (homework.empty()) {
        finalGrade = 0.6 * exam;
    }
    else {
        double average = accumulate(homework.begin(), homework.end(), 0.0) / static_cast<double>(homework.size());
        finalGrade = 0.4 * average + 0.6 * exam;
    }
}

// Calculate final grade using median
void Student::calculateFinalGradeWithMedian() {
    if (homework.empty()) {
        finalGrade = 0.6 * exam;
    }
    else {
        vector<int> temp = homework;
        sort(temp.begin(), temp.end());
        double median;
        if (temp.size() % 2 == 0) {
            median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
        }
        else {
            median = temp[temp.size() / 2];
        }
        finalGrade = 0.4 * median + 0.6 * exam;
    }
}

// Read student data from file
void Student::readFromFile(const string& filename, vector<Student>& students) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    getline(inputFile, line); // Skip header line

    while (getline(inputFile, line)) {
        istringstream stream(line);
        string firstName, lastName;
        stream >> firstName >> lastName;

        vector<int> homework;
        for (int i = 0; i < 15; ++i) {
            int grade;
            stream >> grade;
            homework.push_back(grade);
        }

        int exam;
        stream >> exam;

        students.emplace_back(firstName, lastName, homework, exam);
    }
}

// Input operator
istream& operator>>(istream& in, Student& student) {
    cout << "Enter first name: ";
    in >> student.firstName;
    cout << "Enter last name: ";
    in >> student.lastName;

    cout << "Enter homework grades (end with -1): ";
    int grade;
    student.homework.clear();
    while (in >> grade && grade != -1) {
        student.homework.push_back(grade);
    }

    cout << "Enter exam grade: ";
    in >> student.exam;

    return in;
}

// Output operator
ostream& operator<<(ostream& out, const Student& student) {
    out << setw(15) << left << student.lastName
        << setw(15) << student.firstName
        << setw(10) << fixed << setprecision(2) << student.finalGrade;
    return out;
}
