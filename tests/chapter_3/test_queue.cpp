//
// Created by daniel on 30/01/23.
//

#include "gtest/gtest.h"
#include "queue.h"


TEST(TestQueue, InsertAndRemoveFromQueue)
{
    Queue<double> queue;
    // Create the following queue {4, 3, 2 ,1}
    queue.push_front(3);
    queue.push_front(4);
    queue.push_back(2);
    queue.push_back(1);

    ASSERT_FALSE(queue.empty());

    ASSERT_EQ(queue.front(), 4);
    ASSERT_EQ(queue.back(), 1);
    queue.pop_front();
    queue.pop_back();

    ASSERT_EQ(queue.front(), 3);
    ASSERT_EQ(queue.back(), 2);
    queue.pop_front();
    queue.pop_back();

    ASSERT_TRUE(queue.empty());
}
