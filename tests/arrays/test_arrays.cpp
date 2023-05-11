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


TEST(TestIncrementInteger, LastDigitIsNot9)
{
    std::vector<int> number {1, 4, 5};
    std::vector<int> expected {1, 4, 6};
    incrementNumber(number);
    ASSERT_EQ(number, expected);
}

TEST(TestIncrementInteger, LastDigitIs9)
{
    std::vector<int> number {1, 4, 9};
    std::vector<int> expected {1, 5, 0};
    incrementNumber(number);
    ASSERT_EQ(number, expected);
}

TEST(TestIncrementInteger, All9s)
{
    std::vector<int> number {9, 9, 9};
    std::vector<int> expected {1, 0, 0, 0};
    incrementNumber(number);
    ASSERT_EQ(number, expected);
}


TEST(TeststockMaxProfit, EmptyArray)
{
    std::vector<int> prices;
    ASSERT_EQ(stockMaxProfit(prices), 0);
}


TEST(TeststockMaxProfit, ComputesCorrectProfit)
{
    std::vector<int> prices {310, 315, 275, 295, 260, 270, 290, 230, 255, 260};
    ASSERT_EQ(stockMaxProfit(prices), 30);
}
