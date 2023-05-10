cmake_minimum_required(VERSION 3.24)
project(Cracking)

set(CMAKE_CXX_STANDARD 17)

include_directories(graphs)
add_subdirectory(graphs)

include_directories(linked_list)
add_subdirectory(linked_list)

include_directories(matrix)
add_subdirectory(matrix)

include_directories(queues)
add_subdirectory(queues)

include_directories(stacks)
add_subdirectory(stacks)

include_directories(strings)
add_subdirectory(strings)

include_directories(trees)
add_subdirectory(trees)

add_subdirectory(tests)