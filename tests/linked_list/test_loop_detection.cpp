//
// Created by daniel on 28/01/23.
//

#include "gtest/gtest.h"
#include "node.h"
#include "loop_detection.h"


TEST(TestLoopDetection, ListWithNoLoop)
{
    std::vector<int> values {1, 2, 3, 4};
    Node* head {createList(values)};

    ASSERT_EQ(detectLoop(head), nullptr);
}


TEST(TestLoopDetection, SingleElmentListWithLoop)
{
    Node* head {new Node{1}};
    head->next = head;

    ASSERT_EQ(detectLoop(head), head);
}


TEST(TestLoopDetection, ListWithLoop)
{
    std::vector<int> values {1, 2, 3, 4, 5};
    Node* head {createList(values)};

    Node* loopNode {getNode(2, head)};
    Node* tail {getNode(4, head)};
    tail->next = loopNode;

    ASSERT_EQ(detectLoop(head), loopNode);
}
