#include "generateAnswers.h"


const string ANSDIR = "test/answers";
const string TESTDIR = "test/testcases";


/**
 * Generates the matrices from the file. Matrices are stored in the file like
 * n
 * m
 * matrix
 * there are 2 matrices in a file
 * @param string filePath
 * @return vector<Matrix>
*/
vector<Matrix> readMatricesFromFile(const string& filePath){
    // opens file and allows read
    ifstream file(filePath);

    if(!file.is_open()){
        cerr << "Error : Failed to open the file " << filePath << endl;
        return {};
    }

    vector<Matrix> matrices;
    int n = 0, m = 0;
    // we need to read the data from the testcase file
    while(file >> n >> m){
        Matrix temp(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                file >> temp[i][j];
            }
        }
        matrices.push_back(temp);
    }
    file.close();
    return matrices;
}


/**
 * Gets all the file names from a directory
 * We will use this to get all the file names from the directories
 * Answers Testcases Results
 * gets all the file names from a directory
 * @param string directory
 * @return unordered_set<string> - all the filenames of that directory
*/
unordered_set<string> getFileNames(const string& directory){
    unordered_set<string> fileNames;

    for(const auto& entry : fs::directory_iterator(directory)){
        if(entry.is_regular_file()){
            fileNames.insert(entry.path().filename().string());
        }
    }
    return fileNames;
}


/**
 * Takes in a file name that is a testcase
 * runs naive matrix multiplication to get the answer
 * creates an answer file with the same number and stores the answer there
 * @param string testcase - filename of a testcase
*/
void generateAnswer(const string& testcase){
    vector<Matrix> matrices = readMatricesFromFile(TESTDIR + "/" + testcase);
    Matrix matrix1 = matrices[0];
    Matrix matrix2 = matrices[1];
    Matrix result = naive(matrix1, matrix2);
    int num = extractNumberFromFileName(testcase);
    string fileName = "answer_" + to_string(num) + ".txt";
    writeMatrixToFile(result, fileName);
}


/**
 * Writes a matrix under a filename, used for answers
 * @param Matrix matrix
 * @param string filename
*/
void writeMatrixToFile(const Matrix& matrix, const string& fileName){
    string filePath = ANSDIR + "/" + fileName;

    ofstream file(filePath);
    if(file){
        file << matrixToString(matrix) << endl;
        file.close();
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


/**
 * creates all the answers for the testcases that do not already
 * have answers for them
*/
void generateAllAnswers(){
    unordered_set<string> testcases = getFileNames(TESTDIR);
    unordered_set<string> answers = getFileNames(ANSDIR);
    for(const auto& testcase : testcases){
        int num = extractNumberFromFileName(testcase);
        auto iterator = answers.find("answers_" + to_string(num) + ".txt");
        // 1 position past the end of the array
        if(iterator != answers.end()){
            answers.erase(iterator);
        }
        else{
            generateAnswer(testcase);
        }
    }
}
