//
// Created by daniel on 1/03/23.
//

#include "gtest/gtest.h"
#include "binary_tree.h"


std::vector<int> getLevelValues(const std::list<BTNode*>& level)
{
    std::vector<int> values;
    for (auto node : level)
        values.push_back(node->data);
    return values;
}


TEST(TestListOfDepths, CompleteTree)
{
    BinaryTree tree(4);
    BTNode* root {tree.getRoot()};
    BTNode* leftChild {BinaryTree::insertLeft(root, 3)};
    BTNode* rightChild {BinaryTree::insertRight(root, 5)};
    BinaryTree::insertLeft(leftChild, 1);
    BinaryTree::insertRight(leftChild, 2);
    BinaryTree::insertLeft(rightChild, 6);
    BinaryTree::insertRight(rightChild, 7);

    std::vector<std::list<BTNode*>> result {tree.listOfDepths()};
    std::vector<int> level1Expected {4};
    std::vector<int> level2Expected {3, 5};
    std::vector<int> level3Expected {1, 2, 6, 7};

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(getLevelValues(result[0]), level1Expected);
    ASSERT_EQ(getLevelValues(result[1]), level2Expected);
    ASSERT_EQ(getLevelValues(result[2]), level3Expected);
}


TEST(TestListOfDepths, UncompleteTree) {
    BinaryTree tree(4);
    BTNode* root {tree.getRoot()};
    BTNode* leftChild {BinaryTree::insertLeft(root, 3)};
    BTNode* rightChild {BinaryTree::insertRight(root, 5)};
    BinaryTree::insertLeft(leftChild, 1);
    BinaryTree::insertLeft(rightChild, 6);


    std::vector<std::list<BTNode*>> result{tree.listOfDepths()};
    std::vector<int> level1Expected{4};
    std::vector<int> level2Expected{3, 5};
    std::vector<int> level3Expected{1, 6};

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(getLevelValues(result[0]), level1Expected);
    ASSERT_EQ(getLevelValues(result[1]), level2Expected);
    ASSERT_EQ(getLevelValues(result[2]), level3Expected);
}
