project(chapter_1)

set(HEADER_FILES
        ex_1_1.h
        )

set(SOURCE_FILES
        ex_1_1.cpp
        )

add_library(chapter_1 STATIC ${SOURCE_FILES} ${HEADER_FILES})
