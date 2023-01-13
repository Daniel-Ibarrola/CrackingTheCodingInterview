//
// Created by daniel on 13/01/23.
//

#include "list_w_tail.h"


void TailedLinkedList::push_to_empty_list(int value)
{
    // Push an element to an empty list
    m_head = new Node {value};
    m_tail = m_head;
}


void TailedLinkedList::push_front(int value)
{
    // Insert an element at the start of the list
    if (empty())
        push_to_empty_list(value);
    else
    {
        Node* node = new Node {m_head, value};
        m_head = node;
    }
    m_size++;
}


void TailedLinkedList::push_back(int value)
{
    // Insert an element at the end of the list
    if (empty())
        push_to_empty_list(value);
    else
    {
        Node* node = new Node {value};
        m_tail->next = node;
        m_tail = node;
    }
    m_size++;
}


int TailedLinkedList::back() const
{
    // Get the last element
    if (empty())
        throw EmptyListException("Cannot get element from empty list");
    return m_tail->value;
}


TailedLinkedList numberSum(const TailedLinkedList &list1, const TailedLinkedList &list2)
{
    // Given two numbers represented by a linked list, computes their sum.
    TailedLinkedList result;

    if (list1.empty()|| list2.empty())
        return result;

    // ptr1 will always point to the larger list
    Node* ptr1;
    Node* ptr2;
    if (list1.size() >= list2.size())
    {
        ptr1 = list1.m_head;
        ptr2 = list2.m_head;
    }
    else
    {
        ptr1 = list2.m_head;
        ptr2 = list1.m_head;
    }

    int plusOne {0};
    while (ptr2 != nullptr)
    {
        // Digit sum max value is 19
        int digitSum {plusOne + ptr1->value + ptr2->value};

        if (digitSum < 10)
        {
            result.push_back(digitSum);
            plusOne = 0;
        }
        else
        {
            result.push_back(digitSum % 10);
            plusOne = 1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // If both list were the same size and there is still a plus one
    // we add it to the result
    if (ptr1 == nullptr && plusOne)
    {
        result.push_back(1);
        plusOne = 0;
    }

    // If one of the list was larger than the other the sum
    // may continue if there is still a plusOne
    while (ptr1 != nullptr)
    {
        int sum {ptr1->value + plusOne};
        if (sum < 10)
        {
            result.push_back(sum);
            plusOne = 0;
            break;
        }
        else
            result.push_back(sum % 10);

        ptr1 = ptr1->next;
    }

    if (plusOne)
        result.push_back(1);

    return result;
}