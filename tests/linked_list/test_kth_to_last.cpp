//
// Created by daniel on 7/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedList, KthToLast)
{
    LinkedList list {8, 5, 9, 7, 3, 2};
    ASSERT_EQ(list.kToLast(3), 9);
}
