//
// Created by daniel on 20/02/23.
//

#ifndef CRACKING_DIGRAPH_H
#define CRACKING_DIGRAPH_H

#include <map>
#include <queue>
#include <list>
#include <stack>
#include <vector>


class GraphWithCycleError : public std::exception
{
public:
    [[nodiscard]] const char * what() const noexcept override {
        return "Graph contains a cycle";
    }
};


struct GraphNode
{
    std::size_t index;
    std::list<GraphNode*> neighbors;

    explicit GraphNode(std::size_t index_) : index {index_}
    {

    }
};


enum class NodeStatus{
    unvisited,
    visited,
    processed,
};


class DiGraph
{
    // Directed graph class
private:
    std::vector<GraphNode*> m_nodes;
    std::size_t m_numEdges {0};

    GraphNode* getNode(std::size_t index) { return m_nodes[index]; }

    void traverseAndStack(GraphNode* node,
                          std::vector<bool>& visited,
                          std::stack<std::size_t>& stack) const;

    bool detectCycle(GraphNode* node,
                     std::vector<NodeStatus>& status) const;

public:

    explicit DiGraph(const std::vector<std::vector<std::size_t>>& adjList)
    {
        // Create the graph from an adjacency list
        for (std::size_t ii {0}; ii < adjList.size(); ++ii)
            m_nodes.emplace_back(new GraphNode {ii});

        for (auto ii {0}; ii < adjList.size(); ++ii)
        {
            for (auto jj {0}; jj < adjList[ii].size(); ++jj)
            {
                m_nodes[ii]->neighbors.push_back(m_nodes[adjList[ii][jj]]);
                ++m_numEdges;
            }
        }
    }

    explicit DiGraph(std::size_t numNodes,
                     const std::vector<std::pair<std::size_t, std::size_t>>& edgeList)
    {
        for (std::size_t ii {0}; ii < numNodes; ++ii)
            m_nodes.emplace_back(new GraphNode {ii});

        for (const auto& edge : edgeList)
            m_nodes[edge.first]->neighbors.push_back(m_nodes[edge.second]);
    }

    [[nodiscard]] std::size_t getNumNodes() const { return m_nodes.size(); }
    [[nodiscard]] std::size_t getNumEdges() const { return m_numEdges; }

    bool pathBetween(std::size_t startNode, std::size_t endNode);

    [[nodiscard]] bool isCyclic() const;
    [[nodiscard]] std::vector<std::size_t> topologicalSort() const;
};

#endif //CRACKING_DIGRAPH_H