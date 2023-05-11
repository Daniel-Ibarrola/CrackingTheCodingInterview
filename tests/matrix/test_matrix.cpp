//
// Created by daniel on 10/05/23.
//

#include "gtest/gtest.h"
#include "matrix.h"


TEST(TestTranspose, Matrix3X3)
{
    matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    matrix transpose {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
    };
    transposeMatrix(mat);
    ASSERT_EQ(mat, transpose);
}


TEST(TestTranspose, Matrix4X4)
{
    matrix mat {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
    };
    matrix transpose {
            {1, 5 ,9 , 13},
            {2, 6, 10, 14},
            {3, 7, 11 ,15},
            {4, 8, 12, 16},
    };
    transposeMatrix(mat);
    ASSERT_EQ(mat, transpose);
}


TEST(TestRotateMatrixInplace, Matrix3X3)
{
    matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    matrix expected {
            {3, 6, 9},
            {2, 5, 8},
            {1, 4, 7},
    };
    rotateMatrix(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestRotateMatrixInplace, Matrix4X4)
{
    matrix mat {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
    };
    matrix expected {
            {4, 8, 12, 16},
            {3, 7, 11, 15},
            {2, 6, 10, 14},
            {1, 5, 9, 13},
    };
    rotateMatrix(mat);
    ASSERT_EQ(mat, expected);
}

TEST(TestFillWithZeros, Matrix1)
{
    matrix mat {
            {1, 2, 3},
            {4, 0, 6},
            {7, 8, 9},
    };
    matrix expected {
            {1, 0, 3},
            {0, 0, 0},
            {7, 0, 9},
    };
    fillWithZeros(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestFillWithZeros, Matrix2)
{
    matrix mat {
            {1, 2, 3, 0},
            {4, 5, 6, 7},
    };
    matrix expected {
            {0, 0, 0, 0},
            {4, 5, 6, 0},
    };
    fillWithZeros(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestFillWithZeros, MultipleZeros)
{
    matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {0, 7, 0},
    };
    matrix expected {
            {0, 2, 0},
            {0, 5, 0},
            {0, 0, 0},
    };
    fillWithZeros(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestCheckSudoku, ValidBoard)
{
    std::array<std::array<int, 9>, 9> board{{
                {5, 3, 4, 6, 7, 8, 9, 1, 2},
                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                {1, 9, 8, 3, 4, 2, 5, 6, 7},
                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                {3, 4, 5, 2, 8, 6, 1, 7, 9},
                }};
    ASSERT_TRUE(checkSudokuBoard(board));
}


TEST(TestCheckSudoku, InvalidBoardWrongValueInRow)
{
    std::array<std::array<int, 9>, 9> board{{
            {5, 3, 4, 5, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {1, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 7, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 1},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9},
        }};
    ASSERT_FALSE(checkSudokuBoard(board));
}

TEST(TestCheckSudoku, InvalidBoardWrongValueInColumn)
{
    std::array<std::array<int, 9>, 9> board{{
            {5, 3, 4, 6, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {5, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 7, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 1},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9},
            }};
    ASSERT_FALSE(checkSudokuBoard(board));
}


TEST(TestCheckSudoku, InvalidBoardWrongValueInSubgrid)
{
    // First 3x3 subgrid has repeated value
    std::array<std::array<int, 9>, 9> board{{
                {5, 3, 4, 6, 7, 8, 9, 1, 2},
                {6, 5, 2, 1, 9, 5, 3, 4, 8},
                {1, 9, 8, 3, 4, 2, 5, 6, 7},
                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                {3, 4, 5, 2, 8, 6, 1, 7, 9},
        }};
    ASSERT_TRUE(checkSudokuBoard(board));
}


TEST(TestCheckSudoku, InvalidBoardWithNubersOutOfRange)
{
    std::array<std::array<int, 9>, 9> board{{
            {5, 3, 4, 6, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {1, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 11, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 1},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9},
    }};
    ASSERT_FALSE(checkSudokuBoard(board));
}