project(chapter_1)

set(HEADER_FILES
        ex_1_1.h
        ex_1_2.h
        ex_1_3.h
        ex_1_4.h
        ex_1_6.h
        ex_1_8.h
        rotate_matrix.h
        )

set(SOURCE_FILES
        ex_1_1.cpp
        ex_1_2.cpp
        ex_1_3.cpp
        ex_1_4.cpp
        ex_1_6.cpp
        ex_1_8.cpp
        rotate_matrix.cpp
        )

add_library(chapter_1 STATIC ${SOURCE_FILES} ${HEADER_FILES})
