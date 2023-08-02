#include "generateResults.h"


const string TESTDIR = "testcases";
const string ANSDIR = "answers";
const string RESULTSDIR = "results";


/**
    Each testcase will be ran by this algorithm
    each algorithm in algorithms will run a 
*/
void getNaiveResults(){
    unordered_set<string> testcases = getFileNames(TESTDIR);
    unordered_set<string> answers = getFileNames(ANSDIR);
    vector<TestResult> results;

    for(const auto& testcase : testcases){
        vector<Matrix> matrices = readMatricesFromFile(testcase);
        TestResult result;
        auto start = high_resolution_clock::now();
        Matrix naiveSol = naive(matrices[0], matrices[1]);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        int num = extractNumberFromFileName(testcase);
        string answerFileName = "answer_" + to_string(num) + ".txt";
        vector<Matrix> answerMatrix = readMatricesFromFile(answerFileName);
        vector<int> acuracy = checkCorrectness(naiveSol, answerMatrix[0]);
        result.testcase = num;
        result.executionTime = duration;
        result.score = acuracy[0];
        result.maxScore = acuracy[1];
        results.push_back(result);
    }
    writeResultsToFile(results, "naive");
}


/**

*/
vector<int> checkCorrectness(Matrix experiment, Matrix actual){
    vector<int> scores(2);

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
void writeResultsToFile(const vector<TestResult>& results, const string& algorithm){
    string filePath = RESULTSDIR + "/" + algorithm;

    ofstream file(filePath);
    if(file){
        for(auto& result : results){
            file << result.testcase << "\t" << result.executionTime.count() << "\t" <<
            result.score << "/" << result.maxScore << endl;
        }
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}
