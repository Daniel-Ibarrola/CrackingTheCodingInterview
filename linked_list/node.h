//
// Created by daniel on 28/01/23.
//

#ifndef CRACKING_NODE_H
#define CRACKING_NODE_H

#include <vector>


struct Node
{
    // Singly Linked List Node
    Node* next;
    int value;

    explicit Node(int val) : next {nullptr}, value {val}
    {

    }

    Node (Node* nxt, int val) : next {nxt}, value {val}
    {

    }
};

Node* createList(const std::vector<int>& values);

Node* getNode(std::size_t index, Node* list);


#endif //CRACKING_NODE_H
