//
// Created by daniel on 1/03/23.
//

#include "binary_tree.h"


std::vector<std::list<BTNode*>> AbstractBinaryTree::listOfDepths() const
{
    // Returns a vector with a list of the nodes values for each level
    // of the tree
    std::vector<std::list<BTNode*>> result;
    std::list<BTNode*> current;

    if (m_root != nullptr)
        current.push_back(m_root);

    while (!current.empty())
    {
        result.push_back(current);
        std::list<BTNode*> parents = current;
        current = std::list<BTNode*>();

        for (auto parent : parents)
        {
            if (parent->left != nullptr)
                current.push_back(parent->left);
            if (parent->right != nullptr)
                current.push_back(parent->right);
        }
    }

    return result;
}

std::vector<int> AbstractBinaryTree::levelOrderTraversal() const
{
    // Returns a vector with the values of the nodes visited
    // in a level order traversal
    if (m_root == nullptr)
        return {};

    std::vector<int> values;
    std::queue<BTNode*> queue;
    queue.push(m_root);

    while (!queue.empty())
    {
        BTNode* current {queue.front()};
        queue.pop();

        values.push_back(current->data);

        if (current->left != nullptr)
            queue.push(current->left);
        if (current->right != nullptr)
            queue.push(current->right);
    }

    return values;
}

const int ERROR_CODE {std::numeric_limits<int>::min()};


int isBalancedUtil(BTNode* root)
{
    // Helper function for isBalanced.
    if (root == nullptr)
        return -1;

    int heightLeft {isBalancedUtil(root->left)};
    if (heightLeft == ERROR_CODE) return ERROR_CODE;  // propagate error

    int heightRight {isBalancedUtil(root->right)};
    if (heightRight == ERROR_CODE) return ERROR_CODE;

    if (std::abs(heightRight - heightLeft) > 1)
        return ERROR_CODE;

    return std::max(heightLeft, heightRight) + 1;
}


bool AbstractBinaryTree::isBalanced() const
{
    // Returns true if the tree is balanced. That is, the height of the two subtrees of
    // any node never differ by more than one.
    return isBalancedUtil(m_root) != ERROR_CODE;
}


BTNode* BinaryTree::insertLeft(BTNode *node, int data)
{
    auto* newNode = new BTNode {data};
    node->left = newNode;
    return newNode;
}

BTNode* BinaryTree::insertRight(BTNode *node, int data)
{
    auto* newNode = new BTNode {data};
    node->right = newNode;
    return newNode;
}