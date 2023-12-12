#pragma once


#include <iostream>
#include <vector>
#include "MatrixMultiplication.hpp"

class Naive : public MatrixMultiplication {
public:
    Naive();
    Matrix MatrixMult(Matrix& matrix1, Matrix& matrix2);

};


