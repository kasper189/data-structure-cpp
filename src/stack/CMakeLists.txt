set(STACK_SRCS
    Stack.hpp
    Stack.cpp
)

# Declare the library
add_library(STACK STATIC
    ${STACK_SRCS}
)

target_link_libraries(STACK coverage_config)

# Specify here the include directories exported
# by this library
target_include_directories(STACK PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
