#include "include/Helper.hpp"


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


/**
 * 
*/
Matrix addMatrices(const Matrix& a, const Matrix& b){
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
 * 
*/
Matrix subtractMatrices(const Matrix& a, const Matrix& b){
    int n = a.size();
    Matrix result(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}