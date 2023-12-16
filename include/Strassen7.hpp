#pragma once

#include <iostream>
#include <vector>
#include "MatrixMultiplication.hpp"
#include "Helper.hpp"

class Strassen7 : public MatrixMultiplication {
public:
    Strassen7();
    Matrix MatrixMult(Matrix& matrix1, Matrix& matrix2);
private:
    Matrix multiply(const Matrix& a, const Matrix& b);
};