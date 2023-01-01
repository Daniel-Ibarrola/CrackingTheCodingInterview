//
// Created by daniel on 31/12/22.
//

#include "gtest/gtest.h"
#include "rotate_matrix.h"


TEST(TestRotateMatrix, Matrix3X3)
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
    matrix rotated {rotateMatrix(mat)};
    ASSERT_EQ(rotated, expected);
}


TEST(TestRotateMatrix, Matrix4X4)
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
    matrix rotated {rotateMatrix(mat)};
    ASSERT_EQ(rotated, expected);
}
