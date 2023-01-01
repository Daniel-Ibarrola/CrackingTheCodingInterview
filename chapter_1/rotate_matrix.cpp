//
// Created by daniel on 31/12/22.
//

#include "rotate_matrix.h"


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
