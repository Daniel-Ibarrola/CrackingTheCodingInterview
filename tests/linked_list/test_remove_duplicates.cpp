//
// Created by daniel on 6/01/23.
//
#include "gtest/gtest.h"
#include "linked_list.h"
#include "double_list.h"


TEST(TestLinkedList, RemoveDuplicates)
{
    LinkedList list {2, 1, 3, 2, 1};
    list.remove_duplicates();

    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 2);
}


TEST(TestDoublyLinkedList, RemoveDuplicates)
{
    DoublyLinkedList list {1, 2, 3, 1 ,2};
    list.remove_duplicates();
    
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);
}