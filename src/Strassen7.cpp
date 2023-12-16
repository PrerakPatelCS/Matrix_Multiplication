#include "include/Strassen7.hpp"

Strassen7::Strassen7(){

}

Matrix Strassen7::MatrixMult(Matrix& matrix1, Matrix& matrix2) {
    vector matrices = adjustMatrices(matrix1, matrix2);
    int n = matrix1[0].size();
    Matrix result = multiply(matrices[0], matrices[1]);
    result.resize(n);
    for(auto& row : result){
        row.resize(n);
    }
    return result;
}


/**
 * Given two square matrices that are a power of 2
 * using variable a and b similar to math terms
*/
Matrix Strassen7::multiply(const Matrix& a, const Matrix& b){
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
            }
        }

        // Calculating the 7 products recursively
        Matrix P1 = multiply(addMatrices(a00, a11), addMatrices(b00, b11));
        Matrix P2 = multiply(addMatrices(a10, a11), b00);
        Matrix P3 = multiply(a00, subtractMatrices(b01, b11));
        Matrix P4 = multiply(a11, subtractMatrices(b10, b00));
        Matrix P5 = multiply(addMatrices(a00, a01), b11);
        Matrix P6 = multiply(subtractMatrices(a10, a00), addMatrices(b00, b01));
        Matrix P7 = multiply(subtractMatrices(a01, a11), addMatrices(b10, b11));

        Matrix result00 = addMatrices(subtractMatrices(addMatrices(P1, P4), P5), P7);
        Matrix result01 = addMatrices(P3, P5);
        Matrix result10 = addMatrices(P2, P4);
        Matrix result11 = addMatrices(subtractMatrices(addMatrices(P1, P3), P2), P6);

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


