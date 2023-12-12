#include "generateResults.h"

const string TESTDIR = "test/testcases";
const string ANSDIR = "test/answers";
const string RESULTSDIR = "test/results";
const string ALGORITHMSDIR = "src";
const int RUNS = 10;
const string UNITSTRING = "(micro)";
using TIMEUNIT = duration<double, std::micro>;
unordered_set<string> testcases;
unordered_set<string> answers;

/**
 * Go through the algorithms directory and generates the results of each algorithm
*/
void getAllAlgorithmResults(){
    vector<MatrixMultiplication*> algorithms;
    // add algorithms here
    algorithms.push_back(new Naive());

    for(MatrixMultiplication* algorithm : algorithms){
        getAlgorithmResults(algorithm);
    }
}


/**
 * Run each algorithm using this algorithm 
 * record the results and write it to the file associated with it
 * @param int algorithm
*/
void getAlgorithmResults(MatrixMultiplication* algorithm){
    // only get the files once
    if(testcases.size() == 0)
        testcases = getFileNames(TESTDIR);
    if(answers.size() == 0)
        answers = getFileNames(ANSDIR);
    
    vector<TestResult> results;

    for(const auto& testcase : testcases){
        vector<Matrix> matrices = readMatricesFromFile(TESTDIR + "/" + testcase);
        TestResult result;
        double duration = getAverageTime(algorithm, matrices);
        Matrix solution = algorithm->MatrixMult(matrices[0], matrices[1]);
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
 * Gets the testcase via matrices and runs the algorithm and sees how long it takes to run
 * @param int algorithm
 * @param vector matrices - the 2 matrices to be multiplied together
 * @param int n - number of runs
 * @return double - time to run
*/
double getAverageTime(MatrixMultiplication* algorithm, vector<Matrix>& matrices){
    double average = 0;
    for(int i = 0; i < RUNS; i++){
         // Initial time point
        auto start = high_resolution_clock::now();
        algorithm->MatrixMult(matrices[0], matrices[1]);
        // Subtracting 2 timepoints we get a duration
        TIMEUNIT duration = high_resolution_clock::now() - start;
        average += duration.count();
    }
    return average / RUNS;
}



/**
 * gets the name of the algorithm from an integer
 * @param int algorithm
 * @return string name
*/
string getAlgorithmName(MatrixMultiplication* algorithm){
    string name;
    if(dynamic_cast<Naive*>(algorithm)){
        return "Naive";
    }

    return name;
}


/**
 * Checks what the algorithm returns and what the answer should be
 * returns the score and the maxscore so score/maxscore will be the accuracy
 * @param Matrix, Matrix experiment, actual
 * @return vector<int>
*/
vector<int> checkCorrectness(Matrix experiment, Matrix actual){
    vector<int> scores;

    int n = experiment.size();
    int m = experiment[0].size();
    
    if((int) actual.size() != n){
    	scores.push_back(0);
    	scores.push_back(0);
        return scores;
    }
    else if((int) actual[0].size() != m){
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
 * writes the results to the file for that algorithm
 * Formated by testcase time then accuracy
 * @param vector results
 * @param int algorithm
*/
void writeResultsToFile(vector<TestResult>& results, MatrixMultiplication* algorithm){
    string filePath = RESULTSDIR + "/" + getAlgorithmName(algorithm);
    sort(results.begin(), results.end());
    
    ofstream file(filePath);
    if(file){
        file << "Testcase" << "\t" << "Time" << UNITSTRING << "\t" << "Accuracy" << endl;
        for(auto& result : results){
            file << "\t" << result.testcase << "\t" 
            << fixed << setprecision(4) << result.duration 
            << "\t\t" << result.score << "/" << result.maxScore << endl;
        }
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}