add_library(bookgui "GUI/Graphics.cpp" "GUI/GUI.cpp" "GUI/Simple_window.cpp"
            "GUI/Window.cpp")

add_library(token_stream.no_mod OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream.no_mod
                           PRIVATE
                           -DERR_OUT
                           -DNO_MOD
                           -DNO_CONSTANTS
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_constants OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream.no_constants
                           PRIVATE
                           -DERR_OUT
                           -DNO_CONSTANTS
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_ignore OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream.no_ignore
                           PRIVATE
                           -DERR_OUT
                           -DNO_IGNORE
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_decl OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream.no_decl
                           PRIVATE
                           -DERR_OUT
                           -DNO_DECL
                           -DNO_VARS)

add_library(token_stream.no_vars OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream.no_vars
                           PRIVATE
                           -DERR_OUT
                           -DNO_VARS)

add_library(token_stream OBJECT "calc/token_stream.cpp")
target_compile_definitions(token_stream PRIVATE -DERR_OUT)

add_library(calculator.no_unary OBJECT "calc/calculator.cpp")
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

add_library(calculator.no_mod OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_mod
                           PRIVATE
                           -DERR_OUT
                           -DNO_MOD
                           -DNO_CONSTANTS
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_constants OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_constants
                           PRIVATE
                           -DERR_OUT
                           -DNO_CONSTANTS
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_calculate OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_calculate
                           PRIVATE
                           -DERR_OUT
                           -DNO_CALCULATE
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_recovery OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_recovery
                           PRIVATE
                           -DERR_OUT
                           -DNO_RECOVERY
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_decl OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_decl
                           PRIVATE
                           -DERR_OUT
                           -DNO_DECL
                           -DNO_VARS)

add_library(calculator.no_vars OBJECT "calc/calculator.cpp")
target_compile_definitions(calculator.no_vars
                           PRIVATE
                           -DERR_OUT
                           -DNO_VARS)

add_library(calculator "calc/calculator.cpp")
target_compile_definitions(calculator PRIVATE -DERR_OUT)
target_link_libraries(calculator token_stream)

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

