project(linked_list)

set(HEADER_FILES
        linked_list.h
        double_list.h
        list_w_tail.h
        list_intersection.h
        node.h
        loop_detection.h
        )

set(SOURCE_FILES
        linked_list.cpp
        double_list.cpp
        list_w_tail.cpp
        list_intersection.cpp
        node.cpp
        loop_detection.cpp
        )

add_library(linked_list STATIC ${SOURCE_FILES} ${HEADER_FILES})
