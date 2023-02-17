//
// Created by daniel on 16/02/23.
//

#include "gtest/gtest.h"
#include "sortstack.h"


TEST(TestSortStack, SortingAStack)
{
    std::vector<int> values {2, 7, 3, 10, 8};
    std::stack<int> stack;

    for (auto val : values)
        stack.push(val);

    sort(stack);

    std::vector<int> sortedValues {2, 3, 7, 8, 10};
    for (auto val : sortedValues)
    {
        ASSERT_EQ(stack.top(), val);
        stack.pop();
    }
    ASSERT_TRUE(stack.empty());
}
