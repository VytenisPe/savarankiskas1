#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"
#include "file_utils.h"
#include "performance_utils.h"

using namespace std;

int main() {
    vector<int> sizes = { 1000, 10000, 100000, 1000000, 10000000 };
    Timer timer;

    // Generate files
    timer.startTimer();
    generateFiles(sizes);
    timer.stopTimer("File generation");

    for (int size : sizes) {
        vector<Student> students, vargsiukai, kietiakai;

        string filename = "students_" + to_string(size) + ".txt";

        // Read file
        timer.startTimer();
        readStudentsFromFile(filename, students);
        timer.stopTimer("Reading file: " + filename);

        // Categorize students
        timer.startTimer();
        for (const auto& student : students) {
            if (student.getFinalGrade() < 5.0)
                vargsiukai.push_back(student);
            else
                kietiakai.push_back(student);
        }
        timer.stopTimer("Categorizing students");

        // Write to files
        timer.startTimer();
        writeStudentsToFile("vargsiukai_" + to_string(size) + ".txt", vargsiukai);
        writeStudentsToFile("kietiakai_" + to_string(size) + ".txt", kietiakai);
        timer.stopTimer("Writing categorized students to files");
    }

    return 0;
}
