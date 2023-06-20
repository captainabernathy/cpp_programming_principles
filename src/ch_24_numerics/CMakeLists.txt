add_library(ch_24_utils
            OBJECT
            "random_vector.cpp"
            "random_matrix.cpp")

add_executable(ch_24_02_00_size_precision_overflow
               ch_24_02_00_size_precision_overflow.cpp)

add_executable(ch_24_02_01_numeric_limits ch_24_02_01_numeric_limits.cpp)

add_executable(ch_24_04_c_style_multidimensional_arrays
               ch_24_04_c_style_multidimensional_arrays.cpp)

add_executable(ch_24_05_01_dimensions_access ch_24_05_01_dimensions_access.cpp)

add_executable(ch_24_05_02_1d_matrix ch_24_05_02_1d_matrix.cpp)

add_executable(ch_24_05_03_2d_matrix ch_24_05_03_2d_matrix.cpp)

add_executable(ch_24_05_04_matrix_io ch_24_05_04_matrix_io.cpp)
target_compile_definitions(ch_24_05_04_matrix_io PRIVATE -DERR_OUT)

add_executable(ch_24_05_05_3d_matrix ch_24_05_05_3d_matrix.cpp)

add_executable(ch_24_06_01_classical_gaussian_elimination
               ch_24_06_01_classical_gaussian_elimination.cpp)
target_compile_definitions(ch_24_06_01_classical_gaussian_elimination
                           PRIVATE
                           -DCLASSICAL_ELIMINATION
                           -DERR_OUT)
target_link_libraries(ch_24_06_01_classical_gaussian_elimination
                      numeric_utils.classical)

add_executable(ch_24_06_02_pivoting ch_24_06_02_pivoting.cpp)
target_compile_definitions(ch_24_06_02_pivoting PRIVATE -DERR_OUT)
target_link_libraries(ch_24_06_02_pivoting numeric_utils)

add_executable(ch_24_06_03_testing ch_24_06_03_testing.cpp)
target_compile_definitions(ch_24_06_03_testing
                           PRIVATE
                           -DCLASSICAL_ELIMINATION
                           -DERR_OUT)
target_link_libraries(ch_24_06_03_testing
                      numeric_utils.classical
                      ch_24_utils)

add_executable(ch_24_07_random_numbers ch_24_07_random_numbers.cpp)

add_executable(ch_24_08_standard_mathematical_functions
               ch_24_08_standard_mathematical_functions.cpp)

add_executable(ch_24_09_complex_numbers ch_24_09_complex_numbers.cpp)

add_custom_command(
    TARGET ch_24_05_04_matrix_io POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/matrix_infile.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/matrix_infile.txt
)
