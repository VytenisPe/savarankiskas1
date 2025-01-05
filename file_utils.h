#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "student.h"
#include <vector>
#include <string>

void generateFiles(const vector<int>& sizes);
void readStudentsFromFile(const string& filename, vector<Student>& students);
void writeStudentsToFile(const string& filename, const vector<Student>& students);

#endif // FILE_UTILS_H
