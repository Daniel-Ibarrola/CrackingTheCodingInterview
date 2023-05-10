//
// Created by daniel on 20/02/23.
//

#include "gtest/gtest.h"
#include "digraph.h"


TEST(TestPathBetween, ThereIsAPath)
{
    std::vector<std::vector<std::size_t>> adjList {
            {2},
            {0},
            {4},
            {2},
            {3, 5, 6},
            {},
            {},
    };

    DiGraph digraph {adjList};
    ASSERT_EQ(digraph.getNumNodes(), 7);
    ASSERT_EQ(digraph.getNumEdges(), 7);

    ASSERT_TRUE(digraph.pathBetween(0, 5));
}


TEST(TestPathBetween, ThereIsNoPath)
{
    std::vector<std::vector<std::size_t>> adjList {
            {2},
            {0},
            {4},
            {2},
            {3, 6},
            {4},
            {},
    };

    DiGraph digraph {adjList};
    ASSERT_FALSE(digraph.pathBetween(0, 5));
}
