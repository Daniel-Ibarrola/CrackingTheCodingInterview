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
