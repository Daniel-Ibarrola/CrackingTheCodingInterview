//
// Created by daniel on 16/02/23.
//

#include "gtest/gtest.h"
#include "sortstack.h"


TEST(TestSortStack, PushAndPop)
{
    SortStack<int> stack;
    stack.push(4);
    stack.push(6);
    ASSERT_EQ(stack.top(), 4);

    stack.push(3);
    stack.push(7);
    stack.push(5);

    std::vector<int> expected {3, 4, 5, 6, 7};
    for (auto val : expected)
    {
        ASSERT_EQ(stack.top(), val);
        stack.pop();
    }

    ASSERT_TRUE(stack.empty());
}
