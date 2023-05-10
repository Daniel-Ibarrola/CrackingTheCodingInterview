//
// Created by daniel on 14/03/23.
//

#include "gtest/gtest.h"
#include "digraph.h"


class CyclicGraph : public ::testing::Test
{
protected:

    void SetUp() override
    {

    }

    std::vector<std::pair<std::size_t , std::size_t>> edgeList {
            {0, 1},
            {1, 2},
            {2, 0},
    };
    DiGraph graph {3, edgeList};
};

TEST_F(CyclicGraph, TestGraphIsCyclic)
{
    ASSERT_TRUE(graph.isCyclic());
}

TEST_F(CyclicGraph, CyclicGraphTopologicalSortThrowsError)
{
    ASSERT_THROW(graph.topologicalSort(), GraphWithCycleError);
}


class DAG : public ::testing::Test
{
protected:

    void SetUp() override
    {

    }

    std::vector<std::pair<std::size_t , std::size_t>> edgeList {
            {0, 2},
            {0, 3},
            {3, 1},
            {4, 1},
            {4, 2},
            {5, 0},
            {5, 2},
    };
    DiGraph graph {6, edgeList};
};

TEST_F(DAG, TestGraphIsNotCyclic)
{
    ASSERT_FALSE(graph.isCyclic());
}

TEST_F(DAG, TopologicalSort)
{

    std::vector<std::size_t> expected {5, 4, 0, 3, 1, 2};
    ASSERT_EQ(expected, graph.topologicalSort());
}
