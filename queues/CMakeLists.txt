project(queues)

set(HEADER_FILES
        queue.h
        my_queue.h
        )

set(SOURCE_FILES
        queue.cpp
        )

add_library(queues STATIC ${SOURCE_FILES} ${HEADER_FILES})