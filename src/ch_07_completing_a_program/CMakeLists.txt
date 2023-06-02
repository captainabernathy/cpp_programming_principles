add_executable(ch_07_02_calc_promp_01 ch_07_02_calc_promp_01.cpp)
add_executable(ch_07_03_calc_improved_error_handling_01
               ch_07_03_calc_improved_error_handling_01.cpp)
add_executable(ch_07_04_calc_unary_operators_01
               ch_07_04_calc_unary_operators_01.cpp)
add_executable(ch_07_05_calc_modulus_operator_01
               ch_07_05_calc_modulus_operator_01.cpp)
add_executable(ch_07_06_01_calc_symbolic_constants
               ch_07_06_01_calc_symbolic_constants.cpp)
add_executable(ch_07_06_02_calc_functions ch_07_06_02_calc_functions.cpp)
add_executable(ch_07_07_calc_recovery ch_07_07_calc_recovery.cpp)
add_executable(ch_07_08_01_calc_declarations ch_07_08_01_calc_declarations.cpp)
add_executable(ch_07_08_02_calc_variables ch_07_08_02_calc_variables.cpp)
add_executable(ch_07_08_03_calc_predefined_names
               ch_07_08_03_calc_predefined_names.cpp)

target_compile_definitions(ch_07_02_calc_promp_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_03_calc_improved_error_handling_01
                           PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_04_calc_unary_operators_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_05_calc_modulus_operator_01 PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_06_01_calc_symbolic_constants
                           PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_06_02_calc_functions PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_07_calc_recovery PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_08_01_calc_declarations PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_08_02_calc_variables PRIVATE -DERR_OUT)
target_compile_definitions(ch_07_08_03_calc_predefined_names PRIVATE -DERR_OUT)

