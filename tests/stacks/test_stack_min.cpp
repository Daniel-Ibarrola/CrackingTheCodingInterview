//
// Created by daniel on 3/02/23.
//

#include "gtest/gtest.h"
#include "stack_min.h"


TEST(TestStackMin, PushPopAndMin)
{
    StackMin<int> stack;
    stack.push(4);
    stack.push(6);
    ASSERT_EQ(stack.min(), 4);

    stack.push(2);
    stack.push(3);
    stack.push(1);
    ASSERT_EQ(stack.min(), 1);

    stack.pop();
    ASSERT_EQ(stack.min(), 2);
    ASSERT_EQ(stack.top(), 3);

    stack.pop();
    stack.pop();
    ASSERT_EQ(stack.min(), 4);
}


TEST(TestStackMin, StackWithRepeatedElements)
{
    StackMin<int> stack;
    stack.push(3);
    stack.push(1);
    stack.push(1);
    stack.push(3);

    ASSERT_EQ(stack.min(), 1);
    ASSERT_EQ(stack.top(), 3);

    stack.pop();
    stack.pop();

    ASSERT_EQ(stack.min(), 1);
    ASSERT_EQ(stack.top(), 1);

    stack.pop();
    ASSERT_EQ(stack.min(), 3);
    ASSERT_EQ(stack.top(), 3);

    stack.pop();
    ASSERT_TRUE(stack.empty());
}
