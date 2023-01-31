//
// Created by daniel on 30/01/23.
//

#ifndef CRACKING_STACK_H
#define CRACKING_STACK_H

#include <cassert>
#include <cstddef>

template<typename T>
struct StackNode
{
    StackNode* next {nullptr};
    T data;

    explicit StackNode(T data_) : data {data_}
    {

    }

    StackNode(T data_, StackNode* next_)
        : data {data_}, next {next_}
    {

    }
};


template <typename T>
class Stack
{
private:
    StackNode<T>* m_head {nullptr};
    std::size_t m_size {0};

public:

    explicit Stack() = default;

    void push(T data)
    {
        // Push an element to the top of the stack
        if (!empty())
        {
            StackNode<T>* node {new StackNode<T>{data, m_head}};
            m_head = node;
        }
        else
            m_head = new StackNode<T> {data};
        ++m_size;
    }

    void pop()
    {
        assert(!empty());
        StackNode<T>* temp {m_head};
        m_head = m_head->next;
        --m_size;

        delete temp;
    }

    T top() const
    {
        assert(!empty());
        return m_head->data;
    }

    [[nodiscard]] bool empty() const
    {
        return m_size == 0;
    }


};

#endif //CRACKING_STACK_H
