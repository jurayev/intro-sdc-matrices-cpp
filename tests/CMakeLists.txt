add_executable(
        run_matrix_tests
        main_tests.cpp
        matrix_init_tests.cpp
        matrix_addition_tests.cpp
        matrix_transpose_tests.cpp
)

target_link_libraries(run_matrix_tests matrix_src)
