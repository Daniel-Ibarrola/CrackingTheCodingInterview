cmake_minimum_required(VERSION 3.24)
project(Cracking)

set(CMAKE_CXX_STANDARD 17)

include_directories(chapter_1)
add_subdirectory(chapter_1)

add_library(Cracking library.cpp)
add_subdirectory(tests)