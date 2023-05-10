project(trees)

set(HEADER_FILES
        bst.h
        binary_tree.h
        )

set(SOURCE_FILES
        bst.cpp
        binary_tree.cpp
        )

add_library(trees STATIC ${SOURCE_FILES} ${HEADER_FILES})
