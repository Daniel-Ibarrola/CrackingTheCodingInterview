//
// Created by daniel on 29/12/22.
//


#include "gtest/gtest.h"
#include "ex_1_8.h"


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
