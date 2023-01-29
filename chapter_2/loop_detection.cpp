//
// Created by daniel on 28/01/23.
//

#include "loop_detection.h"


Node* detectLoop(Node* head)
{
    // If the given linked list contains a loop, it returns
    // the node with the loop. Else, it returns a null pointer
    std::unordered_set<Node*> visited;
    while (head != nullptr)
    {
        if (visited.count(head))
            return head;
        visited.insert(head);
        head = head->next;

    }
    return nullptr;
}
