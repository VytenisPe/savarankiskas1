#include <iostream>
#include <vector>
#include <iomanip> // Reikalinga setw ir setprecision
#include "student.h"

using namespace std;

int main() {
    vector<Student> students;

    // Nurodykite failo pavadinimą
    string filename = "studentai10000.txt"; // Čia įrašykite savo failo pavadinimą

    cout << "Reading data from file: " << filename << endl;
    Student::readFromFile(filename, students);

    if (students.empty()) {
        cerr << "No data was read. Please check the file format." << endl;
        return 1;
    }

    for (auto& student : students) {
        student.calculateFinalGrade();
    }

    cout << setw(15) << std::left << "Pavardė"
        << setw(15) << "Vardas"
        << setw(10) << "Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------\n";
    for (const auto& student : students) {
        cout << student << endl;
    }

    return 0;
}
