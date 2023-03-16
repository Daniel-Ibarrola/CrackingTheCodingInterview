//
// Created by daniel on 14/03/23.
//

#include "build_order.h"


std::map<char, std::size_t> getProjectMap(const std::vector<char>& projects)
{
    // Map project names to an unsigned integer
    std::size_t projNum {0};
    std::map<char, std::size_t> projectMap;

    for (auto name : projects)
    {
        projectMap[name] = projNum;
        ++projNum;
    }
    return projectMap;
}

std::vector<std::pair<std::size_t, std::size_t>> getEdgeList(
        const std::vector<std::pair<char, char>>& dependencies,
        const std::map<char, std::size_t>& projectMap
        )
{
    std::vector<std::pair<std::size_t, std::size_t>> edgeList;
    for (const auto& pair : dependencies )
        edgeList.emplace_back(projectMap.at(pair.first), projectMap.at(pair.second));

    return edgeList;
}

std::vector<char> projectsOrdering(
        const std::vector<std::size_t>& ordering,
        const std::map<char, std::size_t>& projectMap
)
{
    std::map<std::size_t, char> reverseMap;
    for (const auto& pair : projectMap)
        reverseMap[pair.second] = pair.first;

    std::vector<char> projects;
    for (auto ii : ordering)
        projects.push_back(reverseMap[ii]);

    return projects;
}


std::vector<char> buildOrder(
        const std::vector<char>& projects,
        const std::vector<std::pair<char, char>>& dependencies
)
{
    std::map<char, std::size_t> projectsMap {getProjectMap(projects)};
    std::vector<std::pair<std::size_t, std::size_t>> edgeList
        {getEdgeList(dependencies, projectsMap)};

    DiGraph graph {projects.size(), edgeList};
    std::vector<std::size_t> ordering {graph.topologicalSort()};
    return projectsOrdering(ordering, projectsMap);
}
