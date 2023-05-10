project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        linked_list/test_linked_list.cpp
        linked_list/test_double_list.cpp
        linked_list/test_remove_duplicates.cpp
        linked_list/test_kth_to_last.cpp
        linked_list/test_partition.cpp
        linked_list/test_linked_list_sum.cpp
        linked_list/test_list_with_tail.cpp
        linked_list/test_is_palindrome.cpp
        linked_list/test_list_intersection.cpp
        linked_list/test_loop_detection.cpp
        matrix/test_matrix.cpp
        queue/test_queue.cpp
        queue/test_queue_via_stack.cpp
        strings/test_strings.cpp
        stacks/test_stack.cpp
        stacks/test_stack_min.cpp
        stacks/test_set_of_stacks.cpp
        stacks/test_sortstack.cpp
        stacks/test_animal_shelter.cpp
        chapter_4/test_path_between.cpp
        chapter_4/test_minimal_height_bst.cpp
        chapter_4/test_list_of_depths.cpp
        chapter_4/test_is_tree_balanced.cpp
        chapter_4/test_binary_search_tree.cpp
        chapter_4/test_validate_bst.cpp
        chapter_4/test_successor.cpp
        chapter_4/test_build_order.cpp
        chapter_4/test_topological_ordering.cpp
)

target_link_libraries(Google_Tests_run linked_list)
target_link_libraries(Google_Tests_run matrix)
target_link_libraries(Google_Tests_run queues)
target_link_libraries(Google_Tests_run stacks)
target_link_libraries(Google_Tests_run strings_algorithms)
target_link_libraries(Google_Tests_run chapter_4)
target_link_libraries(Google_Tests_run gtest gtest_main)
