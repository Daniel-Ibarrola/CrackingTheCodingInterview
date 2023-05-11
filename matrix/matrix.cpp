//
// Created by daniel on 10/05/23.
//

#include "matrix.h"


void transposeMatrix(Matrix& mat)
{
    // Transpose the given matrix. Inplace operation
    std::size_t size {mat.size()};
    for (auto ii {0}; ii < size; ++ii)
    {
        for (auto jj {ii}; jj < size; ++jj)
            std::swap(mat[ii][jj], mat[jj][ii]);
    }
}


void reverseColumns(Matrix& mat)
{
    // Reverse the columns of the given matrix. Inplace operation
    std::size_t size {mat.size()};
    for (auto ii {0}; ii < size; ++ii)
    {
        for (auto jj {0}; jj < size / 2; ++jj)
            std::swap(mat[jj][ii], mat[size - jj - 1][ii]);
    }
}


void rotateMatrix(Matrix& mat)
{
    // Rotate a squared matrix by 90 degrees. Inplace operation
    transposeMatrix(mat);
    reverseColumns(mat);
}


void fillWithZeros(Matrix& mat)
{
    // Given a matrix, if an element is zero its entire row and column
    // are set to zero
    if (mat.empty())
        return;

    std::unordered_set<std::size_t> rows{};
    std::unordered_set<std::size_t> columns{};

    std::size_t numRows {mat.size()};
    std::size_t numCols {mat[0].size()};
    // Find positions of zeros
    for (auto ii {0}; ii < numRows; ++ii)
    {
        for (auto jj {0}; jj < numCols; ++jj)
        {
            if (mat[ii][jj] == 0)
            {
                rows.insert(ii);
                columns.insert(jj);
            }
        }
    }

    // Set rows to zero
    for (auto rw : rows)
    {
        for (auto ii {0}; ii < numCols; ++ii)
            mat[rw][ii] = 0;
    }

    // Set columns to zero
    for (auto col : columns)
    {
        for (auto ii {0}; ii < numRows; ++ii)
            mat[ii][col] = 0;
    }

}

bool invalidBoardValue(std::unordered_set<int>& set, int value)
{
    if (set.count(value) || (value < 0 || value > 9))
        return true;
    if (value != 0)
        set.insert(value);
    return false;
}

bool checkBoardRows(
        const std::array<std::array<int, 9>, 9>& board,
        std::size_t rowStart,
        std::size_t rowEnd,
        std::size_t colStart,
        std::size_t colEnd
        )
{
    std::unordered_set<int> set;
    for (auto ii {rowStart}; ii < rowEnd; ++ii)
    {
        for (auto jj {colStart}; jj < board[colEnd].size(); ++jj)
        {
            if (invalidBoardValue(set, board[ii][jj]))
                return false;
        }
        set.clear();
    }
    return true;
}

bool checkBoardColumns(const std::array<std::array<int, 9>, 9>& board)
{
    std::unordered_set<int> set;
    for (auto ii {0}; ii < board.size(); ++ii)
    {
        for (auto jj {0}; jj < board[ii].size(); ++jj)
        {
            if (invalidBoardValue(set, board[jj][ii]))
                return false;
            set.insert(board[jj][ii]);
        }
        set.clear();
    }
    return true;
}


bool checkSudokuBoard(const std::array<std::array<int, 9>, 9>& board)
{
    std::unordered_set<int> set;
    // Check rows
    if (!checkBoardRows(board, 0, board.size(), 0, board[0].size()))
        return false;

    // Check columns
    if (!checkBoardColumns(board))
        return false;

    // Check 3x3 sub-grids
    for (auto rowStart {0}; rowStart < board.size(); rowStart += 3)
    {
        for (auto colStart {0}; colStart < board[0].size(); colStart += 3)
        {
            if (!checkBoardRows(board,
                                rowStart, rowStart + 3,
                                colStart, colStart + 3))
                return false;
        }
    }

    return true;
}


