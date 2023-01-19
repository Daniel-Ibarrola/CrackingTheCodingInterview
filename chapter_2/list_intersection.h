//
// Created by daniel on 19/01/23.
//

#ifndef CRACKING_LIST_INTERSECTION_H
#define CRACKING_LIST_INTERSECTION_H

#include "linked_list.h"
#include <vector>

Node* createList(const std::vector<int>& values);

Node* getNode(std::size_t index, Node* list);

Node* listIntersection(Node* head1, Node* head2);

#endif //CRACKING_LIST_INTERSECTION_H
