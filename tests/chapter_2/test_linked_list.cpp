//
// Created by daniel on 2/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedList, TestInsertNode)
{
    LinkedList list;
    list.push(3);
    list.push(5);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 5);
    ASSERT_EQ(list.getNode(1), 3);
}


TEST(TestLinkedList, RemovingFromEmptyList)
{
    LinkedList list;
    list.remove(0);
    ASSERT_TRUE(list.empty());
}


TEST(TestLinkedList, TestRemoveHeadNode)
{
    LinkedList list {1, 4, 3};

    list.remove(1);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 4);
    ASSERT_EQ(list.getNode(1), 3);
}


TEST(TestLinkedList, TestRemoveMiddleNode)
{
    LinkedList list {1, 4, 3};

    list.remove(4);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 1);
    ASSERT_EQ(list.getNode(1), 3);
}


TEST(TestLinkedList, InitializerListPreservesOrder)
{
    LinkedList list {3, 4, 5};
    ASSERT_EQ(list.front(), 3);
    ASSERT_EQ(list.getNode(1), 4);
    ASSERT_EQ(list.getNode(2), 5);
}
