#pragma once


#include <iostream>
#include <vector>
#include "MatrixMultiplication.hpp"
#include "Helper.hpp"


class DivideAndConquer : public MatrixMultiplication {
public:
    DivideAndConquer();
    Matrix MatrixMult(Matrix& matrix1, Matrix& matrix2);
private:
    Matrix multiply(const Matrix& a, const Matrix& b);
};


