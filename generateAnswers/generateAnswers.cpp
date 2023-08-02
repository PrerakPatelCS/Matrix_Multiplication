#include "generateAnswers.h"


const string ANSDIR = "answers";
const string TESTDIR = "testcases";


/**

*/
vector<Matrix> readMatricesFromFile(const string& fileName){
    // opens file and allows read
    string filePath = TESTDIR + "/" + fileName;
    cout << filePath << endl;
    ifstream file(filePath);

    if(!file.is_open()){
        cerr << "Error : Failed to open the file " << fileName << endl;
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

*/
void generateAnswer(const string& testcase){
    vector<Matrix> matrices = readMatricesFromFile(testcase);
    Matrix matrix1 = matrices[0];
    Matrix matrix2 = matrices[1];
    Matrix result = naive(matrix1, matrix2);
    int num = extractNumberFromFileName(testcase);
    string fileName = "answer_" + to_string(num) + ".txt";
    writeMatrixToFile(result, fileName);
}


/**

*/
void writeMatrixToFile(const Matrix& matrix, const string& fileName){
    string filePath = ANSDIR + "/" + fileName;

    ofstream file(filePath);
    if(file){
        file << matrixToString(matrix) << endl;
        file.close();
        cout << "Answer written " << fileName << endl;
    }
    else{
        cerr << "Error opening file for writing." << endl;
    }
}


/**

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
