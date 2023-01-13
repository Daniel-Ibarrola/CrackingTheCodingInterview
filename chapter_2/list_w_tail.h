//
// Created by daniel on 13/01/23.
//

#ifndef CRACKING_LIST_W_TAIL_H
#define CRACKING_LIST_W_TAIL_H

#include "linked_list.h"


class TailedLinkedList : public LinkedList
{
    // Singly linked list that has a head and a tail
private:
    Node* m_tail {nullptr};

    void push_to_empty_list(int value);

    using LinkedList::push;
    using LinkedList::remove;
    using LinkedList::remove_duplicates;

public:

    TailedLinkedList() = default;

    TailedLinkedList(std::initializer_list<int> list)
    {
        for (auto element : list)
            push_back(element);
    }

    void push_front(int value);
    void push_back(int value);

    [[nodiscard]] int back() const;

    friend TailedLinkedList numberSum(const TailedLinkedList& list1,
                                      const TailedLinkedList& list2);
};


#endif //CRACKING_LIST_W_TAIL_H
