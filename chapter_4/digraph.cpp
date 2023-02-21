//
// Created by daniel on 20/02/23.
//

#include "digraph.h"


bool DiGraph::pathBetween(std::size_t startNode, std::size_t endNode)
{
    // Returns true if there is a path between the nodes with given indices
    std::queue<GraphNode*> queue;
    getNode(startNode)->visited = true;
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
            if (!nbr->visited)
            {
                nbr->visited = true;
                queue.push(nbr);
            }
        }
    }
    return false;
}
