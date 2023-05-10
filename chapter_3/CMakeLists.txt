project(chapter_3)

set(HEADER_FILES
        stack.h
        stack_min.h
        set_of_stacks.h
        sortstack.h
        animal_shelter.h
        )

set(SOURCE_FILES
        stack.cpp
        animal_shelter.cpp
        )

add_library(chapter_3 STATIC ${SOURCE_FILES} ${HEADER_FILES})