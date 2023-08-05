#include "dacThread.h"


/**
    TODO
    1. If not square matrices turn it into a square
        1. We need to make the matrices the same size so get the highest
        dimension and add 0's so it is a square matrix of those dimensions
        furthur we need it to be a power of 2
    2. We need to divide and conquer
    3. Divide the matrices by N/2
*/


Matrix divideAndConquer(Matrix& matrix1, Matrix& matrix2){
    vector matrices = adjustMatrices(matrix1, matrix2);
    
    Matrix result = matrixMultiplication(matrices[0], matrices[1]);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    return result;
}


/**
 * Given two square matrices that are a power of 2
 * using variable a and b similar to math terms
*/
Matrix matrixMultiplication(const Matrix& a, const Matrix& b){
    int n = a[0].size();
    Matrix result(n, vector<int>(n));
    // Base Case 2x2 matrix
    if(n == 2){
        result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    }
    else{
        int split = n / 2;
        Matrix a00(split, vector<int>(split));
        Matrix a01(split, vector<int>(split));
        Matrix a10(split, vector<int>(split));
        Matrix a11(split, vector<int>(split));
        Matrix b00(split, vector<int>(split));
        Matrix b01(split, vector<int>(split));
        Matrix b10(split, vector<int>(split));
        Matrix b11(split, vector<int>(split));

        for(int i = 0; i < split; i++){
            for(int j = 0; j < split; j++){
                a00[i][j] = a[i][j];
                a01[i][j] = a[i][j + split];
                a10[i][j] = a[i + split][j];
                a11[i][j] = a[i + split][j + split];

                b00[i][j] = b[i][j];
                b01[i][j] = b[i][j + split];
                b10[i][j] = b[i + split][j];
                b11[i][j] = b[i + split][j + split];
            }Matrix result01(split, vector<int>(split));
        Matrix result10(split, vector<int>(split));
        Matrix result11(split, vector<int>(split));
        }
        Matrix result00 = addMatrices(matrixMultiplication(a00, b00), matrixMultiplication(a01, b10));
        Matrix result01 = addMatrices(matrixMultiplication(a00, b01), matrixMultiplication(a01, b11));
        Matrix result10 = addMatrices(matrixMultiplication(a10, b00), matrixMultiplication(a11, b10));
        Matrix result11 = addMatrices(matrixMultiplication(a10, b01), matrixMultiplication(a11, b11));

        // Merge
        for(int i = 0; i < split; i++){
            for(int j = 0; j < split; j++){
                result[i][j] = result00[i][j];
                result[i][j + split] = result01[i][j];
                result[i + split][j] = result10[i][j];
                result[i + split][j + split] = result11[i][j];
            }
        }

    }
    return result;
}


/**
 * 
*/
Matrix addMatrices(Matrix& a, Matrix& b){
    int n = a.size();
    Matrix result(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
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

