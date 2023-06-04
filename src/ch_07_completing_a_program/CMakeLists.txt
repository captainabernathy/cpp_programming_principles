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

target_compile_definitions(ch_07_02_calc_promp_01
                           PRIVATE
                           -DCALC_TEST
                           -DNO_DECL)
target_compile_definitions(ch_07_03_calc_improved_error_handling_01
                           PRIVATE
                           -DCALC_TEST
                           -DNO_DECL)
target_compile_definitions(ch_07_04_calc_unary_operators_01
                           PRIVATE
                           -DCALC_TEST
                           -DNO_DECL)
target_compile_definitions(ch_07_05_calc_modulus_operator_01
                           PRIVATE
                           -DCALC_TEST
                           -DNO_DECL)
target_compile_definitions(ch_07_06_01_calc_symbolic_constants
                           PRIVATE
                           -DNO_DECL)

target_link_libraries(ch_07_02_calc_promp_01
                      token_stream.no_mod
                      calculator.no_unary)
target_link_libraries(ch_07_03_calc_improved_error_handling_01
                      token_stream.no_mod
                      calculator.no_unary)
target_link_libraries(ch_07_04_calc_unary_operators_01
                      token_stream.no_mod
                      calculator.no_mod)
target_link_libraries(ch_07_05_calc_modulus_operator_01
                      token_stream.no_constants
                      calculator.no_constants)
target_link_libraries(ch_07_06_01_calc_symbolic_constants
                      token_stream.no_ignore
                      calculator.no_calculate)
target_link_libraries(ch_07_06_02_calc_functions
                      token_stream.no_ignore
                      calculator.no_recovery)
target_link_libraries(ch_07_07_calc_recovery
                      token_stream.no_decl
                      calculator.no_decl)
target_link_libraries(ch_07_08_01_calc_declarations
                      token_stream.no_vars
                      calculator.no_vars)
target_link_libraries(ch_07_08_02_calc_variables calculator)
target_link_libraries(ch_07_08_03_calc_predefined_names calculator)

