//
// Created by daniel on 1/03/23.
//

#include "binary_tree.h"


std::vector<std::list<BTNode*>> listOfDepths(BTNode* root)
{
    // Returns a vector with a list of the nodes values for each level
    // of the tree
    std::vector<std::list<BTNode*>> result;
    std::list<BTNode*> current;

    if (root != nullptr)
        current.push_back(root);

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
