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

};


class BinaryTree : public AbstractBinaryTree
{
public:

    explicit BinaryTree(int data) : AbstractBinaryTree {data}
    {

    }

    void insert(int data) override {};

    BTNode* getRoot() { return m_root; }
    static BTNode* insertLeft(BTNode* node, int data);
    static BTNode* insertRight(BTNode* node, int data);
};

#endif //CRACKING_BINARY_TREE_H
