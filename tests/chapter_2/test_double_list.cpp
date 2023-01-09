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


TEST(TestDoublyLinkedList, PopFront)
{
    DoublyLinkedList list {4, 5, 6};

    ASSERT_EQ(list.front(), 4);
    list.pop_front();

    ASSERT_EQ(list.front(), 5);
    list.pop_front();

    ASSERT_EQ(list.front(), 6);
    list.pop_front();

    ASSERT_TRUE(list.empty());
}


TEST(TestDoublyLinkedList, PopBack)
{
    DoublyLinkedList list {4, 5, 6};

    ASSERT_EQ(list.back(), 6);
    list.pop_back();

    ASSERT_EQ(list.back(), 5);
    list.pop_back();

    ASSERT_EQ(list.back(), 4);
    list.pop_back();

    ASSERT_TRUE(list.empty());
}


TEST(TestDoublyLinkedList, RemoveMiddleElement)
{
    DoublyLinkedList list {4, 5, 6};

    list.remove(5);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.front(), 4);
    ASSERT_EQ(list.back(), 6);
}


TEST(TestDoublyLinkedList, InitializerListPreservesOrder)
{
    DoublyLinkedList list {1, 2, 3};
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);
}