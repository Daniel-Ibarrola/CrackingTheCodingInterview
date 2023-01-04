//
// Created by daniel on 3/01/23.
//
#include "gtest/gtest.h"
#include "double_list.h"


TEST(TestDoublyLinkedList, TestPushBack)
{
    DoublyLinkedList list;
    ASSERT_TRUE(list.empty());

    list.push_back(3);
    ASSERT_EQ(list.back(), 3);

    list.push_back(7);
    list.push_back(9);
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 3);
    ASSERT_EQ(list.back(), 9);
}


TEST(TestDoublyLinkedList, TestPushFront)
{
    DoublyLinkedList list;
    list.push_front(3);
    list.push_front(7);
    list.push_front(9);

    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 9);
    ASSERT_EQ(list.back(), 3);
}
