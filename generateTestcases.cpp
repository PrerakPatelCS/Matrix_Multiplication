#include "generateTestCases.h"


const string DIRECTORY = "testcases";


/**
    Function that generates test cases
    Each test case will be 2 matrices
    @param int seed - the random seed
    @param int n - the rows
    @param int m - the columns
    @return mat - matrix of size n x m filled with random integers from random
    seed
*/
vector<vector<int>> generateRandomMatrix(int seed, int range, int n, int m){
    vector<vector<int>> matrix(n, vector<int>(m));
    mt19937 rng(seed); // Random Number Generator
    uniform_int_distribution<int> dist(range * -1, range); // Range of Random integers

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = dist(rng);
        }
    }
    return matrix;
}


/**

*/
int findHighestNumber(const string& baseName){
    int highestNumber = 0;
    for(const auto& entry : fs::directory_iterator(DIRECTORY)){
        // Gets the filename only
        string fileName = entry.path().filename().string();
        int number = extractNumberFromFileName(fileName);
        highestNumber = max(highestNumber, number);
    }
    return highestNumber;
}


/**

*/
int extractNumberFromFileName(const string& fileName){
    int start = fileName.find("_") + 1;
    int end = fileName.find(".txt");
    int num = stoi(fileName.substr(start, end));
    return num;
}


/**

*/
string getUniqueFileName(const string& baseName){
    int highestNumber = findHighestNumber(baseName);
    return baseName + "_" + to_string(highestNumber + 1) + ".txt";
}


/**

*/
void writeMatrixToFile(const vector<vector<int>>& matrix, const string& baseName){
    string fileName = getUniqueFileName(baseName);
    string filePath = DIRECTORY + "/" + fileName;
    
    // Create and opens the file at this path starts from current directory
    ofstream file(filePath);
    if(file){
        for(const auto& row : matrix){
            for(int num : row){
                // Pipe into file and then separate with a space
                file << num << " ";
            }
            // new line
            file << endl;
        }
        file.close();
        cout << "Test case written " << fileName << endl;
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


/**

*/
void generateTestCase(const string& baseName, int seed, int range, int n, int m){
    vector<vector<int>> matrix = generateRandomMatrix(seed, range, n, m);
    writeMatrixToFile(matrix, baseName);
}
