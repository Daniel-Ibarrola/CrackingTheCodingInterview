//
// Created by daniel on 10/05/23.
//

#ifndef CRACKING_MATRIX_H
#define CRACKING_MATRIX_H

#include <unordered_set>
#include <vector>

using matrix = std::vector<std::vector<int>>;

void transposeMatrix(matrix& mat);

void rotateMatrix(matrix& mat);

void fillWithZeros(matrix& mat);


#endif //CRACKING_MATRIX_H
