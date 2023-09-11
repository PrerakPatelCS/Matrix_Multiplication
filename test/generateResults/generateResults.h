#ifndef GENERATERESULTS_H
#define GENERATERESULTS_H


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
#include "../../include/dacThread.h"


using namespace std;
using namespace chrono;
namespace fs = filesystem;


struct TestResult{
    int testcase;
    int score;
    int maxScore;
    double duration;
    
    bool operator < (const TestResult& res) const{
    	return (testcase < res.testcase);
    }
};


void getAllAlgorithmResults();
void getAlgorithmResults(int algorithm);
vector<int> checkCorrectness(Matrix experiment, Matrix actual);
void writeResultsToFile(vector<TestResult>& results, int algorithm);
double getAverageTime(int algorithm, vector<Matrix>& matrices, int n);
Matrix runAlgorithm(int algorithm, vector<Matrix>& matrices);
string getAlgorithmName(int algorithm);


#endif