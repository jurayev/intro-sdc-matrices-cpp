add_library(matrix_src matrix.cpp)

# uncomment to run application from main.cpp
add_executable(run_matrix_main main.cpp)
target_link_libraries(run_matrix_main matrix_src)