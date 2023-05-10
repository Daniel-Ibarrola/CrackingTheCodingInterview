//
// Created by daniel on 30/01/23.
//

#ifndef CRACKING_QUEUE_H
#define CRACKING_QUEUE_H

#include <cassert>
#include <cstddef>


template <typename T>
struct QueueNode
{
    T data;
    QueueNode* next;

    explicit QueueNode(T data_) :  data {data_}
    {

    }

};

template <typename T>
class Queue
{
private:
    QueueNode<T>* m_head {nullptr};
    QueueNode<T>* m_tail {nullptr};
    std::size_t m_size {0};

public:

    explicit Queue() = default;

    void push(T data)
    {
        if (!empty())
        {
            QueueNode<T>* node {new QueueNode<T> {data}};
            m_tail->next = node;
            m_tail = node;
        }
        else
        {
            m_head = new QueueNode<T> {data};
            m_tail = m_head;
        }
        ++m_size;
    }

    T front() const
    {
        // Returns the first element of the queue
        assert(!empty());
        return m_head->data;
    }

    T back() const
    {
        // Returns the last element in the queue
        assert(!empty());
        return m_tail->data;
    }

    void pop()
    {
        // Removes the first element in the queue
        assert(!(empty()));
        if (m_head == m_tail)
        {
            delete m_head;
            m_tail = nullptr;
        }
        else
        {
            QueueNode<T>* temp {m_head};
            m_head = m_head->next;
            delete temp;
        }
        --m_size;
    }

    [[nodiscard]] bool empty() const
    {
        return m_size == 0;
    }

};

#endif //CRACKING_QUEUE_H
