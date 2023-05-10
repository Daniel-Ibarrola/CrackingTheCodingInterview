//
// Created by daniel on 28/01/23.
//

#include "node.h"


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
