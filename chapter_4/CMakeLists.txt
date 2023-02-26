project(chapter_4)

set(HEADER_FILES
        digraph.h
        bst.h
        )

set(SOURCE_FILES
        digraph.cpp
        bst.cpp
        )

add_library(chapter_4 STATIC ${SOURCE_FILES} ${HEADER_FILES})
