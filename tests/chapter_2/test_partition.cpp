//
// Created by daniel on 10/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedList, PartitionList)
{
    LinkedList list {3, 5, 8, 5, 10, 2, 1};
    list.partition(5);

    ASSERT_EQ(list.getNode(0), 3);
    ASSERT_EQ(list.getNode(1), 2);
    ASSERT_EQ(list.getNode(2), 1);
    ASSERT_EQ(list.getNode(3), 5);
    ASSERT_EQ(list.getNode(4), 10);
    ASSERT_EQ(list.getNode(5), 5);
    ASSERT_EQ(list.getNode(6), 8);
}