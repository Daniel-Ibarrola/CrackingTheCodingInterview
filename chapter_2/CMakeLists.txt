project(chapter_2)

set(HEADER_FILES
        linked_list.h
        double_list.h
        list_w_tail.h
        list_intersection.h
        )

set(SOURCE_FILES
        linked_list.cpp
        double_list.cpp
        list_w_tail.cpp
        list_intersection.cpp
        )

add_library(chapter_2 STATIC ${SOURCE_FILES} ${HEADER_FILES})
