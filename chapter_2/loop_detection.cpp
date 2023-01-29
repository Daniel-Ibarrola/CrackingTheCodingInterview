//
// Created by daniel on 28/01/23.
//

#include "loop_detection.h"


Node* detectLoop(Node* head)
{
    // If the given linked list contains a loop, it returns
    // the node with the loop. Else, it returns a null pointer
    Node* slow {head};
    Node* fast {head};

    // Find where pointers collide
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    // Find beginning of the loop
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
