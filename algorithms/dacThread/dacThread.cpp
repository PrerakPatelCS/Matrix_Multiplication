#include "dacThread.h"


/**
    TODO
    1. If not square matrices turn it into a square
        1. We need to make the matrices the same size so get the highest
        dimension and add 0's so it is a square matrix of those dimensions
        furthur we need it to be a power of 2
*/


Matrix divideAndConquer(Matrix& matrix1, Matrix& matrix2){
    vector matrices = adjustMatrices(matrix1, matrix2);
    Matrix result = naive(matrices[0], matrices[1]);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    return result;
}


/**

*/
vector<Matrix> adjustMatrices(Matrix& matrix1, Matrix& matrix2){
    int dimension = findHighestDimension(matrix1, matrix2);
    vector<Matrix> result;
    result.push_back(convertToSquare(matrix1, dimension));
    result.push_back(convertToSquare(matrix2, dimension));
    return result;
}


/**

*/
int findHighestDimension(const Matrix& matrix1, const Matrix& matrix2){
    int n1 = matrix1.size();
    int m1 = matrix1[0].size();
    int n2 = matrix2.size();
    int m2 = matrix2[0].size();
    int highestDimension = max(n1, max(m1, max(n2, m2)));
    int power = 1;
    while(power < highestDimension){
        power *= 2;
    }
    return power;
}


/**

*/
Matrix convertToSquare(Matrix& matrix, int dimension){
    Matrix square(dimension, vector<int>(dimension));
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            square[i][j] = matrix[i][j];
        }
    }
    return square;
}

