#include "file_utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <random>

void generateFiles(const vector<int>& sizes) {
    for (int size : sizes) {
        string filename = "students_" + to_string(size) + ".txt";
        ofstream file(filename);
        if (!file) throw runtime_error("Error: Cannot create file " + filename);

        file << "Pavardė     Vardas      ND1 ND2 ND3 ND4 ND5 Egzaminas\n";
        for (int i = 1; i <= size; ++i) {
            file << "Pavarde" << i << "  Vardas" << i;
            for (int j = 0; j < 5; ++j) {
                file << " " << rand() % 10 + 1;
            }
            file << " " << rand() % 10 + 1 << "\n";
        }
    }
}

void readStudentsFromFile(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Error: Cannot open file " + filename);
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        istringstream stream(line);
        string lastName, firstName;
        vector<int> homework(5);
        int exam;

        if (!(stream >> lastName >> firstName)) {
            cerr << "Error: Failed to read lastName or firstName from line: " << line << endl;
            continue;
        }

        for (int& grade : homework) {
            if (!(stream >> grade)) {
                cerr << "Error: Failed to read homework grade from line: " << line << endl;
                continue;
            }
        }

        if (!(stream >> exam)) {
            cerr << "Error: Failed to read exam grade from line: " << line << endl;
            continue;
        }

        students.emplace_back(firstName, lastName, homework, exam);
    }
}

void writeStudentsToFile(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    if (!file) throw runtime_error("Error: Cannot write to file " + filename);

    file << "Pavardė     Vardas      Galutinis\n";
    for (const auto& student : students) {
        file << student << "\n";
    }
}
