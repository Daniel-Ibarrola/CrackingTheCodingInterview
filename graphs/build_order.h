//
// Created by daniel on 14/03/23.
//

#ifndef CRACKING_BUILD_ORDER_H
#define CRACKING_BUILD_ORDER_H

#include "digraph.h"

std::map<char, std::size_t> getProjectMap(const std::vector<char>& projects);

std::vector<std::pair<std::size_t, std::size_t>> getEdgeList(
        const std::vector<std::pair<char, char>>& dependencies,
        const std::map<char, std::size_t>& projectMap
        );

std::vector<char> projectsOrdering(
        const std::vector<std::size_t>& ordering,
        const std::map<char, std::size_t>& projectMap
        );

std::vector<char> buildOrder(
        const std::vector<char>& projects,
        const std::vector<std::pair<char, char>>& dependencies
);


#endif //CRACKING_BUILD_ORDER_H
