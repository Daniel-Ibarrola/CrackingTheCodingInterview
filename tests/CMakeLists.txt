project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        arrays/test_arrays.cpp
        graphs/test_build_order.cpp
        graphs/test_path_between.cpp
        graphs/test_topological_ordering.cpp
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
        trees/test_minimal_height_bst.cpp
        trees/test_list_of_depths.cpp
        trees/test_is_tree_balanced.cpp
        trees/test_binary_search_tree.cpp
        trees/test_validate_bst.cpp
        trees/test_successor.cpp
)

target_link_libraries(Google_Tests_run arrays)
target_link_libraries(Google_Tests_run graphs)
target_link_libraries(Google_Tests_run linked_list)
target_link_libraries(Google_Tests_run matrix)
target_link_libraries(Google_Tests_run queues)
target_link_libraries(Google_Tests_run stacks)
target_link_libraries(Google_Tests_run strings_algorithms)
target_link_libraries(Google_Tests_run trees)
target_link_libraries(Google_Tests_run gtest gtest_main)
