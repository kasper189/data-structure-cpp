set(LINKED_LIST_SRCS
    LinkedList.hpp
    LinkedList.cpp
)

# Declare the library
add_library(LINKED_LIST STATIC
    ${LINKED_LIST_SRCS}
)

target_link_libraries(LINKED_LIST)

# Specify here the include directories exported
# by this library
target_include_directories(LINKED_LIST PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
