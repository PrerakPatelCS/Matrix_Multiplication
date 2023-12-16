#pragma once

#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

vector<Matrix> adjustMatrices(Matrix& matrix1, Matrix& matrix2);
int findHighestDimension(const Matrix& matrix1, const Matrix& matrix2);
Matrix convertToSquare(Matrix& matrix, int dimension);
Matrix addMatrices(const Matrix& a, const Matrix& b);
Matrix subtractMatrices(const Matrix& a, const Matrix& b);