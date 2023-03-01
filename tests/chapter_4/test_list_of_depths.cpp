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
    auto* root = new BTNode {4};
    auto* leftChild = new BTNode {3};
    auto* rightChild = new BTNode {5};
    root->left = leftChild;
    root->right = rightChild;

    leftChild->left = new BTNode {1};
    leftChild->right = new BTNode {2};
    rightChild->left = new BTNode {6};
    rightChild->right = new BTNode {7};

    std::vector<std::list<BTNode*>> result {listOfDepths(root)};
    std::vector<int> level1Expected {4};
    std::vector<int> level2Expected {3, 5};
    std::vector<int> level3Expected {1, 2, 6, 7};

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(getLevelValues(result[0]), level1Expected);
    ASSERT_EQ(getLevelValues(result[1]), level2Expected);
    ASSERT_EQ(getLevelValues(result[2]), level3Expected);
}


TEST(TestListOfDepths, UncompleteTree) {
    auto *root = new BTNode{4};
    auto *leftChild = new BTNode{3};
    auto *rightChild = new BTNode{5};
    root->left = leftChild;
    root->right = rightChild;

    leftChild->left = new BTNode{1};
    rightChild->left = new BTNode{6};

    std::vector<std::list<BTNode *>> result{listOfDepths(root)};
    std::vector<int> level1Expected{4};
    std::vector<int> level2Expected{3, 5};
    std::vector<int> level3Expected{1, 6};

    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(getLevelValues(result[0]), level1Expected);
    ASSERT_EQ(getLevelValues(result[1]), level2Expected);
    ASSERT_EQ(getLevelValues(result[2]), level3Expected);

}
