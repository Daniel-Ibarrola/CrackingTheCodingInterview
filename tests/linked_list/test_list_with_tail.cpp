//
// Created by daniel on 13/01/23.
//

#include "gtest/gtest.h"
#include "list_w_tail.h"


TEST(TestLinkedListWithTail, TestPushFront)
{
    TailedLinkedList list;
    list.push_front(3);
    list.push_front(5);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.front(), 5);
    ASSERT_EQ(list.back(), 3);
}


TEST(TestLinkedListWithTail, TestPushBack)
{
    TailedLinkedList list;
    list.push_back(3);
    list.push_back(5);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.front(), 3);
    ASSERT_EQ(list.back(), 5);
}


TEST(TestLinkedListWithTail, InitializerListPreservesOrder)
{
    TailedLinkedList list {3, 4, 5};
    ASSERT_EQ(list.front(), 3);
    ASSERT_EQ(list.getNode(1), 4);
    ASSERT_EQ(list.getNode(2), 5);
}


TEST(TestLinkedListWithTail, ListEquality)
{
    TailedLinkedList list1 {1, 2, 3};
    TailedLinkedList equal {1, 2, 3};
    TailedLinkedList notEqual {1, 4, 3};

    ASSERT_EQ(list1, equal);
    ASSERT_NE(list1, notEqual);
}


TEST(TestLinkedListWithTail, PrintList)
{
    TailedLinkedList list {1, 2, 3};
    std::cout << list << '\n';
}
