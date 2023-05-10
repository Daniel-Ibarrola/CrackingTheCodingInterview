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