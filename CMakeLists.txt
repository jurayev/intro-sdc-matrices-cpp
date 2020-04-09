cmake_minimum_required(VERSION 3.15)
project(intro_sdc_matrices_cpp)

set(CMAKE_CXX_STANDARD 14)

# include directories for imports
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/tests/src)

add_subdirectory(src)
add_subdirectory(tests)
