#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <filesystem>
#include <fstream>


using std::vector;
using std::mt19937;
using std::uniform_int_distribution;
using std::string;
using std::cout;
using std::max;
using std::to_string;
using std::max;
using std::endl;
using std::ofstream;
using std::cerr;


namespace fs = std::filesystem;

vector<vector<int>> generateRandomMatrix(int seed, int range, int n, int m);
int findHighestNumber(const string& baseName);
int extractNumberFromFileName(const string& fileName);
string getUniqueFileName(const string& baseName);
void writeMatrixToFile(const vector<vector<int>>& matrix, const string& baseName);
void generateTestCase(const string& baseName, int seed, int range, int n, int m);
