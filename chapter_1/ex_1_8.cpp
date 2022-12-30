//
// Created by daniel on 29/12/22.
//

#include "ex_1_8.h"


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
