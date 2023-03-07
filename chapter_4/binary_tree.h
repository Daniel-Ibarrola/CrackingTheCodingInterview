//
// Created by daniel on 1/03/23.
//

#ifndef CRACKING_BINARY_TREE_H
#define CRACKING_BINARY_TREE_H


#include <cstdlib>
#include <queue>
#include <limits>
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


class AbstractBinaryTree
{
    // Abstract base class for binary trees
protected:
    BTNode* m_root;

public:

    AbstractBinaryTree() : m_root {nullptr}
    {

    }

    explicit AbstractBinaryTree(int data)
        : m_root {new BTNode {data}}
    {
        // Initializes the root node
    }

    [[nodiscard]] std::vector<std::list<BTNode*>> listOfDepths() const;

    virtual void insert(int data) = 0;
    virtual ~AbstractBinaryTree() = default;

    [[nodiscard]] std::vector<int> levelOrderTraversal() const;
    [[nodiscard]] bool isBalanced() const;

};


class BinaryTree : public AbstractBinaryTree
{
private:

    static bool checkBST(BTNode* root, int min, int max);

public:

    explicit BinaryTree(int data) : AbstractBinaryTree {data}
    {

    }

    void insert(int data) override {};  // Note that calling insert has no effect on binary tree

    BTNode* getRoot() { return m_root; }
    static BTNode* insertLeft(BTNode* node, int data);
    static BTNode* insertRight(BTNode* node, int data);

    [[nodiscard]] bool checkBST() const;
};

#endif //CRACKING_BINARY_TREE_H
