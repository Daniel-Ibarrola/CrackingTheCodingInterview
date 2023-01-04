//
// Created by daniel on 3/01/23.
//

#include "double_list.h"


void DoublyLinkedList::push_front(int element)
{
    // Add an element to the beginning of the list
    if (empty())
    {
        m_head = new DNode {element};
        m_tail = m_head;
    }
    else
    {
        auto node = new DNode {element};
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    ++m_size;
}


void DoublyLinkedList::push_back(int element)
{
    // Add an element to the end of the list
    if (empty())
    {
        m_head = new DNode {element};
        m_tail = m_head;
    }
    else
    {
        auto node = new DNode {element};
        node->prev = m_tail;
        m_tail->next = node;
        m_tail = node;
    }
    ++m_size;
}


int DoublyLinkedList::front() const
{
    // Access the first element
    return m_head->value;
}


int DoublyLinkedList::back() const
{
    // Access the last element
    return m_tail->value;
}
