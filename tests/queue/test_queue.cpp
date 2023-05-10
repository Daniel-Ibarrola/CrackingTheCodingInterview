//
// Created by daniel on 30/01/23.
//

#include "gtest/gtest.h"
#include "queue.h"


TEST(TestQueue, InsertAndRemoveFromQueue)
{
    Queue<double> queue;
    // Create the following queue {1, 2, 3 ,4}
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    ASSERT_FALSE(queue.empty());
    ASSERT_EQ(queue.back(), 4);

    ASSERT_EQ(queue.front(), 1);
    queue.pop();

    ASSERT_EQ(queue.front(), 2);
    queue.pop();

    ASSERT_EQ(queue.front(), 3);
    queue.pop();

    ASSERT_EQ(queue.front(), 4);
    queue.pop();

    ASSERT_TRUE(queue.empty());
}
