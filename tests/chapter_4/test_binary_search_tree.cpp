//
// Created by daniel on 3/03/23.
//

#include "gtest/gtest.h"
#include "bst.h"


TEST(TestInsertToBinarySearchTree, KeepsBSTProperty)
{
    BST tree;
    std::vector<int> values {8, 4, 12, 2, 6, 10, 14};
    for (auto val : values)
        tree.insert(val);

    ASSERT_EQ(tree.levelOrderTraversal(), values);
}
