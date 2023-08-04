#include "generateResults.h"


const string TESTDIR = "testcases";
const string ANSDIR = "answers";
const string RESULTSDIR = "results";
const string ALGORITHMSDIR = "algorithms";
const int RUNS = 10;
const string UNITSTRING = "(micro)";
using TIMEUNIT = duration<double, std::micro>;


/**

*/
void getAllAlgorithmResults(){
    int algorithms = 0;
    for(const auto& entry : fs::directory_iterator(ALGORITHMSDIR)){
        if(fs::is_directory(entry)){
            getAlgorithmResults(++algorithms);
        }
    }
}


/**
    Each testcase will be ran by this algorithm
    each algorithm in algorithms will run a 
*/
void getAlgorithmResults(int algorithm){
    unordered_set<string> testcases = getFileNames(TESTDIR);
    unordered_set<string> answers = getFileNames(ANSDIR);
    vector<TestResult> results;

    for(const auto& testcase : testcases){
        vector<Matrix> matrices = readMatricesFromFile(TESTDIR + "/" + testcase);
        TestResult result;
        double duration = getAverageTime(algorithm, matrices, RUNS);
        Matrix solution = runAlgorithm(algorithm, matrices);
        int num = extractNumberFromFileName(testcase);
        string answerFileName = "answer_" + to_string(num) + ".txt";
        vector<Matrix> answerMatrix = readMatricesFromFile(ANSDIR + "/" + answerFileName);
        vector<int> acuracy = checkCorrectness(solution, answerMatrix[0]);

        result.testcase = num;
        result.score = acuracy[0];
        result.maxScore = acuracy[1];
        result.duration = duration;
        results.push_back(result);
    }
    writeResultsToFile(results, algorithm);
}


/**

*/
double getAverageTime(int algorithm, vector<Matrix>& matrices, int n){
    double average = 0;
    for(int i = 0; i < n; i++){
         // Initial time point
        auto start = high_resolution_clock::now();
        runAlgorithm(algorithm, matrices);
        // Subtracting 2 timepoints we get a duration
        TIMEUNIT duration = high_resolution_clock::now() - start;
        average += duration.count();
    }
    return average / n;
}


/**

*/
Matrix runAlgorithm(int algorithm, vector<Matrix>& matrices){
    Matrix result;
    switch(algorithm){
        case 1:
            result = naive(matrices[0], matrices[1]);
            break;
        case 2:
            result = divideAndConquer(matrices[0], matrices[1]);
            break;
        case 3:
            naive(matrices[0], matrices[1]);
            break;
        case 4:
            naive(matrices[0], matrices[1]);
            break;
    }
    return result;
}


/**

*/
string getAlgorithmName(int algorithm){
    string name;
    switch(algorithm){
        case 1:
            name = "naive";
            break;
        case 2:
            name = "divideAndConquer";
            break;
        case 3:
            name = "naive";
            break;
        case 4:
            name = "naive";
            break;
    }
    return name;
}


/**

*/
vector<int> checkCorrectness(Matrix experiment, Matrix actual){
    vector<int> scores;

    int n = experiment.size();
    int m = experiment[0].size();
    
    if(actual.size() != n){
    	scores.push_back(0);
    	scores.push_back(0);
        return scores;
    }
    else if(actual[0].size() != m){
        scores.push_back(0);
    	scores.push_back(0);
        return scores;
    }

    
    int maxScore = n * m;
    int score = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(experiment[i][j] == actual[i][j]){
                score++;
            }
        }
    }

    scores.push_back(score);
    scores.push_back(maxScore);
    
    return scores;
}


/**

*/
void writeResultsToFile(vector<TestResult>& results, int algorithm){
    string filePath = RESULTSDIR + "/" + getAlgorithmName(algorithm);
    std::sort(results.begin(), results.end());
    
    ofstream file(filePath);
    if(file){
        file << "Testcase" << "\t" << "Time" << UNITSTRING << "\t" << "Accuracy" << endl;
        for(auto& result : results){
            file << "\t" << result.testcase << "\t" << fixed << setprecision(4) << result.duration << "\t\t" << result.score << "/" << result.maxScore << endl;
        }
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


