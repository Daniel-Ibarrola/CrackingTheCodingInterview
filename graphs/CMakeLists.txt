project(graphs)

set(HEADER_FILES
        digraph.h
        build_order.h
        )

set(SOURCE_FILES
        digraph.cpp
        build_order.cpp
        )

add_library(graphs STATIC ${SOURCE_FILES} ${HEADER_FILES})
