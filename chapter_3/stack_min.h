//
// Created by daniel on 3/02/23.
//

#ifndef CRACKING_STACK_MIN_H
#define CRACKING_STACK_MIN_H

#include <cassert>
#include <stack>


template <typename T>
class StackMin
{
    // A stack with constant access to its minimum element
private:
    std::stack<T> m_stack;
    std::stack<T> min_stack;

public:

    explicit StackMin() = default;

    void push(T data)
    {
        m_stack.push(data);
        if (min_stack.empty() || min_stack.top() >= data)
            min_stack.push(data);
    }

    void pop()
    {
        assert(!empty());
        if (min_stack.top() == m_stack.top())
            min_stack.pop();
        m_stack.pop();
    }

    T top() const
    {
        assert(!empty());
        return m_stack.top();
    }

    T min() const
    {
        assert(!empty());
        return min_stack.top();
    }

    [[nodiscard]] bool empty() const
    {
        return m_stack.empty();
    }
};

#endif //CRACKING_STACK_MIN_H
