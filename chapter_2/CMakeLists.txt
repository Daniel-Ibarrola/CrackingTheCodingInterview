project(chapter_2)

set(HEADER_FILES
        linked_list.h
        double_list.h
        )

set(SOURCE_FILES
        linked_list.cpp
        double_list.cpp
        )

add_library(chapter_2 STATIC ${SOURCE_FILES} ${HEADER_FILES})
