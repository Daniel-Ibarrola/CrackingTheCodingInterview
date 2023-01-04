//
// Created by daniel on 2/01/23.
//

#ifndef CRACKING_LINKED_LIST_H
#define CRACKING_LINKED_LIST_H


#include <cstddef>


struct Node
{
    Node* next;
    int value;

    explicit Node(int val) : next {nullptr}, value {val}
    {

    }

    Node (Node* nxt, int val) : next {nxt}, value {val}
    {

    }
};


class LinkedList
{
    // Singly linked list
private:
    std::size_t m_size {};
    Node* m_head {nullptr};

    void removeNode(Node* prev, Node* node);

public:

    LinkedList() = default;

    [[nodiscard]] bool empty() const { return m_size == 0; }
    [[nodiscard]] std::size_t size() const { return m_size; }

    void push_back(int value);
    [[nodiscard]] int getNode(std::size_t index) const;

    void remove(int value);

};

#endif //CRACKING_LINKED_LIST_H
