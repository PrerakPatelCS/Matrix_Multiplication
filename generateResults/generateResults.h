#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_set>
#include <chrono>
#include <algorithm>
#include "../generateTestCases/generateTestCases.h"
#include "../generateAnswers/generateAnswers.h"


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
using std::fixed;
using std::setprecision;
using namespace std::chrono;


struct TestResult{
    int testcase;
    int score;
    int maxScore;
    double duration;
    
    bool operator < (const TestResult& res) const{
    	return (testcase < res.testcase);
    }
};


namespace fs = std::filesystem;


void getNaiveResults();
vector<int> checkCorrectness(Matrix experiment, Matrix actual);
void writeResultsToFile(vector<TestResult>& results, const string& algorithm);
double getAverageTime(int algorithm, vector<Matrix>& matrices, int n);
void runAlgorithm(int algorithm, vector<Matrix>& matrices);

