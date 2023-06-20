add_library(token_stream.no_mod OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream.no_mod
                           PRIVATE
                           -DERR_OUT
                           -DNO_MOD
                           -DNO_CONSTANTS
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_constants
            OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream.no_constants
                           PRIVATE
                           -DERR_OUT
                           -DNO_CONSTANTS
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_ignore OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream.no_ignore
                           PRIVATE
                           -DERR_OUT
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_decl OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream.no_decl
                           PRIVATE
                           -DERR_OUT
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_vars OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream.no_vars
                           PRIVATE
                           -DERR_OUT
                           -DNO_VARS)

add_library(token_stream OBJECT "calculator_utils/token_stream.cpp")
target_compile_definitions(token_stream PRIVATE -DERR_OUT)

add_library(calculator.no_unary OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_unary
                           PRIVATE
                           -DERR_OUT
                           -DNO_UNARY
                           -DNO_MOD
                           -DNO_CONSTANTS
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_mod OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_mod
                           PRIVATE
                           -DERR_OUT
                           -DNO_MOD
                           -DNO_CONSTANTS
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_constants OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_constants
                           PRIVATE
                           -DERR_OUT
                           -DNO_CONSTANTS
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_calculate OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_calculate
                           PRIVATE
                           -DERR_OUT
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_recovery OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_recovery
                           PRIVATE
                           -DERR_OUT
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_decl OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_decl
                           PRIVATE
                           -DERR_OUT
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_vars OBJECT "calculator_utils/calculator.cpp")
target_compile_definitions(calculator.no_vars
                           PRIVATE
                           -DERR_OUT
                           -DNO_VARS)

add_library(calculator "calculator_utils/calculator.cpp")
target_compile_definitions(calculator PRIVATE -DERR_OUT)
target_link_libraries(calculator token_stream)

add_library(date_constructor_only OBJECT "chrono_utils/date_impl.cpp")
target_compile_definitions(date_constructor_only
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_DEFAULT_CONS
                           -DNO_MONTH
                           -DNO_INVALID
                           -DNO_MONTH_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_has_check
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp")
target_compile_definitions(date_has_check
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_DEFAULT_CONS
                           -DNO_MONTH
                           -DNO_MONTH_CONS
                           -DHAS_CHECK_METH
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS
                           -DERR_OUT)

add_library(month_utils OBJECT "chrono_utils/month_utils.cpp")

add_library(date_has_year OBJECT "chrono_utils/date_impl.cpp")
target_compile_definitions(date_has_year
                           PRIVATE
                           -DHAS_YEAR
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DHAS_YEAR_CONS
                           -DNO_DAY_METH
                           -DNO_MONTH_METH
                           -DNO_YEAR_METH
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_has_friend
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp")
target_compile_definitions(date_has_friend
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_DAY_METH
                           -DNO_MONTH_METH
                           -DNO_YEAR_METH
                           -DNO_ADD_YEAR_METH
                           -DHAS_FRIEND_DATE_OUTPUT_OP
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_has_default OBJECT "chrono_utils/date_impl.cpp")
target_compile_definitions(date_has_default
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_has_accessors OBJECT "chrono_utils/date_impl.cpp")
target_compile_definitions(date_has_accessors
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_has_helpers
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp"
            "chrono_utils/day_utils.cpp")
target_compile_definitions(date_has_helpers
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_DEFAULT_CONS
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_DATE_INPUT_OP
                           -DNO_DATE_OUTPUT_OP
                           -DNO_DAY
                           -DNO_DAY_OF_WEEK_FN)

add_library(date_chrono
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp"
            "chrono_utils/day_utils.cpp")

add_library(date_output_only
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp")
target_compile_definitions(date_output_only
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DATE_INPUT_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(date_input_and_output
            OBJECT
            "chrono_utils/date_impl.cpp"
            "chrono_utils/date_io.cpp")
target_compile_definitions(date_input_and_output
                           PRIVATE
                           -DNO_CHRONO_NS
                           -DNO_INVALID
                           -DNO_ADD_YEAR_METH
                           -DNO_DEFAULT_FN
                           -DNO_IS_DATE_FN
                           -DNO_LEAP_YEAR_FN
                           -DNO_DATE_EQ_OP
                           -DNO_DATE_INEQ_OP
                           -DNO_DAY
                           -DNO_DAY_UTILS)

add_library(bookgui "GUI/Graphics.cpp" "GUI/GUI.cpp" "GUI/Simple_window.cpp"
            "GUI/Window.cpp")

add_library(document_utils OBJECT "text_utils/document_utils.cpp")

add_library(text_utils OBJECT "text_utils/text_utils.cpp")

add_library(io_utils
            OBJECT
            "io_utils/str_to_double.cpp"
            "io_utils/read_word.cpp")
target_compile_definitions(io_utils PRIVATE -DERR_OUT)

add_library(string_utils.no_recursion
            OBJECT
            "string_utils/is_prefix.cpp"
            "string_utils/no_case.cpp"
            "string_utils/is_palindrome.cpp")
target_compile_definitions(string_utils.no_recursion PRIVATE -DNO_RECURSION)

add_library(string_utils
            "string_utils/is_prefix.cpp"
            "string_utils/no_case.cpp"
            "string_utils/is_palindrome.cpp")

add_library(numeric_utils.classical
            OBJECT
            "numeric_utils/solve_linear_system.cpp"
            "numeric_utils/classical_gaussian_elimination.cpp"
            "numeric_utils/classical_elimination.cpp"
            "numeric_utils/back_substitution.cpp")
target_compile_definitions(numeric_utils.classical
                           PRIVATE
                           -DCLASSICAL_ELIMINATION
                           -DERR_OUT)

add_library(numeric_utils
            "numeric_utils/solve_linear_system.cpp"
            "numeric_utils/pivotal_elimination.cpp"
            "numeric_utils/partial_pivot_elimination.cpp"
            "numeric_utils/back_substitution.cpp")
target_compile_definitions(numeric_utils PRIVATE -DERR_OUT)

add_subdirectory("ch_02_hello_world")
add_subdirectory("ch_03_objects_types_values")
add_subdirectory("ch_04_computation")
add_subdirectory("ch_05_errors")
add_subdirectory("ch_06_writing_a_program")
add_subdirectory("ch_07_completing_a_program")
add_subdirectory("ch_08_functions")
add_subdirectory("ch_09_classes")
add_subdirectory("ch_10_input_and_output_streams")
add_subdirectory("ch_11_customizing_input_and_output")
add_subdirectory("ch_12_a_display_model")
add_subdirectory("ch_13_graphics_classes")
add_subdirectory("ch_14_graphics_class_design")
add_subdirectory("ch_15_graphing_functions_and_data")
add_subdirectory("ch_16_graphical_user_interfaces")
add_subdirectory("ch_17_vector_and_free_store")
add_subdirectory("ch_18_vectors_and_arrays")
add_subdirectory("ch_19_vector_templates_and_exceptions")
add_subdirectory("ch_20_containers_and_iterators")
add_subdirectory("ch_21_algorithms_and_maps")
add_subdirectory("ch_23_text_manipulation")
add_subdirectory("ch_24_numerics")
