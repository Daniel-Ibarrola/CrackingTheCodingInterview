//
// Created by daniel on 7/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedList, KthToLast)
{
    LinkedList list {2, 3, 7, 9, 5, 8};
    ASSERT_EQ(list.kToLast(3), 9);
}
