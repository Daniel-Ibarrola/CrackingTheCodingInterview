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
    std::size_t m_first {0}; // Keep track of the first non-empty stack

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
        if (m_stacks[m_current].empty())
        {
            // Find the prev non-empty stack
            while (m_current > 0)
            {
                if (!m_stacks[m_current].empty())
                    break;
                --m_current;
            }
        }
    }

    void popAt(std::size_t index)
    {
        // Pop an element at a specific substack
        assert(!m_stacks[index].empty());
        m_stacks[index].pop();
        if (m_stacks[m_first].empty())
        {
            // Find the next non-empty stack
            while (m_first != m_capacity)
            {
                if (!m_stacks[m_first].empty())
                    break;
                ++m_first;
            }
        }
    }

    T top() const
    {
        // Returns the top value at the last stack that
        // was created
        assert(!empty());
        return m_stacks[m_current].top();
    }

    T topAt(std::size_t index) const
    {
        assert(!m_stacks[index].empty());
        return m_stacks[index].top();
    }

    [[nodiscard]] bool empty() const
    {
        return m_stacks[m_first].empty();
    }

};

#endif //CRACKING_SET_OF_STACKS_H
