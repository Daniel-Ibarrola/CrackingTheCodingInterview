//
// Created by daniel on 10/05/23.
//

#ifndef CRACKING_MATRIX_H
#define CRACKING_MATRIX_H

#include <array>
#include <unordered_set>
#include <vector>

using matrix = std::vector<std::vector<int>>;

void transposeMatrix(matrix& mat);

void rotateMatrix(matrix& mat);

void fillWithZeros(matrix& mat);

bool checkSudokuBoard(const std::array<std::array<int, 9>, 9>& board);

#endif //CRACKING_MATRIX_H
