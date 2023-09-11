#include "generateTestCases.h"


const string DIRECTORY = "test/testcases";


/**
 * Function that generates test cases
 * Each test case will be 2 matrices
 * @param int seed - the random seed
 * @param int range - the range of the random numbers
 * @param int n - the rows
 * @param int m - the columns
 * @return mat - matrix of size n x m filled with random integers from random seed  
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
 * Go through the directory and find all the files of the same basename
 * all Files will be baseName_number.txt
 * we want to get the highest number to get the next subsequent number whenever
 * generating a new testcase
 * @return int
*/
int findHighestNumber(){
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
 * Get the number from the filename
 * expected filename is baseName_number.txt
 * @param string fileName
 * @return int 
*/
int extractNumberFromFileName(const string& fileName){
    int start = fileName.find("_") + 1;
    int end = fileName.find(".txt");
    int num = stoi(fileName.substr(start, end));
    return num;
}


/**
 * finds the next unique filename
 * @param string baseName
 * @return string
*/
string getUniqueFileName(const string& baseName){
    int highestNumber = findHighestNumber();
    return baseName + "_" + to_string(highestNumber + 1) + ".txt";
}


/**
 * Using string stream we create a string for the matrix
 * n
 * m
 * matrix
 * @param Matrix matrix
 * @return string
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
 * Using a fileStream to create and open a file
 * ofstream to write to the file
 * convert matrices into string and put into a file
 * we will make a new file for the basename
 * @param Matrix matrix1
 * @param Matrix matrix2
 * @param string baseName
*/
void writeMatrixToFile(const Matrix& matrix1, const Matrix& matrix2, const string& baseName){
    string fileName = getUniqueFileName(baseName);
    string filePath = DIRECTORY + "/" + fileName;
    // Create and opens the file at this path starts from current directory
    ofstream file(filePath);
    if(file){
        file << matrixToString(matrix1) << endl;
        file << matrixToString(matrix2);
        file.close();
        cout << "Test case written " << fileName << endl;
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


/**
 * The method that will be called by other classes to create a new testcase
 * @param baseName - the basename of the file testcase
 * @param seed, seed2 - the seed for the RNG
 * @param range, range2 - the range of the random numbers
 * @param n, n2 - the number of rows
 * @param m, m2 - the number of columns
*/
void generateTestCase(const string& baseName, int seed, int range, int n, int m,
int seed2, int range2, int n2, int m2){
    Matrix matrix = generateRandomMatrix(seed, range, n, m);
    Matrix matrix2 = generateRandomMatrix(seed2, range2, n2, m2);
    writeMatrixToFile(matrix, matrix2, baseName);
}
