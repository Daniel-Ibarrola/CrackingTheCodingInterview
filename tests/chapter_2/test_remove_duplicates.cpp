//
// Created by daniel on 6/01/23.
//
#include "gtest/gtest.h"
#include "linked_list.h"
#include "double_list.h"


TEST(TestLinkedList, RemoveDuplicates)
{
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(1);
    list.push(2);

    list.remove_duplicates();
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 2);
}


TEST(TestDoublyLinkedList, RemoveDuplicates)
{
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);

    list.remove_duplicates();
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);
}