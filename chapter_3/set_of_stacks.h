//
// Created by daniel on 5/02/23.
//

#ifndef CRACKING_SET_OF_STACKS_H
#define CRACKING_SET_OF_STACKS_H

#include <vector>
#include <stack>


template <typename T>
class SetOfStacks
{
private:
    // Class always starts with one empty stack
    std::vector<std::stack<T>> m_stacks {1, std::stack<T>{}};
    std::size_t m_capacity;
    std::size_t m_current {0};

public:

    explicit SetOfStacks(std::size_t maxCapacity)
        : m_capacity {maxCapacity}
    {

    }

    void push(T data)
    {
        // Push and element into a stack. If its current size its
        // equal to the max capacity, create a new stack.
        if (m_stacks[m_current].size() == m_capacity)
        {
            m_stacks.emplace_back(std::stack<T>{});
            ++m_current;
        }
        m_stacks[m_current].push(data);
    }

    void pop()
    {
        // Pop an element from the last stack that was created
        assert(!empty());
        m_stacks[m_current].pop();
        if (m_stacks[m_current].size() == 0 && m_current >= 1)
            --m_current;
    }

    T top() const
    {
        // Returns the top value at the last stack that
        // was created
        assert(!empty());
        return m_stacks[m_current].top();
    }

    [[nodiscard]] bool empty() const
    {
        return m_stacks[0].empty();
    }

};

#endif //CRACKING_SET_OF_STACKS_H
