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


struct Result
{
    // Struct to store the result from getTailAndSize
    std::size_t size;
    Node* tail;

    Result(std::size_t size_, Node* tail_)
        : size {size_}, tail {tail_}
    {

    }
};


Result getTailAndSize(Node* list)
{
    // Returns the tail node and the size of the given list
    std::size_t size {0};
    while (list->next != nullptr)
    {
        list = list->next;
        ++size;
    }
    ++size;
    return Result {size, list};
}



Node* listIntersection(Node* head1, Node* head2)
{
    // If two list intersects returns the node where the intersection
    // occurs. Otherwise, it returns a null pointer
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;

    Node* list1 {head1};
    Node* list2 {head2};

    Result result1 {getTailAndSize(list1)};
    Result result2 {getTailAndSize(list2)};

    // Intersecting lists always have the same last node
    if (result1.tail != result2.tail)
        return nullptr;

    // list1 will point to the larger list
    if (result1.size < result2.size)
    {
        list1 = head2;
        list2 = head1;
        std::swap(result1, result2);
    }

    // Advance larger list pointer so there are the same remaining
    // number of nodes
    for (auto ii {0}; ii < result1.size - result2.size; ++ii)
        list1 = list1->next;

    // Find first equal node. This is where the intersection begins
    while (list1 != list2)
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1;
}
