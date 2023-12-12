#include <iostream>
#include "include/Naive.hpp"
#include "include/MatrixMultiplication.hpp"


int main() {
    // Create instances of your classes
    // Naive naive;
    MatrixMultiplication* naive = new Naive();

    // Define matrices for testing
    Matrix matrix1 = { {1, 2}, {3, 4} };
    Matrix matrix2 = { {5, 6}, {7, 8} };
    // Test matrix multiplication


    Matrix result = naive->MatrixMult(matrix1, matrix2);
    for(vector<int> row : result){
        for(int num : row){
            cout << num << '\t';
        }
        cout << endl;
    }


    return 0;
}
