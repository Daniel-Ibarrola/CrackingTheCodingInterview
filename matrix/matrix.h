//
// Created by daniel on 10/05/23.
//

#ifndef CRACKING_MATRIX_H
#define CRACKING_MATRIX_H

#include <array>
#include <unordered_set>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

void transposeMatrix(Matrix& mat);

void rotateMatrix(Matrix& mat);

void fillWithZeros(Matrix& mat);

bool checkSudokuBoard(const std::array<std::array<int, 9>, 9>& board);

std::vector<int> spiralOrder(Matrix& matrix);

Matrix createSpiralMatrix(int numElements);

std::vector<int> diagonalOrder(const Matrix& matrix);

#endif //CRACKING_MATRIX_H
