//
// Created by daniel on 31/12/22.
//

#include "rotate_matrix.h"


matrix rotateMatrix(const matrix& mat)
{
    // Rotate a squared matrix by 90 degrees
    std::size_t size {mat.size()};
    matrix rotated {
        mat.size(), std::vector<int>(mat.size(), 0)};

    for (auto ii {0}; ii < size; ++ii)
    {
        for (auto jj {0}; jj < size; ++jj)
            rotated[jj][ii] = mat[ii][size - 1 - jj];
    }

    return rotated;
}
