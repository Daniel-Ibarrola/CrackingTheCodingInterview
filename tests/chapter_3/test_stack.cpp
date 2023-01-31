//
// Created by daniel on 30/01/23.
//

#include "gtest/gtest.h"
#include "stack.h"


TEST(TestStack, RemoveAndAddToStack)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    ASSERT_FALSE(stack.empty());

    ASSERT_EQ(stack.top(), 3);
    stack.pop();

    ASSERT_EQ(stack.top(), 2);
    stack.pop();

    ASSERT_EQ(stack.top(), 1);
    stack.pop();

    ASSERT_TRUE(stack.empty());
}
