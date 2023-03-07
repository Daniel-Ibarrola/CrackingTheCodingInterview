//
// Created by daniel on 7/03/23.
//

#include "gtest/gtest.h"
#include "binary_tree.h"



TEST(ValidateBST, BinarySearchTree)
{
    BinaryTree tree(4);
    BTNode* root {tree.getRoot()};
    BTNode* leftChild {BinaryTree::insertLeft(root, 2)};
    BTNode* rightChild {BinaryTree::insertRight(root, 6)};
    BinaryTree::insertLeft(leftChild, 1);
    BinaryTree::insertRight(leftChild, 3);
    BinaryTree::insertLeft(rightChild, 5);
    BinaryTree::insertRight(rightChild, 7);

    ASSERT_TRUE(tree.checkBST());
}


TEST(ValidateBST, NotABinarySearchTree1)
{
    BinaryTree tree(4);
    BTNode* root {tree.getRoot()};
    BTNode* leftChild {BinaryTree::insertLeft(root, 3)};
    BinaryTree::insertRight(root, 8);
    BinaryTree::insertLeft(leftChild, 1);
    BinaryTree::insertRight(leftChild, 5);

    ASSERT_FALSE(tree.checkBST());
}


TEST(ValidateBST, NotABinarySearchTree2)
{
    BinaryTree tree(4);
    BTNode* root {tree.getRoot()};

    BTNode* leftChild {BinaryTree::insertLeft(root, 2)};
    BinaryTree::insertLeft(leftChild, 1);
    BinaryTree::insertRight(leftChild, 3);

    BTNode* rightChild {BinaryTree::insertRight(root, 8)};
    BinaryTree::insertRight(
            BinaryTree::insertLeft(rightChild, 6),
            9);

    ASSERT_FALSE(tree.checkBST());
}
