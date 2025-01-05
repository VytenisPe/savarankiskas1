#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    vector<int> homework;
    int exam;
    double finalGradeAvg;
    double finalGradeMed;

    void calculateFinalGrade();
    void calculateFinalGradeWithMed();

public:
    Student();
    Student(const string& first, const string& last, const vector<int>& hw, int ex);

    const string& getFirstName() const;
    const string& getLastName() const;
    double getFinalGradeAvg() const;
    double getFinalGradeMed() const;

    friend ostream& operator<<(ostream& out, const Student& student);
};

#endif
