#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_set>
#include "../algorithms/naive/naive.h"
#include "../generateTestCases/generateTestCases.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::cerr;
using std::stringstream;
using std::unordered_set;
using std::to_string;
using Matrix = std::vector<vector<int>>;


namespace fs = std::filesystem;


vector<Matrix> readMatricesFromFile(const string& fileName);
unordered_set<string> getFileNames(const string& directory);
int extractNumberFromFileName(const string& fileName);
void generateAnswer(const string& testcase);
string matrixToString(const Matrix& matrix);
void writeMatrixToFile(const Matrix& matrix, const string& fileName);
void generateAllAnswers();

