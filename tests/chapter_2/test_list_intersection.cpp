//
// Created by daniel on 18/01/23.
//

#include "gtest/gtest.h"
#include "node.h"
#include "list_intersection.h"


TEST(TestLinkedListIntersection, IntersectingLists)
{
    std::vector<int> values {3, 1, 5, 9, 7, 2};
    Node* head1 {createList(values)};
    Node* intersection {getNode(4, head1)};

    values = {4, 6};
    Node* head2 {createList(values)};
    head2->next->next = intersection;

    ASSERT_NE(intersection, nullptr);
    ASSERT_EQ(intersection->value, 7);
    ASSERT_EQ(listIntersection(head1, head2), intersection);
}


TEST(TestLinkedListIntersection, NotIntersectingLists)
{
    std::vector<int> values {3, 1, 5, 9, 7, 2};
    Node* head1 {createList(values)};

    values = {4, 6, 8, 12};
    Node* head2 {createList(values)};

    ASSERT_EQ(listIntersection(head1, head2), nullptr);
}
