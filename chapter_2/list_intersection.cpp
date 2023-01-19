//
// Created by daniel on 19/01/23.
//

#include "list_intersection.h"


Node* createList(const std::vector<int>& values)
{
    // Create a linked list with the given values
    Node* head {nullptr};
    if (values.empty())
        return head;

    head = new Node {values[0]};
    Node* current {head};

    for (auto ii {1}; ii < values.size(); ++ii)
    {
        Node* next = new Node {values[ii]};
        current->next = next;
        current = next;
    }

    return head;
}


Node* getNode(std::size_t index, Node* list)
{
    // Get the node with given index from the list
    std::size_t currInd {0};
    Node* current {list};

    while (current != nullptr)
    {
        if (currInd == index)
            return current;
        current = current->next;
        ++currInd;
    }

    return nullptr;
}


Node* listIntersection(Node* head1, Node* head2)
{
    // If two list intersects returns the node where the intersection
    // occurs. Otherwise, it returns a null pointer
    Node* list1 {head1};
    Node* list2 {head2};

    std::size_t size1 {0};
    std::size_t size2 {0};

    while (list1->next != nullptr)
    {
        list1 = list1->next;
        ++size1;
    }
    ++size1;

    while (list2->next != nullptr)
    {
        list2 = list2->next;
        ++size2;
    }
    ++size2;

    // Intersecting lists always have the same last node
    if (list2 != list1)
        return nullptr;

    // list1 will point to the larger list
    if (size1 >= size2)
    {
        list1 = head1;
        list2 = head2;
    }
    else
    {
        list1 = head2;
        list2 = head1;
        std::swap(size1, size2);
    }

    // Advance larger list pointer so there are the same remaining
    // number of nodes
    for (auto ii {0}; ii < size1 - size2; ++ii)
        list1 = list1->next;

    // Find first equal node. This is where the intersection begins
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1 == list2)
            return list1;

        list1 = list1->next;
        list2 = list2->next;
    }

    return nullptr;
}
