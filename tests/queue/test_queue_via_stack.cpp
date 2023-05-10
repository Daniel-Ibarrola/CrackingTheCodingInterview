//
// Created by daniel on 14/02/23.
//

#include "gtest/gtest.h"
#include "my_queue.h"


TEST(TestQueueViaStack, PushAndPop)
{
    MyQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    ASSERT_EQ(queue.pop(), 1);

    queue.push(4);
    queue.push(5);

    ASSERT_EQ(queue.pop(), 2);
    ASSERT_EQ(queue.pop(), 3);
    ASSERT_EQ(queue.pop(), 4);
    ASSERT_EQ(queue.pop(), 5);
    ASSERT_TRUE(queue.empty());
}
