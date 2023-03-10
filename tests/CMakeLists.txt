project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        chapter_1/test_ex_1_1.cpp
        chapter_1/test_ex_1_2.cpp
        chapter_1/test_ex_1_3.cpp
        chapter_1/test_ex_1_4.cpp
        chapter_1/test_ex_1_6.cpp
        chapter_1/test_ex_1_8.cpp
        chapter_1/test_rotate_matrix.cpp
        chapter_2/test_linked_list.cpp
        chapter_2/test_double_list.cpp
        chapter_2/test_remove_duplicates.cpp
        chapter_2/test_kth_to_last.cpp
        chapter_2/test_partition.cpp
        chapter_2/test_linked_list_sum.cpp
        chapter_2/test_list_with_tail.cpp
        chapter_2/test_is_palindrome.cpp
        chapter_2/test_list_intersection.cpp
        chapter_2/test_loop_detection.cpp
        chapter_3/test_stack.cpp
        chapter_3/test_queue.cpp
        chapter_3/test_stack_min.cpp
        chapter_3/test_set_of_stacks.cpp
        chapter_3/test_queue_via_stack.cpp
        chapter_3/test_sortstack.cpp
        chapter_3/test_animal_shelter.cpp
        chapter_4/test_path_between.cpp
        chapter_4/test_minimal_height_bst.cpp
        chapter_4/test_list_of_depths.cpp
        chapter_4/test_is_tree_balanced.cpp
        chapter_4/test_binary_search_tree.cpp
        chapter_4/test_validate_bst.cpp
        chapter_4/test_successor.cpp
)

target_link_libraries(Google_Tests_run chapter_1)
target_link_libraries(Google_Tests_run chapter_2)
target_link_libraries(Google_Tests_run chapter_3)
target_link_libraries(Google_Tests_run chapter_4)
target_link_libraries(Google_Tests_run gtest gtest_main)
