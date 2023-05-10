//
// Created by daniel on 3/03/23.
//
#include "gtest/gtest.h"
#include "bst.h"


BST createTree(const std::vector<int>& values)
{
    BST tree;
    for (auto val : values)
        tree.insert(val);
    return tree;
}

TEST(TestIsTreeBalanced, BalancedTree)
{
    std::vector<int> values {8, 4, 12, 2, 6, 10, 14};
    BST tree {createTree(values)};
    ASSERT_TRUE(tree.isBalanced());
}


TEST(TestIsTreeBalanced, UnbalancedTree)
{
    std::vector<int> values {8, 4, 12, 2, 3};
    BST tree {createTree(values)};
    ASSERT_FALSE(tree.isBalanced());
}
