//
// Created by daniel on 26/02/23.
//
#include "gtest/gtest.h"
#include "bst.h"


TEST(TestMinimanlHeightBinarySearchTree, CompleteTree)
{
    std::vector<int> values {1, 2, 3, 4, 5, 6, 7};
    BST tree {minimalHeightBST(values)};

    std::vector<int> levelOrder {tree.levelOrderTraversal()};
    std::vector<int> expected {4, 2, 6, 1, 3, 5, 7};

    ASSERT_EQ(levelOrder, expected);
}


TEST(TestMinimanlHeightBinarySearchTree, UncompleteTree)
{
    std::vector<int> values {1, 2, 3, 4, 5, 6};
    BST tree {minimalHeightBST(values)};

    std::vector<int> levelOrder {tree.levelOrderTraversal()};
    std::vector<int> expected {3, 1, 5, 2, 4, 6};

    ASSERT_EQ(levelOrder, expected);
}
