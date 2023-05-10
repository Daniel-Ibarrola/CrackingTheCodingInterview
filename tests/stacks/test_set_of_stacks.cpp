//
// Created by daniel on 5/02/23.
//

#include "gtest/gtest.h"
#include "set_of_stacks.h"


SetOfStacks<int> createStack()
{
    // Create the following set:
    // stack 1 {1, 2}
    // stack 2 {3, 4}
    // stack 3 {5, }

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


TEST(TestSetOfStacks, PopAtMiddleStack)
{
    SetOfStacks<int> stacks {createStack()};

    ASSERT_EQ(stacks.topAt(1), 4);
    ASSERT_EQ(stacks.topAt(0), 2);

    // Remove all elements from second stack
    stacks.popAt(1);
    stacks.popAt(1);

    ASSERT_EQ(stacks.top(), 5);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 2);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 1);
    stacks.pop();

    ASSERT_TRUE(stacks.empty());
}


TEST(TestSetOfStacks, PopAtFirstStack)
{
    SetOfStacks<int> stacks {createStack()};

    // Remove all elements from first stack
    stacks.popAt(0);
    stacks.popAt(0);

    ASSERT_EQ(stacks.top(), 5);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 4);
    stacks.pop();

    ASSERT_EQ(stacks.top(), 3);
    stacks.pop();

    ASSERT_TRUE(stacks.empty());
}