project(arrays)

set(HEADER_FILES
        arrays.h
        )

set(SOURCE_FILES
        arrays.cpp
        )

add_library(arrays STATIC ${SOURCE_FILES} ${HEADER_FILES})
