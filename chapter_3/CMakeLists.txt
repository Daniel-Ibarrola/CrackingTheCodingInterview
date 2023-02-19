project(chapter_3)

set(HEADER_FILES
        stack.h
        queue.h
        stack_min.h
        set_of_stacks.h
        my_queue.h
        sortstack.h
        animal_shelter.h
        )

set(SOURCE_FILES
        stack.cpp
        queue.cpp
        animal_shelter.cpp
        )

add_library(chapter_3 STATIC ${SOURCE_FILES} ${HEADER_FILES})