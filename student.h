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
    double finalGrade;

public:
    Student();
    Student(const string& first, const string& last, const vector<int>& hw, int ex);

    double calculateFinalGrade();
    const string& getFirstName() const;
    const string& getLastName() const;
    double getFinalGrade() const;

    friend ostream& operator<<(ostream& out, const Student& student);
};

#endif // STUDENT_H
