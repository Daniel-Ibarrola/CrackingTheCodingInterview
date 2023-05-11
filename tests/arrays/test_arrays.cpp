//
// Created by daniel on 10/05/23.
//

#include "gtest/gtest.h"
#include "arrays.h"

TEST(TestsEvenOdd, SortsValuesCorrectly)
{
    std::vector<int> array {1, 2, 4, 3, 6, 7};
    std::vector<int> expected {6, 2, 4, 3, 7, 1};
    evenOdd(array);
    ASSERT_EQ(array, expected);
}


TEST(TestDutchFlagPartition, GroupsElementsInThreeGroups)
{
    std::vector<int> array {1, 1, 2, 3, 0, 1, 2};
    std::vector<int> expected {1, 1, 0, 1, 2, 2, 3};
    dutchFlagPartition(array, 2);
    ASSERT_EQ(array, expected);
}
