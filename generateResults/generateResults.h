#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_set>
#include <chrono>
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
using namespace std::chrono;

milliseconds mil(1000);

struct TestResult{
    int testcase;
    duration_cast<milliseconds> executionTime;
    int score;
    int maxScore;
};


namespace fs = std::filesystem;


void getNaiveResults();
vector<int> checkCorrectness(Matrix experiment, Matrix actual);
void writeResultsToFile(const vector<TestResult>& results, const string& algorithm);

