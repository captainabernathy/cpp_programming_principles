add_executable(ch_21_02_01_generic_find_uses ch_21_02_01_generic_find_uses.cpp)
add_executable(ch_21_02_find_01 ch_21_02_find_01.cpp)
add_executable(ch_21_02_find_02 ch_21_02_find_02.cpp)
add_executable(ch_21_03_find_if ch_21_03_find_if.cpp)
add_executable(ch_21_04_01_abstract_view_of_function_objects
               ch_21_04_01_abstract_view_of_function_objects.cpp)
add_executable(ch_21_04_function_objects ch_21_04_function_objects.cpp)
add_executable(ch_21_05_01_accumulate ch_21_05_01_accumulate.cpp)
add_executable(ch_21_05_03_inner_product ch_21_05_03_inner_product.cpp)
add_executable(ch_21_05_04_generalizing_inner_product
               ch_21_05_04_generalizing_inner_product.cpp)
add_executable(ch_21_06_01_map ch_21_06_01_map.cpp)
add_executable(ch_21_06_03_another_map_example
               ch_21_06_03_another_map_example.cpp)
add_executable(ch_21_06_04_unordered_map ch_21_06_04_unordered_map.cpp)
add_executable(ch_21_07_01_copying ch_21_07_01_copying.cpp)
add_executable(ch_21_07_02_stream_iterators ch_21_07_02_stream_iterators.cpp)
add_executable(ch_21_07_03_using_a_set_to_keep_order
               ch_21_07_03_using_a_set_to_keep_order.cpp)
add_executable(ch_21_07_04_copy_if ch_21_07_04_copy_if.cpp)
add_executable(ch_21_08_sorting_and_searching
               ch_21_08_sorting_and_searching.cpp)

add_custom_command(
    TARGET ch_21_07_02_stream_iterators POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/Juliet.txt
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Juliet.txt
)

