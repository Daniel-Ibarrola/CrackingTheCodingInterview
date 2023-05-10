//
// Created by daniel on 10/05/23.
//

#include "gtest/gtest.h"
#include "arrays.h"

TEST(TestsEvenOdd, SortsValuesCorrectly)
{
    std::vector<int> array {1, 2, 4, 5, 6};
    std::vector<int> expected {1, 3, 5, 2, 1};
    evenOdd(array);
    ASSERT_EQ(array, expected);
}
