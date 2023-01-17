//
// Created by daniel on 16/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestIsPalindrome, APalindrome)
{
    LinkedList list {1, 2, 3, 2, 1};
    ASSERT_TRUE(list.isPalindrome());
}


TEST(TestIsPalindrome, NotAPalindrome)
{
    LinkedList list {1, 2, 2, 3, 1};
    ASSERT_FALSE(list.isPalindrome());
}
