#ifndef GENERATETESTCASES_H
#define GENERATETESTCASES_H


#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <sstream>


using namespace std;
using std::mt19937;
using std::uniform_int_distribution;
using std::string;
using std::ofstream;
using std::stringstream;
using Matrix = std::vector<vector<int>>;


namespace fs = std::filesystem;


vector<vector<int>> generateRandomMatrix(int seed, int range, int n, int m);
int findHighestNumber();
int extractNumberFromFileName(const string& fileName);
string getUniqueFileName(const string& baseName);
void writeMatrixToFile(const vector<vector<int>>& matrix, const string& baseName);
void generateTestCase(const string& baseName, int seed, int range, int n, int m, int seed2, int range2, int n2, int m2);
string matrixToString(const vector<vector<int>>& matrix);


#endif
