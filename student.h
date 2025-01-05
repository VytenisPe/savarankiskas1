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
    // Constructors and Destructor
    Student();
    Student(const string& first, const string& last, const vector<int>& hw, int ex);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    // Methods
    void calculateFinalGrade();
    void calculateFinalGradeWithMedian();
    static void readFromFile(const string& filename, vector<Student>& students);

    // Overloaded operators
    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);
};

#endif // STUDENT_H
