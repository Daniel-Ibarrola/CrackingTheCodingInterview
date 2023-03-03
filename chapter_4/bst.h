//
// Created by daniel on 26/02/23.
//

#ifndef CRACKING_BST_H
#define CRACKING_BST_H


#include <queue>
#include <vector>
#include "binary_tree.h"



class BST : public AbstractBinaryTree
{
    // A binary search tree
public:

    BST() = default;

    void insert(int data) override {}

    friend BST minimalHeightBST(const std::vector<int>& values);
};


BST minimalHeightBST(const std::vector<int>& values);

#endif //CRACKING_BST_H
