//
// Created by daniel on 2/01/23.
//

#include "linked_list.h"


void LinkedList::push_back(int value)
{
    // Add a new node with the given value to the list
    if (m_head == nullptr)
        m_head = new Node {value};
    else
    {
        Node* node = new Node {m_head, value};
        m_head = node;
    }
    m_size++;
}


int LinkedList::getNode(std::size_t index) const
{
    // Return the value of node with given index
    if (index >= m_size)
        return -1;

    std::size_t currInd {0};
    Node* currNode {m_head};
    while (currInd < index)
    {
        currNode = currNode->next;
        ++currInd;
    }

    return currNode->value;
}


void LinkedList::removeNode(Node *prev, Node *node)
{
    if (node == m_head)
    {
        Node* tmp {m_head};
        m_head = m_head->next;
        delete tmp;
    }
    else {
        prev->next = node->next;
        delete node;
    }
    --m_size;
}


void LinkedList::remove(int value)
{
    // Removes the node with given value from the list. If the list
    // does not contain the value it remains unaltered.
    Node* curr {m_head};
    Node* prev {m_head};

    while (curr != nullptr)
    {
        if (curr->value == value)
        {
            removeNode(prev, curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
