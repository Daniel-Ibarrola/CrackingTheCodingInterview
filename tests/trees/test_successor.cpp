//
// Created by daniel on 12/03/23.
//

#include "gtest/gtest.h"
#include "bst.h"


class TestNodeSuccessor : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<int> values {15, 6, 20, 2, 10, 5, 8, 12, 4};
        for (auto val : values)
        {
            auto* node {new BTNode {val}};
            tree.insert(node);
            nodes.push_back(node);
        }

    }

    BST tree;
    std::vector<BTNode*> nodes;
};


TEST_F(TestNodeSuccessor, LeftMostChild)
{
    ASSERT_EQ(tree.successor(nodes[1]), nodes[6]);
    ASSERT_EQ(tree.successor(nodes[0]), nodes[2]);
}


TEST_F(TestNodeSuccessor, SuccessorAbove)
{
    ASSERT_EQ(tree.successor(nodes[7]), nodes[0]);
    ASSERT_EQ(tree.successor(nodes[5]), nodes[1]);
}
