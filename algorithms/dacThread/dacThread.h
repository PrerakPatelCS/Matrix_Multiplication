#ifndef DACTHREAD_H
#define DACTHREAD_H


#include <iostream>
#include <vector>
#include "../naive/naive.h"


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::max;
using Matrix = std::vector<vector<int>>;


Matrix divideAndConquer(Matrix& matrix1, Matrix& matrix2);
vector<Matrix> adjustMatrices(Matrix& matrix1, Matrix& matrix2);
int findHighestDimension(const Matrix& matrix1, const Matrix& matrix2);
Matrix convertToSquare(Matrix& matrix, int dimension);


#endif