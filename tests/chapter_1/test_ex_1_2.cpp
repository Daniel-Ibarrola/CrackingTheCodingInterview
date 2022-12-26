//
// Created by daniel on 25/12/22.
//

#include "gtest/gtest.h"
#include "ex_1_2.h"


TEST(IsPermutationTest, DifferentLenghts)
{
    ASSERT_FALSE(isPermutation("abc", "abcd"));
}


TEST(IsPermutationTest, Permutation)
{
    ASSERT_TRUE(isPermutation("abcd", "bacd"));
    ASSERT_TRUE(isPermutation("abcd", "dcab"));
}


TEST(IsPermutationTest, NoPermutation)
{
    ASSERT_FALSE(isPermutation("abcd", "abce"));
}
