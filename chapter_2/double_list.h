//
// Created by daniel on 3/01/23.
//

#ifndef CRACKING_DOUBLE_LIST_H
#define CRACKING_DOUBLE_LIST_H

#include <cstdlib>
#include <unordered_set>


struct DNode
{
    DNode* prev {nullptr};
    DNode* next {nullptr};
    int value;

    explicit DNode(int val) : value {val}
    {

    }
};


class DoublyLinkedList
{
    // Double linked list. Stores integers
private:
    std::size_t m_size {0};
    DNode* m_head {nullptr};
    DNode* m_tail {nullptr};

public:

    DoublyLinkedList() = default;

    [[nodiscard]] bool empty() const { return m_size == 0; }
    [[nodiscard]] std::size_t size() const { return m_size; }

    void push_back(int element);
    void push_front(int element);

    [[nodiscard]] int front() const;
    [[nodiscard]] int back() const;

    void pop_back();
    void pop_front();
    void remove(int element);
    void remove_duplicates();

};


#endif //CRACKING_DOUBLE_LIST_H
