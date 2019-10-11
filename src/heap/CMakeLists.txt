set(HEAP_SRCS
    Heap.hpp
    Heap.cpp
)

# Declare the library
add_library(HEAP STATIC
    ${HEAP_SRCS}
)

target_link_libraries(HEAP)

# Specify here the include directories exported
# by this library
target_include_directories(HEAP PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
