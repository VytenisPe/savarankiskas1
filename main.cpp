#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "student.h"
#include "file_utils.h"

using namespace std;

int main() {
    vector<Student> students;

    try {
        readStudentsFromFile("kursiokai.txt", students);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getLastName() < b.getLastName();
        });

    cout << setw(15) << left << "Pavarde"
        << setw(15) << "Vardas"
        << setw(20) << "Galutinis (Vid.)"
        << setw(20) << "Galutinis (Med.)" << endl;
    cout << string(66, '-') << endl;

    for (const auto& student : students) {
        cout << student << endl;
    }

    return 0;
}
