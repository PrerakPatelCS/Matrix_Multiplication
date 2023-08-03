#include "generateResults.h"


const string TESTDIR = "testcases";
const string ANSDIR = "answers";
const string RESULTSDIR = "results";
const int RUNS = 10;
const int NAIVE = 1;

using TIMEUNIT = duration<double, std::micro>;


/**
    Each testcase will be ran by this algorithm
    each algorithm in algorithms will run a 
*/
void getNaiveResults(){
    unordered_set<string> testcases = getFileNames(TESTDIR);
    unordered_set<string> answers = getFileNames(ANSDIR);
    vector<TestResult> results;

    for(const auto& testcase : testcases){
        vector<Matrix> matrices = readMatricesFromFile(TESTDIR + "/" + testcase);
        TestResult result;
        
	double duration = getAverageTime(NAIVE, matrices, RUNS);
        Matrix naiveSol = naive(matrices[0], matrices[1]);
        int num = extractNumberFromFileName(testcase);
        string answerFileName = "answer_" + to_string(num) + ".txt";
        vector<Matrix> answerMatrix = readMatricesFromFile(ANSDIR + "/" + answerFileName);
        vector<int> acuracy = checkCorrectness(naiveSol, answerMatrix[0]);

        result.testcase = num;
        result.score = acuracy[0];
        result.maxScore = acuracy[1];
        result.duration = duration;
        results.push_back(result);
    }
    writeResultsToFile(results, "naive");
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
void runAlgorithm(int algorithm, vector<Matrix>& matrices){
    switch(algorithm){
        case 1:
            naive(matrices[0], matrices[1]);
            break;
        case 2:
            naive(matrices[0], matrices[1]);
            break;
        case 3:
            naive(matrices[0], matrices[1]);
            break;
        case 4:
            naive(matrices[0], matrices[1]);
            break;
    }
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
void writeResultsToFile(vector<TestResult>& results, const string& algorithm){
    string filePath = RESULTSDIR + "/" + algorithm;
    std::sort(results.begin(), results.end());
    
    ofstream file(filePath);
    if(file){
        file << "Testcase" << "\t" << "Time(micro)" << "\t" << "Accuracy" << endl;
        for(auto& result : results){
            file << "\t" << result.testcase << "\t" << fixed << setprecision(4) << result.duration << "\t\t" << result.score << "/" << result.maxScore << endl;
        }
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}
