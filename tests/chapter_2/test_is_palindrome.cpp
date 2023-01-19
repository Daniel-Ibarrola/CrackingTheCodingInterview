//
// Created by daniel on 16/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestIsPalindrome, ListOddSize)
{
    LinkedList list {1, 2, 3, 2, 1};
    ASSERT_TRUE(list.isPalindrome());
}


TEST(TestIsPalindrome, ListEvenSize)
{
    LinkedList list {1, 2, 2, 1};
    ASSERT_TRUE(list.isPalindrome());
}


TEST(TestIsPalindrome, NotAPalindromeOddSize)
{
    LinkedList list {1, 2, 2, 3, 1};
    ASSERT_FALSE(list.isPalindrome());
}


TEST(TestIsPalindrome, NotAPalindromeEvenSize)
{
    LinkedList list {1, 2, 3, 4};
    ASSERT_FALSE(list.isPalindrome());
}
