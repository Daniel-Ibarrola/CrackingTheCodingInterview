project(matrix)

set(HEADER_FILES
        matrix.h
        )

set(SOURCE_FILES
       matrix.cpp
        )

add_library(matrix STATIC ${SOURCE_FILES} ${HEADER_FILES})
