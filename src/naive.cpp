#include "include/naive.h"


Matrix naive(Matrix& matrix1, Matrix& matrix2){
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if(cols2 != rows2){
        throw runtime_error("Matrix dimensions are incompatible");
    }

    Matrix result(rows1, vector<int>(cols2, 0));

    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            for(int k = 0; k < cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}
