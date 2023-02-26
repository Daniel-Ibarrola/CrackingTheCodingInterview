//
// Created by daniel on 26/02/23.
//

#include "bst.h"



std::vector<int> BST::levelOrderTraversal() const
{
    // Returns a vector with the values of the nodes visited
    // in a level order traversal
    if (m_root == nullptr)
        return {};

    std::vector<int> values;
    std::queue<BSTNode*> queue;
    queue.push(m_root);

    while (!queue.empty())
    {
        BSTNode* current {queue.front()};
        queue.pop();

        values.push_back(current->value);

        if (current->left != nullptr)
            queue.push(current->left);
        if (current->right != nullptr)
            queue.push(current->right);
    }

    return values;
}


BSTNode* minimalHeightBST(const std::vector<int>&values, int left, int right)
{
    // Helper function for minimalHeightBST
    if (left > right)
        return nullptr;
    if (left == right)
        return new BSTNode {values[left]};

    int mid {(left + (right - left) / 2)};
    auto* root = new BSTNode {values[mid]};
    root->left = minimalHeightBST(values, left, mid - 1);
    root->right = minimalHeightBST(values, mid + 1, right);

    return root;
}


BST minimalHeightBST(const std::vector<int>& values)
{
    // Create a binary search tree of minimal height from a sorted
    // array in increasing order
    return BST(minimalHeightBST(values, 0, static_cast<int>(values.size() - 1)));
}