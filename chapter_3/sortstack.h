//
// Created by daniel on 16/02/23.
//

#ifndef CRACKING_SORTSTACK_H
#define CRACKING_SORTSTACK_H

#include <stack>

template <typename T>
class SortStack
{
// Stack that keeps the smallest elements at the top
private:
    std::stack<T> m_stack;

public:

    SortStack() = default;

    void push(T data)
    {
        // Push an element into the stack and keep it sorted
        if (empty() || data <= top())
            m_stack.push(data);
        else
        {
            std::stack<T> temp;
            while(!empty() && top() < data)
            {
                temp.push(top());
                m_stack.pop();
            }
            m_stack.push(data);
            while (!temp.empty())
            {
                m_stack.push(temp.top());
                temp.pop();
            }
        }

    }

    T top() const
    {
        return m_stack.top();
    }

    void pop()
    {
        return m_stack.pop();
    }

    [[nodiscard]] bool empty() const
    {
        return m_stack.empty();
    }
};

#endif //CRACKING_SORTSTACK_H
