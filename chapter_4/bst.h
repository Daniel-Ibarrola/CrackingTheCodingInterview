//
// Created by daniel on 26/02/23.
//

#ifndef CRACKING_BST_H
#define CRACKING_BST_H


#include <queue>
#include <vector>


struct BSTNode
{
    int value;
    BSTNode* left {nullptr};
    BSTNode* right {nullptr};

    explicit BSTNode(int _value) : value {_value}
    {

    }
};


class BST
{
private:
    // A binary search tree
    BSTNode* m_root {nullptr};

public:

    BST() = default;

    explicit BST(BSTNode* root)
        : m_root {root}
    {

    }

    [[nodiscard]] std::vector<int> levelOrderTraversal() const;
};


BSTNode* minimalHeightBST(const std::vector<int>&values, int left, int right);
BST minimalHeightBST(const std::vector<int>& values);

#endif //CRACKING_BST_H
