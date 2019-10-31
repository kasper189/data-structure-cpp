set(BST_SRCS
    BST.hpp
    BST.cpp
)

# Declare the library
add_library(BST STATIC
    ${BST_SRCS}
)

target_link_libraries(BST coverage_config)

# Specify here the include directories exported
# by this library
target_include_directories(BST PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
