#include "file_utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void readStudentsFromFile(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error: Cannot open file " + filename);
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream stream(line);
        string firstName, lastName;
        vector<int> homework(5);
        int exam;

        stream >> lastName >> firstName;
        for (int& grade : homework) {
            stream >> grade;
        }
        stream >> exam;

        students.emplace_back(firstName, lastName, homework, exam);
    }
}
