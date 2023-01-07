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


void DoublyLinkedList::pop_back()
{
    // Delete the last element from the list
    if (m_size > 1)
    {
        DNode* temp {m_tail};
        m_tail = temp->prev;
        m_tail->next = nullptr;
        delete temp;
        --m_size;
    }
    else if (m_size == 1)
    {
        delete m_tail;
        --m_size;
    }
}


void DoublyLinkedList::pop_front()
{
    // Remove the first element from the list
    if (m_size > 1)
    {
        DNode* temp {m_head};
        m_head = temp->next;
        m_head->prev = nullptr;
        delete temp;
        --m_size;
    }
    else if (m_size == 1)
    {
        delete m_head;
        --m_size;
    }
}


void DoublyLinkedList::remove(int element)
{
    // Remove an element with the given value from the list.
    // It can be in any position. Remove is O(N)
    DNode* current {m_head};
    while (current != nullptr)
    {
        if (current->value == element)
        {
            if (current == m_head)
                pop_front();
            else if (current == m_tail)
                pop_back();
            else
            {
                // Middle node always has a prev and next node
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                --m_size;
                return;
            }
        }
        current = current->next;
    }

}


void DoublyLinkedList::remove_duplicates()
{
    // Removes all duplicates from the list
    std::unordered_set<int> found{};

    DNode* current {m_head};
    while (current != nullptr)
    {
        if (found.count(current->value))
        {
            if (current == m_tail)
            {
                pop_back();
                return;
            }
            else
            {
                DNode* temp {current};
                current = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                --m_size;
            }
        }
        else
        {
            found.insert(current->value);
            current = current->next;
        }
    }
}