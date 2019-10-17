cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(data-struct-cpp)

set(CMAKE_CXX_STANDARD 14)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

# Code Coverage Configuration
add_library(coverage_config INTERFACE)
option(CODE_COVERAGE "Enable coverage reporting" ON)

target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
  )
target_link_libraries(coverage_config INTERFACE --coverage)

enable_testing()

include (CTest)

set(CTEST_MEMORYCHECK_COMMAND valgrind) 
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--tool=callgrind -v") 

add_subdirectory(src)
add_subdirectory(tests)

