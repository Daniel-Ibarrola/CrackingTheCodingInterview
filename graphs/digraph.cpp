//
// Created by daniel on 20/02/23.
//

#include "digraph.h"


bool DiGraph::pathBetween(std::size_t startNode, std::size_t endNode)
{
    // Returns true if there is a path between the nodes with given indices
    std::queue<GraphNode*> queue;
    std::vector<bool> visited (getNumNodes(), false);
    queue.push(getNode(startNode));

    GraphNode* end {getNode(endNode)};

    while (!queue.empty())
    {
        GraphNode* current {queue.front()};
        queue.pop();

        if (current == end)
            return true;

        for (auto nbr : current->neighbors)
        {
            if (!visited[nbr->index])
            {
                visited[nbr->index] = true;
                queue.push(nbr);
            }
        }
    }
    return false;
}


bool DiGraph::detectCycle(GraphNode *node, std::vector<NodeStatus> &status) const
{
    // Helper function for isCyclic
    if (status[node->index] == NodeStatus::visited)
        return true;
    if (status[node->index] == NodeStatus::processed)
        return false;

    status[node->index] = NodeStatus::visited;
    for (auto nbr: node->neighbors)
        if (detectCycle(nbr, status))
            return true;

    status[node->index] = NodeStatus::processed;
    return false;
}


bool DiGraph::isCyclic() const
{
    // Returns true if the graph is cyclic
    std::vector<NodeStatus> status(getNumNodes(), NodeStatus::unvisited);
    for (auto node : m_nodes)
    {
        if (status[node->index] == NodeStatus::unvisited)
            if (detectCycle(node, status))
                return true;
    }
    return false;
}

void DiGraph::traverseAndStack(
        GraphNode *node,
        std::vector<bool>& visited,
        std::stack<std::size_t>& stack) const
{
    // Do a depth first search while pushing the nodes into a stack
    visited[node->index] = true;
    for (auto nbr : node->neighbors)
    {
        if (!visited[nbr->index])
            traverseAndStack(nbr, visited, stack);
    }
    stack.push(node->index);
}

std::vector<std::size_t> DiGraph::topologicalSort() const
{
    // Returns a topological ordering of the graph
    if (isCyclic())
        throw GraphWithCycleError();

    std::vector<bool> visited(getNumNodes(), false);
    std::stack<std::size_t> stack;
    for (auto node : m_nodes){
        if (!visited[node->index])
            traverseAndStack(node, visited, stack);
    }

    std::vector<std::size_t> ordering(getNumNodes());
    std::size_t ii {0};
    while (!stack.empty())
    {
        ordering[ii] = stack.top();
        stack.pop();
        ++ii;
    }

    return ordering;
}
