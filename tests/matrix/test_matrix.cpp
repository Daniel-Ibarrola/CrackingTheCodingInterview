//
// Created by daniel on 10/05/23.
//

#include "gtest/gtest.h"
#include "matrix.h"


TEST(TestTranspose, Matrix3X3)
{
    Matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Matrix transpose {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
    };
    transposeMatrix(mat);
    ASSERT_EQ(mat, transpose);
}


TEST(TestTranspose, Matrix4X4)
{
    Matrix mat {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
    };
    Matrix transpose {
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
    Matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Matrix expected {
            {3, 6, 9},
            {2, 5, 8},
            {1, 4, 7},
    };
    rotateMatrix(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestRotateMatrixInplace, Matrix4X4)
{
    Matrix mat {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
    };
    Matrix expected {
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
    Matrix mat {
            {1, 2, 3},
            {4, 0, 6},
            {7, 8, 9},
    };
    Matrix expected {
            {1, 0, 3},
            {0, 0, 0},
            {7, 0, 9},
    };
    fillWithZeros(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestFillWithZeros, Matrix2)
{
    Matrix mat {
            {1, 2, 3, 0},
            {4, 5, 6, 7},
    };
    Matrix expected {
            {0, 0, 0, 0},
            {4, 5, 6, 0},
    };
    fillWithZeros(mat);
    ASSERT_EQ(mat, expected);
}


TEST(TestFillWithZeros, MultipleZeros)
{
    Matrix mat {
            {1, 2, 3},
            {4, 5, 6},
            {0, 7, 0},
    };
    Matrix expected {
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
                {6, 5, 2, 1, 9, 7, 3, 4, 8},
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

Matrix createMatrix(std::size_t numRows, std::size_t numColumns)
{
    Matrix matrix(numRows, std::vector<int>(numColumns));
    int count {1};

    for (auto ii {0}; ii < numRows; ++ii)
    {
        for (auto jj {0}; jj < numColumns; ++jj)
        {
            matrix[ii][jj] = count;
            ++count;
        }
    }
    return matrix;
}


TEST(SpiralOrder, SingleRow)
{
    Matrix matrix {{1, 2, 3}};
    std::vector<int> expected {1, 2, 3};
    ASSERT_EQ(spiralOrder(matrix), expected);
}


TEST(SpiralOrder, SingleColumn)
{
    Matrix matrix {{1}, {2}, {3}};
    std::vector<int> expected {1, 2, 3};
    ASSERT_EQ(spiralOrder(matrix), expected);
}


TEST(SpiralOrder, Matrix3X3)
{
    Matrix matrix {createMatrix(3, 3)};
    std::vector<int> expected {1,2,3,6,9,8,7,4,5};
    ASSERT_EQ(spiralOrder(matrix), expected);
}


TEST(SpiralOrder, Matrix3X4)
{
    Matrix matrix {createMatrix(3, 4)};
    std::vector<int> expected {1,2,3,4,8,12,11,10,9,5,6,7};
    ASSERT_EQ(spiralOrder(matrix), expected);
}


TEST(SpiralOrder, Matrix4X5)
{
    Matrix matrix {createMatrix(4, 5)};
    std::vector<int> expected {1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12};
    ASSERT_EQ(spiralOrder(matrix), expected);
}


TEST(CreateSpiralMatrix, SingleElement)
{
    Matrix expected {{1}};
    ASSERT_EQ(createSpiralMatrix(1), expected);
}


TEST(CreateSpiralMatrix, Matrix2X2)
{
    Matrix expected {{1, 2}, {4, 3}};
    ASSERT_EQ(createSpiralMatrix(2), expected);
}


TEST(CreateSpiralMatrix, Matrix3X3)
{
    Matrix expected {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    ASSERT_EQ(createSpiralMatrix(3), expected);
}


TEST(CreateSpiralMatrix, Matrix4X4)
{
    Matrix expected {
            {1, 2, 3, 4},
            {12, 13, 14, 5},
            {11, 16, 15, 6},
            {10, 9, 8, 7}
    };
    ASSERT_EQ(createSpiralMatrix(4), expected);
}


TEST(DiagonalOrder, SingleRow)
{
    Matrix matrix {{1, 2, 3}};
    std::vector<int> expected {1, 2, 3};
    ASSERT_EQ(diagonalOrder(matrix), expected);
}


TEST(DiagonalOrder, SingleColumn)
{
    Matrix matrix {{1}, {2}, {3}};
    std::vector<int> expected {1, 2, 3};
    ASSERT_EQ(diagonalOrder(matrix), expected);
}


TEST(DiagonalOrder, Matrix2X2)
{
    Matrix matrix {createMatrix(2, 2)};
    std::vector<int> expected {1,2,3,4};
    ASSERT_EQ(diagonalOrder(matrix), expected);
}


TEST(DiagonalOrder, Matrix3X3)
{
    Matrix matrix {createMatrix(3, 3)};
    std::vector<int> expected {1,2,4,7,5,3,6,8,9};
    ASSERT_EQ(diagonalOrder(matrix), expected);
}


TEST(DiagonalOrder, Matrix4X4)
{
    Matrix matrix {createMatrix(4, 4)};
    std::vector<int> expected {1,2,5,9,6,3,4,7,10,13,14,11,8,12,15,16};
    ASSERT_EQ(diagonalOrder(matrix), expected);
}
