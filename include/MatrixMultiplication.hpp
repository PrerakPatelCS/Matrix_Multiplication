#pragma once // guard clause


using namespace std;
using Matrix = vector<vector<int>>;

class MatrixMultiplication {
    public:
        virtual Matrix MatrixMult(
            Matrix& matrix1, Matrix& matrix2
        ) = 0;
        virtual ~MatrixMultiplication() = default;
};

