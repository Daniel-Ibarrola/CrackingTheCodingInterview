//
// Created by daniel on 26/02/23.
//

#include "bst.h"


BTNode* minimalHeightBST(const std::vector<int>&values, int left, int right)
{
    // Helper function for minimalHeightBST
    if (left > right)
        return nullptr;
    if (left == right)
        return new BTNode {values[left]};

    int mid {(left + (right - left) / 2)};
    auto* root = new BTNode {values[mid]};
    root->left = minimalHeightBST(values, left, mid - 1);
    root->right = minimalHeightBST(values, mid + 1, right);

    return root;
}

BST minimalHeightBST(const std::vector<int>& values)
{
    // Create a binary search tree of minimal height from a sorted
    // array in increasing order
    BST tree;
    tree.m_root = minimalHeightBST(values, 0, static_cast<int>(values.size() - 1));
    return tree;
}


BTNode* insertUtil(BTNode* root, int data)
{
    if (root != nullptr)
    {
        if (data < root->data)
            root->left = insertUtil(root->left, data);
        else
            root->right = insertUtil(root->right, data);
        return root;
    }
    return new BTNode {data};
}


void BST::insert(int data)
{
    // Inserts a node with the given value while keeping
    // the binary search tree property. Insertions may make the tree unbalanced
    m_root = insertUtil(m_root, data);
}