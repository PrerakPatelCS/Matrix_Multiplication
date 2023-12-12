#ifndef GENERATEANSWERS_H
#define GENERATEANSWERS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_set>
#include "../../include/Naive.hpp"
#include "../../include/MatrixMultiplication.hpp"
#include "../generateTestCases/generateTestCases.h"


using namespace std;
namespace fs = std::filesystem;


using Matrix = std::vector<vector<int>>;


vector<Matrix> readMatricesFromFile(const string& fileName);
unordered_set<string> getFileNames(const string& directory);
int extractNumberFromFileName(const string& fileName);
void generateAnswer(const string& testcase);
string matrixToString(const Matrix& matrix);
void writeMatrixToFile(const Matrix& matrix, const string& fileName);
void generateAllAnswers();

#endif