//
// Created by daniel on 5/02/23.
//

#include "gtest/gtest.h"
#include "set_of_stacks.h"


SetOfStacks<int> createStack()
{
    SetOfStacks<int> stacks(2);
    std::vector<int> data {
            1, 2, 3, 4, 5,
    };
    for (auto val : data)
        stacks.push(val);
    return stacks;
}

TEST(TestSetOfStacks, PushAndPop)
{
    SetOfStacks<int> stacks {createStack()};

    ASSERT_EQ(stacks.top(), 5);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 4);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 3);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 2);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 1);
    stacks.pop();

    ASSERT_TRUE(stacks.empty());
}
