project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        chapter_1/test_ex_1_1.cpp
        chapter_1/test_ex_1_2.cpp
        chapter_1/test_ex_1_3.cpp
        chapter_1/test_ex_1_4.cpp
)

target_link_libraries(Google_Tests_run chapter_1)
target_link_libraries(Google_Tests_run gtest gtest_main)
