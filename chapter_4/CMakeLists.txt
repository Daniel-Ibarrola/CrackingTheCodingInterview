project(chapter_4)

set(HEADER_FILES
        digraph.h
        )

set(SOURCE_FILES
        digraph.cpp
        )

add_library(chapter_4 STATIC ${SOURCE_FILES} ${HEADER_FILES})
