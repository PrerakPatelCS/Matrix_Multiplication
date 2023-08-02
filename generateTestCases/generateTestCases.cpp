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
Matrix generateRandomMatrix(int seed, int range, int n, int m){
    Matrix matrix(n, vector<int>(m));
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
    Go through the directory and find all files of the same basename
    Files should be testcase_number.txt
    we want to get the next subsequent number whenever generating a new testcase
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
    Get the number from the filename
    expected filename is testcase_number.txt
    @param fileName
*/
int extractNumberFromFileName(const string& fileName){
    int start = fileName.find("_") + 1;
    int end = fileName.find(".txt");
    int num = stoi(fileName.substr(start, end));
    return num;
}


/**
    Get the highest number testcase in the directory
    Make a new filename that is the next subsequent number testcase
*/
string getUniqueFileName(const string& baseName){
    int highestNumber = findHighestNumber(baseName);
    return baseName + "_" + to_string(highestNumber + 1) + ".txt";
}


/**
    Turn a matrix into a string
    using String stream it is easy to pipe into it
    We want to store the number of rows and columns
    and then the matrix with spaces to separate the numbers
    @param matrix
*/
string matrixToString(const Matrix& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    stringstream ss;
    ss << n << endl;
    ss << m << endl;

    for(const auto& row : matrix){
        for(int num : row){
            ss << num << " ";
        }
        ss << endl;
    }
    return ss.str();
}


/**
    Using fileStream to create and open a file
    ofstream to write to the file
    We write the matrix strings into the file
    We need two matrices because we want the testcase to multiply matrices
    @param matrix
    @param matrix2
    @param baseName
*/
void writeMatrixToFile(const Matrix& matrix, const Matrix& matrix2, const string& baseName){
    string fileName = getUniqueFileName(baseName);
    string filePath = DIRECTORY + "/" + fileName;
    
    // Create and opens the file at this path starts from current directory
    ofstream file(filePath);
    if(file){
        file << matrixToString(matrix) << endl;
        file << matrixToString(matrix2);
        file.close();
        cout << "Test case written " << fileName << endl;
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


/**
    The method that will be called by other classes to create a new testcase
    @param baseName - the basename of the file testcase
    @param seed - the seed for the RNG
    @param range - the range of the random numbers
    @param n - the number of rows
    @param m - the number of columns
*/
void generateTestCase(const string& baseName, int seed, int range, int n, int m,
int seed2, int range2, int n2, int m2){
    Matrix matrix = generateRandomMatrix(seed, range, n, m);
    Matrix matrix2 = generateRandomMatrix(seed2, range2, n2, m2);
    writeMatrixToFile(matrix, matrix2, baseName);
}
