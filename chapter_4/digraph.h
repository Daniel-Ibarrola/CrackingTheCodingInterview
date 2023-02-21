//
// Created by daniel on 20/02/23.
//

#ifndef CRACKING_DIGRAPH_H
#define CRACKING_DIGRAPH_H

#include <queue>
#include <list>
#include <vector>


struct GraphNode
{
    std::size_t index;
    std::list<GraphNode*> neighbors;
    bool visited {false};

    explicit GraphNode(std::size_t index_) : index {index_}
    {

    }
};


class DiGraph
{
    // Directed graph class
private:
    std::vector<GraphNode*> m_nodes;
    std::size_t m_numEdges {0};

    GraphNode* getNode(std::size_t index) { return m_nodes[index]; }

public:

    explicit DiGraph(const std::vector<std::vector<std::size_t>>& adjList)
    {
        // Create the graph from an adjacency list
        for (std::size_t ii {0}; ii < adjList.size(); ++ii)
        {
            auto* node = new GraphNode {ii};
            m_nodes.push_back(node);
        }

        for (auto ii {0}; ii < adjList.size(); ++ii)
        {
            for (auto jj {0}; jj < adjList[ii].size(); ++jj)
            {
                m_nodes[ii]->neighbors.push_back(m_nodes[adjList[ii][jj]]);
                ++m_numEdges;
            }
        }
    }

    [[nodiscard]] std::size_t getNumNodes() const { return m_nodes.size(); }
    [[nodiscard]] std::size_t getNumEdges() const { return m_numEdges; }

    bool pathBetween(std::size_t startNode, std::size_t endNode);
};

#endif //CRACKING_DIGRAPH_H