std::vector<int> spiralOrder(Matrix& matrix)
{
    // Returns a vector with the elements of the matrix in spiral order
    std::vector<int> result;
    if (matrix.empty())
        return result;

    int numElements {static_cast<int>(matrix.size() * matrix[0].size())};
    int count {0};

    int rowStart {0};
    int colStart {0};

    int rowEnd {static_cast<int>(matrix.size() - 1)};
    int colEnd {static_cast<int>(matrix[0].size() - 1)};

    while (count < numElements)
    {
        // Go right. Row is fixed
        for (auto ii {colStart}; ii <= colEnd && count < numElements; ++ii)
        {
            result.push_back(matrix[rowStart][ii]);
            ++count;
        }
        ++rowStart;

        // Go down. Column is fixed
        for (auto ii {rowStart}; ii <= rowEnd && count < numElements; ++ii)
        {
            result.push_back(matrix[ii][colEnd]);
            ++count;
        }
        --colEnd;

        // Go left. Row is fixed
        for (auto ii {colEnd}; ii >= colStart && count < numElements; --ii)
        {
            result.push_back(matrix[rowEnd][ii]);
            ++count;
        }
        --rowEnd;

        // Go up. Column is fixed
        for (auto ii {rowEnd}; ii >= rowStart && count < numElements; --ii)
        {
            result.push_back(matrix[ii][colStart]);
            ++count;
        }
        ++colStart;
    }
    return result;
}


Matrix createSpiralMatrix(int n)
{
    // Create a n x n matrix filled with elements from 1 to n² in spiral order
    if (n == 0)
        return {};

    Matrix matrix(n, std::vector<int>(n));

    int numElements {(n * n) + 1} ;
    int count {1};

    int rowStart {0};
    int colStart {0};

    int rowEnd {static_cast<int>(matrix.size() - 1)};
    int colEnd {static_cast<int>(matrix[0].size() - 1)};

    while (count < numElements)
    {
        // Go right. Row is fixed
        for (auto ii {colStart}; ii <= colEnd && count < numElements; ++ii)
        {
            matrix[rowStart][ii] = count;
            ++count;
        }
        ++rowStart;

        // Go down. Column is fixed
        for (auto ii {rowStart}; ii <= rowEnd && count < numElements; ++ii)
        {
            matrix[ii][colEnd] = count;
            ++count;
        }
        --colEnd;

        // Go left. Row is fixed
        for (auto ii {colEnd}; ii >= colStart && count < numElements; --ii)
        {
            matrix[rowEnd][ii] = count;
            ++count;
        }
        --rowEnd;

        // Go up. Column is fixed
        for (auto ii {rowEnd}; ii >= rowStart && count < numElements; --ii)
        {
            matrix[ii][colStart] = count;
            ++count;
        }
        ++colStart;
    }
    return matrix;
}


std::vector<int> diagonalOrder(const Matrix& matrix)
{
    // Returns a vector with the elements of the matrix in diagonal order
    if (matrix.empty())
        return {};

    int numRows {static_cast<int>(matrix.size())};
    int numCols {static_cast<int>(matrix[0].size())};

    int currentRow {0};
    int currentCol {0};

    std::vector<int> result(numRows*numCols);
    std::size_t ii {0};

    bool up {true};
    // Note the last element in diagonal order is in the last row and last column
    while (currentRow < numRows && currentCol < numCols)
    {
        result[ii] = matrix[currentRow][currentCol];
        ++ii;
        if (up)
        {
            ++currentCol;
            --currentRow;
            if (currentCol >= numCols)
            {
                // Start descending at the row below
                currentRow += 2;
                --currentCol;
                up = false;
            }
            else if (currentRow < 0)
            {
                // Start descending at the column to the right
                ++currentRow;
                up = false;
            }
        }
        else
        {
            --currentCol;
            ++currentRow;
            if (currentRow >= numRows)
            {
                // Start ascending at column to the right
                up = true;
                --currentRow;
                currentCol += 2;
            }
            else if (currentCol < 0)
            {
                // Start ascending at the row below
                ++currentCol;
                up = true;
            }
        }
    }
    return result;
}
