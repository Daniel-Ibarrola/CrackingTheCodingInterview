//
// Created by daniel on 10/05/23.
//

#include "matrix.h"


void transposeMatrix(matrix& mat)
{
    // Transpose the given matrix. Inplace operation
    std::size_t size {mat.size()};
    for (auto ii {0}; ii < size; ++ii)
    {
        for (auto jj {ii}; jj < size; ++jj)
            std::swap(mat[ii][jj], mat[jj][ii]);
    }
}


void reverseColumns(matrix& mat)
{
    // Reverse the columns of the given matrix. Inplace operation
    std::size_t size {mat.size()};
    for (auto ii {0}; ii < size; ++ii)
    {
        for (auto jj {0}; jj < size / 2; ++jj)
            std::swap(mat[jj][ii], mat[size - jj - 1][ii]);
    }
}


void rotateMatrix(matrix& mat)
{
    // Rotate a squared matrix by 90 degrees. Inplace operation
    transposeMatrix(mat);
    reverseColumns(mat);
}


void fillWithZeros(matrix& mat)
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

bool invalidBoardValue(const std::unordered_set<int>& set, int value)
{
    return set.count(value) || (value < 0 || value > 9);
}


bool checkSudokuBoard(const std::array<std::array<int, 9>, 9>& board)
{
    std::unordered_set<int> set;

    // Check rows
    for (auto ii {0}; ii < board.size(); ++ii)
    {
        for (auto jj {0}; jj < board[ii].size(); ++jj)
        {
            if (invalidBoardValue(set, board[ii][jj]))
                return false;
            set.insert(board[ii][jj]);
        }
        set.clear();
    }

    // Check columns
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

    // Check 3x3 sub-grids
    for (auto row_start {0}; row_start < board.size(); row_start += 3)
    {
        for (auto col_start {0}; col_start < board[0].size(); col_start += 3)
        {
            for (auto ii {row_start}; ii < row_start + 3; ++ii)
            {
                for (auto jj {col_start}; jj < col_start + 3; ++jj)
                {
                    if (invalidBoardValue(set, board[ii][jj]))
                        return false;
                    set.insert(board[ii][jj]);
                }
            }
            set.clear();
        }
    }

    return true;
}