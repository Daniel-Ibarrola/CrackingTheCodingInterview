project(chapter_3)

set(HEADER_FILES
        stack.h
        queue.h
        stack_min.h
        set_of_stacks.h
        )

set(SOURCE_FILES
        stack.cpp
        queue.cpp
        )

add_library(chapter_3 STATIC ${SOURCE_FILES} ${HEADER_FILES})