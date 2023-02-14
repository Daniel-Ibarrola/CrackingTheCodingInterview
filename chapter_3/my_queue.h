//
// Created by daniel on 14/02/23.
//

#ifndef CRACKING_MY_QUEUE_H
#define CRACKING_MY_QUEUE_H

#include <cassert>
#include <stack>


template <typename T>
class MyQueue
{
    // A queue implemented using two stacks
private:
    std::stack<T> m_stack_1;
    std::stack<T> m_stack_2;

    void rollover()
    {
        // Move the elements from stack 1 to stack 2, so element
        // are now in reverse order and when popping an element from stack 2
        // it will maintain FIFO property
        while(!m_stack_1.empty())
        {
            m_stack_2.push(m_stack_1.top());
            m_stack_1.pop();
        }
    }

public:

    MyQueue() = default;

    void push(T data)
    {
        m_stack_1.push(data);
    }

    T pop()
    {
        assert(!empty());
        if (m_stack_2.empty())
            rollover();

        T data {m_stack_2.top()};
        m_stack_2.pop();

        return data;
    }

    [[nodiscard]] bool empty() const
    {
        return m_stack_1.empty() && m_stack_2.empty();
    }
};

#endif //CRACKING_MY_QUEUE_H
