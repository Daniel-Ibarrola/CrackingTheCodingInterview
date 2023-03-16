//
// Created by daniel on 14/03/23.
//

#include "gtest/gtest.h"
#include "build_order.h"


TEST(TestBuildOrder, GetProjectsMap)
{
    std::vector<char> projects {'a', 'b', 'c', 'd'};
    std::map<char, std::size_t> expected {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}};

    ASSERT_EQ(expected, getProjectMap(projects));
}

TEST(TestBuildOrder, GetEdgeList)
{
    std::vector<std::pair<char, char>> dependencies {
            {'a', 'b'}, {'b', 'c'},  {'c', 'd'}
    };
    std::map<char, std::size_t> projectMap {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}};

    std::vector<std::pair<std::size_t, std::size_t>> expected {
            {0, 1}, {1, 2}, {2, 3}
    };
    ASSERT_EQ(expected, getEdgeList(dependencies, projectMap));
}


TEST(TestBuildOrder, projectsOrdering)
{
    std::map<char, std::size_t> projectMap {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}};
    std::vector<std::size_t> ordering {2, 1, 3, 0};
    std::vector<char> expected {'c', 'b', 'd', 'a'};

    ASSERT_EQ(expected, projectsOrdering(ordering, projectMap));
}


TEST(TestBuildOrder, GraphWithCycleThrowsError)
{
    std::vector<char> projects {'a', 'b', 'c', 'd'};
    std::vector<std::pair<char, char>> dependencies {
            {'a', 'b'}, {'b', 'c'}, {'c', 'a'}, {'c', 'd'}
    };

    ASSERT_THROW(buildOrder(projects, dependencies), GraphWithCycleError);
}


TEST(TestBuildOrder, FindsCorrectOrdering)
{
    std::vector<char> projects {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::pair<char, char>> dependencies {
            {'a', 'd'},
            {'b', 'd'},
            {'d', 'c'},
            {'f', 'a'},
            {'f', 'b'},
    };

    std::vector<char> expected {'f', 'e', 'b', 'a', 'd', 'c'};
    ASSERT_EQ(buildOrder(projects, dependencies), expected);
}
