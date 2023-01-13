//
// Created by daniel on 11/01/23.
//
#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedListSum, EqualSizeList)
{
    LinkedList list1 {2, 3, 4};
    LinkedList list2 {3, 2, 1};

    LinkedList expected {5, 5, 5};
    LinkedList sum {numberSum(list1, list2)};
    ASSERT_EQ(sum, expected);
}


TEST(TestLinkedListSum, DigitSumGreaterThan10)
{
    LinkedList list1 {7, 1, 6};
    LinkedList list2 {5, 9, 3};

    LinkedList expected {2, 1, 0, 1};
    LinkedList sum {numberSum(list1, list2)};
    ASSERT_EQ(sum, expected);
}


TEST(TestLinkedListSum, LongerList)
{
    LinkedList list1 {9, 9, 9};
    LinkedList list2 {9};

    LinkedList expected {8, 0, 0, 9};
    ASSERT_EQ(numberSum(list1, list2), expected);
}
