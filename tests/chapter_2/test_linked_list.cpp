//
// Created by daniel on 2/01/23.
//

#include "gtest/gtest.h"
#include "linked_list.h"


TEST(TestLinkedList, TestInsertNode)
{
    LinkedList list;
    list.push_back(3);
    list.push_back(5);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 5);
    ASSERT_EQ(list.getNode(1), 3);
}


TEST(TestLinkedList, TestRemoveHeadNode)
{
    LinkedList list;
    list.push_back(3);
    list.push_back(4);
    list.push_back(1);

    list.remove(1);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 4);
    ASSERT_EQ(list.getNode(1), 3);
}


TEST(TestLinkedList, TestRemoveMiddleNode)
{
    LinkedList list;
    list.push_back(3);
    list.push_back(4);
    list.push_back(1);

    list.remove(4);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.getNode(0), 1);
    ASSERT_EQ(list.getNode(1), 3);
}
