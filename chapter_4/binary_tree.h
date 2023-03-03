//
// Created by daniel on 1/03/23.
//

#ifndef CRACKING_BINARY_TREE_H
#define CRACKING_BINARY_TREE_H


#include <queue>
#include <list>
#include <vector>


struct BTNode
{
    int data;
    BTNode* left {nullptr};
    BTNode* right {nullptr};

    explicit BTNode(int _data) : data {_data}
    {

    }
};


std::vector<std::list<BTNode*>> listOfDepths(BTNode* root);

#endif //CRACKING_BINARY_TREE_H
