//
// Created by daniel on 11/01/23.
//
#include "gtest/gtest.h"
#include "list_w_tail.h"


TEST(TestLinkedListSum, EqualSizeList)
{
    TailedLinkedList list1 {2, 3, 4};
    TailedLinkedList list2 {3, 2, 1};

    TailedLinkedList expected {5, 5, 5};
    TailedLinkedList sum {numberSum(list1, list2)};
    ASSERT_EQ(sum, expected);
}


TEST(TestLinkedListSum, DigitSumGreaterThan10)
{
    TailedLinkedList list1 {7, 1, 6};
    TailedLinkedList list2 {5, 9, 3};

    TailedLinkedList expected {2, 1, 0, 1};
    TailedLinkedList sum {numberSum(list1, list2)};
    ASSERT_EQ(sum, expected);
}


TEST(TestLinkedListSum, LongerList)
{
    TailedLinkedList list1 {9, 9, 9};
    TailedLinkedList list2 {9};

    TailedLinkedList expected {8, 0, 0, 1};
    TailedLinkedList sum {numberSum(list1, list2)};
    ASSERT_EQ(sum, expected);
}
