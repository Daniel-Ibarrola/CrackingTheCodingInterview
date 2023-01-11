//
// Created by daniel on 2/01/23.
//

#ifndef CRACKING_LINKED_LIST_H
#define CRACKING_LINKED_LIST_H


#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <unordered_set>


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

    LinkedList(std::initializer_list<int> list)
    {
        // Initializer list preserves order
        for (auto it {rbegin(list)}; it != rend(list); ++it)
            push(*it);
    }

    ~LinkedList()
    {
        Node* current {m_head};
        while (current != nullptr)
        {
            Node* next {current->next};
            delete current;
            current = next;
        }
    }

    [[nodiscard]] bool empty() const { return m_size == 0; }
    [[nodiscard]] std::size_t size() const { return m_size; }

    void push(int value);
    [[nodiscard]] int getNode(std::size_t index) const;

    void remove(int value);
    void remove_duplicates();

    [[nodiscard]] int front() const;
    [[nodiscard]] int kToLast(std::size_t pos) const;

    void partition(int partitionNum);
};

#endif //CRACKING_LINKED_LIST_H
