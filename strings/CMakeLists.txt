project(strings_algorithms)

set(HEADER_FILES
        strings_algo.h
        )

set(SOURCE_FILES
        strings_algo.cpp
        )

add_library(strings_algorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})
